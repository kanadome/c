#include <stdio.h>

int main(void)
{
    int num;
    int *Pnum;
    Pnum = &num;

    int i = 0;
    while (i < 5)
    {
        num = i;
        printf("\nnum : %d\n", num);
        printf("\nPnum  : %p\n", Pnum);
        printf("\n*Pnum  : %d\n", *Pnum);
        printf("\n --------------\n");

        *Pnum  = i * i;
        printf("%d", num);
        printf("\n===========================\n");

        i++;
    }
}