#include <cs50.h>
#include <stdio.h>

void pyramid(int height);
void spacer(int height, int width);
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int width = 2;
    for (int i = 1; i <= height; i++)
    {
        spacer(height, width);
        pyramid(width);
        printf("  ");
        pyramid(width);
        printf("\n");
        width += 2;
    }
}

// function to printout the pyramid
void pyramid(int width)
{
    for (int n = 1; n <= width / 2; n++)
    {
        printf("#");
    }
}
void spacer(int height, int width)
{
    int spaces = height - width / 2;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
}
