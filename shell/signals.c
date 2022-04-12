#include "headers.h"

void ctrlC(int signal)
{
    
    if (for_ground.pidd == -1)
    {
        printf("\nNo foreground process present\n");
        if (currentpid != 1)
        {
            prompt();
            fflush(stdout);
        }
        currentpid=0;
    }
    else
    {
        kill(for_ground.pidd, SIGINT);
    }
    
}

void ctrlZ(int signa)
{
     if(for_ground.pidd==-1)
     {
        printf("\nNo foreground process present\n");
          prompt();
        fflush(stdout);
        
     }
     else
     {
        
         jobcount++;
         jobarray[jobcount].pidd=for_ground.pidd;
         strcpy(jobarray[jobcount].name,for_ground.name);
         jobarray[jobcount].jobid=jobcount;
         jobarray[jobcount].status=1;
         kill(for_ground.pidd,signa);
         for_ground.pidd=-1;
         strcpy(for_ground.name,"");
        
         
     }
}

