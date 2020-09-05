## Basic Operation
### create  
```python
import torch
# create empty without initialize
x=torch.empty(5)  # 1 dimension
x=torch.rand(5,5) # 2 dimension
x=torch.ones(3,3,3) # 3 dimension
x=torch.ones(5,dtype=torch.double) # initialize and specify their types
x=torch.tensor([2.5,0.1]) # create tensor
x=torch.tensor([[1,2,3],[4,5,6]],dtype=torch.float32,device="cuda") # specify the type and device
```

### operation  
```python
x=torch.rand(3,3)
y=torch.rand(3,3)
z=x+y	  			# z=x+y
z=torch.add(x,y)	# z=x+y
y.add_(x) 			# y=x+y

z=torch.sub(x,y)
z=torch.mul(x,y)
z=torch.div(x,y)

# get first column data
print(z[:,0])

# get the value of specified location in tensor
print(z[1,1].item())

# reshape
x=torch.ones(4,4)
y=x.view(16)

# watch the size of a tensor
print(y.size())
print(y.shape)

```

### numpy <-> tensor    
```
/* tensor -> numpy */
import torch 
import numpy as np
a= torch.ones(5)
b=a.numpy() // if a and b are on cpu, they share the same memory

/* numpy -> tensor */
a=np.ones(5)
b=torch.from_numpy(a)
```
### load cuda  
```python
import pytorch 
import numpy as np
if torch.cuda.is_available():
	device=torch.device("cuda")
	# Way 01: put variable on GPU
	x=torch.ones(5,device=device)

	# Way 02: move variable to gpu device 
	y=torch.ones(5).to(device)

	
	z=x+y # then this operation will be performed on gpu
	# here we cannot call z.numpy(), because z is on gpu, and numpy cannot call variable on gpu, so we should
	z=z.to("cpu")
	
```
 
