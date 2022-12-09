#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#define BUFFER_SIZE 1000

void reading();
int countTimes(FILE *fptr, const char *word);


int main(){
 
 reading();
    
    return 0;
}



void reading(){
    
    FILE* fptr;
    char word[50];
    int wCount;
    int y;
    for ( y = 0 ; y<2 ; y++){
    printf("Enter word to search in file: ");
    scanf("%s", word);
    
    fptr = fopen("words.txt", "r");
    

    if (NULL == fptr) {
        printf("file can't be opened \n");
    } 
    
    wCount = countTimes(fptr, word);
 
 
    
    printf("%s is formed %d times in the file \n", word , wCount);
    }
 
    fclose(fptr);
    
    }
    
int countTimes(FILE *fptr, const char *word)
{
    
    char str[BUFFER_SIZE];
    char *pos;

    int index, count;
    
    count = 0;

    
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

       
        while ((pos = strstr(str + index, word)) != NULL)
        {
           
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}