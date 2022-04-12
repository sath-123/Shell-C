#include "headers.h"

void jobs(int x, int y)
{

    struct jobs temparray[100];
    struct jobs temp;
    for (int i = 1; i <= jobcount; i++)
    {
        //printf("ll");
        temparray[i] = jobarray[i];
    }
    for (int i = 1; i < jobcount; i++)

    {
        //printf("pp");
        for (int j = 1 + i; j <= jobcount; j++)

        {
            //printf("oo");
            if (strcmp(temparray[i].name, temparray[j].name) > 0)
            {
                //printf("..");
                temp = temparray[i];
                temparray[i] = temparray[j];

                temparray[j] = temp;
                // printf("%s\n",temparray[j].name);
            }
            else if (strcmp(temparray[j - 1].name, temparray[j].name) == 0)
            {
                if (temparray[j - 1].jobid > temparray[j].jobid)
                {
                    temp = temparray[j - 1];
                    temparray[j - 1] = temparray[j];
                    temparray[j] = temp;
                }
            }
        }
    }

    char temp1[100];
    int size;
    char status[30], xam[30], cha[100];
    for (int i = 1; i <= jobcount; i++)
    {
        if (temparray[i].status == 1)
        {
            sprintf(temp1, "/proc/%d/stat", temparray[i].pidd);
            FILE *f = fopen(temp1, "r");
            //if(f!)
            //{
            //  temparray[i].
            //}
            fscanf(f, "%s %s %s", cha, cha, status);
            //printf("%c\n",status);
            if (x == 1 && y == 1)
            {
                if (strcmp(status, "T") == 0)
                {
                    //if (x != 0 && y == 1)
                        printf("[%d] stopped %s %d\n", temparray[i].jobid, temparray[i].name, temparray[i].pidd);
                }
                else
                {

                    //if (x == 1 && y != 0)
                        printf("[%d]  running %s %d\n", temparray[i].jobid, temparray[i].name, temparray[i].pidd);
                }
            }
            else
            {
                if (strcmp(status, "T") == 0)
                {
                    if (x == 0 && y == 1)
                        printf("[%d] stopped %s %d\n", temparray[i].jobid, temparray[i].name, temparray[i].pidd);
                }
                else
                {

                    if (x == 1 && y== 0)
                        printf("[%d]  running %s %d\n", temparray[i].jobid, temparray[i].name, temparray[i].pidd);
                }
            }
        }
    }
}

void sig(char *string, char **str, int i)
{
    if (strcmp(str[i - 1], "\0") == 0)
    {
        if (i > 4)
        {
            perror("More command passed");
            return;
        }
        if(i<4)
        {
            printf("less command\n");
            return;
        }
        int id = atoi(str[1]);
        int sig = atoi(str[2]);
        

        if (id <= jobcount && id > 0 && jobarray[id].status==1)
        {
              //printf("LLL");
                kill(jobarray[id].pidd, sig);
                //jobarray[id].status=1;
                if(sig==9)
                {
                   printf("process is killed\n");
                   jobarray[id].status=0;
                }
            
             
            
        }
        else
        {
            perror("no process found");
        }
    }
    else
    {
        if (i > 3)
        {
            perror("More command passed");
            return;
        }
        if(i<3)
        {
            printf("less commands\n");
            return;
        }
        int id = atoi(str[1]);
        int sig = atoi(str[2]);

        if (id <= jobcount && id > 0 && jobarray[id].status==1)
        {
            kill(jobarray[id].pidd, sig);
            //jobarray[id].status=1;
             if(sig==9)
             {
                 printf("process killed\n");
                jobarray[id].status=0;
             }
        }
        else
        {
            perror("no process found");
        }
    }
}
