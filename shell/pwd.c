#include "headers.h"

void Built_In_Pwd(char *string, char **str, int x)
{
    //printf("%c",str[1][0]);

    if (x == 1)
    {
        char *space = (char *)malloc(100 * sizeof(char));
        if (!space)
        {
            perror("Memory error");
        }

        printf("%s\n", getcwd(space, 100));
        free(space);
    }
    else
    {
        if (str[1][0] == '\0')
        {

            char *space = (char *)malloc(100 * sizeof(char));
            if (!space)
            {
                perror("Memory error");
            }
            printf("%s\n", getcwd(space, 100));
            free(space);
        }

        else
        {

            perror("to many arguments");
        }
    }
}
