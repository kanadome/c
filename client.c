#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 1120
#define SERVER_ADDRESS "127.0.0.1"


/* --------- Read and Write Socket ------------*/
int read_write (int sock, int sock_judgment){

    char contents[10000];
    int judgment;

    while (1 == 1){
        /* ---------- READ  ---------------*/
        read(sock, contents, sizeof(contents));
        printf("\n  SERVER :  \033[37m\033[40m%s\033[0m", contents);

        /*---------- WRITE ---------------*/
        printf("\n\n--- %s  \n\n", contents); /*---------------------------------------*/
        printf("\n  >>  ");
        fgets(contents, sizeof(contents), stdin);
        write(sock, contents, sizeof(contents));
        printf("\n\n--- %s  \n\n", contents); /*---------------------------------------*/
    }

    return 0;
}


int main(void){

  
    int sock = socket(AF_INET, SOCK_STREAM, 0);     
    int sock_judgment = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr (SERVER_ADDRESS);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1){
        printf("\n Error :  Server not found  \n");
        return -1;
    }
    if (connect(sock_judgment, (struct sockaddr *)&server, sizeof(server)) == -1){
        printf("\n Error  :  Server not found \n");
        return 0;
    }


   read_write(sock, sock_judgment);


    close(sock);
    close(sock_judgment);

    printf("\003[0m");

    return 0;
}
