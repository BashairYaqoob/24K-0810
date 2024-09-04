#include <stdio.h>
int main () {
int A, B, c, m ;
printf("Enter x co-ordinate: ");
scanf("%d", &A);
printf("\nEnter y co-ordinate:");
scanf("%d", &B);
printf("\nEnter y-intercept:");
scanf("%d", &c);
m = ((B - c) / A) ;
printf("The slope is: %d", m);
    return 0;
}