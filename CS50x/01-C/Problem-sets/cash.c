#include <cs50.h>
#include <stdio.h>

void reduce_amount(int *change_amount, int *num_of_coins, int coins);

int main(void)
{
    const int quarter = 25;
    const int dime = 10;
    const int nickel = 5;
    const int penny = 1;

    int change_amount;
    do
    {
        change_amount = get_int("Change owed: ");
    }
    while (change_amount < 0);

    int num_of_coins = 0;
    while (change_amount > 0)
    {
        if (change_amount >= quarter)
        {
            reduce_amount(&change_amount, &num_of_coins, quarter);
        }
        else if (change_amount >= dime)
        {
            reduce_amount(&change_amount, &num_of_coins, dime);
        }
        else if (change_amount >= nickel)
        {
            reduce_amount(&change_amount, &num_of_coins, nickel);
        }
        else
        {
            reduce_amount(&change_amount, &num_of_coins, penny);
        }
    }
    printf("%i\n", num_of_coins);
}

void reduce_amount(int *change_amount, int *num_of_coins, int coins)
{
    *change_amount -= coins;
    (*num_of_coins)++;
}
