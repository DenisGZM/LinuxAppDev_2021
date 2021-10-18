#include <stdio.h>
#include <stdlib.h>

void print_range( int start, int end, int step)
{
    int i;
    for ( i = start; i < end; i += step )
    {
        printf("%d\n", i);
    }
}

int main( int argc, char **argv)
{
    int start = 0;
    int end = 0;
    int step = 1;

    switch ( argc )
    {
      case 2:
        end = atoi(argv[1]);
        break;
      case 3:
        start = atoi(argv[1]);
        end = atoi(argv[2]);
        break;
      case 4:
        start = atoi(argv[1]);
        end = atoi(argv[2]);
        step = atoi(argv[3]);
        break;
      default:
        printf("Help:\n");
        printf(" - Without args — print help.\n");
        printf(" - N — print sequence [0, 1, … N-1]\n");
        printf(" - M, N — print sequence [M, M+1, … N-1]\n");
        printf(" - M, N, S — sequence [M, M+S, M+2S, … N-1]\n");
        return 1;
        break;
    }

    print_range( start, end, step);
    return 0;
}