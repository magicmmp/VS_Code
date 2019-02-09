#include<stdio.h>

using namespace std;
extern char **environ;

int main(int argc,char*argv[])
{
    int i;
    char **ptr;
    
    for(i=0;i<argc;i++)
        printf("argv[%d]: %s\n",i,argv[i]);
    printf("\n");
    printf("Hello this is echoall\n");
    
    return 0;

}