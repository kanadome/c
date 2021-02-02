#include <stdio.h>

char *return_japanese(char *);

int main(void)
{
    char output_text[1000]; /* Japanese */
    char input_text[1000];    /* Romaji      */
    int i = 0;

    printf(" [MAX 1000] >>");
    scanf("%s", input_text);

    /* Substitute the result from "return_japanese" to output_text */
    while (i < 1000){
        output_text[i] = *return_japanese(input_text)   + i;
        i++;
    }

    printf("\n  %s", output_text);

    return 0;
}

/* Return Japanese by pointer*/
char *return_japanese(char *P_input_text){

    char output_text[1000]; /* Japanese */
    char input_text[1000];    /* Romaji      */

    /* Substitute variable address to  pointer variable "P_output_text"*/
    char *P_output_text = &output_text[0];  
    

    int i = 0;
    while (i < 1000){
        input_text[i] = *P_input_text + i;
        i++;
    }

    return P_output_text;
}