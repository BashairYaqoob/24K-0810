#include <stdio.h>
int main() {
int dist1, distance, f1, f2, fuel_avg, c1, c2, cost, a,b;
dist1= 1207;
distance = dist1 * 2 ;
c1= 118;
c2= 123;
printf("Enter fuel average: ");
scanf("%d", &fuel_avg);
f1= dist1* fuel_avg/100;
f2= f1*2;
printf("\n The total fuel consumed is: %d litres", f2);
a= f1*c1;
b= f1*c2;
cost= a+b;
printf("\n The total fuel cost is : %d rupees", cost);
return 0;
}
