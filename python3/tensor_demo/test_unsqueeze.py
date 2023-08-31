import torch

x = torch.tensor([1, 2, 3])
print(x.dim())
print(x.unsqueeze(0))
print(x.unsqueeze(1))
print(x.unsqueeze(-1))
