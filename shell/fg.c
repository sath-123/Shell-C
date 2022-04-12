#include "headers.h"

void fg(char *string, char **str, int i)
{
    int stam;
    if (strcmp(str[i - 1], "\0") == 0)
    {
        if (i != 3)
        {
            perror("no proper commands");
            return;
        }

        
        int s = atoi(str[1]);
        if (s <= jobcount && jobarray[s].status == 1)
        {
            kill(jobarray[s].pidd, SIGCONT);
            printf("process entered to foreground\n");
            for_ground.pidd = jobarray[s].pidd;
            jobarray[s].status = 0;
            waitpid(for_ground.pidd, &stam, WUNTRACED);
            for_ground.pidd = -1;
        }
        else
        {
            printf("no background process found with given number\n");
        }
    }
    else
    {
        if (i !=2)
        {
            perror("inproper commands");
            return;
        }
        int s = atoi(str[1]);
        if (s <= jobcount && jobarray[s].status == 1)
        {
            kill(jobarray[s].pidd, SIGCONT);
            printf("process entered to foreground\n");
            for_ground.pidd = jobarray[s].pidd;
            jobarray[s].status = 0;
            waitpid(for_ground.pidd, &stam, WUNTRACED);
            for_ground.pidd = -1;
        }
        else
        {
            printf("no background process found with given number\n");
        }
    }
}