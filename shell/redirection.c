#include "headers.h"

int redircheck(char *string, char **str, int i)
{
    //printf("...");
    for (int j = 0; j < i; j++)
    {
        if (strcmp(str[j], "<") == 0)
        {
            input++;
            pos1=j;
        }
        else if (strcmp(str[j], ">") == 0)
        {
            output++;
            pos2=j;
        }
        else if (strcmp(str[j], ">>") == 0)
        {
            append++;
            pos3=j;
        }
    }
   // printf("%d %d %d\n", input, output, append);
    if (input >0 || output >0 || append >0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void redirection(char copy[])
{
    
    int fds[2] = {-1, -1};
    char delimiter[5], outfile[100], *temp[10], out[100], infile[100], *temp2[10], in[100];
    in[0] = '\0';
    //strcpy(in,"");
    out[0] = '\0';

    //if()
    if (append > 0)
    {
        strcpy(delimiter, ">>");
    }
    else
    {
        strcpy(delimiter, ">");
    }
    char *tokens;
    char *rests = copy;
    char **man = (char **)malloc(20 * sizeof(char *));
    //man[0]='\0';
    int i = 0;
    while ((tokens = strtok_r(rests, delimiter, &rests)))
    {
        man[i] = tokens;

        i++;
    }
    //printf("%d",i);
    if (i == 2 || i>2)
    {
        strcpy(outfile, man[i-1]);
        temp[0] = strtok(outfile, " \t\n\r");
        strcpy(out, temp[0]);
        //printf("%s",out);
    }
    
    char *token;
    //strcpy(copy, token);
    char *rest = man[0];
    char **mans = (char **)malloc(20 * sizeof(char *));
    int k = 0;
    while ((token = strtok_r(rest, "<", &rest)))
    {
        mans[k] = token;
        k++;
    }
    char *toke;
    char *res = mans[0];
    char **ma = (char **)malloc(20 * sizeof(char *));
    //make
    //ma[0]='\0';
    int p = 0;
    while ((toke = strtok_r(res, " \n\r\t", &res)))
    {
        ma[p] = toke;

        p++;
    }
    ma[p]='\0';
    //eprintf("%d\n", k);
    if (k == 2 || k>2)
    {
        strcpy(infile, mans[k-1]);
        temp2[0] = strtok(infile, " \t\n\r");
        strcpy(in, temp2[0]);
        //printf("%s\n",in);
    }
    

    int oldout, oldin;
    if (in[0] == '\0' && out[0] != '\0')
    {
        //printf("enters out\n");
        oldout = dup(1);
        //fds[0]=open(out,O_RDONLY);
        //printf("%d\n", append);
        if (append == 0)
        {
            fds[1] = open(out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
        }
        else
        {
            fds[1] = open(out, O_APPEND | O_WRONLY | O_CREAT, 0644);
        }
        dup2(fds[1], 1);
        
    }

    else if (in[0] != '\0' && out[0] == '\0')
    {
        //printf("enters input\n");
        oldin = dup(0);
        fds[0] = open(in, O_RDONLY);
        if (fds[0] == -1)
        {
            printf("No such file existed\n");
            return;
        }
        dup2(fds[0], 0);
        
    }
    else
    {   
        
        oldin=dup(0);
        oldout=dup(1);
        //int pid=fork();
        if (append == 0)
        {
            fds[1] = open(out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
        }
        else
        {
            fds[1] = open(out, O_APPEND | O_WRONLY | O_CREAT, 0644);
        }
        fds[0]=open(in,O_RDONLY);
        if(fds[0]==-1)
        {
            printf("file not existed\n");
        }
        dup2(fds[0],0);
        dup2(fds[1],1);
        
       

    }
    int pid=fork();

    if(pid<0)
    {
        close(fds[1]);
        close(fds[0]);
        printf("fork failed\n");
        return;
    }
    else if (pid==0)
    {
        verify(man[0],ma,p,oldout,fds);
        exit(0);
    }
    else
    {
        wait(NULL);
       
        dup2(oldin,0);
        dup2(oldout,1);
        close(fds[0]);
        close(fds[1]);
    }
    

    
    free(man);
    free(mans);
    free(ma);
}