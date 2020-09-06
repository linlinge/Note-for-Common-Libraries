## Basic Operation
reference [website](https://www.youtube.com/watch?v=x9JiIFvlUwk&list=PLhhyoLH6IjfxeoooqP9rhU3HJIAVAJ3Vz&index=2)
### create (basic)  
```python
import torch
# create empty without initialize
x=torch.empty(size=(3,3)) # 3x3 matrix
x=torch.empty((3,3))  	  # 3x3 matrix
x=torch.rand(5,5) 		  # 2 dimension
x=torch.randn(3,4)		  # 3x4 normal distributed matrix
x=torch.ones(3,3,3) 	  # 3 dimension
x=torch.ones(5,dtype=torch.double) 	# initialize and specify their types
x=torch.tensor([2.5,0.1])  			# create tensor
x=torch.tensor([[1,2,3],[4,5,6]],dtype=torch.float32,device="cuda") # specify the type and device
```

### create (advance) 
```python
x=torch.empty((3,3)) # 3x3 matrix
x=torch.zeros((3,3)) # 3x3 zero matrix
x=torch.rand((3,3))	 # 3x3 random matrix
x=torch.ones((3,3))  # 3x3 ones matrix
x=torch.eye(5,5)	 # 5x5 eye matrix
x=torch.arange(start=0,end=5,step=1) 			# arithmetic sequence
x=torch.linspace(start=0,end=1, steps=10) 		# arithmetic sequence
x=torch.empty(size=(1,5)).normal_(mean=0,std=1)	# generate data of normal distribution
x=torch.empty(size=(1,5)).uniform_(0,1)			# generate data of uniform distribution within (0,1)
x=torch.arange(4) 	# default with start=0,step=1, and end=4 (user specified)
```

### convert to other types
```python
# basic types
tensor=torch.arange(4)
print(tensor.bool())	# convert to bool  
print(tensor.short())	# convert to int16
print(tensor.long())	# convert to int64
print(tensor.half())	# convert to float16
print(tensor.float())	# convert to float32
print(tensor.double())	# convert to float64

# convert with numpy
import numpy as np
np_array=np.zeros((5,5))
tensor=torch.from_numpy(np_array)	# convert numpy to tensor
np_to_tensor=tensor.numpy()			# convert tensor to numpy
```

### specify device  
```python
device="cuda" if torch.cuda.is_available() else "cpu"
```

### operation  
```python
x=torch.tensor([1,2,3])
y=torch.tensor([2,6,9])

# addition
z=x+y	  			# z=x+y
z=torch.add(x,y)	# z=x+y
y.add_(x) 			# y=x+y

# subtraction
z=torch.sub(x,y)

# multiply
z=torch.mul(x,y) 
z=x*y			 # element wise multiply
z=torch.dot(x,y) # dot multiply
x1=torch.rand((2,5))
x2=torch.rand((5,3)) 
x3=torch.mm(x1,x2)	# way 1
x3=x1.mm(x2)		# way 2

# batch matrix multiplication
batch=32
n=10
m=20
p=30
tensor1=torch.rand((batch,n,m))
tensor2=torch.rand((batch,m,p))
out_bmm=torch.bmm(tensor1,tensor2) # (batch,n,p)


# division
z=torch.div(x,y)
z=torch.true_divide(x,y) # out: [1/2,2/6,3/9]

# Exponentiation
print(x.pow(3)) # dot exponentiation
print(x**3)		
print(x.matrix_power(3)) # x*x*x


# Simple comparison
z=x>0

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

# example of broadcasting
x1=torch.ones((5,5))
x2=torch.ones((1,5))
z=x1-x2 # x2 will subtract all rows of x1
z=x1**x2
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
 
