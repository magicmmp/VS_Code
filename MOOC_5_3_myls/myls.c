#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<sys/types.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<sys/stat.h>
//#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include <errno.h>
extern errno;

int main(int argc, char* argv[])
{
    char DirName[256];/*将被打开的文件名*/
    DIR * dir;  /*与文件名关联的目录流*/
    struct dirent *currentdp;  /*被打开目录下的一个子文件*/
    struct stat FileAttr;
    if(argc<2)
    {
        if(getcwd(DirName,256)==NULL)
        {
            perror("getcwd error!");
            printf("%s\n",strerror(errno));
            return -1;
        }
    }
    else
        strcpy(DirName,argv[1]);

    printf("DirName = %s\n",DirName);
    if((dir=opendir(DirName))==NULL)
    {
        perror("opendir error!");
        printf("%s\n",strerror(errno));
        return -1;
    }
    else 
    {
        printf("file in directory include: \n");
        while((currentdp = readdir(dir))!=NULL)
        {




            printf("%s\n",currentdp->d_name);

        }
             
    }




    



    return 0;

}