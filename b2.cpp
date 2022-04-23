#include <stdio.h>
#include <sys/mman.h>
typedef int (*asmFunc)(void);

int writeTempCode(unsigned char * tempCode){

  unsigned char buffer[4096];
  FILE *ptr;

  ptr = fopen("debug.bin","rb");  // r for read, b for binary

  int n = fread(buffer,1,sizeof(buffer),ptr); // read 10 bytes to our buffer
  pclose(ptr);
  for(int i = 0; i<n; i++)
    tempCode[i]=buffer[i];
  
  return n;
}

int main(int argc, char *argv[])
{
   // probably needs to be page aligned...

   unsigned int codeBytes = 4096;
   void * virtualCodeAddress = 0;

   virtualCodeAddress = mmap(
       NULL,
       codeBytes,
       PROT_READ | PROT_WRITE | PROT_EXEC,
       MAP_ANONYMOUS | MAP_PRIVATE,
       0,
       0);

   printf("virtualCodeAddress = %p\n", virtualCodeAddress);

   // write some code in
   unsigned char * tempCode = (unsigned char *) (virtualCodeAddress);
   int n = writeTempCode(tempCode);
   printf("%d bytes written from debug.o to buffer\n", n);
   
   asmFunc myFunc = (asmFunc) (virtualCodeAddress);

   unsigned out = myFunc();

   printf("out is %x\n", out);

   return 0;
}
