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
    //fp now has that output stream
    //print the first ten lines of the stream using a for loop - simulating piping the file ouput into the head -10 command
    for(int i=0; i<=9; i++){
      fgets(path, PATH_MAX, fp);
      printf("%s", path);
    }
    //after printing out the top ten names from the cesnsus file use pclose to close the stream that was opened by popen
    pclose(fp);
  }
