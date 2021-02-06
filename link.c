#include <stdio.h>
#include <string.h>

int main(void){

    FILE *file = fopen("referenced_website.html", "a");

    char url[1001];
    char url4[100] = "</a>";
    strcpy(url4, strcat(url, url4));
    fgets(url, 1000, stdin); /*標準入力からURLを取得し、Char配列 "url" に代入*/

/* <a href='  と url をつなげて url に代入　これにより、　<a href='https://example.com     となる　*/
    char url1[100] = "<a href='";
    strcpy(url, strcat(url1, url));

    char url2[100] = "' style='color:mediumblue; font-size: 20px; text-align:center; font-family: sans-serif;'>";
    strcpy(url, strcat(url, url2));
    strcpy(url, strcat(url, url4));

    
    fputs(url, file);
    

    fclose(file);
    return 0;
}