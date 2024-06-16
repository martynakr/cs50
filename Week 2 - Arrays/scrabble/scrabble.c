#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int LETTERS_IN_ALPHABET = 26;

int count_word_value(string word, int arr[], int maxIndex);
void print_winner(int score_one, int score_two);

int main(void)
{
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int word1_count = count_word_value(word1, points, LETTERS_IN_ALPHABET);
    int word2_count = count_word_value(word2, points, LETTERS_IN_ALPHABET);

    print_winner(word1_count, word2_count);
}

int count_word_value(string word, int arr[], int max)
{

    int value = 0;
    printf("Word: %s\n", word);

    for (int i = 0, l = strlen(word); i < l; i++)
    {
        int word_code = toupper(word[i]);
        int distance_from_A = word_code - 65;
        if (distance_from_A < max && distance_from_A >= 0)
        {
            value += arr[distance_from_A];
        }
    }

    return value;
}

void print_winner(int score_one, int score_two)
{
    if (score_one > score_two)
    {
        printf("Player 1 wins!");
    }
    else if (score_two > score_one)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}