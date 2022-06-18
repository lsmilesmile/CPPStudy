/// C文件读写


#include <cstdio>
#include <cerrno>
#include <cstring>

int main() {
   FILE* pf;
   pf = fopen("data.txt", "w");
   fprintf(pf, "age is %d", 12);
   

   fclose(pf);
   pf = NULL;
    return 0;
}