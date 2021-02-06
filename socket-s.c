#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 1992
#define ADDRESS 

int main(void){

/* sockaddr_in構造体は、接続先のIPアドレスやポート番号の情報を格納し、bindシステムコールによって、ソッケトと関連付けられる */
    struct sockaddr_in addr;
    struct sockaddr_in client;

    int sock0 = socket(AF_INET, SOCK_STREAM, 0);    /*ソッケトを作成*/

    addr.sin_family = AF_INET;                            /* アドレスファミリ */
    addr.sin_port = htons(PORT);                        /* Port 番号    ( htons は整数をネットワークバイトオーダーに変換する )   */
    addr.sin_addr.s_addr = htonl(INADDR_ANY);       /* INADDR_ANY を指定するとどのIPからの要求も受け付ける　*/
    /* htons と htonl の違いは htons は返り値が s_short , htonl は 返り値が u_long  */

    if (bind (sock0, (struct sockaddr *) &addr, sizeof (addr)) == -1){
        printf("\n Error !!!!!!!!!!!!!!!!!!!!!\n");
    }

    listen(sock0, 5);    /* 第2引数は、接続要求で待たせることができるクライアントの数      ( OSで5以下に制限される )*/
     
     unsigned int length = sizeof (client);
     int sock = accept(sock0, (struct sockaddr *)&client, &length);

    write(sock, "Hello World", sizeof("Hello World"));

    close(sock);
    close(sock0);

    return 0;
}