#include "headers.h"

void verify(char *string, char **str, int i, int out, int fds[])
{

    if (background(str[0], str, i))
    {
        str[i - 1] = '\0';
        backs(str[0], str);
    }
    else if (!strcmp(str[0], "echo"))
    {

        echo(str[0], str, i);
    }
    else if (!strcmp(str[0], "cd"))
    {

        Built_in_cd(str[0], str, i);
    }
    else if (!strcmp(str[0], "pwd"))
    {
        Built_In_Pwd(str[0], str, i);
    }
    else if (!strcmp(str[0], "ls"))
    {
        ls(str[0], str, i);
    }
    else if (!strcmp(str[0], "pinfo"))
    {
        pinfo(str[0], str, i);
    }
    else if (!strcmp(str[0], "repeat"))
    {
        repeat(str[0], str, i);
    }
    else if (!strcmp(str[0], "exit"))
    {
        printf("coming out of shell\n");
        exit(0);
    }
    else if (!strcmp(str[0], "jobs"))
    {
        //printf("jj");
        if (strcmp(str[i - 1], "\0") == 0)
        {
            if (i > 3)
            {
                perror("more commands");
            }
            else if (i == 2)
            {
                jobs(1, 1);
            }
            else if (strcmp(str[i - 2], "-r") == 0)
            {
                jobs(1, 0);
            }
            else if (strcmp(str[i - 2], "-s") == 0)
            {
                jobs(0, 1);
            }
        }
        else
        {
            if (i > 2)
            {
                perror("more commands");
                return;
            }
            else if (i == 1)
            {
                jobs(1, 1);
            }
            else if (strcmp(str[i - 1], "-r") == 0)
            {
                jobs(1, 0);
            }
            else if (strcmp(str[i - 1], "-s") == 0)
            {
                jobs(0, 1);
            }
            else
            {
                printf("incorrect input\n");
            }
        }
    }
    else if (strcmp(str[0], "gedit") == 0 || strcmp(str[0], "sleep") == 0 || strcmp(str[0], "vim") == 0 || strcmp(str[0], "emacs") == 0 || strcmp(str[0], "firefox") == 0)
    {
        if (strcmp(str[i - 1], "\0") == 0)
        {
            str[i - 1] = '\0';
        }
        else
        {
            str[i] = '\0';
        }
        foreground(str[0], str);
    }
    else if (strcmp(str[0], "sig") == 0)
    {
        sig(str[0], str, i);
    }
    else if (strcmp(str[0], "bg") == 0)
    {
        bg(str[0], str, i);
    }
    else if (strcmp(str[0], "fg") == 0)
    {
        fg(str[0], str, i);
    }
    else
    {
        if (strcmp(str[i - 1], "\0") == 0)
        {
            str[i - 1] = '\0';
        }
        else
        {
            str[i] = '\0';
        }
        int x = execvp(str[0], str);
        if (x < 0)
        {
            printf("command not found\n");
        }
    }
}
