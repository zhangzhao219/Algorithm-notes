import copy
import math
import torch
import torch.nn as nn
import torch.nn.functional as F

class Transformer(nn.Module):
    def __init__(self, encoder, decoder, src_embed, tgt_embed, generator):
        super().__init__()
        self.encoder = encoder
        self.decoder = decoder
        self.src_embed = src_embed
        self.tgt_embed = tgt_embed
        self.generator = generator
    def forward(self, src, tgt, src_mask, tgt_mask):
        """
        Args:
            src: (batch_size, seq_len_src)
            tgt: (batch_size, seq_len_tgt)
            src_mask: (batch_size, 1, seq_len_src)
            tgt_mask: (batch_size, seq_len_tgt, seq_len_tgt)
        Returns:
            output: (batch_size, seq_len, d_model)
        """
        return self.do_decode(
            self.do_encode(src, src_mask),
            src_mask,
            tgt,
            tgt_mask,
        )
    def do_encode(self, src, src_mask):
        return self.encoder(self.src_embed(src), src_mask)
    def do_decode(self, memory, src_mask, tgt, tgt_mask):
        return self.decoder(self.tgt_embed(tgt), memory, src_mask, tgt_mask)

class Generator(nn.Module):
    def __init__(self, d_model, vocab_size):
        """
        Args:
            vocab_size: size of the vocabulary, that is, total number of unique tokens
        """
        super().__init__()
        self.linear = nn.Linear(d_model, vocab_size)
    def forward(self, x):
        return F.log_softmax(self.linear(x), dim=-1)

class Encoder(nn.Module):
    def __init__(self, layer, N):
        super().__init__()
        self.layers = nn.ModuleList([copy.deepcopy(layer) for _ in range(N)])
        self.norm = LayerNorm(layer.d_model)
    def forward(self, x, mask):
        for layer in self.layers:
            x = layer(x, mask)
        return self.norm(x)

class EncoderLayer(nn.Module):
    def __init__(self, d_model, attention, feed_forward, dropout_prob):
        super().__init__()
        self.d_model = d_model
        self.attention = attention
        self.feed_forward = feed_forward
        self.sub_layers = nn.ModuleList(
            [Sublayer(d_model, dropout_prob) for _ in range(2)]
        )
    def forward(self, x, mask):
        """
        Args:
            x: (batch_size, seq_len, d_model)
            mask: 
        Returns:
            out: (batch_size, seq_len, d_model)
        """
        x = self.sub_layers[0](x, lambda x: self.attention(x,x,x,mask))
        x = self.sub_layers[1](x, self.feed_forward)
        return x

class Sublayer(nn.Module):
    def __init__(self, d_model, dropout_prob=0.1):
        super().__init__()
        self.norm = LayerNorm(d_model)
        self.dropout = nn.Dropout(dropout_prob)
    def forward(self, x, main_logic):
        x_norm = self.norm(x)
        return x + self.dropout(main_logic(x_norm))

class LayerNorm(nn.Module):
    def __init__(self, d_model, eps=1e-6):
        super().__init__()
        self.gamma = nn.Parameter(torch.ones(d_model))
        self.beta = nn.Parameter(torch.zeros(d_model))
        self.eps = eps
    def forward(self, x):
        mean = x.mean(-1, keepdim=True)
        std = x.std(-1, keepdim=True)
        return self.gamma * (x - mean) / (std + self.eps) + self.beta

class Decoder(nn.Module):
    def __init__(self, layer, N):
        super().__init__()
        self.layers = nn.ModuleList([copy.deepcopy(layer) for _ in range(N)])
        self.norm = LayerNorm(layer.d_model)
    def forward(self, x, memory, src_mask, tgt_mask):
        # print(tgt_mask)
        for layer in self.layers:
            x = layer(x, memory, src_mask, tgt_mask)
        return self.norm(x)

