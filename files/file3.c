#include <stdio.h>

int main ()
{
   FILE *fp;
   int c;
  
   fp = fopen("file2","r");
   if(fp == NULL) 
   {
      perror("Error in opening file");
      return(-1);
   }
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) )
      { 
          break ;
      }
      printf("%c", c);
   }
   fclose(fp);
   getch();
}