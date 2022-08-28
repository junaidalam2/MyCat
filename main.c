#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096


int main(int argc, char *argv[])
{
   
   if(argc < 2) { //check if no input into the function
        printf("Error");
    }

    for(int j = 1; j <argc; j++) {
 
        char buff[BUFSIZE];

        FILE * fp;  // fp is the pointer to the file being opened. Can be named to anything.
        fp = fopen(argv[j], "r");  //open the file
 
        int fd=fileno(fp);
        
        read(fd, buff, sizeof(buff));  // reads data into the array called buff

        for (int i = 0; buff[i] != 0; i++){  // 0 indicates the end of a file
          
            printf("%c", buff[i]);
        }
        
        for (int i = 0; i < BUFSIZE; i++){  // clear the buff array 
        
            buff[i] = '\0';
        
        }
   
        fclose(fp);  // close the file
     
     }
    
    return 0;
}
