/* A recursive solution the the puzzle of 8 Queens */
#include <stdio.h>

#define FAIL 0
#define SOLVED 1
#define QUEEN '*'
#define EMPTY '-'

char colmk[8];  /* Flag for testing columns */
char tiltf[15]; /* Flag for testing foward tilted diagonals */
char tiltb[15]; /* Flag for testing backward tilted diagonals */
char board[8][8];

void eightqueens(void);
int nextqueen(int row);
int safe(int row, int col);
void set_flags(int row, int col);
void reset_flags(int row, int col);
void disp_board(void);

int main(void) {
    eightqueens();
    return 0;
}

void eightqueens(void)
{
    int i, j;

    /* innitializing all arrays */

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++)
            board[i][j] = EMPTY;
    }

    for(i = 0; i < 15; i++) {
        if(i < 7)
            colmk[i] = EMPTY;
        tiltf[i] = EMPTY;
        tiltb[i] = EMPTY;
    }

    /**
     * Attempt to solve puzzle
    */

    if(nextqueen(0) == SOLVED)
        disp_board();
    else
        printf("No solutions found!\n");  
}

int nextqueen(int row)
{
    int i;

    if(row > 7)
        return (SOLVED);
    
    for(i = 0; i < 8; i++) {
        if(safe(row, i)) {
            board[row][i] = QUEEN;
            set_flags(row, i);

            if(nextqueen(row + 1) == SOLVED)
                return (SOLVED);

            else {
                board[row][i] = EMPTY;
                reset_flags(row, i);
            }
        }
    }
    return (FAIL);
}

int safe(int row, int col)
{
    if(colmk[col] == QUEEN ||
       tiltf[ row + col ] == QUEEN ||
       tiltb[ (row - col) + 7 ] == QUEEN)
        return 0;
    
    return 1;
}

void set_flags(int row, int col)
{
    colmk[col] = QUEEN;
    tiltf[ row + col ] = QUEEN;
    tiltb[ (row - col) + 7 ] = QUEEN;
}

void reset_flags(int row, int col)
{
    colmk[col] = EMPTY;
    tiltf[ row + col ] = EMPTY;
    tiltb[ (row - col) + 7 ] = EMPTY;
}

void disp_board(void)
{
    int i, j;

    putchar('\n');
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++)
            putchar( board[i][j] );
        
        putchar('\n');
    }
}