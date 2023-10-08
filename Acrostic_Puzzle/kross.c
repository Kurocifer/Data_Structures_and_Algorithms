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
    char *p;
    FILE *fp;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <puzzlefile.krs>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    p = argv[1];

    while(*p++ != '.')
        ;
    
    if(strcmp(p, "krs") != 0) {
        fprintf(stderr, "Wrong file extension. File name should have extension 'krs'.\n"
                "Usage: %s <puzzlefile.krs>\n", argv[0]);
        
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: Cannot open '%s' to read!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    readpuz(fp);

    if(solve(0, -1) == SOLVED)
        puz_print();
    else
        printf("No Solution!!\n");
    
    fclose(fp);
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
                puzzle[length][i] = '\0';

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

/**
 *  puz_pritn: Display solve puzzle 
*/
void puz_print(void)
{
    int i, j;

    for(i = 0; i < length; i++) {
        for(j = 0; j < width; j++)
            putchar(puzzle[i][j]);
        
        putchar('\n');
    }
}

/**
 * solve: fuction that searches for a solution.
*/

static int prev = -1;

int solve(int length, int width)
{
    int l, w, i, len, temp, type;
    char old[WORDLEN - MINWORD + 1];

    w = width;
    l= length;
    len = next(&l, &w, &type);
    if(len == 0)
        return SOLVED;
    
    for(i = 0; i < MAXWORD && WORD(len, i)[0] != '\0'; i++)
    {
        if(FLAG(len, i) == FREE 
          && itfits(l, w, WORD(len, i), type)) {
            FLAG(len, i) == USED;
            enter(old, l, w, WORD(len, i), type);
            prev = type;
            if(solve(l, w) == SOLVED)
                return SOLVED;
            
            restore(old, l, w, type);
            FLAG(len, i) == FREE;
          }
    }

    return FAIL;
}


/**
 * next: Locate the next slot to fill.
*/
int next(int *len, int *wht, int *t)
{
    int l, w, temp;

    l = *len;
    w = *wht;

    /**
     * check current position for actoss: down would
     * have been done already.
    */
   if(w != -1 && ((w - 1) < 0 || puzzle[1][w - 1] == '\0') 
       && puzzle[1][w] && (w + 1) < width && puzzle[1][w + 1]) {
        /* Across! */
        *t = ACROSS;

        /* Necessary evil */
        *wht = w + 1;

        temp = 0;
        while(puzzle[1][w] != '\0' && w < width) {
            w++;
            temp++;
        }

        return(temp);

    }

    else if(prev == DOWN || w == -1)
        w++;
    
    /* check for next possible postion */
    for(; l < length; l++) {
        for(; w < width; w++) {
            if((( l - 1) < 0 || puzzle[l - 1][w] == '\0') 
               && puzzle[l][w] != '\0' && (l + 1) < length
               && puzzle[l + 1][w] != '\0') {

                    /* Down */
                    *t = DOWN;
                    prev = DOWN;
                    *wht = w;
                    *len = l;
                    temp = 0;
                    while(puzzle[l][w] != '\0' && l < length) {
                        l++;
                        temp++;
                    }
                    
                    return temp;
               }

            if(((w - 1) < 0 || puzzle[l][w - 1] == '\0')
                && puzzle[l][w] && (w + 1) < width
                && puzzle[l][w + 1]) {
                    /* Across */
                    *t = ACROSS;
                    prev = ACROSS;
                    *len = 1;
                    *wht = w + 1;

                    temp = 0;
                    if(w == -1)
                        w = 0;
                    
                    while(puzzle[l][w] != '\0' &&  w < width) {
                        w++;
                        temp++;
                    }
                    
                    return temp;
                }
        }
        w = 0;
    }
    /* puzzle completed */
    return 0;
}

/**
 * itfits: Determines if a word fits into a given slot
*/
int itfits(int l, int w, char *word, int t)
{
    char *cp;

    if(t == ACROSS && w != -1)
        w--;

    cp = word;

    while(*cp) {
        if(*cp != puzzle[l][w] && puzzle[l][w] != PADCHAR)
            return 0;
        
        if(t == ACROSS)
            w++;
        else
            l++;
        cp++;
    }

    return 1;
}

/**
 * Enter: Enter a word into the puzzle
*/
void enter(char *old, int l, int w, char *word, int t)
{
    char *cp;

    if(t == ACROSS)
        w--;

    cp = word;

    while(*cp) {
        *old++ = puzzle[l][w];
        puzzle[l][w] = *cp;

        if(t == ACROSS)
            w++;
        
        else
            l++;
        
        cp++;
    }

    *old = '\0';
}

/**
 * restore: Restore puzzle to its previous state
*/
void restore(char *old, int l, int w, int t)
{
    char *cp;

    if(t == ACROSS)
        w--;
    
    cp = old;
    
    while(*cp) {
        puzzle[l][w] = *cp;
        if(t == ACROSS)
            w++;
        else
            l++;

        cp++;
    }
}

