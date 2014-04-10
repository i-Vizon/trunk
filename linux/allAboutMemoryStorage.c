#include <stdio.h>
#include <string.h>

static int gloabal_static_integer;
char       global_string[] = "Mageswaran";
char*      global_string_ptr = "Mageswaran";
int        global_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int        global_integer;

int main(int argv, char* argc)
{
    int     local_integer;
    static  local_static;
    char*   local_sting_ptr = "Mageswaran";

    printf("Time to run some tools and check the memory layout\n");
}
