#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 1120
#define SERVER_ADDRESS 127.0.0.1

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

    char contents[10000];

   
    if (read(sock, contents, sizeof(contents)) != -1){
        printf("\n Server :\033[37m\033[1m\033[40m  %s\n", contents);
    }

    char server_c[10000], client_c[10000], exit[10] = "exit";
    int i = 1;
    while (i == 1){
   
    printf("\n\033[0m >>   ");
    fgets(client_c, 10000, stdin);
    write(sock, client_c, sizeof(client_c));
    if (strcmp(client_c, exit) == 0){
        close(sock);
        return 0;
    }
    /*printf("\n\033[32m Client :  %s\n", client_c);*/


    read(sock, server_c, sizeof(server_c));
    printf("\n  Server :\033[37m\033[1m\033[40m  %s\n", server_c);
    if (strcmp(server_c, exit) == 0){
        close(sock);
        return 0;
    }
    }

    close(sock);

    printf("\003[0m");

    return 0;
}