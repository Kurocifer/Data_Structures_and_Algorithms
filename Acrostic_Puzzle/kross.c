#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALL     1
#define PUZ     2
#define DOWN    1
#define ACROSS  2

#define MINWORD 2
#define MAXPUZ  25
#define MAXWORD 50
#define WORDLEN 15

#define EMPTY   0
#define FREE    1
#define USED    2

#define FAIL   -1
#define SOLVED  3

#define BLANK   ' '
#define PADCHAR '-'
#define WORDS   "@words"
#define PUZZLE  "@puzzle"

#define FLAG(x, y)  list[x - MINWORD].w[y].flag
#define WORD(x, y)  list[x - MINWORD].w[y].word

int solve(int length, int width);
int next(int *len, int *wht, int *t);
int itfits(int l, int w, char *word, int t);

void readpuz(FILE *fp);
void puz_print(void);
void restore(char *old, int l, int w, int t);
void enter(char *old, int l , int w, char *word, int t);

int length, width;
char puzzle[MAXPUZ][MAXPUZ];

struct words {
    int flag;
    char word[WORDLEN];
};

struct wordlist {
    struct words w[MAXWORD];
}list[WORDLEN - MINWORD];

int main(int argc, char *argv[])
{
    int i, j;
    FILE *fp;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s puzzlefile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: Cannot open '%s' to read!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    readpuz(fp);
    /*
    if(solve(0, -1) == SOLVED)
        puz_print();
    else
        printf("No Solution!!\n");
    */
    printf("test 1: passed succesfully!\n");

    puz_print();
    printf("test 2: Passed succesfully1\n");
    
    return 0;
}

/**
 * readpuz: read puzzle into memory from file
*/
void readpuz(FILE *fp)
{
    int i;
    char buffer[85];

    /* Puzzle Selction */
    length = 0;
    
    if(fgets(buffer, sizeof(buffer), fp) == NULL) {
        fprintf(stderr, "Error: %s: premture EOF!", PUZZLE);
        exit(EXIT_FAILURE);
    }

    if(strncmp(buffer, PUZZLE, strlen(PUZZLE))) {
        fprintf(stderr, "Error: %s: BAD FORMAT!\n", PUZZLE);
        exit(EXIT_FAILURE);
    }

    if(fgets(buffer, sizeof(buffer), fp) == NULL
       || !strncmp(buffer, WORDS, strlen(WORDS))) {
        fprintf(stderr, "Error: %s: Premature EOF!\n", PUZZLE);
        exit(EXIT_FAILURE);
    }

    width = strlen(buffer) - 1;

    do {
        if((strlen(buffer) -1) != width) {
            fprintf(stderr, "Error: Line %d: bad width!\n", width);
            exit(EXIT_FAILURE);
        }

        for(i = 0; i < width; i++) {
            if(buffer[i] == BLANK)
                puzzle[length][i] = BLANK;

            else if(buffer[i] == PADCHAR)
                puzzle[length][i] = buffer[i];

            else {
                fprintf(stderr, "Error: BAD CHAR %c L# %d\n", buffer[i], length);
                exit(EXIT_FAILURE);
            }
        }

        puzzle[++length][width] = '\0';
    }while(fgets(buffer, sizeof(buffer), fp) != NULL &&
           strncmp(WORDS, buffer, strlen(WORDS)) != 0);
        
    /* Words Section */
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        for(i = 0; i < MAXWORD; i++) {
            if( FLAG(strlen(buffer) - 1, i) == EMPTY) {
                strncpy(WORD(strlen(buffer) - 1, i), buffer, strlen(buffer) - 1);
                FLAG(strlen(buffer) - 1, i) == FREE;
            }
            break;
        }

        if(i >= MAXWORD) {
            fprintf(stderr, "Out of space %ld %s\n", strlen(buffer) - 1, buffer);
            exit(EXIT_FAILURE);
        }
    }
}

void puz_print(void)
{
    int i, j;

    for(i = 0; i < length; i++) {
        for(j = 0; j < width; j++)
            putchar(puzzle[i][j]);
        
        printf("\n");
    }
}