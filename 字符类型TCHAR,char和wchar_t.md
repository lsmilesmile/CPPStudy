# C++字符类型TCHAR、char和wchar_t

> Felix
>
> 2022.4.26



1. 首先，char是8位字符类型，最多只能包含256中字符，许多外文字符集数目超多256个，char型无法表示。

2. wchar_t是C/C++得字符数据类型，是一种扩展的字符存储方式，wchar_t类型主要用在国际化程序的实现中，但它不等同于unicode编码。unicode编码的字符一般以wchar_t类型存储。

3. wchar_t数据类型一般为16位或36位，但不同的C/C++库有不同的规定。总之，wchar_t所能表示的字符数远超char型。标准C++中的wprinf()函数以及iostream类库中的类和对象能提供wchar_t宽字符类型的相关操作。

4. 可以用TEXT()方法将char转换为wchar_t

   ```c++
   wchar_t s[5] = TEXT("test");
   ```

   

5. TCHAR

   因为C++支持两种字符串，即常规的ANSI编码（使用""包裹）和Unicode编码（使用L""包裹），这样对应的就有了两套字符串处理函数，如：strlen和wcslen，分别用于处理两种字符串。

   微软将这两套字符集及其操作进行了统一，通过条件编译（通过_UNICODE和UNICODE宏）控制实际使用的字符集，这样就有了\_T("")这样的字符串，对用的就有了\_tcslen这样的函数。为了存储这样的通用字符，就有了TCHAR：

   **当没有定义_UNICODE宏时，TCHAR = char，_tcslen =strlen**
   **当定义了_UNICODE宏时，TCHAR = wchar_t ， _tcslen = wcslen[1]**

   ```c++
   #ifdef UNICODE
       typedef wchar_t TCHAR;
   #else
       typedef char TCHAR;
   #endif
   ```

   当我们定义了UNICODE宏，就相当于告诉了编译器：我准备采用UNICODE版本。这个时候，TCHAR就会摇身一变，变成了wchar_t。而未定义UNICODE宏时，TCHAR摇身一变，变成了unsignedchar。这样就可以很好的切换宽窄字符集。
   tchar可用于双字节字符串，使程序可以用于中日韩等国 语言文字处理、显示。使编程方法简化。

6. _T("")是一个宏，定义于tchar.h下

   ```c++
   #define __T(x) L ## x
   #define _T(x) __T(x)
   ```

   他的作用是让你的程序支持Unicode编码，因为Windows使用两种字符集ANSI和UNICODE，前者就是通常使用的单字节方式，但这种方式处理像中文这样的双字节字符不方便，容易出现半个汉字的情况。而后者是双字节方式，方便处理双字节字符。Windows NT的所有与字符有关的函数都提供两种方式的版本，而Windows 9x只支持ANSI方式。如果你编译一个程序为ANSI方式，_T实际不起任何作用。而如果编译一个程序为UNICODE方式，则编译器会把"Hello"字符串以UNICODE方式保存。_T和_L的区别在于，_L不管你是以什么方式编译，一律以UNICODE方式保存。
   LPSTR：32bit指针指向一个字符串，每个字符占1字节
   LPCSTR:32-bit指针指向一个常字符串，每个字符占1字节
   LPCTSTR:32-bit指针指向一个常字符串,每字符可能占1字节或2字节，取决于Unicode是否定义
   LPTSTR:32-bit指针每字符可能占1字节或2字节，取决于Unicode是否定义
   L是表示字符串资源为Unicode的。
   比如
   wchar_tStr[] = L"Hello World!";
   这个就是双字节存储字符了。
   _T是一个适配的宏～
   当
   #ifdef _UNICODE的时候
   _T就是L
   没有#ifdef _UNICODE的时候
   _T就是ANSI的。

   ```c++
   #ifdef UNICODE
       typedef wchar_t TCHAR;
   #else
       typedef char TCHAR;
   #endif
   ```

   