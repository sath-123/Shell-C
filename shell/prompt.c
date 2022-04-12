#define color "\033[0;32m"
#define colors "\033[0;34m"
#define colo "\033[0;37m"

#include "headers.h"
#include "sys/utsname.h"
#include<string.h>
#include<unistd.h>
int i=0;

void prompt() {
    
    
    struct passwd* user=getpwuid(getuid());
    printf(color"%s"colo,user->pw_name);
    printf(color"@"colo); 
    char host[100];
    int hostname=gethostname(host,sizeof(host));
    strcat(host,":");
    printf(color"%s"colo,host);
   getcwd(currentdir,100);
   //printf("%s\n",currentdir);
   //printf("%d\n",strlen(intialdir));
  if(strlen(currentdir)>strlen(intialdir))
   {
       printf(colors"~"colo);
       //char *s=cdir;
       //*s++='~';
       for(int i=strlen(intialdir);currentdir[i]!='\0';i++)
       {
           
           ////s++=currentdir[i];
           printf(colors"%c"colo,currentdir[i]);
          
       }
       //*s='\0';
       printf(colors">"colo);
   }
   else if (strcmp(intialdir,currentdir)==0)
   {
       //printf("hhh");
       printf(colors"~>"colo);
   }
   else
   {
       //printf("kkk");
       printf(colors"~%s>"colo,currentdir);
       
   }
    
}
