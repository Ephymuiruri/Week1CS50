#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long crno = get_long("Number: "); // Get the long number from the user
    int sum = 0;
    int length = 0;
    int first_digit = 0, first_two_digits = 0;
    
    // Luhn's algorithm: Process each digit starting from the last
    for (long temp = crno; temp > 0; temp /= 10, length++)
    {
        int digit = temp % 10;

        if (length % 2 == 0)
        {
            // Add digits not being doubled
            sum += digit;
        }
        else
        {
            // Double every other digit and sum its digits
            int doubled = digit * 2;
            sum += (doubled > 9) ? (doubled - 9) : doubled;
        }

        // Capture the first and first two digits
        if (temp >= 10 && temp < 100)
        {
            first_two_digits = temp;
        }
        if (temp < 10)
        {
            first_digit = temp;
        }
    }

    // Check if the sum is valid
    if (sum % 10 == 0)
    {
        // Card type checks
        if (first_two_digits == 34 || first_two_digits == 37)
        {
            printf("AMEX\n");
        }
        else if (first_digit == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else if (first_two_digits >= 51 && first_two_digits <= 55 && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
