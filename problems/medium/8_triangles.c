#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;


double calc_area(triangle *t1)
{
    double p = (t1->a + t1->b + t1->c)/2;
    double area = sqrt(p * (p - t1->a) * (p - t1->b) * (p - t1->c) );
    return area;
}


void sort_by_area(triangle* tr, int n) {
    triangle *temp = tr;
    double *areas = (double *)malloc(n * sizeof(double));
    triangle temp2;

    for ( int i = 0; i < n; i++ )
    {
        areas[i] = calc_area(temp);
        temp++;
    }

    for ( int i = 0; i < n; i++)
    {
        for ( int j = 0; j < n; j++)
        {
            if ( areas[j] < areas[i] )
            {
                temp2 = tr[i];
                tr[i] = tr[j];
                tr[j] = temp2;
            }
        }
    }

}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}