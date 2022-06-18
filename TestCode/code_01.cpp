/// C文件读写


#include <cstdio>
#include <cerrno>
#include <cstring>

int main() {
   char str1[10], str2[10], str3[10];
   int year;
   FILE* pf;

   pf = fopen("data.txt", "w+");
   fputs("we are in 2015", pf);

   rewind(pf); // 让pf回到文件起始位置
   fscanf(pf, "%s %s %s %d", str1, str2, str3, &year);

   printf("%s\n", str1);
   printf("%s\n", str2);
   printf("%s\n", str3);
   printf("%d\n", year);

   fclose(pf);

   


    return 0;
}