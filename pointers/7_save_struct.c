#include <stdlib.h>
#include <stdio.h>

struct record {
    char name[32];
    int age;
};


int main(void) {

    struct record *rec;
    const char filename[] = "saved.dat";

    rec = (struct record *)malloc(sizeof(struct record));
    if ( rec == NULL )
    {
        fprintf(stderr, "Allocation failure\n");
        exit(1);
    }

    printf("Enter your name: ");
    char *r;
    r = fgets(rec->name, 32, stdin);
    if ( r == NULL )
    {
        printf("Error\n");
    }

    printf("How old are you? ");
    scanf("%d", &rec->age );

    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to create file\n");
        exit(1);
    }

    fwrite(rec, sizeof(struct record), 1, fp);
    
    fclose(fp);
    return 0;
}