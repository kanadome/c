#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 1120

int main(void){

  
    int sock = socket(AF_INET, SOCK_STREAM, 0);     

    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr ("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1){
        printf("\n Error :  Server not found  \n");
    }

    char contents[10000];

   
    if (read(sock, contents, sizeof(contents)) != -1){
        printf("\n Server :  %s\n", contents);
    }

    char server_c[10000], client_c[10000], exit[10];
    while (strcmp(server_c, "exit") != 0){
   
    printf("\n >>");
    fgets(client_c, 10000, stdin);
    write(sock, client_c, sizeof(client_c));
    printf("\n Client :  %s\n", client_c);


    read(sock, server_c, sizeof(server_c));
    printf("\n Server :  %s\n", client_c);
    }

    close(sock);

    return 0;
}