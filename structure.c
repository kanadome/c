#include <stdio.h>
#include <string.h>

typedef struct{
    int id, password;
    char name[5];
}user;

int main(void){

     user user1;

    user1.id = 111;
    user1.password = 111;
    strcpy(user1.name, "usr1");
    printf("\n Name : %s"
           "\n ID   : %d"
           "\n Password : %d\n\n",
           user1.name,user1.id,user1.password);

    return 0;

}