#include <stdio.h>
#include <stdlib.h>
#include "sock.c"


/*

　HTMLファイルから、 % で始まり $ で終わる GET リクエストを送ると、
その文字列を　request_contents にだいにゅうできます


*/




#define PORT 1120   /* 使用するポート番号 */

char *communication();

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
    char contents[1000000];
    char *Phead = communication();
    for (int i = 0; i < 1000000; i++) {
        contents[i] = *(Phead + i);
    }

    char request[10000]; 
    char request_contents[1000];
    int count = 0;
    int count1 = 0;
    while (1)
    {
        int sock = accept(sock_acceptance, (struct sockaddr *)&client, &client_size);

        count = 0;
        count1 = 0;
 
        
        if (fork() == 0) {
            write(sock, contents, sizeof(contents));


            read(sock, request, sizeof(request)); /*クライアントからの要求を読む*/
        printf("\n\n\n %s\n\n", request);

/*  count を　GET　で送られてきた文字列の開始地点にセットする  */
        while (request[count] != '%') {
            count++;
        }

/*  request_contents に GET でら送られてきた文字列を代入する  */
        while (request[count] != '$') {
            request_contents[count1] = request[count + 1];
            count1++;
            count++;
        }

/*  request_contents から、 GET で送られた文字列の終端を表す $ を取り除く  */
    request_contents[count1 -1] = '\0';

/*
    for(int i = 0; i < (count1 - 1);) {
        request_contents[i] = request_contents[i];
        i++;
    }
*/

/*  GET で送られてきた文字列を出力する  */
        printf("\n"
        "=================================="
        "\n"
        "%s"
        "\n"
        "=================================="
        "\n", request_contents);

       
        printf("\n############################################################\n");


            count = 0;
            count1 = 0;
            close(sock);
            exit (0);
        }else{
            close(sock);
        }
    }
    

    close(sock_acceptance);
    return 0;
}

char *communication() {
    char head[1000000], contents[1000000];

    

    FILE *html_file = NULL;
    html_file = fopen("test.html", "r");


    char a;
    int i = 0;
    while ((a = fgetc(html_file)) != EOF) {
        contents[i] = a;
        i++;
    }
/*
    write(sock, "HTTP/1.0 200 OK\r\n", sizeof("HTTP/1.1 200 OK\r\n"));
    write(sock, "Content-Length: 20\r\n", sizeof("Content-Length: 20\r\n"));
    write(sock, "Content-Type: text/html\r\n", sizeof("Content-Type: text/html\r\n"));
    write(sock, "\r\n", sizeof("\r\n"));
    write(sock, "Hello World\r\n", sizeof("Hello World\r\n"));
*/  


    strcpy(head,"HTTP/1.1 200 OK\r\n"
	            "Content-Length: 5000\r\n"
	            "Content-Type: text/html\r\n"
	            "\r\n"
    );

    strcat(head, contents);
    strcat(head, "\r\n");

    char *Phead = &head[0];
    return Phead;
}