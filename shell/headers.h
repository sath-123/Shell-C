#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<sys/wait.h>
#include<fcntl.h>
#ifndef __HEADER_H
#define __HEADER_H


char intialdir[100];
char anotherdir[100];
char currentdir[100];
char *history[20];
int historycount;
int back;
int sath;
int currentpid;

typedef struct jobs{
    char name[100];
    int pidd;
    int jobid,status;
} job;
int jobcount;
struct jobs jobarray[100];
struct jobs for_ground;
struct jobs current;
int input,output,append,pos1,pos2,pos3;
int killid;

void Built_In_Pwd(char *string,char **str,int i);
void Built_in_commands(char *string,char **str,int i,char copy[]);
void echo(char *string,char **ptrs,int i);
void Built_in_cd(char *string,char **str,int i );
void ls(char *string,char **str,int i);
void permission(char *str);
void repeat(char *string,char ** str,int i);
void ech(char *string,char **str,int i);
void lssdir(char *dir,int x,int y);
void pinfo(char *string ,char **str,int i);
int background(char *string,char **str,int i);
void foreground(char *string,char **str);
void prompt();
void backs(char *string,char **str);
void checking();
int redircheck(char *string,char **str,int i);
void redirection(char copy[]);
void verify(char *string,char **str,int i,int out,int fds[]);
int pipecheck(char *string,char **str,int i);
void piping(char cop[],int i);
void ctrlC(int signal);
void ctrlZ(int signal);
void jobs(int x,int y);
void sig(char *string,char **str,int i);
void bg(char *string,char **str,int i);
void del(int s);
void fg(char *string,char **str,int i);
void replay(char copy[]);


#endif



