#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "string_array.h"
#include "kbtree.h"

typedef const char *str_t;

KBTREE_INIT(str, str_t, kb_str_cmp)

static int data_size = 100000000;

void ht_khash_str() {
	int i;
	kbtree_t(str) *h;

	h = kb_init(str, KB_DEFAULT_SIZE);

	for (i = 0; i < data_size; ++i) {
        char data[20];
        sprintf(data, "NUNO_PEDRO_KEY_%d", i);
		kb_put(str, h, strdup(data));
	}

	printf("[ht_khash_str] size: %d\n", kb_size(h));

    printf("NUNO_PEDRO_KEY_0 RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_0"));
    printf("NUNO_PEDRO_KEY_1 RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_1"));
	printf("NUNO_PEDRO_KEY_2 RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_2"));
	printf("NUNO_PEDRO_KEY_3 RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_3"));
	printf("NUNO_PEDRO_KEY_500 RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_500"));

    printf("NUNO_PEDRO_KEY_NUNO_PEDRO_KEY_1000000 RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_1000000"));

    printf("NUNO_PEDRO_KEY_AA RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_AA"));
    printf("NUNO_PEDRO_KEY_BB RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_BB"));
    printf("NUNO_PEDRO_KEY_CC RESULT:%d\n", kb_get(str, h, "NUNO_PEDRO_KEY_CC"));

	__kb_destroy(h);
}

void arratStr(){

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

    const char *search[] = {"ONE", "TWO", "THREE", "FOUR"};

    int *results = binary_search_parallel(strArray, len, search, 4);

    for (int i = 0; i < 4; i++)
        printf("%d\n", results[i]);

    //TODO verify this free with electric fence
    free(strArray);
    free(results);
}

void ht_timing(void (*f)(void)) {
	clock_t t = clock();
	(*f)();
	printf("[ht_timing] %.3lf sec\n", (double)(clock() - t) / CLOCKS_PER_SEC);
}

int main(void)
{
    printf("------------------------------- ARRAY  -------------------\n\n");
    ht_timing(arratStr);

    printf("------------------------------- B+ TREE  com 100 000 000 -------------------\n\n");
    ht_timing(ht_khash_str);

    return 0;
}
