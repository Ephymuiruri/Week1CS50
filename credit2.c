#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number = get_long("Number: ");  // Get the card number from user
    
    int sum1 = 0, sum2 = 0;
    int total_sum = 0;
    int digit_count = 0;
    int first_two_digits = 0;
    
    // Processing the card number
    long number_copy = card_number;  // Make a copy to extract digits from
    while (number_copy > 0)
    {
        int last_digit = number_copy % 10;   // Get the last digit
        number_copy /= 10;                   // Remove the last digit
        
        // Process every second digit starting from the end
        if (digit_count % 2 == 0)
        {
            sum1 += last_digit;  // Just add the digit if it's not to be doubled
        }
        else
        {
            int doubled_digit = last_digit * 2;
            sum2 += (doubled_digit > 9) ? (doubled_digit - 9) : doubled_digit;  // Add digits of doubled number
        }
        
        // Store the first two digits for later card type check
        if (number_copy < 100 && number_copy > 9)
        {
            first_two_digits = number_copy;
        }

        digit_count++;
    }
    
    // Luhn's algorithm total sum
    total_sum = sum1 + sum2;
    
    // Check if the total sum is divisible by 10
    if (total_sum % 10 == 0)
    {
        // Determine card type based on first digits and number of digits
        if (digit_count == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (digit_count == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((digit_count == 13 || digit_count == 16) && (first_two_digits / 10 == 4))
        {
            printf("VISA\n");
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
