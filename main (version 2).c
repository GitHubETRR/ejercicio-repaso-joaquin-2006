#include <stdio.h>

int main() {
    float mivar = -15;
    unsigned char *p = (unsigned char *)&mivar;
    
    printf("0x%x\n", *p);
    printf("0x%x\n", *(p + 1));
    printf("0x%x\n", *(p + 2));
    printf("0x%x\n", *(p + 3));
    
    p++;
    printf("0x%x\n", *p);
    p++;
    printf("0x%x\n", *p);
    p++;
    printf("0x%x\n", *p);
    
    return 0;
}
