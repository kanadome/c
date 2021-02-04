#include "include.c"
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

#define PORT 1992

int main(){

    struct sockaddr_in addr;
    struct sockaddr_in client;

    int sock0 = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    unsigned int addr_len = sizeof(addr);
    bind (sock0, &addr, addr_len);
}