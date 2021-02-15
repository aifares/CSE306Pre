#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *filePointer;
char ch;
int count = 0;
char buffer[4096] = "";
char line[4096] = "";
int rowCol = -1;
int minimum = 1000000000;
int maximum = -1000000000;
float meanTotal = 0;
int meanCount = 0;
float mean = 0;

// This is a boolean to check for double quotes 0 = false 1 = true
int quoteChecker = 0;

//Prints the number of header (fields) in the file.
int number_of_fields(){
  int numberOfHeaders = 1;
  while ((ch = fgetc(filePointer)) != '\n'){
    if (ch == ','){
      numberOfHeaders += 1;
    }
  }
  printf("%d\n",numberOfHeaders);
  return 0;
}

int number_of_data(){
  int records = 0;
  while ((ch = fgetc(filePointer)) != EOF){
    if (ch == '\n'){
      records += 1;
    }
  }
  printf("Total Records %d \n", records);
  return 0;
}

int minMaxMean(char* Header , int operation){

  while ((ch = fgetc(filePointer)) != EOF)
      {
        //If we are in quotes add commas to string
        if (quoteChecker==1){
          strncat(line, &ch, 1);
        }
        else{
          // Don't add commas if we are not in quotes
          if (ch != ','){
            strncat(line, &ch, 1);
          }
        }

        // Check the column number of the header.
        // You can change gitto any header
        if (strcmp(line,Header)==0){
          rowCol = count;
        }
        
        // If the char is a comma and we are not in a quote print the string created so far for that entry
        if (ch == ',' && quoteChecker == 0){
          // count is counting the columns Ref_Date is 0th col 
          if (count == rowCol){
              if (strcmp(line, Header) != 0){
                int temp = atoi(line); 
                if (operation == 0){
                  if(temp < minimum){
                    minimum = temp;
                  }
                }
                else if(operation == 1){
                  if (temp > maximum){
                    maximum = temp;
                  }
                }
                else if(operation == 2){
                  printf("%d\n",temp);
                  meanTotal += temp;
                  meanCount += 1;
                }
                else{
                  return EXIT_FAILURE;
                }
                
              }
          }
          count = count + 1;
          strcpy(line, "");
        }
          
          // If we find open quotes set quoteChecker to 1(true) so we dont consider any commas inside of them
          if (ch == '\"' && quoteChecker == 0){
            quoteChecker = 1;
            continue;
          }

          // Found closing quotes so set it equal to false, next char is either a comma or a new line
          if (ch == '\"' && quoteChecker == 1){
            quoteChecker = 0;
            continue;
          }

        // Reset string of line since it's a new line
        if (ch == '\n'){
          // count is counting the columns Value is 0th col
          // If the entry is the last of the line there is no comma it begins a new line so we check for a new line instead of comma
          if (count == rowCol){
            // printf("%s", line);
            if (strcmp(line, Header) != 0){
                int temp = atoi(line); 
                if (operation == 0){
                  if(temp < minimum){
                    minimum = temp;
                  }
                }
                else if(operation == 1){
                  if (temp > maximum){
                    maximum = temp;
                  }
                }
                else if(operation == 2){
                  meanTotal += temp;
                  meanCount += 1;
                }
                else{
                  return EXIT_FAILURE;
                }
          }
          }
          strcpy(line, "");
          count = 0;
        }

      }
  if(operation == 0){
    printf("%d\n",minimum);
  }
  else if(operation == 1){
    printf("%d\n",maximum);
  }
  else if(operation == 2){
    printf("%f\n", meanTotal);
    printf("%d\n", meanCount);
    mean = meanTotal/meanCount;
    printf("%f\n",mean);
  }
  
  return 0;
}

int getRecords(char* Header, char*value){
  while ((ch = fgetc(filePointer)) != EOF)
      {

        strncat(buffer, &ch, 1);
        bufferChecker = 0;
        //If we are in quotes add commas to string
        if (quoteChecker==1){
          strncat(line, &ch, 1);
        }
        else{
          // Don't add commas if we are not in quotes
          if (ch != ','){
            strncat(line, &ch, 1);
          }
        }

        // Check the column number of the header.
        // You can change gitto any header
        if (strcmp(line,Header)==0){
          rowCol = count;
        }
        
        // If the char is a comma and we are not in a quote print the string created so far for that entry
        if (ch == ',' && quoteChecker == 0){
          // count is counting the columns Ref_Date is 0th col 
          if (count == rowCol){
            if (strcmp(line,value)==0)
             printf("%s", line);
          }
          count = count + 1;
          strcpy(line, "");
        }
          
          // If we find open quotes set quoteChecker to 1(true) so we dont consider any commas inside of them
          if (ch == '\"' && quoteChecker == 0){
            quoteChecker = 1;
            continue;
          }

          // Found closing quotes so set it equal to false, next char is either a comma or a new line
          if (ch == '\"' && quoteChecker == 1){
            quoteChecker = 0;
            continue;
          }

        // Reset string of line since it's a new line
        if (ch == '\n'){
          // count is counting the columns Value is 0th col
          // If the entry is the last of the line there is no comma it begins a new line so we check for a new line instead of comma
          if (count == rowCol){
             printf("%s", line);
          }
          strcpy(line, "");
          count = 0;
        }

      }
  
  return 0;
}

int main(int argc, char *argv[]) {

    filePointer = fopen("05020004-eng.csv", "r");

  
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
      //Checking the comand line argument used.
      if (argc == 3){
        if(strcmp(argv[1],"-f") == 0){
          //number_of_fields();
          getRecords("Ref_data", 2002);
        }
        else if(strcmp(argv[1],"-r") == 0){
          number_of_data();
        }
      }
      else if(argc > 3){
        if(strcmp(argv[1],"-h") == 0){
          if(strcmp(argv[2], "-min") == 0){
            minMaxMean(argv[3],0);
          }
          else if(strcmp(argv[2],"-max") == 0){
            minMaxMean(argv[3], 1);
          }
          else if(strcmp(argv[2],"-mean") == 0){
            minMaxMean(argv[3], 2);
          }
        }
      }
      else{
        //If the command line arguments are less than 3 then exit.
        printf("Incorrect number of command line arguments.\n");
        return EXIT_FAILURE;
      }
        
      fclose(filePointer);

      return 0;
    }
}     