#include <stdio.h>
int writeTempCode(unsigned char * tempCode){

  unsigned char buffer[1000];
  FILE *ptr;

  ptr = fopen("debug.o","rb");  // r for read, b for binary

  int n = fread(buffer,1,sizeof(buffer),ptr); // read 10 bytes to our buffer
  pclose(ptr);
  for(int i = 0; i<n; i++)
    tempCode[i]=buffer[i];
  
  return n;
}

void main(void){
  unsigned char tempCode[1000];
  int n=writeTempCode(tempCode);
  printf("%d bytes read from debug.o \n", n); // prints a series of bytes
  
  for(int i = 0; i<n; i++)
    printf("%u ", tempCode[i]); // prints a series of bytes
}
