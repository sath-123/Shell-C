#include "headers.h"

void repeat(char *string, char **str, int x)
{
     currentpid=1;
    char **tokens = (char **)malloc(100 * sizeof(char *));
    int y = 0;

    if (strcmp(str[x - 1], "\0") == 0)
    {
        int p = atoi(str[1]);
        for (int i = 2; i < x - 1; i++)
        {
            tokens[y] = str[i];
            //printf("%s ",tokens[y]);
            y++;
        }
        tokens[y] = '\0';
        for (int s = 0; s < p; s++)
        {
            int pid = fork();
            if (pid == 0)
            {
                
                int r = execvp(tokens[0], tokens);
                if(r<0)
                {
                    printf("command not found\n");
                }
                 
                exit(0);
            }
            else
            {
                wait(NULL);
            }
        }
    }
    else
    {
        int p = atoi(str[1]);
        for (int i = 2; i < x; i++)
        {
            tokens[y] = str[i];
            //printf("%s ",tokens[y]);
            y++;
        }
        tokens[y] = '\0';
        for (int s = 0; s < p; s++)
        {

            int pid = fork();
            if (pid == 0)
            {
                int r = execvp(tokens[0], tokens);

                 if(r<0)
                 {
                     printf("command not found\n");
                 }
                exit(0);
            }
            else
            {
                wait(NULL);
            }
        }
    }

    /* if(!strcmp(str[2],"echo"))
    {    
        //
        //int s=str[1][0]-'0';
        int s=atoi(str[1]);
         for(int i=0;i<s;i++)
         {
            ech(str[0],str,x);
         }
        //free(tokens);
    }
    else
    {
        int p=atoi(str[1]);
        for(int i=2;i<x;i++)
        {
           tokens[y]=str[i];
           //printf("%s ",tokens[y]);
           y++;
        }
        tokens[y]='\0';
        int pid=fork();
        if(pid==0)
        {
            for(int s=0;s<p;s++)
            {
                int x=execvp(tokens[0],tokens);
            }
            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }
    /*else if(!strcmp(str[2],"pwd"))
    {
        int p=str[1][0]-'0';
        for(int i=2;i<x;i++)
        {
           tokens[y]=str[i];
           //printf("%s ",tokens[y]);
           y++;
        }
        //printf("%d",y);
        for(int i=0;i<p;i++)
        {
            Built_In_Pwd(tokens[0],tokens,y);
        }
    }
    else if(!strcmp(str[2],"cd"))
    {
        int m=str[1][0]-'0';
        for(int i=2;i<x;i++)
        {
           tokens[y]=str[i];
           //printf("%s ",tokens[y]);
           y++;
        }
        //printf("%d",y);
        for(int i=0;i<m;i++)
        {
            //Built_in_cd(tokens[0],tokens,y);
            int s=execvp(tokens[0],tokens);
        }
    }
    else if(!strcmp(str[2],"ls"))
    {
        int p=str[1][0]-'0';
        for(int i=2;i<x;i++)
        {
           tokens[y]=str[i];
           //printf("%s ",tokens[y]);
           y++;
        }
        //printf("%d",y);
        for(int i=0;i<p;i++)
        {
            
            ls(tokens[0],tokens,y);
        }
    }
    else if(!strcmp(str[2],"sleep"))
    {
        int p=str[1][0]-'0';
        int c=str[3][0]-'0';
        for(int i=0;i<p;i++)
        {
            int f=sleep(c);
            //int s=execp(str[0])
        }
    }*/
    free(tokens);
    //free(str);
}