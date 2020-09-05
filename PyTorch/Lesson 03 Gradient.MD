### gradient  
```python
import torch
# the requires_grad tells the compiller that the following code will calculate gradient, 
# so it can give a better optimization for this code 
x=torch.randn(3,requires_grad=True) 
print(x)
>> tensor([-1.9880,0.5238,1.3865],requires_grad=True)

y=x+2
print(y)
>> tensor([0.0120,2.5238,3.3865],grad_fn=<AddBackward0>)

z=y*y*2
v=torch.tensor([0.1,1.0,0.001],dtype=torch.float32)

z.backward(v)
print(x.grad)
```

### three ways to stop backpropagation
```python
# way 1
x.require_grad_(False)

# way 2
x.detach()

# way 3
with torch.no_grad():
```

###  Examples
y_hat=w*x-y
loss=(y_hat-y)^2
```
import torch
x=torch.tensor(1.0)
y=torch.tensor(2.0)
w=torch.tensor(1.0,requires_grad=True)

# forward
y_hat=w*x
loss=(y_hat-y)**2

# backward pass
loss.backward()
print(w.grad)
```