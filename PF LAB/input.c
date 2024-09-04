Answer 1️⃣: The int data type in C typically has a range of -2,147,483,648 to 2,147,483,647.
The value 3000000000 exceeds this range . The printed output is the highest value that int can take.


Answer 2️⃣:
  
#include <stdio.h>
int main () {
int num1, num2, c, d;
printf("enter number 1: ");
scanf("%d", &num1);

printf("enter number 2: ");
scanf("%d", &num2);
c = num2;
d = num1;
printf ("output is = %d , %d",c, d);
return 0;
}


Answer 3️⃣:

