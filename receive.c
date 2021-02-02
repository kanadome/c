#include "include.c"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int fifo;
char contents[10000], output[10000];
char username[10];

int sent(){
    fifo = open(".fifo", O_RDWR);
    printf("\n >>>");
    fgets(output, 10000, stdin);
    if (!strcmp(output, "exit")){
        return 1;
    }
    strcpy(output,strcat(strcat(username, " : "),output));
    write(fifo, output, strlen(output) + 1);
    close(fifo);
    return 0;
}
void receive(){
    fifo = open(".fifo", O_RDWR);
    read(fifo, contents, 10000);
    printf("\n%s", contents);
    close(fifo);
}
int main(void){
    
    fifo = open(".fifo", O_RDONLY | O_NONBLOCK);
    int b;
    char a[10];
    b = read(fifo, a, 9);
    printf("\n%d\n", b);
    if (b == 0){
         mkfifo(".fifo", 0777);
    }
   

    printf(" Your Name >>");
    fgets(username, 9, stdin);
    
    
   

    int exit = 0;
    while (exit == 0){
        sent();
        receive();
    }
   

    return 0;
}