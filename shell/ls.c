#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include "headers.h"

//char  **directory=(char *)malloc()

void lss(char *dir, int x, int y)
{
    
    struct stat sam;
    int exist = stat(dir, &sam);

    
    
        if (x == 1)
        {
            printf("%s\n", dir);
        }
        else if (x == 3 || x == 2)
        {
            if (S_ISREG(sam.st_mode))
                printf("-");
            else if (S_ISDIR(sam.st_mode))
                printf("d");
            else if (S_ISCHR(sam.st_mode))
                printf("c");
            else if (S_ISBLK(sam.st_mode))
                printf("b");
            else if (S_ISFIFO(sam.st_mode))
                printf("f");
            else if (S_ISLNK(sam.st_mode))
                printf("l");
            else
                printf("s");

            printf("%c", ((sam.st_mode & S_IRUSR) ? 'r' : '-'));
            printf("%c", ((sam.st_mode & S_IWUSR) ? 'w' : '-'));

            printf("%c", ((sam.st_mode & S_IXUSR) ? 'x' : '-'));

            printf("%c", ((sam.st_mode & S_IRGRP) ? 'r' : '-'));

            printf("%c", ((sam.st_mode & S_IWGRP) ? 'w' : '-'));

            printf("%c", ((sam.st_mode & S_IXGRP) ? 'x' : '-'));

            printf("%c", ((sam.st_mode & S_IROTH) ? 'r' : '-'));

            printf("%c", ((sam.st_mode & S_IWOTH) ? 'w' : '-'));
            printf("%c", ((sam.st_mode & S_IXOTH) ? 'x' : '-'));
            printf(" ");
            printf("%3.ld ", sam.st_nlink);
            struct passwd *pw = getpwuid(sam.st_uid);
            struct group *gr = getgrgid(sam.st_gid);
            printf("%s %s ", pw->pw_name, gr->gr_name);
            printf("%7.ld ", sam.st_size);
            char time[16];
            strftime(time, 16, "%b %2d  %I:%M", localtime(&(sam.st_ctime)));
            printf("%s ", time);

            //printf("%s ",status.st_mtim);
            printf("%s", dir);
            //free(sam);
            printf("\n");
        }
        return;
    
}
    //struct dirent *s;
    //DIR *pointer=opendir(dir);
    



