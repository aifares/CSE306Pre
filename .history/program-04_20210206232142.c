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



struct csv
{
  /* data */
};





  char line[1096][1096];
	char fname[20];
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;

    fptr = fopen("05020004-eng.csv", "r");
    while(fgets(line[i], 1096, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    
    for(i = 0; i < tot; ++i)
    {
        if (strcmp( argc[i], "&") == 0){
          printf("%s", line[i]);
        }
    }
    printf("\n");
  fclose(inFile);
  return EXIT_SUCCESS;
}
