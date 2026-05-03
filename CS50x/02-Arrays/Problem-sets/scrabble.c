#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score_calculation(string word);

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Plater 2: ");

    int score1 = score_calculation(word1);
    int score2 = score_calculation(word2);
    printf("%i %i\n", score1, score2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score_calculation(string word)
{
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if isupper (word[i])
        {
            score += points[word[i] - 'A'];
        }
        else if islower (word[i])
        {
            score += points[word[i] - 'a'];
        }
        else
        {
            continue;
        }
    }
    return score;
}
