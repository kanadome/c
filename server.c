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
        return -1;
    }

    listen(sock0, 5);    
     
     unsigned int length = sizeof (client);
     int sock = accept(sock0, (struct sockaddr *)&client, &length);

    char server_c[10000], client_c[10000], exit[10] = "exit";

    printf("\n >>   ");
    fgets(server_c, 10000, stdin);
    write(sock, server_c , sizeof(server_c));

    int i =1;
    while (i ==1){

    read(sock, client_c, sizeof(client_c));
    printf("\n Client : \033[37m\033[1m\033[40m %s\033[0m\n", client_c);
 
   
    printf("\n >>   ");
    fgets(server_c, 10000, stdin);
    write(sock, server_c , sizeof(server_c));
  
    }

    close(sock);

    close(sock);
    close(sock0);

    printf("\003[0m");

    return 0;
}