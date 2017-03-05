#include <stdio.h>
#include <stdlib.h>

main(){
 int i,j,e,f;
 for(j=0;j < 3; j++){
  if(fork() == 0){
    printf("%d => %d\n",getppid(),getpid());
  }
  else{
   wait(&e);
   printf("%d ha despertado\n",getpid());
   if( fork() == 0){
     printf("%d => %d\n",getppid(),getpid());
   }else{
      wait(&f); 
      printf("%d ha muerto :(\n",getpid());
      exit(1);
    }
  }
 }

}
