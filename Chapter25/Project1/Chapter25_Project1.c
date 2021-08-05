#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{

    // get user choice
    printf("Enter locale to check (en_GB), (fr_CH)\n>> ");
    char user_locale[6];
    scanf("%s", user_locale);

    // TODO check if locale is correct

    // print info
    setlocale(LC_ALL, user_locale);
    struct lconv *info;
    info = localeconv();

    printf("Decimal point: [%s]\n", info->decimal_point);
    printf("thousands sep: [%s]\n", info->thousands_sep);
    printf("Grouping: [%d]\n", (int)info->grouping[0]);

    printf("Mon decimal point: [%s]\n", info->mon_decimal_point);
    printf("Mon thousands sep: [%s]\n", info->mon_thousands_sep);
    printf("Mon grouping: [%d]\n", (int)info->mon_grouping[0]);

    printf("Positive sign: [%s]\n", info->positive_sign);
    printf("Negative sign: [%s]\n", info->negative_sign);

    printf("Currency symbol: [%s]\n", info->currency_symbol);
    printf("Frac digits: [%d]\n", info->frac_digits);

    printf("p cs precedes: [%d]\n", info->p_cs_precedes);
    printf("n cs precedes: [%d]\n", info->n_cs_precedes);
    printf("p sep by space: [%d]\n", info->p_sep_by_space);
    printf("n sep by space: [%d]\n", info->n_sep_by_space);

    printf("p sign posn: [%d]\n", info->p_sign_posn);
    printf("n sign posn: [%d]\n", info->n_sign_posn);

    printf("int curr symbol: [%s]\n", info->int_curr_symbol);
    printf("int frac digits: [%d]\n", info->int_frac_digits);

    printf("int p sign posn: [%d]\n", info->p_sign_posn);
    printf("int n sign posn: [%d]\n", info->n_sign_posn);
}