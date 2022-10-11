#include "xmd.h"

void cd_t(char *path){
    //获取当前工作目录
    char buf[250];
    getcwd(buf,SIZE(buf));

    //打印当前工作目录
    puts(buf);

    //改变当前工作目录
    int ret = chdir(path);
    ERROR_CHECK(ret,-1,"chdir");

    getcwd(buf,SIZE(buf));
    puts(buf);
}

void ls_t(char* dir){
    printf("%s\n",dir);
    DIR * pdir = opendir(dir);
    ERROR_CHECK(pdir,NULL,"opendir");

    //读目录流
    struct dirent * pdirent;
    errno = 0;
    while((pdirent = readdir(pdir)) != NULL){
        char * name = pdirent->d_name;
        if(name[0] == '.'){
            continue;
        }
        printf("%s",name);
        printf("\n");
    }
    printf("\n");

    //错误处理
    if(errno != 0){
        perror("readdir");
        closedir(pdir);
        exit(1);
    }

    closedir(pdir);
}

void getcwd_t(void){
    char * cwd = getcwd(NULL,0);
    ERROR_CHECK(cwd,NULL,"getcwd");

    puts(cwd);

    free(cwd);
}
