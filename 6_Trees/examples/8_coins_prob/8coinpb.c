/* An embeded solution to the 8 coin problem showing a decision tree,
    as an application of trees
*/
/* functions other than the eightcoins function, are of my implemetation */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LIGHT -1
#define HEAVY 1

void eightcoins(const int *coin, int *bad, int *stat);
void initialize_number(void);
int bad_coin_index(void);


int main(void) {

    int bad_coin_i, coin[8], bad;
    int i, stat;

    bad_coin_i = bad_coin_index();

    for (i = 0; i < 8; i++)
            coin[i] = 1;

    if((bad_coin_i % 2) == 0)
        coin[bad_coin_i] = 0;
    else
        coin[bad_coin_i] = 2;
    
    eightcoins(coin, &bad, &stat);

    printf("bad coin is at index %d, and it is ", bad);
    
    if(stat = HEAVY)
        printf("heavy\n");
    else if(stat == LIGHT)
        printf("light\n");
    
    return 0;

}

void eightcoins(const int *coin, int *bad, int *stat)
{
    int s1 = 0, s2 = 0;
    int s3, s4;
    int i;

    for(i = 0; i < 6; i++) {
        if (i <= 2)
            s1 += coin[i];
        else
            s2 += coin[i];
    }


    if(s1 == s2) {
        if(coin[6] > coin[7]) {
            if(coin[6] != coin[0]) {
                *bad = 6;
                *stat = HEAVY;
            }
            else {
                *bad = 7;
                *stat = LIGHT;
            }
        }
        else {
            if(coin[7] != coin[0]) {
                *bad = 7;
                *stat = HEAVY;
            }
            else {
                *bad = 6;
                *stat = LIGHT;
            }
        }
    }

    
    else if(s1 < s2) {
        s3 = coin[0] + coin[3];
        s4 = coin[1] + coin[4];


        if(s3 == s4) {
            if(coin[2] != coin[0]) {
                *bad = 2;
                *stat = LIGHT;
            }
            else {
                *bad = 4;
                *stat = HEAVY;
            }
        }

        else if(s3 > s4) {
            if(coin[1] != coin[0]) {
                *bad = 1;
                *stat = LIGHT;
            }
            else {
                *bad = 3;
                *stat = HEAVY;
            }
        }

        else {
            if(coin[0] != coin[2]) {
                *bad = 0;
                *stat = LIGHT;
            }
            else {
                *bad = 4;
                *stat = HEAVY;
            }
        }
        
    }

    else {
        s3 = coin[0] + coin[3];
        s4 = coin[1] + coin[4];

       if(s3 == s4) {
            if(coin[2] != coin[0]) {
                *bad = 2;
                *stat = HEAVY;
            }
            else {
                *bad = 4;
                *stat = LIGHT;
            }
        }

        else if(s3 > s4) {
            if(coin[1] != coin[0]) {
                *bad = 1;
                *stat = HEAVY;
            }
            else {
                *bad = 3;
                *stat = LIGHT;
            }
        }

        else {
            if(coin[0] != coin[2]) {
                *bad = 0;
                *stat = HEAVY;
            }
            else{
                *bad = 4;
                *stat = LIGHT;
            }
        }
    }
}

void initialize_number(void)
{
    srand((unsigned) time(NULL));
}

int bad_coin_index(void)
{   
    return (rand() % 8);
}