import numpy as np
import torch
import torch.nn as nn

nn.Softmax()

def softmax(logits):
    max_logits = np.max(logits)
    exp_logits = np.exp(logits - max_logits)
    return exp_logits / np.sum(exp_logits)

print(softmax([1,2,3,4,5,6]))


class Our_CrossEntropy(torch.nn.Module):

    def __init__(self):
        super(Our_CrossEntropy,self).__init__()
    
    def forward(self, x ,y):
        P_i = torch.nn.functional.softmax(x, dim=1)
        y = torch.nn.functional.one_hot(y)
        loss = y*torch.log(P_i + 0.0000001)
        loss = -torch.mean(torch.sum(loss, dim=1),dim = 0)
        return loss
