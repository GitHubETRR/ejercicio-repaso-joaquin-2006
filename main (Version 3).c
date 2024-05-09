#include <stdio.h>

int main() {
    float mivar = -15;
    unsigned char *p = (unsigned char *)&mivar;
    
    for (int i = 0; i < sizeof(float); ++i) {
        printf("0x%x\n", *(p + i));
    }
    
    return 0;
}
