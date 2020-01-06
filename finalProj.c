#include <stdio.h>

int main()
  {
    //declare the variables that will be used
    FILE *fp;
    int PATH_MAX = 100;
    char path[PATH_MAX];

    //use popen to open a stream and execute the first command of my two piped commands
    //open the file containing the census of all the names and their frequencies
    fp = popen( "cat /data/raw/census/dist.all.last", "r");

    //handle error with popen
     if  (fp == NULL){
     printf("there was an error if with popen");
     return -1;
    }
    
    //fp now has that output stream
    //print the first ten lines of the stream using a for loop - simulating piping the file ouput into the head -10 command
    for(int i=0; i<=9; i++){
      //check to make sre there are ten names
      if (fgets(path, PATH_MAX, fp) != NULL)
	printf("%s", path);
       else {
	printf("there were not 10 lines in the output stream from the file");
	return -1;
	}
    }
    //after printing out the top ten names from the cesnsus file use pclose to close the stream that was opened by popen
    //check to make sure the pclose had no error
    int status = pclose(fp);
    if (status == -1){
    printf("there was an error with pclose");
    return -1;
    }
  }
