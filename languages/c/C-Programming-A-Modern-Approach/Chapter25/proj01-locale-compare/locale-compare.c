// Determines whether any differences between C locale and native locale

#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strdupFail(void);
void notTheSame(const char *varName, const char *cVal, const char *natVal,
                bool isStr);

FILE *fOut;
bool same = true;

int main(void) {
    if ((fOut = fopen("output.txt", "wb")) == NULL) {
        fprintf(stderr, "Couldn't open file for writing\n");
        exit(EXIT_FAILURE);
    }

    struct lconv cLocaleCopy;

    struct lconv *currLocale = localeconv();

    cLocaleCopy = *currLocale;

    if ((cLocaleCopy.decimal_point = strdup(currLocale->decimal_point)) == NULL)
        strdupFail();
    if ((cLocaleCopy.thousands_sep = strdup(currLocale->thousands_sep)) == NULL)
        strdupFail();
    if ((cLocaleCopy.grouping = strdup(currLocale->grouping)) == NULL)
        strdupFail();
    if ((cLocaleCopy.mon_decimal_point =
             strdup(currLocale->mon_decimal_point)) == NULL)
        strdupFail();
    if ((cLocaleCopy.mon_thousands_sep =
             strdup(currLocale->mon_thousands_sep)) == NULL)
        strdupFail();
    if ((cLocaleCopy.mon_grouping = strdup(currLocale->mon_grouping)) == NULL)
        strdupFail();
    if ((cLocaleCopy.positive_sign = strdup(currLocale->positive_sign)) == NULL)
        strdupFail();
    if ((cLocaleCopy.negative_sign = strdup(currLocale->negative_sign)) == NULL)
        strdupFail();
    if ((cLocaleCopy.currency_symbol = strdup(currLocale->currency_symbol)) ==
        NULL)
        strdupFail();
    if ((cLocaleCopy.int_curr_symbol = strdup(currLocale->int_curr_symbol)) ==
        NULL)
        strdupFail();

    if (setlocale(LC_ALL, "") == NULL) {
        fprintf(stderr, "setlocale failed");
        exit(EXIT_FAILURE);
    }

    struct lconv *nativeLocale = localeconv();

    if (strcmp(cLocaleCopy.decimal_point, nativeLocale->decimal_point) != 0)
        notTheSame("", cLocaleCopy.decimal_point, nativeLocale->decimal_point,
                   true);
    if (strcmp(cLocaleCopy.thousands_sep, nativeLocale->thousands_sep) != 0)
        notTheSame("thousands_sep", cLocaleCopy.thousands_sep,
                   nativeLocale->thousands_sep, true);
    if (strcmp(cLocaleCopy.grouping, nativeLocale->grouping) != 0)
        notTheSame("grouping", cLocaleCopy.grouping, nativeLocale->grouping,
                   true);
    if (strcmp(cLocaleCopy.mon_decimal_point,
               nativeLocale->mon_decimal_point) != 0)
        notTheSame("mon_decimal_point", cLocaleCopy.mon_decimal_point,
                   nativeLocale->mon_decimal_point, true);
    if (strcmp(cLocaleCopy.mon_thousands_sep,
               nativeLocale->mon_thousands_sep) != 0)
        notTheSame("mon_thousands_sep", cLocaleCopy.mon_thousands_sep,
                   nativeLocale->mon_thousands_sep, true);
    if (strcmp(cLocaleCopy.mon_grouping, nativeLocale->mon_grouping) != 0)
        notTheSame("mon_grouping", cLocaleCopy.mon_grouping,
                   nativeLocale->mon_grouping, true);
    if (strcmp(cLocaleCopy.positive_sign, nativeLocale->positive_sign) != 0)
        notTheSame("positive_sign", cLocaleCopy.positive_sign,
                   nativeLocale->positive_sign, true);
    if (strcmp(cLocaleCopy.negative_sign, nativeLocale->negative_sign) != 0)
        notTheSame("negative_sign", cLocaleCopy.negative_sign,
                   nativeLocale->negative_sign, true);
    if (strcmp(cLocaleCopy.currency_symbol, nativeLocale->currency_symbol) != 0)
        notTheSame("currency_symbol", cLocaleCopy.currency_symbol,
                   nativeLocale->currency_symbol, true);
    if (strcmp(cLocaleCopy.int_curr_symbol, nativeLocale->int_curr_symbol) != 0)
        notTheSame("int_curr_symbol", cLocaleCopy.int_curr_symbol,
                   nativeLocale->int_curr_symbol, true);
    if (cLocaleCopy.frac_digits != nativeLocale->frac_digits)
        notTheSame("frac_digits", &cLocaleCopy.frac_digits,
                   &nativeLocale->frac_digits, false);
    if (cLocaleCopy.p_cs_precedes != nativeLocale->p_cs_precedes)
        notTheSame("p_cs_precedes", &cLocaleCopy.p_cs_precedes,
                   &nativeLocale->p_cs_precedes, false);
    if (cLocaleCopy.n_cs_precedes != nativeLocale->n_cs_precedes)
        notTheSame("n_cs_precedes", &cLocaleCopy.n_cs_precedes,
                   &nativeLocale->n_cs_precedes, false);
    if (cLocaleCopy.p_sep_by_space != nativeLocale->p_sep_by_space)
        notTheSame("p_sep_by_space", &cLocaleCopy.p_sep_by_space,
                   &nativeLocale->p_sep_by_space, false);
    if (cLocaleCopy.n_sep_by_space != nativeLocale->n_sep_by_space)
        notTheSame("n_sep_by_space", &cLocaleCopy.n_sep_by_space,
                   &nativeLocale->n_sep_by_space, false);
    if (cLocaleCopy.p_sign_posn != nativeLocale->p_sign_posn)
        notTheSame("p_sign_posn", &cLocaleCopy.p_sign_posn,
                   &nativeLocale->p_sign_posn, false);
    if (cLocaleCopy.n_sign_posn != nativeLocale->n_sign_posn)
        notTheSame("n_sign_posn", &cLocaleCopy.n_sign_posn,
                   &nativeLocale->n_sign_posn, false);
    if (cLocaleCopy.int_frac_digits != nativeLocale->int_frac_digits)
        notTheSame("int_frac_digits", &cLocaleCopy.int_frac_digits,
                   &nativeLocale->int_frac_digits, false);
    if (cLocaleCopy.int_p_cs_precedes != nativeLocale->int_p_cs_precedes)
        notTheSame("int_p_cs_precedes", &cLocaleCopy.int_p_cs_precedes,
                   &nativeLocale->int_p_cs_precedes, false);
    if (cLocaleCopy.int_n_cs_precedes != nativeLocale->int_n_cs_precedes)
        notTheSame("int_n_cs_precedes", &cLocaleCopy.int_n_cs_precedes,
                   &nativeLocale->int_n_cs_precedes, false);
    if (cLocaleCopy.int_p_sep_by_space != nativeLocale->int_p_sep_by_space)
        notTheSame("int_p_sep_by_space", &cLocaleCopy.int_p_sep_by_space,
                   &nativeLocale->int_p_sep_by_space, false);
    if (cLocaleCopy.int_n_sep_by_space != nativeLocale->int_n_sep_by_space)
        notTheSame("int_n_sep_by_space", &cLocaleCopy.int_n_sep_by_space,
                   &nativeLocale->int_n_sep_by_space, false);
    if (cLocaleCopy.int_p_sign_posn != nativeLocale->int_p_sign_posn)
        notTheSame("int_p_sign_posn", &cLocaleCopy.int_p_sign_posn,
                   &nativeLocale->int_p_sign_posn, false);
    if (cLocaleCopy.int_n_sign_posn != nativeLocale->int_n_sign_posn)
        notTheSame("int_n_sign_posn", &cLocaleCopy.int_n_sign_posn,
                   &nativeLocale->int_n_sign_posn, false);

    if (same)
        fprintf(fOut,
                "The native locale has no difference from the C locale\n");

    return EXIT_SUCCESS;
}

void strdupFail(void) {
    fprintf(stderr, "strdup call failed\n");
    exit(EXIT_FAILURE);
}

void notTheSame(const char *varName, const char *cVal, const char *natVal,
                bool isStr) {
    same = false;
    if (isStr && (strcmp(varName, "grouping") == 0 ||
                  strcmp(varName, "mon_grouping") == 0)) {
        fprintf(fOut, "%s is different:\nC locale: ", varName);
        while (*cVal)
            fprintf(fOut, "%d ", (int)(*(cVal++)));
        fprintf(fOut, "\nNative locale: ");
        while (*natVal)
            fprintf(fOut, "%d ", (int)(*(natVal++)));
        fprintf(fOut, "\n\n");
    } else if (isStr)
        fprintf(fOut, "%s is different:\nC locale: %s\nNative locale: %s\n\n",
                varName, cVal, natVal);
    else
        fprintf(fOut, "%s is different:\nC locale: %d\nNative locale: %d\n\n",
                varName, *cVal, *natVal);
}