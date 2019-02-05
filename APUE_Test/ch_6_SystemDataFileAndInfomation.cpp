#include<stdio.h>
#include<pwd.h>
#include<shadow.h>
#include<grp.h>
#include<sys/utsname.h>
#include<unistd.h>
#include<time.h>

using namespace std;

int main()
{
    /*6.2获取口令，根据用户名获取passwd结构*/
    struct passwd* ptr=NULL;
    ptr=getpwnam("tuhao");
    if(ptr==NULL)
    {
        perror("getpwnam error!");
        return -1;
    }
    printf("user name=%s\n",ptr->pw_name);
    printf("user passwd=%s\n",ptr->pw_passwd);
    printf("user dir=%s\n",ptr->pw_dir);
/*6.2阴影口令，根据用户名获取spwd结构,只有root用户才能权限调用该组函数*/

    struct spwd *sptr=NULL;
    sptr=getspnam("tuhao");
    if(sptr==NULL)
    {
        perror("getspwnam error!");
        return -1;
    }
    printf("user spwd=%s\n",sptr->sp_pwdp);
    
/*6.9获取主机和操作系统的信息*/
    struct utsname utsNam;
    if(uname(&utsNam)==-1)
    {
        perror("get uname error!");
        return -1;
    }
    else
    {
        printf("sysname=%s\n",utsNam.sysname);
        printf("nodename=%s\n",utsNam.nodename);
        printf("release=%s\n",utsNam.release);
        printf("version=%s\n",utsNam.version);
        printf("machine=%s\n",utsNam.machine);
        printf("domainname=%s\n",utsNam.domainname);
    }
/*6.9获取主机名*/
    char HostBuff[128];
    if(gethostname(HostBuff,sizeof(HostBuff))==-1)
    {
        perror("get gethostname error!");
        return -1;
    }
    else
    {
        printf("hostname=%s\n",HostBuff);
        printf("HOST_NAME_MAX=%d\n",_SC_HOST_NAME_MAX);
    }
/*6.10获取日期和时间*/
    time_t t;
    struct tm* tmp;
    char TimeBuff[128];
    time(&t);
    tmp=localtime(&t);
    if(strftime(TimeBuff,sizeof(TimeBuff),"time and date: %c",tmp)==0)
        printf("buffer length %d is too small.\n",sizeof(TimeBuff));
    else
        printf("%s\n",TimeBuff);

}