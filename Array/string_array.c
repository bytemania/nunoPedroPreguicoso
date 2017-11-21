#ifndef _STRING_ARRAY_
#define _STRING_ARRAY_

#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#include <pthread.h>

const char ** init_array(const unsigned int len) {
    if (len <= 0)
        return NULL;
    else
        return (const char **) calloc(len, sizeof(char *));
}

void swap(const char **str1, const char **str2) {
    const char *tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

void quick_sort(const char **array, const unsigned int len) {

  unsigned int i, pvt=0;

    if (len <= 1)
        return;

    // swap a randomly selected value to the last node
    swap(array+((unsigned int)rand() % len), array+len-1);

    // reset the pivot index to zero, then scan
    for (i=0; i<len-1; ++i)
    {
        if (strcmp(array[i], array[len-1]) < 0)
            swap(array+i, array+pvt++);
    }

    // move the pivot value into its place
    swap(array+pvt, array+len-1);

    // and invoke on the subsequences. does NOT include the pivot-slot
    quick_sort(array, pvt++);
    quick_sort(array+pvt, len - pvt);
}


/*
 * returns 1 if is found 0 otherwise
 */
int binary_search(const char **array, const unsigned int len, const char* find) {
  int first, last, middle;

   first = 0;
   last = len - 1;
   middle = (first+last) / 2;

   while ( first <= last )
   {
      if (strcmp(array[middle], find) < 0 )
         first = middle + 1;
      else if (strcmp(array[middle], find) == 0)
      {
         return 1;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }

   return 0;
}

typedef struct binary_search_parallel_args {
  const char **array;
  unsigned int len;
  const char* find;
  int *result;
  int index;
} binary_search_parallel_args;

void *binary_search_parallel_aux(void *context) {
    binary_search_parallel_args *args = (binary_search_parallel_args *) context;
    args->result[args->index] = binary_search(args->array, args->len, args->find);
    return NULL;
}

int *binary_search_parallel(const char **array, const unsigned int len, const char** findArray, const unsigned int thread_number) {

    pthread_t threads[thread_number];
    int *result = (int *) calloc(thread_number, sizeof(int));

    int ret;

    binary_search_parallel_args args[thread_number];

    for (int i = 0; i < thread_number; i++) {
	     args[i].array = array;
	     args[i].len = len;
	     args[i].find = findArray[i];
	     args[i].result = result;
	     args[i].index = i;

	     ret = pthread_create(&threads[i], NULL, binary_search_parallel_aux, (void*) &args[i]);

	     if(ret) {
            //BAD CODE
	         fprintf(stderr,"Error - pthread_create() return code: %d\n",ret);
	         exit(EXIT_FAILURE);
	     }
    }

    for (int i = 0; i < thread_number; i++) {
        pthread_join(threads[i], NULL);
    }

    return result;
}


#endif // _STRING_ARRAY_

