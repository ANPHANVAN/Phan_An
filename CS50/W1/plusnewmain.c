#include <stdio.h>
int add(int a, int b);

int main(void)
{
    int x;
    int y;
    printf("Nhập x: ");
    scanf("%d", &x); // Nhập số nguyên và lưu vào biến number
    printf("Bạn vừa nhập x: %d\n", x);
    printf("Nhập y: ");
    scanf("%d", &y); // Nhập số nguyên và lưu vào biến number
    printf("Bạn vừa nhập y: %d\n", y);
    printf("Tong 2 so la: %d\n", add(x,y));
    return 0;
}

int add(int a, int b)
{
    return a + b;
}