class DecoderLayer(nn.Module):
    def __init__(self, d_model, self_attention, src_attention, feed_forward, dropout_prob):
        super().__init__()
        self.d_model = d_model
        self.self_attention = self_attention
        self.src_attention = src_attention
        self.feed_forward = feed_forward
        self.sub_layers = nn.ModuleList(
            [Sublayer(d_model, dropout_prob) for _ in range(3)]
        )
    def forward(self, x, memory, src_mask, tgt_mask):
        """
        Args:
            x: (batch_size, seq_len, d_model)
            memory: (batch_size, seq_len, d_model)
            src_mask: 
            tgt_mask:
        Returns:
            out: (batch_size, seq_len, d_model)
        """
        x = self.sub_layers[0](x, lambda x: self.self_attention(x,x,x,tgt_mask))
        x = self.sub_layers[1](x, lambda x: self.src_attention(x,memory,memory,src_mask))
        x = self.sub_layers[2](x, self.feed_forward)
        return x

def subsequent_mask(size):
    "Mask out subsequent positions"
    attention_shape = (1, size, size)
    subsequent_mask = torch.triu(torch.ones(attention_shape), diagonal=1).type(torch.uint8)
    # print(subsequent_mask)
    return subsequent_mask == 0

def scaled_dot_product_attention(query, key, value, mask=None, dropout=None):
    """
    Args:
        query: (batch_size, num_heads, seq_len_q, d_k), given sequence that we focus on
        key: (batch_size, num_heads, seq_len_k, d_k), the sequence to check relevance with query
        value: (batch_size, num_heads, seq_len_v, d_k), seq_len_k == seq_len_v, usually value and key come from the same source
        mask: for encoder, mask is [batch_size, 1, 1, seq_len_k], for decoder, mask is [batch_size, 1, seq_len_q, seq_len_k]
        dropout: nn.Dropout(), optional
    Returns:
        output: (batch_size, num_heads, seq_len_q, d_v), attn: (batch_size, num_heads, seq_len_q, seq_len_k)
    """
    d_k = query.size(-1)
    scores = torch.matmul(query, key.transpose(-2,-1)) / math.sqrt(d_k)
    if mask is not None:
        scores = scores.masked_fill(mask == 0, -1e9)
    scores = scores.softmax(dim=-1)
    
    if dropout is not None:
        scores = dropout(scores)
    
    return torch.matmul(scores, value), scores

class MultiHeadAttention(nn.Module):
    def __init__(self, h, d_model, dropout_prob=0.1):
        super().__init__()
        self.d_k = d_model // h
        self.h = h
        self.linears = nn.ModuleList(
            [nn.Linear(d_model, d_model) for _ in range(4)]
        )
        self.dropout = nn.Dropout(dropout_prob)
    def forward(self, query, key, value, mask=None):
        """
        Args:
            query: (batch_size, seq_len_q, d_model)
            key: (batch_size, seq_len_k, d_model)
            value: (batch_size, seq_len_v, d_model), seq_len_k == seq_len_v
            mask: 
        Returns:
            output: (batch_size, seq_len_q, d_model)
            attn: (batch_size, num_heads, seq_len_q, seq_len_k)
        """
        if mask is not None:
            mask = mask.unsqueeze(1)
        n_batches = query.size(0)

        # 1. linear projection for query, key, value
        #    after this step, the shape of each is (batch_size, h, seq_len, d_k)
        query, key, value = [linear(x).view(n_batches, -1, self.h, self.d_k).transpose(1, 2) for linear, x in zip(self.linears, (query, key, value))]

        # 2. scaled dot product attention
        #    out: (batch_size, h, seq_len_q, d_k)
        out, _  = scaled_dot_product_attention(query, key, value, mask, self.dropout)

        # 3. "Concat" using a view and apply a final linear
        out = (
            out.transpose(1, 2)
            .contiguous()
            .view(n_batches, -1, self.h * self.d_k)
        )
        out = self.linears[-1](out)

        return out

