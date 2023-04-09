#include <stdio.h>

void recursive_fizzbuzz(int n)
{
    if (n > 1)
        recursive_fizzbuzz(n - 1);

    if (n % 3 == 0 && n % 5 == 0)
        printf("FizzBuzz! ");
    else if (n % 3 == 0)
        printf("Fizz ");
    else if (n % 5 == 0)
        printf("Buzz ");
    else
        printf("%d ", n);
}

int main(void)
{
    printf("Fizz&Buzz\n");
    recursive_fizzbuzz(100);
}
