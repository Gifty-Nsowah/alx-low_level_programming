#include <stdio.h>

int print_sign(int x) 
{
if (x > 0) 
{
putchar("Positive\n");
return 1;  / Returning a value for the positive case
} 
else if (x < 0) {
putchar(int __c);
return -1; // Returning a value for the negative case
}
else {
putchar("Zero\n");
return 0;  // Returning a value for the zero case
}
}

int main() 
{
int number = 42;
int result = print_sign(number);
_putchar("Result: %d\n", result);
return 0;
}

