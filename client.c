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
int read_write (int sock){

    char contents[10000];

    /*----*/ printf("%d", sock);

    while (1 == 1){
        /* ---------- READ  ---------------*/
        read(sock, contents, sizeof(contents));
        printf("\n  SERVER :  \033[37m\033[40m%s\033[0m", contents);

        /*---------- WRITE ---------------*/
        printf("\n  >>  ");
        fgets(contents, sizeof(contents), stdin);
        /* --- */ printf("\n\n %s \n\n", contents);
        write(sock, contents, sizeof(contents));
    }

    return 0;
}


int main(void){

  
    int sock = socket(AF_INET, SOCK_STREAM, 0);     

    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr (SERVER_ADDRESS);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1){
        printf("\n Error :  Server not found  \n");
        return -1;
    }

/*
    char contents[10000];
    read(sock, contents, sizeof(contents));
    printf("\n Server :\033[37m\033[1m\033[40m  %s\033[0m\n", contents);
*/

   read_write(sock);
    /*
    char server_c[10000], client_c[10000], exit[10] = "exit";
    int i = 1;
    while (i == 1){
   
    printf("\n >>   ");
    fgets(client_c, 10000, stdin);
    
    write(sock, client_c, sizeof(client_c));
   
    read(sock, server_c, sizeof(server_c));
    printf("\n  Server :\033[37m\033[1m\033[40m  %s\033[0m\n", server_c);
    
    }
    */

    close(sock);

    printf("\003[0m");

    return 0;
}