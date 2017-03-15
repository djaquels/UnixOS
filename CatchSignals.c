#include <signal.h>
#include <unistd.h>

void catcher(int); // Prototype
 int main(){
  int i;
  for(i=1; i <= 64;i++){
     signal(i,catcher);
   }
  printf("ID of process: %d \n",getpid());
  pause();
  printf("Continue....\n");
  return 0;


}

void catcher(int signal){
    printf("Signal: %d \n",signal);
    
   }
