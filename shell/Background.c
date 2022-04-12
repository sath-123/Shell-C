#include "headers.h"

int background(char *strng, char **str, int i)
{
    if (str[i - 1][0] == '\0')
    {
        if (!strcmp(str[i - 2], "&"))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (!strcmp(str[i - 1], "&"))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void backs(char *string, char **str)
{
    int pid = fork();
    setpgid(0, 0);
    int r = 0;
    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        int s = getpid();
        if (execvp(str[0], str) < 0)
        {
            printf("\n%s : command not found\n", str[0]);
            prompt();
            fflush(stdout);

            
        }

        exit(0);
    }
    else
    {

        jobcount++;
        jobarray[jobcount].pidd = pid;
        strcpy(jobarray[jobcount].name, str[0]);
        jobarray[jobcount].jobid = jobcount;
        jobarray[jobcount].status = 1;
        printf("[%d] %d  %s\n", jobcount, pid, str[0]);
        
    }
}
void del(int s)
{
    /*for (int i = 1; i <= jobcount; i++)
    {

        if (jobarray[i].pidd == s)
        {
            // printf("job killed\n");
            //flag = 1;
            for (int j = i; j < jobcount; j++)
                jobarray[j] = jobarray[j + 1];
            //int s=jobarray[j].jobid;
            //jobarray[j].jobid=jobarray[j+1].jobid;
            //jobarray[j+1].jobid=s;
            jobcount--;
        }
    }*/
    /*int p=0;
    for (int i = 1; i <= jobcount; i++)
    {
        if(jobarray[i].status==1)
        {
           jobarray[p++]=jobarray[i];
           
        }
    }
    jobcount=p;*/
}

void checking()
{
    int pid, sam;
    pid = waitpid(-1, &sam, WNOHANG );
    int m = 0;
    if (WIFEXITED(sam))
    {

        for (int i = 1; i <= jobcount; i++)
        {

            if (jobarray[i].pidd == pid)
            {
                int pru=WEXITSTATUS(sam);
                if(pru!=0)
                //m++;
                   printf("\nProcess  %s with %d terminated \n", jobarray[i].name, pid);
                else
                  printf("\nProcess  %s with %d terminated normally\n", jobarray[i].name, pid);
                 
                     
                
                //jobarray[jobcount].status=0;
                jobarray[i].status = 0;

                prompt();
                fflush(stdout);
                del(pid);
            }
            
        }
    }
    
 }
