#include <stdio.h>
int main () {
int amount, rate, year, interest ;
printf ("Please type the number in accordance with the range provided!\n");
printf("\n Enter a value (between 100-1,000,000):");
scanf("%d", &amount);
printf("\n Enter rate (between 5-10): ");
scanf("%d", &rate);
printf("\n Enter time period (between 1-10): ");
scanf("%d", &year);
interest = (amount*rate*year/100);
printf("The interest is : %d", interest);
    return 0;
}