#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1120

int main(void){

    int sock = socket(AF_INET, SOCK_STREAM, 0);     /* ソッケトを作成 */

    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1){
        printf("\n Error");
    }

    char contents[10000];
    if (read(sock, contents, sizeof(contents)) != -1){
        printf("\n\n The TCP Server Said :  %s", contents);
    }

    close(sock);

    return 0;
}