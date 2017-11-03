#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

int main(){
  struct stat sb;
  int bytes = 0;
  char * curr_dir= ".";
  printf("Statistics for directory: %s\n", curr_dir);
  printf("Total directory size: %lld bytes\n\n", sb.st_size);
  printf("Directories:\n");
  DIR * dir = opendir(curr_dir);
  struct dirent * entry;
  entry = readdir(dir);
  while(entry){
    if(entry -> d_type == DT_DIR){
      printf("     %s \n", entry->d_name);
    }
    entry = readdir(dir);
  }
  closedir(dir);
  printf("Files:\n");
  dir = opendir(curr_dir);
  entry = readdir(dir);
  while(entry){
    if(entry -> d_type == DT_REG){
      printf("     %s \n", entry->d_name);
      printf("          size: %hu bytes\n", entry -> d_reclen);
    }
    entry = readdir(dir);
  }
  closedir(dir);
}
