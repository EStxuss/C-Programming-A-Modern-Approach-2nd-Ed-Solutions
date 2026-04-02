// lines up input information into columns
// date and product number are left justified, price is right justified

#include <stdio.h>

int main(void) {
    int itemNum = 0;
    printf("Enter the item number: ");
    scanf("%d", &itemNum);

    float itemPrice = 0.0f;
    printf("Enter the item price: ");
    scanf("%f", &itemPrice);

    int day = 0, month = 0, year = 0;
    printf("Enter the purchase date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%7.2f\t%.2d/"
           "%.2d/%d\n",
           itemNum, itemPrice, day, month, year);
}
