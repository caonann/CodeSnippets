from typing import List, Optional

import numpy as np
import torch
from memory_profiler import profile


# 创建一个Tensor
@profile
def test_tensor():
    with torch.no_grad():
        output = []
        for i in range(1000):
            t1 = torch.Tensor(2, 3, 4)
            output.append(t1)
    # list to tensor
    return torch.stack(output, dim=0)


@profile
def test_tensor_cat():
    with torch.no_grad():
        output = [None] * 1000
        for idx, _ in enumerate(range(1000)):
            output[idx] = torch.Tensor(2, 3, 4)

    a = torch.cat([x.unsqueeze(0) for x in output], dim=0)
    print(a.shape)
    return a


def deal(a: Optional[List[torch.Tensor]]):
    output = []
    if a is None or len(a) == 0:
        a = [torch.Tensor(2, 3, 4)]
    else:
        a.append(torch.Tensor(2, 3, 4))
    return a


@profile
def test_tensor_func():
    output = [None]
    b = [torch.tensor([1, 2, 3])] * 100000
    output = b
    for i in range(1000):
        output = deal(output)


def tensor_data():
    data = [[1, 2],[3, 4],[5,5]]
    x_data = torch.tensor(data)
    np_array = np.array(data)
    x_np = torch.from_numpy(np_array)
    x_ones = torch.ones_like(x_data) # retains the properties of x_data
    print(f"Ones Tensor: \n {x_ones} \n")
    zeros = torch.zeros_like(x_data)
    print(f"Zeros Tensor: \n {zeros} \n")
    x_rand = torch.rand_like(x_data, dtype=torch.float) # overrides the datatype of x_data
    print(f"Random Tensor: \n {x_rand} \n")
    
if __name__ == "__main__":
    # a = test_tensor()
    # b = test_tensor_cat()
    # 判断a和b是否相等
    # print(torch.equal(a, b))
    # 判断a和b形状是否相等
    # print(a.shape == b.shape)

    # test_tensor_func()
    
    tensor_data()