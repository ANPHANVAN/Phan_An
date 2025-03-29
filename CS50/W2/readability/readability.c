#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float L;
float S;
float number;
int main(void)
{
    // Nhập chuỗi từ người dùng
    string vanban = get_string("Nhap van ban: ");
    int numberspace = 0;
    // Duyệt qua từng ký tự trong chuỗi
    for (int i = 0; i < strlen(vanban); i++)
    {
        // Kiểm tra xem ký tự có phải là khoảng trắng không
        if (isspace(vanban[i]))
        {
            numberspace += 1;
        }
    }

    int daucau = 0;
    // Duyệt qua từng ký tự trong chuỗi
    for (int i = 0; i < strlen(vanban); i++)
    {
        // Kiểm tra xem ký tự có phải là ký tự không
        if (vanban[i] == '.' || vanban[i] == '!' || vanban[i] == '?')

        {
            daucau += 1;
        }
    }
    int sotu = numberspace + 1;
    int n = strlen(vanban) - sotu - daucau;

    L = (float) n / (float) sotu * 100;

    S = (float) daucau / (float) sotu * 100;

    number = 0.0588 * L - 0.296 * S - 15.8;

    if ((number > 1) & (number < 16))
    {
        printf("Grade %i\n", (int) round(number));
    }
    else if (number < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}
