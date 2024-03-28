import numpy as np

def softmax(logits):
    max_logits = np.max(logits)
    exp_logits = np.exp(logits - max_logits)
    return exp_logits / np.sum(exp_logits)

print(softmax([1,2,3,4,5,6]))