# string中的npos

> Felix
>
> 2022.4.22



## npos定义

string::npos是一个静态成员常量，表示size_t的最大值。该值表示知道字符串结尾，作为返回值它通常被用作表明没有匹配。

定义：

```c++
static const size_type npos = -1;
```

因为string::size_type描述的是size，故应为无符号整数类型。因为缺省配置为size_t作为size_type，于是-1被转换为无符号整数类型，npos也就成了该类别的最大无符号值。不过实际值还是取决于size_type的实际定义类型，即无符号整数的-1与无符号长整型的-1是不同的。

验证-1表示size_t的最大值：

```c++
#include <iostream>
#include <limits>
#include <string>
using namespace std;
 
int main()
{
    size_t npos = -1;
    cout << "npos: " << npos << endl;
    cout << "size_t max: " << numeric_limits<size_t>::max() << endl;
}
```

**npos: 18446744073709551615
size_t max: 18446744073709551615**



## 使用npos

一般配合string::find()来使用。

string::find()函数是一个字符或字符串查找函数，该函数有唯一的返回类型，即string::size_type，即一个无符号整型类型，可能是整数，也可能是长整数。如果查找成功，返货找到的第一个字符或字串的位置；如果查找失败，返回string::npos，即-1（当然答应出来不是-1，而是一个很大的数值）

```c++
#include <iostream>
#include <limits>
#include <string>
 
std::string s("1a2b3c4d5e6f7g8h9i1a2b3c4d5e6f7g8ha9i");
void result(const char* p)
{
    std::string::size_type position = s.find(p);
 
    if ( position != std::string::npos )
    {
        std::cout << "Position is : " << position << std::endl;
    }
    else{
        std::cout << "Not found." << std::endl;
    }
}
 
int main()
{
    result("jk");
    result("b3");
 
    return 0;
}
```

