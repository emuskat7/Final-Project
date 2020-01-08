#include <stdio.h>
#include <stdlib.h>
int main()
  {
    //declare the variables that will be used
    FILE *streamOne;
    FILE *streamTwo;
    char result[1000];
    int statusOne, statusTwo;

    //use popen to open a stream and execute the first command of my two piped commands
    //open the file containing the census of all the names and their frequencies
    streamOne = popen( "cat /data/raw/census/dist.all.last", "r");

     //handle error with popen for streamOne 
     if  (streamOne == NULL){
     perror("Error with the popen of streamOne");
     exit(EXIT_FAILURE);
    }

     //use popen to take the resulting of the first popen and take the first ten lines and read them into a new file 
     streamTwo = popen("head -10" , "w");

     //handle error with popen for streamTwo
      if  (streamTwo == NULL){
	 perror("Error with the popen of streamTwo");
	 exit(EXIT_FAILURE);
      }

     //act as the pipe between streamOne and streamTwo, reading in streamOne and printing out the result to streamTwo
     while (fgets(result, sizeof(result), streamOne)!=NULL){
      fprintf(streamTwo, "%s", result);
      }

     //print the result of streamTwo thus simulating the pipe command which also prints the result of the command if not redirected
      while (fgets(result, sizeof(result), streamTwo)!=NULL){
	printf("%s", result);
      }

     
     //execute pclose to close the streams and do error checking to make sure they closed properly
     statusOne = pclose(streamOne);
     statusTwo = pclose(streamTwo);
     if (statusOne == -1|| statusTwo == -1)
       exit(EXIT_FAILURE);
     

     return 0;
  }
    
