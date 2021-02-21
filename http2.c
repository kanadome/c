#include <stdio.h>
#include <stdlib.h>
#include "sock.c"

#define PORT 1120   /* 使用するポート番号 */


int main(void) {
  

    struct sockaddr_in acceptance;
    struct sockaddr_in client;

    acceptance.sin_family = AF_INET;
    acceptance.sin_port = htons(PORT);
    acceptance.sin_addr.s_addr = htonl(INADDR_ANY);

    int sock_acceptance = socket(AF_INET, SOCK_STREAM, 0);
    if(bind (sock_acceptance, (struct sockaddr *)&acceptance, sizeof(acceptance)) == -1) {
        printf("\n bind error\n");
        return 0;
    }

    listen (sock_acceptance, 5);

    unsigned int client_size = sizeof(client);
    



/*---------------------------------------------------------*/
char head[1000000], contents[1000000];

    

    FILE *html_file = NULL;
    html_file = fopen("./http2.html", "r");


    char a;
    int i = 0;
    while ((a = fgetc(html_file)) != EOF) {
        printf("%c", a);
        contents[i] = a;
        i++;
    }

    strcpy(head,"HTTP/1.1 200 OK\r\n"
	            "Content-Length: 5000\r\n"
	            "Content-Type: text/html\r\n"
	            "\r\n"
    );

    printf("\n %s\n", contents);
    strcat(head, contents);
    strcat(head, "\r\n");


/*-------------------------------------------------------------------------------*/

    int count = 0;
    while (count < 100) {
        int sock = accept(sock_acceptance, (struct sockaddr *)&client, &client_size);

        if (fork() == 0) {
            write(sock, head, sizeof(head));
            close(sock);

            exit (0);
        }else{
            close(sock);
        }
    }

    close(sock_acceptance);
    return 0;
}

