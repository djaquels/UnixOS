#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
// A tee with pipes
// We know that
/*
 0-> STDIN
 1-> STDOUT
 2-> STDERR
*/

int e;
int main(){
 int log = open("mylog.txt",  O_WRONLY | O_APPEND); // My log file
// my pipe
 int mypipe[2];
  pipe(mypipe);
 // we made a fork
 if(fork() == 0){
    // The son log to a file
    close(mypipe[0]); // Close reading;
    dup2(mypipe[1],1);// redirect stdout to file
    execle("/usr/bin/who","who",NULL,NULL);
    
 }else{
   wait(&e);
   close(mypipe[0]); // Close writing
   dup2(1,mypipe[1]); // We go back to normal output
   
  //execle("/usr/bin/wc","wc",mypipe[0],NULL);
   
   
 } 
 return 0;
}
