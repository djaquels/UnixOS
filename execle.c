#include <stdio.h>
#include <stdlib.h>
// Downloading a file from source code

 main(){
   char * cbook = "http://publications.gbdirect.co.uk/c_book/thecbook.pdf";
  printf("Downloading C Book\n");
  execle("/usr/bin/wget","wget",cbook,NULL);
  printf("Error Downloading\n");
   return 0;
 }
