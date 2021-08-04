#include <stdio.h>
#include <stddef.h>

int main()
{
    struct s
    {
        char a;
        int b[2];
        float c;
    } s;

    struct s test;

    printf("Size of entire structure: %d\n", sizeof(test));

    printf("Size of a: %d\t", sizeof(test.a));
    printf("Offset of a: %d\n", offsetof(struct s, a));

    printf("Size of b: %d\t", sizeof(test.b));
    printf("Offset of b: %d\n", offsetof(struct s, b));

    printf("Size of c: %d\t", sizeof(test.c));
    printf("Offset of c: %d\n", offsetof(struct s, c));

    int sum_offset = offsetof(struct s, a) + offsetof(struct s, b) + offsetof(struct s, c);

    int sum_sizeof = sizeof(test.a) + sizeof(test.b) + sizeof(test.c);

    printf("Size of individual members: %d\n", sum_sizeof);
    printf("Sum of offsets: %d\n", sum_offset);
    printf("Size difference produced by \"holes\": %d\n", sum_offset - sum_sizeof);
}