#include <stdio.h>

int x;
int y;
int block;
void lapblock(void);
void lapx(void);

int main(void)
{
// này để nhập x, chiều ngang của mỗi block
    printf("nhập x: ");
    scanf("%d", &x);
    printf("Bạn vừa nhập x: %d\n", x);

// này để nhập y, chiều dọc của mỗi block
    printf("nhập y: ");
    scanf("%d", &y);
    printf("Bạn vừa nhập y: %d\n", y);

// này để thể hiện số block muốn thể hiện
    printf("nhập block: ");
    scanf("%d", &block);
    printf("Bạn vừa nhập số block: %d\n", block);

// này là cách từng dòng y
    printf("Kết quả:\n");

    for (int i = 0; i < y; i++)
    {
        lapblock();
        printf("\n");
    }
    
    return 0;
}

// này chia các block bằng dấu cách
void lapblock(void)
{
    for (int i = 0; i < block; i++)
    {
        lapx();
        printf("  ");
    }
    
}

void lapx(void)
{
    for (int i = 0; i < x; i++)
    {
        printf("#");
    }
}