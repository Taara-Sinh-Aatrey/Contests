#include <stdio.h>
#include<string.h>
int main(){
    char s[]="hello";
    char t[]="Delhi";
    strcat(t,s);
    printf("\n%s",s);
    printf("\n%s",t);
    return 0;
}
