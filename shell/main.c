
#include "headers.h"
#include <stdlib.h>
#include <string.h>
#define cos "\033[0;33m"

//#include<stdio.h>

int main()
{

    getcwd(intialdir,100);
    jobcount=0;
    sath=0;
    currentpid=0;
    killid=0;
    
    while (1)
    {

        //prompt();
        //currentpid=getpid();
        for_ground.pidd=-1;
        signal(SIGCHLD,checking);
        prompt();
        signal(SIGINT,ctrlC);
        signal(SIGTSTP,ctrlZ);
       
        //prompt();
        input=0;
        output=0;
        append=0;
        pos1=0;
        pos2=0;
        pos3=0;

        
        char *string;
        size_t size = 20;
        string = (char *)malloc(size);
        char **string_pointer = &string;
        int charecters = getline(string_pointer, &size, stdin);
        if(charecters==-1)
        {
            printf(cos"\nComing out of shell\n");
            exit(0);
        }

        char *token;
        char *test = string;
        char copy[100],cop[100];
        int i = 0;
        //signal(SIGCHLD,checking);

        while ((token = strtok_r(test, ";", &test)))
        {

            //printf("%d",strlen(token));
            char *tokens;
            strcpy(copy, token);
            strcpy(cop,token);
            char *rests = token;
            char **man = (char **)malloc(20 * sizeof(char *));

            //tokens=strtok(token," ");
            char s[3]={' ','\t'};

            while ((tokens = strtok_r(rests,s, &rests)))
            {
                man[i] = tokens;
                
                i++;
                //free(tokens);
            }
            
            if (man[i-1][strlen(man[i-1])-1]=='\n')
            {
                man[i-1][strlen(man[i-1]) - 1] = '\0';
            }

            int m=pipecheck(man[0],man,i);
             
            if(m!=0)
            {
                
                piping(cop,m);
            }
            else if(strcmp(man[0],"replay")==0)
            {
                replay(cop);
            }
            else{

              Built_in_commands(man[0],man,i,copy);
            
                
            }
            //printf("%d",i);
            free(man);
            i=0;
            
             
        }

        
    }
}
