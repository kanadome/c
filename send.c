#include "include.c"

int main (void){

int fifo;
char output[10000];

fifo = open(".fifo", O_RDWR);

printf("\n >>>");
fgets(output, 10000, stdin);

write(fifo, output, strlen(output) + 1);

close(fifo);

return 0;
}