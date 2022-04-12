#include "headers.h"

void foreground(char *string,char **str)
{
    int pid=fork();
    for_ground.pidd=pid;
    strcpy(for_ground.name,str[0]);
   int s=0;
    if(pid<0)
    {
        printf("Fork failed\n");
    }
    else if(pid ==0)
    {
        if(execvp(str[0],str)<0)
        {
            printf("%s : command not found ,not a foreground process\n",str[0]);
            s++;
            return;
        }
        exit(0);
    }
    else
    {
       int stat;
       waitpid(pid,&stat,WUNTRACED);
       
       
    }

    
}