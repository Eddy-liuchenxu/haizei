/*************************************************************************
	> File Name: ls-2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月17日 星期二 15时33分43秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include<sys/ioctl.h>
#include <grp.h>
#include<unistd.h>

void do_ls1(char[]);
void do_ls2(char[]);
void sort_string(char strx[][100]);

int temp = 0;
char str[1002][100] = {0};
//char str1[1000][100] = {0};
//char sort_1[1002][100] = {0};
//char sort_2[1002][100] = {0};
int len = 0;
int length = 0;
int s = 0;



//判断文件类型及权限
void diction(mode_t mode){
//判断文件类型
     if(S_ISREG(mode))
        printf("-");/*普通文件*/
    else if(S_ISDIR(mode))
        printf("d");/*目录文件*/
//用户权限
    if(mode&S_IRUSR)
        printf("r");
    else
        printf("-");

    if(mode&S_IWUSR)
        printf("w");
    else
        printf("-");

    if(mode&S_IXUSR)
        printf("x");
    else
        printf("-");

//用户所属组权限
    if(mode&S_IRGRP)
        printf("r");
    else
        printf("-");

    if(mode&S_IWGRP)
        printf("w");
    else
        printf("-");

    if(mode&S_IXGRP)
        printf("x");
    else
        printf("-");

//其他权限
    if(mode&S_IROTH)
        printf("r");
    else
        printf("-");

    if(mode&S_IWOTH)
        printf("w");
    else
        printf("-");

    if(mode&S_IXOTH)
        printf("x");
    else
        printf("-");
}

int main(int argc, char *argv[]) {
       //获取屏幕宽度
    struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    length = size.ws_col;
    //选项
    int s;
    char *opt = "-al";
    if (argc == 2) {
        do_ls2(".");
    } else {
   //     while (--argc) {
           // printf("%s:\n", *++argv);
            while(1){
                s = getopt(argc,argv,opt);
                if(s == -1)
                    break;
                switch(s)
                {
                    case 'l': do_ls1(argv[2]);
                       break;
                    case 'a': do_ls2(argv[2]);
                       break;
                    default:
                       break;
                 }
            }
    //        do_ls(*argv);
    //        (argc == 1) || printf("\n");        
    //    }
    }
    return 0;
}

void id_to_string(const struct stat * get_message)
{
    struct passwd * pwd;/*根据用户id获取用户名*/
    pwd = getpwuid(get_message->st_uid);
    printf(" %s ",pwd->pw_name);

    struct group * grp;/*根据组id获取组名*/
    grp = getgrgid(get_message->st_gid);
    printf("%s ",grp->gr_name);

    printf("%ld ",get_message->st_size);/*打印所占空间文件大小*/
}

void do_ls1(char dirname[]) { //ls -l
    DIR *dirp;
    struct dirent *direntp;
    struct stat * buf = (struct stat *)malloc(sizeof(struct stat));
    if ((dirp = opendir(dirname)) == NULL) {
        perror("opendir");
        return;
    }
    while ((direntp = readdir(dirp)) != NULL) {
        if (direntp->d_name[0] == '.') continue;
        stat(direntp->d_name,buf);
        diction(buf->st_mode);
         id_to_string(buf);
        printf("  %s\n", direntp->d_name);
    }
    closedir(dirp);
    printf("\n");
}
void do_ls2(char dirname[] ){ //ls -a
    DIR *dirp;
    struct dirent *direntp;
    if((dirp = opendir(dirname)) == NULL) {
        perror("opendir");
        return;
    }
    s = 0;
    temp = 0;
    while((direntp = readdir(dirp)) != NULL) {
        sprintf(str[s],"%s",direntp->d_name);
        if(strlen(str[s]) > temp){
            temp = strlen(str[s]);
         }
        s++;
        len++;
    }
    s = 0;
    /*
    while(len--) {
        printf("%s",str[s]);
        s++;
    }*/
/*    s = 0;
    while(str[s]) {
        printf("%s",str[s]);
        s++;
    }*/
    //sort_string(str);
    while(len--){
    for(int i = 1; i <= length / temp - 1; i++) {
        if(len == 0) break;
        printf("%s",str[s]);
        int times = strlen(str[s]);
        while(times <= temp) {
            printf(" ");
            times++;
        }
            s++;
            len--;
    }
        printf("\n");
    }
    closedir(dirp);
}

/*void sort_string(char strx[][100]){
    for(int i = 0; i < sizeof(strx)/sizeof(*strx); i++) {
        for(int j = i; j < sizeof(strx)/sizeof(*strx); j++){
            if(strcmp(strx[j],strx[i])) {
                char temp[100];
                strcpy(temp,strx[j]);
                strcpy(strx[j],strx[i]);
                strcpy(strx[i],temp);
            }
        }
    }
}*/
