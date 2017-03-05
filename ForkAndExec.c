#include <stdio.h>
#include <stdlib.h>
// A son that makes an exec :)
main(){
 int e;
 if(fork() == 0){ // The son will executing this line
   // Beacuse of fork returns 0
   printf("The son will make a exec \n");
   printf("Showing files and directories\n");
   execl("/bin/ls","ls","-l",(char*)0);
   exit(1);
 }else{
    wait(&e);
    printf("Goodbye\n"); // Fathers kills process
    exit(1);
    printf("Waba Laba dap dap"); //This line never runs
  }
}
