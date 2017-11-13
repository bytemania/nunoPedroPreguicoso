#ifndef _STRING_ARRAY_
#define _STRING_ARRAY_

/*
 * Its a pointer to strings so these strings are immutable! fixed size
 */

const char **init_array(const unsigned int len);

/*
 * sort the array (change the pointers order)
 */
void quick_sort(const char **array, const unsigned int len);

/*
 * returns 1 if is found 0 otherwise
 */
int binary_search(const char **array, const unsigned int len, const char* find);


/*
 * Binary search Parallel with posix threads --much faster!!!
 * returns one array with the thread number of founds or not
 * findArray = thread_number
 */
int *binary_search_parallel(const char **array, const unsigned int len, const char** findArray, const unsigned int thread_number);


#endif // _STRING_ARRAY_
