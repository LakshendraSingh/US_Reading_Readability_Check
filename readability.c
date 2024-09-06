#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    float cl = 0;
    for (int i = 0, x = strlen(text); i < x; i++)
    {
        if (isalpha(text[i]))
        {
            cl++;
        }
    }
    return cl;
}
int count_words(string text)
{
    float cw = 1;
    for (int i = 0, x = strlen(text); i < x; i++)
    {
        if (isblank(text[i]))
        {
            cw++;
        }
    }
    return cw;
}
int count_sentences(string text)
{
    float cs = 0;
    for (int i = 0, x = strlen(text); i < x; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            cs++;
        }
    }
    return cs;
}
