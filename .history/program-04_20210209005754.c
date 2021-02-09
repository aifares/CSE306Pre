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

    FILE *filePointer;
    char ch;
    int count = 0;
    int number = 1;
    char line[4096] = "";

    // This is a boolean to check for double quotes 0 = false 1 = true
    int quoteChecker = 0;

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

          if (ch != ','){
          strncat(line, &ch, 1);
          }

          
          
          // Check the column number of the header.
          if (strcmp(line,"Ref_Date")==0){
              // printf("%d Row Number", count);
            }
          
          if (ch == ',' && quoteChecker == 0){
            // count is counting the columns Ref_Date is 0th col 
            if (count == 0){
            printf("%s \n", line);
            }
            count = count + 1;
            strcpy(line, "");
          }
           
           // If we find open quotes set quoteChecker to 1(true) so we dont consider any commas ins
            if (ch == '\"' && quoteChecker == 0){
              quoteChecker = 1;
              continue;
            }

            if (ch == '\"' && quoteChecker == 1){
              quoteChecker = 0;
              continue;
            }

            
            
          

          // Reset string of line since it's a new line
          if (ch == '\n'){
            // count is counting the columns Value is 0th col 
            // If the entry is the last of the line there is no comma it begins a new line so we check for a new line instead of comma
            if (count == 0){
            printf("%s \n", line);
            }
            strcpy(line, "");
            count = 0;
          }

        }
        
      
        fclose(filePointer);

        return 0;
}
}