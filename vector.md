# vector

> Felix
>
> 2022.6.22



## 简介

vector实质是C++的一个类，与数组很相似，但是vector的优势是可以动态扩展，不需要考虑其内存大小。

**定义：**

向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。

**特性：**

1. 顺序序列

   顺序容器中的元素按照严格的线性顺序排序。可以通过元素在序列中的位置访问对应的元素。

2. 动态数组

   支持对序列中的任意元素进行快速直接访问，甚至可以通过指针算述进行该操作。操供了在序列末尾相对快速地添加/删除元素的操作。

3. 能够感知内存分配器的（Allocator-aware）

   容器使用一个内存分配器对象来动态地处理它的存储需求。



## vector构造函数原型

- vector\<T\> data; //使用模板类，默认构造函数
- vector(data.begin(),data.end()); //将data的【begin(),end())区间中的元素拷贝给本身，注意是数学中的前闭后开 区间
- vector(n,elem); //将n个elem元素拷贝给本身
- vector(const vector &data); //拷贝构造

```c++
#include <iostream>
#include <vector>

void PrintVector(std::vector<int>& data) {
    for (auto itData = data.begin(); itData != data.end(); itData++) {
        std::cout << *itData << ", " << std::endl;
    }
}

int main() {
    std::vector<int> data1; // 默认构造
    data1.push_back(1);
    data1.push_back(2);
    data1.push_back(3);
    PrintVector(data1);

    std::vector<int> data2(data1.begin(), data1.end()); // 区间构造
    PrintVector(data2);

    std::vector<int> data3(4, 1); // 4个1构造
    PrintVector(data3);

    std::vector<int> data4(data3); // 拷贝构造
    PrintVector(data4);
    return 0;
}
```



## vector的容量和大小函数原型

- empty(); //判断容器是否为空
- capacity(); //容器的容量  capacity一定会大于等于size
- size(); //返回容器中元素的个数
- resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新的位置；若容器变短，则末尾超出的元素被删除
- resize(int num，elem); //重新指定容器的长度为num，若容器变长，则以elem数值填充新的位置；若容器变短，则末尾超出的元素被删除

```c++
#include <iostream>
#include <vector>
 
using namespace std;
 
void fun_print_vector(std::vector<int>&data)
{
    //std::vector<int>::iterator it; //可以用auto代替。
    for(auto it_data = data.begin();it_data != data.end();it_data++){
        std::cout << *it_data << " " << std::endl;
    }
}
void fun_vector()
{
    vector<int> data1;
    for(int i = 0;i < 6;i++){
        data1.push_back(i);
    }
    fun_print_vector(data1); //打印 0 1 2 3 4 5
 
    if(data1.empty() == true){
        std::cout << "该容器是空" << std::endl;
    }else{
        std::cout << "该容器不是空" << std::endl;
        std::cout << "data1.capacity:" << data1.capacity() << std::endl;
        std::cout << "data1.size:" << data1.size() << std::endl;
    }
    data1.resize(10); //填充默认值0
    fun_print_vector(data1); //打印 0 1 2 3 4 5 0 0 0 0
    data1.resize(13,8); //填充数值8
    fun_print_vector(data1); //打印 0 1 2 3 4 5 0 0 0 0 8 8 8
    data1.resize(4);
    fun_print_vector(data1); //打印 0 1 2 3
}
```



## vector的赋值函数原型

- vector& operator=(cost vector &data); //重载操作符
- vector& assign(beg,end); //将[ beg,ed )区间中的数据拷贝赋值给本身
- vector& assign(n,elem); //将n个elem拷贝赋值给本身

```c++
#include <iostream>
#include <vector>
 
using namespace std;
 
void fun_print_vector(std::vector<int>&data)
{
    //std::vector<int>::iterator it; //可以用auto代替。
    for(auto it_data = data.begin();it_data != data.end();it_data++){
        std::cout << *it_data << " " << std::endl;
    }
}
void fun_vector()
{
    vector<int> data1;
    for(int i = 0;i < 6;i++){
        data1.push_back(i);
    }
    fun_print_vector(data1); //打印 0 1 2 3 4 5
 
    vector<int> data2;
    data2 = data1;
    fun_print_vector(data2); //打印 0 1 2 3 4 5
 
    vector<int> data3;
    data3.assign(data1.begin(),data1.end());
    fun_print_vector(data3); //打印 0 1 2 3 4 5
 
    vector<int> data4;
    data3.assign(3,6);
    fun_print_vector(data4); //打印 6 6 6
}
```



