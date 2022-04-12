#include "headers.h"
void Built_in_cd(char *string, char **str, int i)
{
    //printf("%s",str[1]);
    /*if(i==2){

         str[1][strlen(str[1])-1] = '\0';

    }*/

    char sath[50];
    getcwd(sath,50);
    if (str[i - 1][0] == '\0')
    {
        if (str[i-1][0] != '\0')
        {
            perror("Extra commands");
        }
        else if (i == 2)
        {  
            strcpy(anotherdir,sath);
            chdir(intialdir);
        }

        else if (!strcmp(str[1], ".."))
        {
            strcpy(anotherdir,sath);
            chdir("..");
            //chdir("..");
            /*printf("%s", getcwd(intialdir, 100));
        printf("....");
        printf("%s", getcwd(intialdir, 100));
        printf("....");*/
        }
        else if (!strcmp(str[1], "."))
        {
             return;
            //chdir(intialdir);
        }
        else if (!strcmp(str[1], "~"))
        {    
            strcpy(anotherdir,sath);
            if(str[1][1]=='/')
            {
                chdir(intialdir);
                char sunny[30];
                int y=0;
                for(int i=2;i<strlen(str[1]);i++)
                {
                    sunny[y]=str[1][i];
                    y++;
                }
                
                sunny[strlen(str[1])-2]='\0';
                //printf("%s",sunny);
                chdir(sunny);
            }
            else
            {
                chdir(intialdir);
            }
        }
        else if(!strcmp(str[1],"-"))
        {
            
            printf("%s\n",anotherdir);
            chdir(anotherdir);
            strcpy(anotherdir,sath);
        }
        else if(str[1][0]=='.'&& str[1][2]=='/')
        {
            char *tokens;
            char *test=str[1];
            int m=0;
            strcpy(anotherdir,sath);
            while(tokens=strtok_r(test,"/",&test))
            {
               chdir("..");
            }
            free(tokens);
            free(test);
        }
        else
        {
            strcpy(anotherdir,sath);
            int i = chdir(str[1]);
            if (i != 0)
            {
                printf("%s :No such directory or file\n", str[1]);
            }
        }
        
    }
    else
    {
        if (i==3)
        {
            perror("Extra commands");
        }
        else if (i == 1)
        {
            strcpy(anotherdir,sath);
            chdir(intialdir);
        }

        else if (!strcmp(str[1], ".."))
        {
            //printf("%s",sath);
            strcpy(anotherdir,sath);
            chdir("..");
        }
        else if (!strcmp(str[1], "."))
        {
             return;
            //chdir(intialdir);
        }
        else if (str[1][0]=='~')
        {
            strcpy(anotherdir,sath);
            //printf("%s",currentdir);
            //chdir(intialdir);
            if(str[1][1]=='/')
            {
                chdir(intialdir);
                char sunny[30];
                int y=0;
                for(int i=2;i<strlen(str[1]);i++)
                {
                    sunny[y]=str[1][i];
                    y++;
                }
                
                sunny[strlen(str[1])-2]='\0';
                //printf("%s",sunny);
                if(sunny[0]=='\0')
                {
                    chdir(intialdir);
                    return;
                }
                if(chdir(sunny))
                {
                    printf("No such directory\n");
                    chdir(anotherdir);
                }
            }
            else
            {
                chdir(intialdir);
            }
        }
        else if(!strcmp(str[1],"-"))
        {
            
            //char s[100];

            printf("%s\n",anotherdir);
            chdir(anotherdir);
            strcpy(anotherdir,sath);
            
        }
        else if(str[1][0]=='.' && str[1][2]=='/')
        {
            char *tokens;
            char *test=str[1];
            strcpy(anotherdir,sath);
            while(tokens=strtok_r(test,"/",&test))
            {
                chdir("..");
            }
        }
        else
        {
            strcpy(anotherdir,sath);
            int i = chdir(str[1]);
            if (i != 0)
            {
                printf("%s :No such directory or file\n", str[1]);
            }
        }
    }
    //anotherdir[0]='\0';
    
    
}