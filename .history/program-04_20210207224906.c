#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

  This program shows how to read from a file and write to a file.

  argv[1] is the name of the input file

*/

int main(int argc, char *argv[]) {

  FILE * inFile = NULL;


  // remember: program name is argv[0]
  if (argc == 2) {
    inFile = fopen(argv[1], "r");  // open file for reading
    if (inFile == NULL) {
      printf("Error opening input file\n");
    }
  }
  else {
    printf("Incorrect number of command line arguments.\n");
  }

  // triggered= if wrong number of command line args
  // or if input file could not be read
  if (inFile == NULL) {
    return EXIT_FAILURE;
  }
  // initialize variables

  int number = 0;
  int sum = 0;
  int n = 0;
  int max = 1;








    FILE *filePointer;
    char ch;

    
    filePointer = fopen("05020004-eng.csv", "r");

  
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //Read file char by char
        while ((ch = fgetc(filePointer)) != EOF)
        {
          //Check if char is == to ,
          if (ch == ','){
            printf("%s", "FOUND");
          }
          //print char
            printf("%c", ch);
        }
    }

    
    fclose(filePointer);

    return 0;
}
