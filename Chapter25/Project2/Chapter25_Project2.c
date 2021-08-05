#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *native, *C_locale;

    // get C locale info
    native = setlocale(LC_ALL, NULL);

    if (native == NULL)
    {
        printf("C locale information not available\n");
        exit(EXIT_FAILURE);
    }

    C_locale = malloc(strlen(native) + 1);
    if (C_locale == NULL)
    {
        printf("malloc() failed!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(C_locale, native);

    // get native locale info
    native = setlocale(LC_ALL, "");
    if (native == NULL)
    {
        printf("Native locale information not available\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(native, C_locale) == 0)
        printf("Native locale is the same as the C locale.\n");
    else
        printf("Native locale is NOT the same as the C locale.\n");

    return 0;
}