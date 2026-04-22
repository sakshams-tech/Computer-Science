#include <cs50.h>
#include <stdio.h>

void space(int num_of_spaces);
void brick(int num_of_bricks);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    int num_of_spaces = height - 1;
    int num_of_bricks = 1;
    for (int lines = 0; lines < height; lines++)
    {
        space(num_of_spaces);
        brick(num_of_bricks);

        printf("  ");

        brick(num_of_bricks);
        printf("\n");

        num_of_spaces -= 1;
        num_of_bricks += 1;
    }
}

void space(int num_of_spaces)
{
    for (int space = 0; space < num_of_spaces; space++)
    {
        printf(" ");
    }
}

void brick(int num_of_bricks)
{
    for (int brick = 0; brick < num_of_bricks; brick++)
    {
        printf("#");
    }
}
