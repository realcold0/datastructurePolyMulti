#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct {
	float coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERMS] = { {4,3},{3,2},{2,1},{1,0},    {3,2},{2,1} ,{8,0} };
polynomial terms2[MAX_TERMS] = { {7,6},{5,3},{9,2},{1,0},    {5,3},{2,2} ,{1,1},{10,0} };
int avail = 7;


void attach(float coef, int expon, polynomial terms[])
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 갯수가 너무 많음");
		exit(1);

	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}
void print_poly(int s, int e, polynomial terms[])
{
	for (int i = s; i < e; i++)
	{
		printf("%3.lfx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.lfx^%d \n", terms[e].coef, terms[e].expon);

}
void poly_multi(int As, int Ae, int Bs, int Be, int *Cs, int *Ce, polynomial terms[])
{
    *Cs = avail;

    for (int i = As; i <= Ae; i++)
    {
        for (int j = Bs; j <= Be; j++)
        {
            int expon = terms[i].expon + terms[j].expon;
            float coef = terms[i].coef * terms[j].coef;

            
            int k;
            for (k = *Cs; k < avail; k++)
            {
                if (terms[k].expon == expon)
                {
                    terms[k].coef += coef;
                    break;
                }
            }
            
            if (k == avail)
            {
                attach(coef, expon, terms);
            }
        }
    }

    *Ce = avail - 1;
    *Cs = (*Cs > *Ce) ? *Ce : *Cs;


}


void main() {
    printf("문제 1===============================\n");
	int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;
	print_poly(As, Ae, terms);
	print_poly(Bs, Be, terms);
	poly_multi(As, Ae,Bs,Be,&Cs,&Ce,terms);
	printf("답  ===============================\n");
	print_poly(Cs, Ce, terms);

    printf("문제 2===============================\n");

    As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;
    print_poly(As, Ae, terms2);
    print_poly(Bs, Be, terms2);
    poly_multi(As, Ae, Bs, Be, &Cs, &Ce, terms2);
    printf("답  ===============================\n");
    print_poly(Cs, Ce, terms2);
    system("PAUSE");

}