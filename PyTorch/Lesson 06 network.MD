# Network  
### convolution network
```
[in]:  nSamples x nChannels x Height x Width
[out]: nSamples x nChannels x Height x Width 
```  
卷积神将网络的计算公式为：
N=(W-F+2P)/S+1
其中N：输出大小
W：输入大小
F：卷积核大小
P：填充值的大小
S：步长大小


```python
# 函数原型
torch.nn.Conv2d(in_channels, out_channels, kernel_size, stride=1, padding=0, dilation=1, groups=1, bias=True)
```
卷积一层的几个参数:
in_channels=3:表示的是输入的通道数，由于是RGB型的，所以通道数是3.
out_channels=96:表示的是输出的通道数，设定输出通道数的96（这个是可以根据自己的需要来设置的）
kernel_size=12:表示卷积核的大小是12x12的，也就是上面的 “F”, F=12
stride=4:表示的是步长为4，也就是上面的S, S=4
padding=2:表示的是填充值的大小为2，也就是上面的P, P=2
假如你的图像的输入size是256x256的,由计算公式知N=(256-12+2x2)/4+1=63,也就是输出size为63x63的

### pooling  
```python
nn.MaxPool2d(kernel_size=2, stride=(2, 1), padding=(0, 1))
```


