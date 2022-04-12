#include "headers.h"

void pinfo(char *string, char **str, int i)
{
    char p[20], path[100], buffer[1000], expath[100];
    char buffer1[1000], pat[100];
    //int x=getpid();
    //int y=getppid();
    //int s;
    if (i == 1)
    {   
        
            sprintf(p, "%d", getpid());
        
       // sprintf(p, "%d", if(back==1)getpid());
        sprintf(buffer, "/proc/%s/stat", p);

        FILE *f = fopen(buffer, "r");
        if (!f)
        {
            printf("ERROR\n");
            return;
        }
        printf("pid -- %d\n", getpid());
        int size;
        char status,dis[30];
        fscanf(f, "%d %s %c", &size,dis,&status);
        //printf("pid -- %d\n", pid);
        
            printf("Process Status -- %c\n",status);
        
        
        fclose(f);
        sprintf(buffer1, "/proc/%s/statm", p);
        //char stat;
        f = fopen(buffer1, "r");

        fscanf(f, "%d", &size);
       printf("Memory--%d\n", size);

        //printf("pid -- %d\n", getpid());

        sprintf(path, "/proc/%s/exe", p);
        int m = readlink(path, pat, 1000);
        pat[m]='\0';
        printf("Executable path--%s\n", pat);
        
    }
    else if (i == 2 && str[1][0] == '\0')
    {
        sprintf(p, "%d", getpid());
        sprintf(buffer, "/proc/%s/status", p);

        FILE *f = fopen(buffer, "r");
        if (!f)
        {
            printf("ERROR\n");
            return;
        }
        printf("pid -- %d\n", getpid());
        int size;
        char status,dam[30];
        fscanf(f, "%d %s %c",&size,dam ,&status);
        
        
            printf("Process Status -- %c\n",status);
        
        //printf("Process Status -- %c",status);
       // printf("pid -- %d\n",getpid());
        fclose(f);
        sprintf(buffer1, "/proc/%s/statm", p);
        //char stat;
        f = fopen(buffer1, "r");
        fscanf(f, "%d", &size);
        printf("Memory -- %d\n", size);

        //printf("pid -- %d\n", getpid());

        sprintf(path, "/proc/%s/exe", p);
        int m = readlink(path, pat, 1000);
        pat[m]='\0';
        printf("Executable path--%s\n", pat);
    }
    else if (i == 2 && !str[1][0] == '\0')
    {
        sprintf(p, "%s", str[1]);
        sprintf(buffer, "/proc/%s/status", p);

        FILE *f = fopen(buffer, "r");
        if (!f)
        {
            printf("ERROR\n");
            return;
        }
        printf("pid -- %d\n", getpid());
        int size;
        char status,dir[30];
        fscanf(f, "%d %s %c",&size,dir, &status);
        
            printf("Process Status -- %c\n",status);
        
        //printf("Process Status--%c\n", status);
        fclose(f);
        sprintf(buffer1, "/proc/%s/statm", p);
        //char stat;
        f = fopen(buffer1, "r");
        fscanf(f, "%d", &size);
        printf("Memory--%d\n", size);

        //printf("pid -- %d\n", getpid());

        sprintf(path, "/proc/%s/exe", p);
        int m = readlink(path, pat, 1000);
        pat[m]='\0';
        printf("Executable path--%s\n", pat);
    }
}
