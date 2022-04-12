#include "headers.h"

void bg(char *string,char **str,int i)
{
    if(strcmp(str[i-1],"\0")==0)
    {
        if(i>3)
        {
            perror("more commans");
            return;
        }
        if(i<3)
        {
            printf("less commands\n");
            return;
        }
        int id=atoi(str[1]);
        int m=0;
        if(id<=jobcount && id>0)
        {
            if(jobarray[id].status==1)
            {
                m++;
                kill(jobarray[id].pidd,SIGCONT);
            }
        }
        //else
        //{
        if(m==0){
            perror("No background process present");
        }
    }
    else
    {
        if(i>2)
        {
            perror("more commands");
            return;
        }
        if(i<2)
        {
            printf("less commands\n");
            return;
        }
        int id=atoi(str[1]);
        int m=0;
        if(id<=jobcount && id>0)
        {
            if(jobarray[id].status==1)
            {
               // printf("ll");
               m++;
                kill(jobarray[id].pidd,SIGCONT);
                jobarray[id].status=1;
                
            }
        }
        //else
        //{
        if(m==0){
            perror("No background process present");
        }
    }
}