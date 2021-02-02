#include <stdio.h>


int return_exponentiation(int x, int y)
{
    int result;
    int i = 1; /*Counter*/
    result = x;

    while (i < y)
    {
        result =  result * x;
        i++;
	}
    return result;
}
