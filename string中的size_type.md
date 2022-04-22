# string中的size_type

> Felix
>
> 2022.4.22



平时的编码过程中，最好不要将size_type和int混用。如：

```c++
string str("zhoajdsofjalsdfnnfdslnfdsklfn");
for(int i=0;i<str.size();++i)
{
    ............
}
```

为什么这样不好呢？

在C++Primer有这样的描述，string类及其他大多数标准库类型都定义了几种配套的类型。这些配套类型体现了标准库类型与极其无关的特性，size_type就是其中一种。

string::size_type它是一个无符号类型的值，而且能够存放下任何string对象的大小。另外，string类型的索引也是一个size_type类型的。下标运算符 [ ] 接收的就是string::size_type类型。

当我们的程序需要在不同机器或者运行环境中使用的时候，定义为int就不太好，因为对应机器中的int可能较小，出现溢出。另外，如果我们的string特别长，远超int所能表示的范围，那么也是存在问题的。而size_type是一个设计为可以存放任何大小string对象的类型。

还有，应该尽可能避免无符号类型和int型数的比较。如果n是一个具有负值的int型，那么表达式 str.size()<n 的判断将坑定是 true。因为负数n，会自动转换为一个特别大的无符号类型的值。



正确做法：

```c++
for(decltype(str.size()) i=0;i<str.size();++i)
{
    ............
}
```

```c++
auto i=str.size();
```

