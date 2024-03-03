#include<stdio.h>  
#include<string.h> 
#include <stdlib.h> 
  int main() {
        char *ptr = (char *)calloc(5, 1);
        free(ptr);
        return 0;
  }