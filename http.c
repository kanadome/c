#include <stdio.h>
#include "sock.c"

#define PORT 1120   /* 使用するポート番号 */

int communication(int);

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
    int sock = accept(sock_acceptance, (struct sockaddr *)&client, &client_size);

    for (int i = 0; i < 1; i++){communication(sock);}

    close(sock);
    close(sock_acceptance);
    return 0;
}

int communication(int sock) {
    char head[100], contents[1000000];

    

    FILE *html_file = NULL;
    html_file = fopen("test.html", "r");
    int i = 0;


    char a;
    while ((a = fgetc(html_file)) != EOF) {
        printf("%c", a);
    }
    printf("\n%s\n", contents);
/*
    write(sock, "HTTP/1.0 200 OK\r\n", sizeof("HTTP/1.1 200 OK\r\n"));
    write(sock, "Content-Length: 20\r\n", sizeof("Content-Length: 20\r\n"));
    write(sock, "Content-Type: text/html\r\n", sizeof("Content-Type: text/html\r\n"));
    write(sock, "\r\n", sizeof("\r\n"));
    write(sock, "Hello World\r\n", sizeof("Hello World\r\n"));
*/  


    strcpy(head,"HTTP/1.0 200 OK\r\n"
	            "Content-Length: 20\r\n"
	            "Content-Type: text/html\r\n"
	            "\r\n"
    );

    char html[1000000];

    strcpy(html, contents);

    strcpy(contents, strcat(head, contents));

    printf("\n\n %s \n", contents);

    write(sock,head, 10000);

    return 0;
}