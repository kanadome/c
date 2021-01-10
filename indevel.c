#include <stdio.h>

int return_exponentiation(int, int);

/*
int main(void)
{
    int num[20] = {};
    int i = 0;
    for (int count = 0; count < 20; count++) {num[count] = count * count; }
    while (i < 20) {printf("\n %x >> %x", i  + 1,num[i]); i++; }
    printf("\n");
    return 0;
}
*/

int main(void)
{
    int x, y;
    printf("\n  >>");
    scanf("%d", &x);
    printf("\n  >>");
    scanf("%d", &y);

    int result = return_exponentiation(x, y);

    printf("\n\n     %d\n", result);

    return 0;
}

int return_exponentiation(int x, int y)
{
    int result;
    int i = 1;
    result = x;
    while (i < y)
    {
        result =  result * x;
        i++;
    }
    return result;
}