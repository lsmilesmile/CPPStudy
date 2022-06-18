#include <cstdio>
#include <cstdlib>
#include <cstring>


int main() {
    
    FILE* pf = fopen("data.txt", "r");
   // 定位文件指针
   fseek(pf, 3, SEEK_CUR); // 从文件指针当前位置向后偏移3个位置
   char ch = fgetc(pf);
   printf("%c\n", ch);

    fclose(pf);
    return 0;
}