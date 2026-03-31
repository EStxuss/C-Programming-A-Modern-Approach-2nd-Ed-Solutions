// Determines whether any differences between C locale and native locale

#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Please provide a locale name e.g. en_IE.utf8\n");
        exit(EXIT_FAILURE);
    }

    const char *localeStr;
    if ((localeStr = setlocale(LC_ALL, argv[1])) == NULL) {
        printf("Locale not found.\n");
        exit(EXIT_FAILURE);
    }

    struct lconv *localeDetails = localeconv();

    printf("%s details:\n", localeStr);
    printf("grouping: ");
    for (const char *p = localeDetails->grouping; *p; ++p)
        printf("%d ", *p);

    printf("\nmon_grouping: ");
    for (const char *p = localeDetails->mon_grouping; *p; ++p)
        printf("%d ", *p);

    printf("\n%s: %s\n", "decimal_point", localeDetails->decimal_point);
    printf("%s: %s\n", "thousands_sep", localeDetails->thousands_sep);
    printf("%s: %s\n", "mon_decimal_point", localeDetails->mon_decimal_point);
    printf("%s: %s\n", "mon_thousands_sep", localeDetails->mon_thousands_sep);
    printf("%s: %s\n", "positive_sign", localeDetails->positive_sign);
    printf("%s: %s\n", "negative_sign", localeDetails->negative_sign);
    printf("%s: %s\n", "currency_symbol", localeDetails->currency_symbol);
    printf("%s: %s\n", "int_curr_symbol", localeDetails->int_curr_symbol);

    printf("%s: %d\n", "frac_digits", (int)localeDetails->frac_digits);
    printf("%s: %d\n", "p_cs_precedes", (int)localeDetails->p_cs_precedes);
    printf("%s: %d\n", "n_cs_precedes", (int)localeDetails->n_cs_precedes);
    printf("%s: %d\n", "p_sep_by_space", (int)localeDetails->p_sep_by_space);
    printf("%s: %d\n", "n_sep_by_space", (int)localeDetails->n_sep_by_space);
    printf("%s: %d\n", "p_sign_posn", (int)localeDetails->p_sign_posn);
    printf("%s: %d\n", "n_sign_posn", (int)localeDetails->n_sign_posn);
    printf("%s: %d\n", "int_frac_digits", (int)localeDetails->int_frac_digits);
    printf("%s: %d\n", "int_p_cs_precedes",
           (int)localeDetails->int_p_cs_precedes);
    printf("%s: %d\n", "int_n_cs_precedes",
           (int)localeDetails->int_n_cs_precedes);
    printf("%s: %d\n", "int_p_sep_by_space",
           (int)localeDetails->int_p_sep_by_space);
    printf("%s: %d\n", "int_n_sep_by_space",
           (int)localeDetails->int_n_sep_by_space);
    printf("%s: %d\n", "int_p_sign_posn", (int)localeDetails->int_p_sign_posn);
    printf("%s: %d\n", "int_n_sign_posn", (int)localeDetails->int_n_sign_posn);

    return EXIT_SUCCESS;
}
