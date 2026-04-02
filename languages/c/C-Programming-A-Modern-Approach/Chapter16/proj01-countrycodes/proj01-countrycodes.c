// takes a international dialing code input and outputs the name of the
// corresponding country if it's in the list of 32 select countries

#include <stdio.h>

#define SIZE 32

int main(void) {
    struct DialingCode {
        char *countryName;
        int dialingCode;
    };

    const struct DialingCode country_codes[SIZE] = {
        {"Argentina", 54},
        {"Bangladesh", 880},
        {"Brazil", 55},
        {"Burma (Myanmar)", 95},
        {"China", 86},
        {"Colombia", 57},
        {"Congo, Dem. Rep. of", 243},
        {"Egypt", 20},
        {"Ethiopia", 251},
        {"France", 33},
        {"Germany", 49},
        {"India", 91},
        {"Indonesia", 62},
        {"Italy", 39},
        {"Mexico", 52},
        {"Pakistan", 92},
        {"Poland", 48},
        {"South Africa", 27},
        {"Spain", 34},
        {"Thailand", 66},
        {"Ukraine", 380},
        {"United States", 1},
        {"Iran", 98},
        {"Japan", 81},
        {"Nigeria", 234},
        {"Philippines", 63},
        {"Russia", 7},
        {"South Korea", 82},
        {"Sudan", 249},
        {"Turkey", 90},
        {"United Kingdom", 44},
        {"Vietnam", 84}};

    printf("Enter a dialing code: ");
    int input;
    scanf("%d", &input);

    for (int i = 0; i < SIZE; ++i) {
        if (country_codes[i].dialingCode == input) {
            printf("%s\n", country_codes[i].countryName);
            return 0;
        }
    }

    printf("Country with dialing code %d not found in list\n", input);

    return 0;
}
