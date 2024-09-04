#include <stdio.h>
int main () {
int A, B, c;
double m ;
printf("Enter x co-ordinate: ");
scanf("%d", &A);
printf("\nEnter y co-ordinate:");
scanf("%d", &B);
printf("\nEnter y-intercept:");
scanf("%d", &c);
m = (double)(B - c)/A ;
printf("The slope is: %.3f\n", m);
    return 0;
}
