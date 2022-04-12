#include "headers.h"

int pipecheck(char *string, char **str, int i)
{
    int s = 0;
    for (int j = 0; j < i; j++)
    {
        if (strcmp(str[j], "|") == 0)
        {
            s++;
        }
    }
    if (s == 0)
    {
        return 0;
    }
    else
    {
        return s;
    }
}

void piping(char cop[], int i)
{   
    char copy[100];
    char *tokens;
    char *rests = cop;
    int j=0;
    int pds[2],standin,standout;
    standin=dup(0);
    standout=dup(1);
    

    while ((tokens = strtok_r(rests, "|", &rests)))
    {
        
        if(j==0)
        {
            pipe(pds);
            dup2(pds[1],1);
            close(pds[1]);
        }
        else if(j==i)
        {
            //pipe(pds);
            dup2(pds[0],0);
            close(pds[0]);
        }
        else 
        {
            dup2(pds[0],0);
            close(pds[0]);
            pipe(pds);
            dup2(pds[1],1);
            close(pds[1]);
        }
        

        int pid=fork();

        if(pid<0)
        {
            dup2(standin,0);
            dup2(standout,1);
            return;
        }
        else if(pid==0)
        {
            
            char *token;
            strcpy(copy,tokens);
            char *rest = tokens;
            char **mans = (char **)malloc(100 * sizeof(char *));

            int m=0;

            while ((token = strtok_r(rest," \n\r\t", &rest)))
            {
                mans[m] = token;
                
                m++;
                
            }
            mans[m]='\0';
            int o=redircheck(mans[0],mans,m);
            if(o==1)
            {
                redirection(copy);
            }
            else
            {
                
                int r=execvp(mans[0],mans);
                if(r<0)
                {
                    printf("command not found\n");
                }
            }
            free(mans);
            exit(0);
        }
        else
        {
            wait(NULL);
            dup2(standin,0);
            dup2(standout,1);
        }

        j++;
        
        
    }
   
}