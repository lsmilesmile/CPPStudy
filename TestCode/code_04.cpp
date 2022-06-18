#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    FILE* pf = fopen("data.txt", "r");
    if (pf == NULL) {
        printf("%s\n", strerror(errno));
        return -1;
    }

    int ch = fgetc(pf);
    printf("%c\n", ch);

    int ret = ftell(pf);
    printf("%d\n", ret);

    rewind(pf);
    ret = ftell(pf);
    printf("%d\n", ret);

    fclose(pf);
    pf = NULL;
    return 0;
}