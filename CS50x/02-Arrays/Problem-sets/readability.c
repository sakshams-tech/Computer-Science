#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int grade_evaluation(string text);

int main(void)
{
    string text = get_string("Text: ");

    int grade_level = grade_evaluation(text);
    if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 1 && grade_level < 16)
    {
        printf("Grade %i\n", grade_level);
    }
}

int grade_evaluation(string text)
{
    double l = 0;
    double s = 0;
    double w = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s++;
        }
        else if (text[i] == ' ')
        {
            w++;
        }
        else
        {
            continue;
        }
    }

    double L = l * 100 / (w + 1);
    double S = s * 100 / (w + 1);

    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade_level = round(index);
    return grade_level;
}
