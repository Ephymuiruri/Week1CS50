#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int crarray[16];                  // Array to store each digit of the long number
    long crno = get_long("Number: "); // Get the long number from the user
    char string[20];                  // String to hold the long number as a string

    // Convert the long number to a string
    sprintf(string, "%li", crno);

    // Iterate over each character in the string
    for (int i = 0; string[i] != '\0'; i++)
    {
        // Convert each character to an integer and store it in the array
        crarray[i] = string[i] - '0';
    }
    int length = strlen(string) - 1;
    int sum = 0;
    int position;
    do
    {
        position = length - 1;
        if (crarray[position] * 2 < 9)
        {
            sum += crarray[position] * 2;
        }
        else
        {
            int value = crarray[position] * 2;
            int tens = value / 10;
            int ones = value % 10;
            sum += tens + ones;
        }
        length -= 2;
    }
    while (length > 0);
    length = strlen(string) - 1;
    for (int j = length; j >= 0; j -= 2)
    {
        sum += crarray[j];
    }

    if (sum % 10 == 0)
    {
        if (string[0] == '3' && (string[1] == '4' || string[1] == '7') && strlen(string) == 15)
        {
            printf("AMEX\n");
        }
        else if (string[0] == '4' && (strlen(string) == 13 || strlen(string) == 16))
        {
            printf("VISA\n");
        }
        else if (string[0] == '5' &&
                 (string[1] == '1' || string[1] == '2' || string[1] == '3' || string[1] == '4' ||
                  string[1] == '5') &&
                 strlen(string) == 16)
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
