//
// clang -cc1 -ast-dump hello.c
//

#include "stdio.h"

int main()
{
    int a = 3;
    a += 4;
    printf("a: %d\n", a);
}
