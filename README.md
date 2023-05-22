main.c :
    This file split the commands by ; and checks if there are build in commands are not .
prompt.c :
     to print the prompt 
echo.c:
    this file is to execute echo command
pwd.c :
    this file is to execute pwd command

ls.c :
    it will implemnt ls commands for only singal file

pinfo.c :
    implementation of pinfo

Built.c :
   to check if given commands are build in

 background.c :
   to check if it is background are not
foreground.c :
  if is a foreground process ,it will execute the process

headers.h :

     contains all header files and function declaration

lsdir.c :
   to implemt ls for directories

repeat.c :
   implementation of repeat command

cd.c :
  implementation of cd
fg.c :
  implementation of fg command and through error if command is given like fg,fg 2 2
bg.c :
   implementation of bg command and throw error if command is given like bg,bg 2 3
jobs.c :
  contains implementation of jobs,sig commands
  jobs----throw error if commands are given like jobs (any character other than -r and -s),jobs (-r,-s) some character.
  sig---throws error if no of commands less than 3 and greater than 3

Redirection.c :
  implemnetation of redirections
verify.c :
   this contains all comparions between implemented commands and execute redirections according to command
piping.c :
  implementation of pipe commands
signals.c :
  implementation of ctrl+z and ctrl+c

xtra.c :
  implementation of replay command(xtra)

headers.h :
  all funtions declaration and declaration of global variables.

shell will exit in 2 ways
->exit 
->ctrl+D

->The shell  will tokenize the commands based on ; delimiter
and execute each one.
-> I assumed that there will be no more than 20 arguments in a single command
->Also no more than 20 commands can be given at a time with ; this
->I have considered that if any background process is terminated then ,if other process is entered then the number assigned to that process is just greater than 1 of background process which is terminated.

For execution of shell:
-> make
->./a.out



