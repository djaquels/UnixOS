/*
  Implementacion del comando ls -l de Unix usando funciones de lenguaje C
  como stat

*/
#include <stdio.h>
#include <sys/stat.h> // Para al estructura
#include <sys/types.h> // Tipos de stat
#include <fcntl.h>
//#include <sys/mode.h> // Modo de los archivos
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char **argv){
  printf("Ejecutando comando ls -l con stat\n");
  DIR *dir; // Apuntador al directorio
  struct dirent *entry; // Guarda el directorio
  struct stat archivo; // Para un archivo
  if ((dir = opendir(argv[1])) == NULL)
    perror("opendir() error");
  else {
    printf("Contenido de %s: \n",argv[1]);
    printf("Permisos Ligas* Usuario Grupo Tamaño Fecha Nombre Inodo\n");
    while ((entry = readdir(dir)) != NULL){
      // Para cada valor de entry usar un stat
      // printf("  %s\n", entry->d_name);
      if(stat(entry->d_name,&archivo)){
        perror("Error leyendo archivo");
      }else{
        // Para los permisos
        printf( (S_ISDIR(archivo.st_mode)) ? "d" : "-");
        printf( (archivo.st_mode & S_IRUSR) ? "r" : "-");
        printf( (archivo.st_mode & S_IWUSR) ? "w" : "-");
        printf( (archivo.st_mode & S_IXUSR) ? "x" : "-");
        printf( (archivo.st_mode & S_IRGRP) ? "r" : "-");
        printf( (archivo.st_mode & S_IWGRP) ? "w" : "-");
        printf( (archivo.st_mode & S_IXGRP) ? "x" : "-");
        printf( (archivo.st_mode & S_IROTH) ? "r" : "-");
        printf( (archivo.st_mode & S_IWOTH) ? "w" : "-");
        printf( (archivo.st_mode & S_IXOTH) ? "x" : "-");
        printf("\t");
        // Numero de ligas suaves
        printf("%d ", archivo.st_nlink );
        // Identificador de Usuario
        printf("%d ", archivo.st_uid);
        // Identificador de Grupo
        printf("%d ", archivo.st_gid);
        // Tamaño
        printf("%d ",archivo.st_size );
        printf("%s ", asctime(localtime(&archivo.st_mtime)) );
        // Nombre del archivo
        printf("%s ",entry->d_name );
        // Inodo
        printf("%d\n ",archivo.st_ino );
      }
    }
    printf("* Solo para archivos que no sean directorios\n");
    closedir(dir);
  }
  return 0;
}
