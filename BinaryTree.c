#include <stdio.h>
#include <stdlib.h>
// The next program represents a binary tree ejecution process
// For Unix like systems (FreeBSD,OpenBSD,Linux)
main(){
 int i,j,e,f;
 int prof = 3 // The depth of the tree - 1
 for(j=0;j < prof ; j++){
  if(fork() == 0){ // The son prints info
    printf("%d => %d\n",getppid(),getpid());
  }
  else{ // Father waits son to end and then
   wait(&e);
   printf("%d ha despertado\n",getpid()); // Wakes up
   if( fork() == 0){ // Creates the second branch (son)
     printf("%d => %d\n",getppid(),getpid()); // The son prints info
   }else{
      wait(&f); // The father waits and ...
      printf("%d ha muerto :(\n",getpid()); // Second time wakes up
      // The father deads
      exit(1);
    } // This process repeats till high rank father dead.
  }
 }

}
