#include <stdlib.h>
#include <stdio.h>

struct command {
    char * command_name;
    void (*func_name) (void *);
};

void my_print(void * arg)
{
    char * my_str = (char *)arg;
    printf("%s", my_str);
}

int main()
{
    //int m = 1;
    struct command my_command = {"hello", my_print};
    my_command.func_name("hi");
    //printf("%d", m);
}