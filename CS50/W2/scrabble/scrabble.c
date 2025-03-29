#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Bảng điểm cho các chữ cái từ A đến Z
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Hàm tính điểm cho một từ
int compute_score(char word[])
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {                                       // Kiểm tra ký tự có phải chữ cái không
            char upper_char = toupper(word[i]); // Chuyển sang chữ hoa
            score += points[upper_char - 'A'];  // Tính điểm
        }
    }
    return score;
}

int main()
{
    char word1[100], word2[100];

    // Nhập từ của người chơi 1
    printf("Player 1: ");
    scanf("%s", word1);

    // Nhập từ của người chơi 2
    printf("Player 2: ");
    scanf("%s", word2);

    // Tính điểm cho từng người chơi
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // So sánh điểm và in kết quả
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
