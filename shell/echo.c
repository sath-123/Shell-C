#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <string.h>

void echo(char *string, char **str, int x)
{
    

    

        for (int i = 1; str[i] != NULL && i<x; i++)
        {
            printf("%s ", str[i]);
            /*if (i != x - 1)
            {
                printf(" ");
            }*/
        }
        printf("\n");
}

void ech(char *string, char **str, int x)
{
    

    

        for (int i = 3; str[i] != NULL ; i++)
        {
            printf("%s ", str[i]);
            /*if (i != x - 1)
            {
                printf(" ");
            }*/
        }
        printf("\n");
}