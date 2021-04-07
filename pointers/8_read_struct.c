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

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to read file\n");
        exit(1);
    }

    int r;
    r = fread(rec, sizeof(struct record), 1, fp);
    if (r != 1)
    {
        fprintf(stderr, "Could not read from file\n");
        exit(1);
    }

    printf("%s\n", rec->name);
    printf("%d\n", rec->age);


    fclose(fp);
    return 0;
}