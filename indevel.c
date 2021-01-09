#include <stdio.h>

int main(void)
{
    char test[10];
    char *Ptest;
    int i = 0;

    while (i < 10){test[i] = i; i++;}

    printf("\n  >>");
    scanf("%d", &i);

    Ptest = &test[i];

    printf("\n>> %s\n", test);
    printf("\n>> %p\n", Ptest);
    printf("\n>> %c\n", *Ptest);

    
    /*
    int i = 0;
    while (i < 10)
    {
        int ii = i +1;
        printf("\n test[%d]  :", ii);
        scanf("%*c%c",  &test[i]);
 
        i++;

    }

    printf("%s \n\n", test);
    */

    return 0;
}