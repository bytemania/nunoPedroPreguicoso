#include <stdio.h>
#include <stdlib.h>
#include "string_array.h"

int main(void)
{

    const unsigned int len = 3;

    const char **strArray = init_array(len);

    strArray[0] = "ONE";
    strArray[1] = "TWO";
    strArray[2] = "THREE";

    puts(strArray[0]);
    puts(strArray[1]);
    puts(strArray[2]);
    puts("------------------------------");
    quick_sort(strArray, len);

    puts(strArray[0]);
    puts(strArray[1]);
    puts(strArray[2]);

    puts("------------------------------");

    printf("%d\n", binary_search(strArray, len, "ONE"));
    printf("%d\n", binary_search(strArray, len, "TWO"));
    printf("%d\n", binary_search(strArray, len, "THREE"));
    printf("%d\n", binary_search(strArray, len, "FOUR"));

    puts("------------------------------");

const char * search[] = {"ONE", "TWO", "THREE", "FOUR"};

    int *results = binary_search_parallel(strArray, len, search, 4);

    for (int i = 0; i < 4; i++)
        printf("%d\n", results[i]);


    return 0;
}
