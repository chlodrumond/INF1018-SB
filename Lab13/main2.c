#include <stdio.h>
#include <stdint.h>
#include <limits.h>

typedef int (*funcp)(int x);

int add(int x)
{
    return x + 1;
}

int main()
{
    unsigned char codigo[] = 
  {
        0x55,
        0x48, 0x89, 0xe5,
        0xe8, 0x00, 0x00, 0x00, 0x00,
        0xc9,
        0xc3
    };

    int64_t deslocamento =
        (int64_t)(intptr_t)add -
        (int64_t)(intptr_t)(codigo + 9);

    if (deslocamento < INT32_MIN ||
        deslocamento > INT32_MAX) 
    {
        printf("Deslocamento fora do alcance.\n");
        return 1;
    }

    uint32_t d = (uint32_t)deslocamento;

    codigo[5] = d & 0xff;
    codigo[6] = (d >> 8) & 0xff;
    codigo[7] = (d >> 16) & 0xff;
    codigo[8] = (d >> 24) & 0xff;

    funcp f = (funcp)codigo;

    int i = (*f)(10);

    printf("O valor de i e %d\n", i);

    return 0;
}
  
