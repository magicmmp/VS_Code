#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
extern char** environ;
int main()
{
/*7.9遍历整个环境变量表*/
    char**Env=environ;
    /*
    while(Env++)
        printf("%s\n",*Env);
    */
/*7.9获取、更改某个环境变量值*/
    printf("USER=%s\n",getenv("USER"));
    setenv("USER","Pss",1);
    printf("USER=%s\n",getenv("USER"));


}