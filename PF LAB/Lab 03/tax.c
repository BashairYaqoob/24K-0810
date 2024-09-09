#include <stdio.h>
int main() {
int S, R, tax, salary;
printf("Enter the amount:");
scanf("%d", &S);
printf("Enter tax rate: ");
scanf("%d", &R);
tax= S*R/100;
printf("\n tax to be paid = %d", tax);
salary= S - tax;
printf("\n the new salary is: %d", salary);
    return 0;
}