void ls(char *string, char **str, int i)
{

    char **directory = (char **)malloc(100 * sizeof(char *));
    int s = 0;

    if (str[i - 1][0] == '\0')
    {
        //printf(" ...");
        if (i == 2)
        {
            lssdir(".", 1, 0);
        }
        
        else
        {

            int p = 0;
            int r = 0;
            int y = 0;
            int g = 0;
            for (int j = 2; j <= i - 1; j++)
            {
                if (str[j - 1][0] == '-')
                {
                    if (!strcmp(str[j - 1], "-l"))
                    {
                        p++;
                    }
                    else if (!strcmp(str[j - 1], "-a"))
                    {
                        r++;
                    }
                    else if (!strcmp(str[j - 1], "-al"))
                    {
                        y++;
                    }
                    else if (!strcmp(str[j - 1], "-la"))
                    {
                        g++;
                    }
                }
                else
                {
                    directory[s] = str[j - 1];
                    s++;
                }
            }
            if (s == 0)
            {
                if (y > 0 || g > 0)
                    lssdir(".", 3, 0);
                else if (p > 0)
                {
                    lssdir(".", 2, 0);
                }
                else if (p = 0 && r > 0)
                {
                    lssdir(".", 1, 0);
                }
            }
            else
            {

                 for (int h = 0; h < s; h++)
                {

                    struct stat sam;
                    int exist = stat(directory[h], &sam);
                    if (!exist)
                    {

                        

                        if (y > 0 || g > 0)
                            lss(directory[h], 3, 0);
                        else if (p > 0)
                        {
                            lss(directory[h], 2, 0);
                        }
                        else if (p == 0 && r > 0)
                        {
                            lss(directory[h], 1, 0);
                        }
                        else if (p == 0 && y == 0 && g == 0 && r == 0)
                        {
                            lss(directory[h], 1, 0);
                        }
                        
                    }
                    else
                    {
                        //printf("%s:\n", directory[h]);

                        if (y > 0 || g > 0)
                            lssdir(directory[h], 3, 0);
                        else if (p > 0)
                        {
                            lssdir(directory[h], 2, 0);
                        }
                        else if (p == 0 && r > 0)
                        {
                            lssdir(directory[h], 1, 0);
                        }
                        else if (p == 0 && y == 0 && g == 0 && r == 0)
                        {
                            lssdir(directory[h], 1, 0);
                        }
                        if (h != s - 1)
                        {
                            
                                printf("\n");
                        }
                    }
                
                }

            }
        }
        free(directory);

    }
    else
    {
        //printf("nnn");
        if (i == 1)
        {
            lssdir(".", 1, 0);
        }
        /*else if (i == 2)
        {
            int x;
            int y;
            //argv[3][2]='\0';
            //printf("%s",argv[2]);
            if (str[1][0] == '-')
            {
                if (!strcmp(str[1], "-l"))
                {
                    x = 2;
                }
                else if (!strcmp(str[1], "-a"))
                {
                    x = 1;
                }
                else if (!strcmp(str[1], "-al"))
                {
                    x = 3;
                }
                else if (!strcmp(str[1], "-la"))
                {
                    x = 3;
                }
                //printf("%d", x);

                lss(".", x, y);
            }
            x = 0;
        }*/
        else
        {

            int p = 0;
            int r = 0;
            int y = 0;
            int g = 0;
            for (int j = 2; j <= i; j++)
            {
                if (str[j - 1][0] == '-')
                {
                    if (!strcmp(str[j - 1], "-l"))
                    {
                        p++;
                    }
                    else if (!strcmp(str[j - 1], "-a"))
                    {
                        r++;
                    }
                    else if (!strcmp(str[j - 1], "-al"))
                    {
                        y++;
                    }
                    else if (!strcmp(str[j - 1], "-la"))
                    {
                        g++;
                    }
                }
                else
                {
                    directory[s] = str[j - 1];
                    s++;
                }
            }
            //printf("%d %d %d %d ", p, r, y, g);
            if (s == 0)

            {
                if (y > 0 || g > 0)
                    lssdir(".", 3, 0);
                else if (p > 0)
                {
                    lssdir(".", 2, 0);
                }
                else if (p == 0 && r > 0)
                {
                    lssdir(".", 1, 0);
                }
            }
            else
            {
                int h;
                for ( h = 0; h < s; h++)
                {

                    struct stat sam;
                    int exist = stat(directory[h], &sam);
                    if (!S_ISDIR(sam.st_mode)&&!exist && directory[h][0]!='.'&& directory[h][0]!='~')
                    {

                        
                        


                        if (y > 0 || g > 0)
                            lss(directory[h], 3, 0);
                        else if (p > 0)
                        {
                            lss(directory[h], 2, 0);
                        }
                        else if (p == 0 && r > 0)
                        {
                            lss(directory[h], 1, 0);
                        }
                        else if (p == 0 && y == 0 && g == 0 && r == 0)
                        {
                            lss(directory[h], 1, 0);
                        }
                        //free(directory[h]);
                        
                    }
                    else
                    {
                        //printf("%s:\n", directory[h]);

                        

                        if (y > 0 || g > 0)
                            lssdir(directory[h], 3, 0);
                        else if (p > 0)
                        {
                            lssdir(directory[h], 2, 0);
                        }
                        else if (p == 0 && r > 0)
                        {
                            lssdir(directory[h], 1, 0);
                        }
                        else if (p == 0 && y == 0 && g == 0 && r == 0)
                        {
                            lssdir(directory[h], 1, 0);
                        }
                        if (h != s - 1)
                        {
                            
                                printf("\n");
                        }
                        //free(directory[h]);
                    }
                }
            }
        }
       free(directory);
    }
}