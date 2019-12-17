# Attentions
新手使用的时候有时候可能会出现开启omp之后，得到的计算结果是错的，而且多次执行结果还不相同。
1.   其中一个可能的原因是你的代码中不同的线程同时使用某一内存的值并且试图改变它，比如累加操作，这种情况下线程x获取的数据可能不是最新的。 
```
#pragma omp parallel for reduction(+:sum)
```
它的意思是告诉编译器：下面的for循环你要分成多个线程跑，但每个线程都要保存变量sum的拷贝，循环结束后，所有线程把自己的sum累加起来作为最后的输出。reduction虽然很方便，但它只支持一些基本操作，比如+,-,*,&,|,&&,||等。


```c++
#define ELAPSED(START,END)  (((END.tv_sec  - START.tv_sec) * 1000000u + END.tv_usec - START.tv_usec) / 1.e6)
struct timeval start, end;
gettimeofday(&start, NULL);
gettimeofday(&end, NULL);
cout<<ELAPSED(start,end)<<" (s)"<<endl;
```