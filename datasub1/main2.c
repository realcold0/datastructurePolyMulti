#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct {
    float coef;
    int expon;
}polynomial;

polynomial terms[MAX_TERMS] = { {7,6},{5,3},{9,2},{1,0},    {5,3},{2,2} ,{1,1}, {10,0} };
int avail = 7;


void main() {
    int As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;
    print_poly(As, Ae);
    print_poly(Bs, Be);
    poly_multi(As, Ae, Bs, Be, &Cs, &Ce);
    printf("===============================\n");
    print_poly(Cs, Ce);

}