#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0);

    int num_of_spaces = height - 1;
    int num_of_bricks = 1;

    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < num_of_spaces; b++)
        {
            printf(" ");
        }
        for (int c = 0; c < num_of_bricks; c++)
        {
            printf("#");
        }
        printf("\n");

        num_of_spaces -= 1;
        num_of_bricks += 1;
    }
}
