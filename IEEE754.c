#include <stdio.h>
#include <stdint.h>

typedef union {
    float f;
    struct {
        uint32_t mantisa : 23;
        uint32_t exponente : 8;
        uint32_t signo : 1;
    } partes;
    uint32_t u;
} IEEE754;

int main() {
    float decimal;
    IEEE754 ieee;

    printf("Ingresa un numero decimal: ");
    scanf("%f", &decimal);

    ieee.f = decimal;

    printf("1) El valor decimal que puso el usuario: %f\n", decimal);
    printf("2) Cuanto vale el exponente: %d\n", (int)ieee.partes.exponente - 127);

    // Imprimir el número decimal en binario
    printf("3) El numero decimal en binario: 0b");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (ieee.u >> i) & 1);
        if (i == 31 || i == 23) printf(" ");
    }
    printf("\n");

    // Imprimir la mantisa en binario
    printf("4) Cuanto vale la mantisa en binario: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (ieee.partes.mantisa >> i) & 1);
    }
    printf("\n");

    // Determinar si el número es positivo o negativo
    if (ieee.partes.signo == 0) {
        printf("5) El primer bit indica que el número es positivo.\n");
    } else {
        printf("5) El primer bit indica que el número es negativo.\n");
    }

    // Imprimir el valor del primer bit
    printf("    Primer bit: %d\n", ieee.partes.signo);

    printf("6) Por ultimo, en hexadecimal: 0x%X\n", ieee.u);

    return 0;
}
