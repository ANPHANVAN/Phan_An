#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char key[27];
char vanban[1000];
char ketqua[1000];
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char giai[26];

void chuyen(void);
void magiai(void);
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    strcpy(key, argv[1]);

    int valid = 1;
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            valid = 0;
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // input key, biến key thành key dưới 26, input chỉ là chữ không số không ký tự đặc biệt
    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(key[i]);
    }

    // check coi ky tu trung lap
    for (int i = 0; i < 25; i++)
    {
        for (int j = i; j < 25; j++)
        {
            if (key[i] == key[j + 1])
            {
                return 1;
            }
        }
    }

    if ((valid == 1) && (strlen(key) == 26))
    {
        printf("plaintext:  ");
        fgets(vanban, sizeof(vanban), stdin);
        // tạo 1 vòng từ z quay lại a, tạo 1 vòng ngoài main với biến văn bản
        // Chuyển văn bản (kiểu như char[]+key) trong vòng lặp
        // chuyển mã quay về chữ
        // in kết quả tất cả văn bản
        chuyen();
        printf("ciphertext: %s", ketqua);
    }
}

void chuyen(void)
{
    magiai();

    for (int i = 0; i < strlen(vanban); i++)
    {
        // Kiểm tra ký tự là chữ cái
        if (isalpha(vanban[i]))
        {
            // Xử lý ký tự viết thường
            if (islower(vanban[i]))
            {
                ketqua[i] = ((vanban[i] - 'a' + giai[vanban[i] - 'a']) % 26) + 'a';
            }
            // Xử lý ký tự viết hoa
            else if (isupper(vanban[i]))
            {
                ketqua[i] = ((vanban[i] - 'A' + giai[vanban[i] - 'A']) % 26) + 'A';
            }
        }
        else
        {
            // Giữ nguyên các ký tự không phải chữ cái
            ketqua[i] = vanban[i];
        }
    }
    // Thêm ký tự kết thúc chuỗi
    ketqua[strlen(vanban)] = '\0';
}

void magiai(void)
{
    for (int i = 0; i < 26; i++)
    {
        if (key[i] - alpha[i] >= 0)
        {
            giai[i] = key[i] - alpha[i];
        }
        else
        {
            giai[i] = key[i] - alpha[i] + 26;
        }
    }
}