class PositionWiseFeedForward(nn.Module):
    def __init__(self, d_model, d_ff, dropout_prob=0.1):
        super().__init__()
        self.linear1 = nn.Linear(d_model, d_ff)
        self.linear2 = nn.Linear(d_ff, d_model)
        self.dropout = nn.Dropout(dropout_prob)
    def forward(self, x):
        return self.linear2(self.dropout(F.relu(self.linear1(x))))

class Embeddings(nn.Module):
    def __init__(self, d_model, vocab_size):
        super().__init__()
        self.lookup_table = nn.Embedding(vocab_size, d_model)
        self.d_model = d_model
    def forward(self, x):
        return self.lookup_table(x) * math.sqrt(self.d_model)

class PositionalEncoding(nn.Module):
    def __init__(self, d_model, dropout_prob, max_len=5000):
        super().__init__()
        self.dropout = nn.Dropout(dropout_prob)

        # Compute the positional encodings once in log space.
        positional_encodings = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len).unsqueeze(1) # size: (max_len, 1)

        # Equivalent to 1 / (10000 ^ (2i / d_model)) in the paper
        div_term = torch.exp(
            torch.arange(0, d_model, 2) * -(math.log(10000.0) / d_model)
        ) # size: (d_model / 2,)

        positional_encodings[:, 0::2] = torch.sin(position * div_term)
        positional_encodings[:, 1::2] = torch.cos(position * div_term)

        positional_encodings = positional_encodings.unsqueeze(0) # size: (1, max_len, d_model)
        self.register_buffer('positional_encodings', positional_encodings)

    def forward(self, x):
        x = x + self.positional_encodings[:, :x.size(1)]
        return self.dropout(x)

def make_model(src_vocab_size, tgt_vocab_size, N=6, d_model=512, d_ff=2048, h=8, dropout_prob=0.1, max_len=5000):
    """
    Helper: Construct a model from hyperparameters.
    """
    func_copy = copy.deepcopy
    attention = MultiHeadAttention(h, d_model, dropout_prob)
    feed_forward = PositionWiseFeedForward(d_model, d_ff, dropout_prob)
    positional_encoding = PositionalEncoding(d_model, dropout_prob, max_len)
    model = Transformer(
        encoder=Encoder(EncoderLayer(d_model, func_copy(attention), func_copy(feed_forward), dropout_prob), N),
        decoder=Decoder(DecoderLayer(d_model, func_copy(attention), func_copy(attention), func_copy(feed_forward), dropout_prob), N),
        src_embed=nn.Sequential(Embeddings(d_model, src_vocab_size), func_copy(positional_encoding)),
        tgt_embed=nn.Sequential(Embeddings(d_model, tgt_vocab_size), func_copy(positional_encoding)),
        generator=Generator(d_model, tgt_vocab_size)
    )

    # Initialize parameters with Glorot / fan_avg.
    for p in model.parameters():
        if p.dim() > 1:
            nn.init.xavier_uniform_(p)
    return model

def inference_test():
    vocab = ['<pad>', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10']
    vocab_size = len(vocab)

    test_model = make_model(vocab_size, vocab_size, N=2)
    test_model.eval()

    src = torch.LongTensor([[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]]) # (batch_size, seq_len)
    src_mask = torch.ones(1, 1, 10) # (batch_size, 1, seq_len)

    memory = test_model.do_encode(src, src_mask)
    ys = torch.zeros(1, 1).type_as(src)

    for i in range(10):
        # exit()
        out = test_model.do_decode(memory, src_mask, ys, subsequent_mask(ys.size(1)).type_as(src))
        prob = test_model.generator(out[:, -1])
        _, next_word = torch.max(prob, dim=1)
        next_word = next_word.data[0]
        ys = torch.cat([ys, torch.empty(1, 1).type_as(src).fill_(next_word)], dim=1)

    print("Example Untrained Model Prediction: ", ys)


def run_tests():
    for _ in range(10):
        inference_test()


if __name__ == "__main__":
    # exit()
    run_tests()
    # https://zhuanlan.zhihu.com/p/668781029