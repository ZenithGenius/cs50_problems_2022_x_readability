#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    float L, W, S, words, letters, sentences;
    float X;
    string text = get_string("Text: ");
    //X = Coleman-Liau index
    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    //L is the average number of letters per 100 words
    L = (letters / words) * 100;

    //S is the average number of sentences per 100 words
    S = (sentences / words) * 100;
    X = (0.0588 * L) - 0.296 * S - 15.8;
    X = round(X);
    //print the result according to the interval
    if (X > 15)
    {
        printf("Grade 16+\n");
    }
    else if (X < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", X);
    }
    return 0;
}

//function to get the number of letters
int count_letters(string text)
{
    //L is the number of letters
    int L = 0;
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (isalpha(text[i]))
        {
            L = L + 1;
        }
    }
    return L;
}

//function to get the number of sentences
int count_words(string text)
{
    //W is the number of words
    int W;
    if (text[0] == 0)
    {
        return 1;
    }
    else
    {
        W = 1;
        for (int i = 0 ; i < strlen(text) ; i++)
        {
            if (text[i] == 32)
            {
                W = W + 1;
            }
        }
    }
    return W;
}

//function to get the number of sentences
int count_sentences(string text)
{
    //S is the number of sentences
    int S = 0;
    if (text[0] == 0)
    {
        return S;
    }
    else
    {
        for (int i = 0 ; i < strlen(text) ; i++)
        {
            if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
            {
                S = S + 1;
            }
        }
    }
    return S;
}