## vector的插入和删除函数原型

- push_back(elem); //尾部插入元素elem
- pop_back(); //删除最后一个元素
- insert(const_iterator pos, elem); //迭代器指向位置pos插入元素elem
- insert(const_iterator pos, int count,elem); //迭代器指向位置pos插入count个元素elem
- erase(const_iterator pos); //删除迭代器指向的元素
- erase(const_iterator start,const_iterator end); //删除迭代器start到end之间的元素
- clear(); //删除容器中所有元素

```c++
#include <iostream>
#include <vector>
 
using namespace std;
 
void fun_print_vector(std::vector<int>&data)
{
    //std::vector<int>::iterator it; //可以用auto代替。
    for(auto it_data = data.begin();it_data != data.end();it_data++){
        std::cout << *it_data << " " << std::endl;
    }
}
void fun_vector()
{
    vector<int> data1;
    for(int i = 0;i < 6;i++){
        data1.push_back(i);
    }
    fun_print_vector(data1); //打印 0 1 2 3 4 5
    data1.pop_back(); //尾删
    fun_print_vector(data1); //打印 0 1 2 3 4
    data1.insert(data1.begin(),22); //迭代器位置插入一个22
    fun_print_vector(data1); //打印 22 0 1 2 3 4
    data1.insert(data1.begin(),3,7); //迭代器位置插入三个22
    fun_print_vector(data1); //打印 7 7 7 22 0 1 2 3 4
 
    data1.erase(data1.begin()); //迭代器位置删除
    fun_print_vector(data1); //打印 7 7 22 0 1 2 3 4
    data1.erase(data1.begin(),data1.end()); //迭代器位置 区间 删除
    fun_print_vector(data1); //打印 空
 
    data1.clear(); //清空容器
    fun_print_vector(data1); //打印 空
 
}
```



## vector的存取操作

- at(int idx); //返回索引idx所指的数据
- operator []; //返回索引idx所指的数据
- front(); //返回容器的第一个数据元素
- back(); //返回容器的最后一个数据元素

```c++
#include <iostream>
#include <vector>
 
using namespace std;
 
void fun_print_vector(std::vector<int>&data)
{
    //std::vector<int>::iterator it; //可以用auto代替。
    for(auto it_data = data.begin();it_data != data.end();it_data++){
        std::cout << *it_data << " " << std::endl;
    }
}
void fun_vector()
{
    vector<int> data1;
    for(int i = 0;i < 6;i++){
        data1.push_back(i);
    }
 
    //利用[]方式访问vector中的元素
    for(int j = 0;j<data1.size();j++){
        std::cout << data1[j] << " " << std::endl;
    }
    //利用at方式访问vector中的元素
    for(int j = 0;j<data1.size();j++){
        std::cout << data1.at(j) << " " << std::endl;
    }
 
    std::cout << "第一个元素是：" << data1.front() << std::endl;
    std::cout << "最后一个元素是：" << data1.back() << std::endl;
 
}
```



## vector互换容器

- swap(vec); //将vecy与本身 两个容器中的元素互换

```c++
#include <iostream>
#include <vector>
 
using namespace std;
 
void fun_print_vector(std::vector<int>&data)
{
    //std::vector<int>::iterator it; //可以用auto代替。
    for(auto it_data = data.begin();it_data != data.end();it_data++){
        std::cout << *it_data << " " << std::endl;
    }
}
void fun_vector()
{
    vector<int> data1;
    for(int i = 0;i < 6;i++){
        data1.push_back(i);
    }
    fun_print_vector(data1); //打印 0 1 2 3 4 5
 
    vector<int> data2;
    for(int i = 6;i > 0;i++){
        data2.push_back(i);
    }
    fun_print_vector(data2); //打印 6 5 4 3 2 1 
 
    data1.swap(data2);
    fun_print_vector(data1); //打印 6 5 4 3 2 1 
    fun_print_vector(data2); //打印 0 1 2 3 4 5 
 
}
```

