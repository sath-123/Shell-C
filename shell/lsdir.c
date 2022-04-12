#include "headers.h"

void lssdir(char *dir,int x,int y)
{

    if(!strcmp(dir,"~"))
    {
        dir=intialdir;
    }
    

    int p = 0;
    struct dirent *m;
    DIR *pointer = opendir(dir);

    //struct stat sam;
    //int exist = stat(dir, &sam);

    if (!pointer)

    {
        printf("no such directory or file\n");
        return;
    }
    else
    {
        printf("%s:\n",dir);
    }
    while ((m = readdir(pointer)) != NULL)
    {

        if (x == 2)
        {
            if (m->d_name[0] == '.')
                continue;
            char *suffer = (char *)malloc(100 * sizeof(char));
            suffer[0]='\0';
            strcat(suffer, dir);
            strcat(suffer, "/");
            strcat(suffer, m->d_name);
            //printf("%s\n",m->d_name);
            struct stat stt;
            stat(suffer, &stt);
            //printf("%d \n",stt.st_blocks);
            p = p + stt.st_blocks;
            free(suffer);
        }
        else if (x == 3)
        {

            char *suffer = (char *)malloc(100 * sizeof(char));
            suffer[0]='\0';
            strcat(suffer, dir);
            strcat(suffer, "/");
            strcat(suffer, m->d_name);
            struct stat stt;
            stat(suffer, &stt);
            p = p + stt.st_blocks;
            free(suffer);
        }
        //printf("total %d\n",p/2);
        //p=0;
    }
    //free(suffer)
    if (x != 1)
    {
        printf("total %d\n", p / 2);
        p = 0;
    }
    int s=closedir(pointer);

    //int s=closedir(dir);
    struct dirent *d;

    DIR *pointertodir = opendir(dir);

    if (x == 1)

    {

        while ((d = readdir(pointertodir)) != NULL)
        {
            if (d->d_name[0] == '.')
                continue;

            printf("%s\n", d->d_name);
        }
    }
    else if (x == 3)
    {
        while ((d = readdir(pointertodir)) != NULL)
        {
            char *buffer = (char *)malloc(100 * sizeof(char));

            strcat(buffer, dir);
            strcat(buffer, "/");
            strcat(buffer, d->d_name);
            struct stat status;
            stat(buffer, &status);
            if (S_ISREG(status.st_mode))
                printf("-");
            else if (S_ISDIR(status.st_mode))
                printf("d");
            else if (S_ISCHR(status.st_mode))
                printf("c");
            else if (S_ISBLK(status.st_mode))
                printf("b");
            else if (S_ISFIFO(status.st_mode))
                printf("f");
            else if (S_ISLNK(status.st_mode))
                printf("l");
            else
                printf("s");

            printf("%c", ((status.st_mode & S_IRUSR) ? 'r' : '-'));
            printf("%c", ((status.st_mode & S_IWUSR) ? 'w' : '-'));

            printf("%c", ((status.st_mode & S_IXUSR) ? 'x' : '-'));

            printf("%c", ((status.st_mode & S_IRGRP) ? 'r' : '-'));

            printf("%c", ((status.st_mode & S_IWGRP) ? 'w' : '-'));

            printf("%c", ((status.st_mode & S_IXGRP) ? 'x' : '-'));

            printf("%c", ((status.st_mode & S_IROTH) ? 'r' : '-'));

            printf("%c", ((status.st_mode & S_IWOTH) ? 'w' : '-'));
            printf("%c", ((status.st_mode & S_IXOTH) ? 'x' : '-'));
            printf(" ");
            printf("%3.ld ", status.st_nlink);
            struct passwd *pw = getpwuid(status.st_uid);
            struct group *gr = getgrgid(status.st_gid);
            printf("%s %s ", pw->pw_name, gr->gr_name);
            printf("%7.ld ", status.st_size);
            char time[16];
            strftime(time, 16, "%b %2d  %I:%M", localtime(&(status.st_ctime)));
            printf("%s ", time);

            //printf("%s ",status.st_mtim);
            printf("%s", d->d_name);
            free(buffer);
            printf("\n");
        }
    }
    else if (x == 2)
    {
        while ((d = readdir(pointertodir)) != NULL)
        {
            if (d->d_name[0] == '.')
                continue;
            else
            {
                char *buffer = (char *)malloc(110 * sizeof(char));
                //char buffer[1000];
                buffer[0]='\0';

                strcat(buffer, dir);
                strcat(buffer, "/");
                strcat(buffer, d->d_name);
                struct stat status;
                stat(buffer, &status);
                if (S_ISREG(status.st_mode))
                    printf("-");
                else if (S_ISDIR(status.st_mode))
                    printf("d");
                else if (S_ISCHR(status.st_mode))
                    printf("c");
                else if (S_ISBLK(status.st_mode))
                    printf("b");
                else if (S_ISFIFO(status.st_mode))
                    printf("f");
                else if (S_ISLNK(status.st_mode))
                    printf("l");
                else
                    printf("s");

                printf("%c", ((status.st_mode & S_IRUSR) ? 'r' : '-'));
                printf("%c", ((status.st_mode & S_IWUSR) ? 'w' : '-'));

                printf("%c", ((status.st_mode & S_IXUSR) ? 'x' : '-'));

                printf("%c", ((status.st_mode & S_IRGRP) ? 'r' : '-'));

                printf("%c", ((status.st_mode & S_IWGRP) ? 'w' : '-'));

                printf("%c", ((status.st_mode & S_IXGRP) ? 'x' : '-'));

                printf("%c", ((status.st_mode & S_IROTH) ? 'r' : '-'));

                printf("%c", ((status.st_mode & S_IWOTH) ? 'w' : '-'));
                printf("%c", ((status.st_mode & S_IXOTH) ? 'x' : '-'));
                printf(" ");
                printf("%3.ld ", status.st_nlink);
                struct passwd *pass = getpwuid(status.st_uid);
                struct group *gr = getgrgid(status.st_gid);
                printf("%s %s ", pass->pw_name, gr->gr_name);
                //printf("%ld ",status.st_nlink);
                printf("%7.ld ", status.st_size);
                char time[16];
                strftime(time, 16, "%b %2d  %I:%M", localtime(&(status.st_ctime)));
                printf("%s ", time);

                //printf("%s ",status.st_mtim);

                printf("%s", d->d_name);
                free(buffer);
                printf("\n");
            }
        }
    }
}

