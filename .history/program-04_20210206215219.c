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

  // fscanf returns number of items read - here we expect 1
  // if we don't get 1 (i.e. if we get 0) we bail
  // 
  // notice use of '&' to pass the address of the number variable to fscanf
  // fscanf will deposit the value read at this address
  // 
  // read the first value in the file
  // don't look for a comma - if the file has just one value there should be no comma

  char line[1028];
  int col = 0;
  int row = 0;

  while (fgets(line,sizeof(line),inFile)){
    char *token;

    token = strtok(line, ",");

    while (token != NULL){
      col = col + 1;
      token = strtok(NULL, ",");
    }
    printf("\n");
  }

  fclose(inFile);
    return EXIT_SUCCESS;
}
