/*counts the number of characters and lines in a file*/
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

FILE *fp;

void countchar(char *filename, int *num_word, int *num_line);

int main(int argc, char *argv[])
{
    int newl = 0, words;

    if(argc == 1) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    countchar(argv[1], &words, &newl);

    printf("number of words: %d\n", words);
    printf("number of new lines: %d\n", newl);

    return 0;
}

void countchar(char *filename, int *num_word, int *num_line)
{
    int ch;
    bool seen_word = false;

    *num_word = 0;
    *num_line = 1;

    if((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: file %s can't be opened\n", filename);
        exit(EXIT_FAILURE);
    }

    while(isspace(ch))
            ;
   while((ch = getc(fp)) != EOF) {
        if(!isspace(ch) && (ch != '\n') && (!seen_word)) {
            seen_word = true;
            *num_word += 1;
        }

        if(isspace(ch))
            seen_word = false;

        if(ch == '\n')
            *num_line += 1;
   }
   fclose(fp);
}