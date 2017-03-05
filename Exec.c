#include <stdio.h>
#include <stdlib.h>
// Next program is a example for use exec comand in Unix Like Systems
main(){
  printf("Executing some Unix Commands\n");
  execl("/bin/ls","ls","-l",(char*)0);
  perror("Fail executing ls");
  exit(1);

}
