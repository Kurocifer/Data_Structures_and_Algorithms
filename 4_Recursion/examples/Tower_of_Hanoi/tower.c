#include <stdio.h>

/**
 * tower: prints the different steps to solve the
 *         problem the tower of hanoi for n discs.
 * 
 * n- The number of disc.
 * a- The 'from' peg.
 * b- The 'auxiliary' peg.
 * c- The destination peg.
 * 
 * return- Returns the number of steps required
 */
long tower(int n, char a, char b, char c);

int main(void)
{
    int num_disc;
    long n_mv;

    printf("Enter num discs: ");
    scanf("%d", &num_disc);

    n_mv = tower(num_disc, 'A', 'B', 'C');
    printf("\n\nNumber of steps = %lu\n", n_mv);
}

long tower(int n, char a, char b, char c)
{
    long num_mv = 0;

    if(n <= 0)
        return 0; /* invalid number of discs*/

    if(n == 1) {
        printf("Move ring %d from peg %c to peg %c\n", n, a, c);
        num_mv++;
        return 0;
    }

    /* Move n - 1 rings from peg A to peg B using C as auxiliary */
    tower(n - 1, a, c, b);

    /* Move remaining rings from peg A to peg C */
    printf("Move ring %d from peg %c to peg %c\n", n, a, c);
    num_mv++;

    /* Move n - 1 rings from peg B to C using A as auxiliary */
    tower(n - 1, b, a, c);

    return num_mv;
}