#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 1120

int main(void){

    char str_send[10001];
    /*fgets(str_send, 10000, stdin);*/

    struct sockaddr_in addr;
    struct sockaddr_in client;

    int sock0 = socket(AF_INET, SOCK_STREAM, 0);    

    addr.sin_family = AF_INET;                      
    addr.sin_port = htons(PORT);                    
    
    addr.sin_addr.s_addr = htonl(INADDR_ANY);       

    if (bind (sock0, (struct sockaddr *) &addr, sizeof (addr)) == -1){
        printf("\n Error !!!!\n");
    }

    listen(sock0, 5);    
     
     unsigned int length = sizeof (client);
     int sock = accept(sock0, (struct sockaddr *)&client, &length);

    char server_c[10000], client_c[10000], exit[10];
    while (strcmp(server_c, "exit") != 0){
   
    printf("\n >>");
    fgets(server_c, 10000, stdin);
    write(sock, server_c, sizeof(server_c));
    printf("\n Server :  %s\n", server_c);


    read(sock, client_c, sizeof(client_c));
    printf("\n Client :  %s\n", client_c);
    }

    close(sock);

    close(sock);
    close(sock0);

    return 0;
}