#include "headers.h"

void replay(char copy[])
{
    char cop[100];
    strcpy(cop,copy);
    char *tokens;
    char *rests = copy;
    char **man = (char **)malloc(20 * sizeof(char *));
    int i = 0, j = 0,k=0,m=0,n=0;
    while ((tokens = strtok_r(rests, "-", &rests)))
    {
        man[i] = tokens;
        //printf("%s\n",man[i]);

        i++;
    }
    if(i!=4)
    {
        printf("incorrect input formate\n");
        return;
    }

    //printf("%d\n", i);

    char *token;
    char *rest = man[1];
    char **ma = (char **)malloc(20 * sizeof(char *));
    //char **sath = (char **)malloc(20 * sizeof(char *));
   
   
    while ((token = strtok_r(rest, " \n\t\r", &rest)))
    {
        ma[j] = token;
        //printf("%s",ma[j]);
        //sath[n]=token
        j++;
    }
    if(j==1)
    {
        printf("command not provided\n");
        return;
    }
    //printf("%d\n",j);
    char **sath=(char **)malloc(20*sizeof(char *));
    for(int g=1;g<j;g++)
    {
        sath[n]=ma[g];
        //printf("%s",sath[n]);
        n++;
    }
    char *toke;
    char *res = man[2];
    char **mans = (char **)malloc(20 * sizeof(char *));

    //tokens=strtok(token," ");

    while ((toke = strtok_r(res, " \n\t\r", &res)))
    {
        mans[k] = toke;

        k++;
        //free(tokens);
    }
    if(k!=2)
    {
        printf("incorrect input,interval not provided\n");
        return;
    }
    //printf("%d\n",k);
    int d=atoi(mans[1]);

    char *tt;
    char *rr = man[3];
    char **nan = (char **)malloc(20 * sizeof(char *));
    while ((tt = strtok_r(rr, " \n\t\r", &rr)))
    {
        nan[m] = tt;

        m++;
        
    }
    if(m!=2)
    {
        printf("incorrect input,period not provided\n");
        return;
    }
    //printf("%d %d\n",m,d);
    int o=atoi(nan[1]);
    int l=o/d;
    int w=o%d;
   // printf("%d %d\n",o,l);
    for(int q=0;q<l;q++)
    {
        //printf("JJ");
        sleep(d);
        Built_in_commands(sath[0],sath,n,cop);
    }
    sleep(w);

    free(ma);
    free(nan);
    free(mans);
    free(man);
    free(sath);
}