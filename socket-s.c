#include "include.c"
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

int main(void){

    int socket_d = socket(AF_INET, SOCK_STREAM, 0);
    
    
    return 0;
}