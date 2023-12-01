/*
 * CSE 351 Lab 4 (Caches and Cache-Friendly Code)
 * Part 1 - Inferring Mystery Cache Geometries
 *
 * Name(s):  
 * NetID(s): 
 *
 * NOTES:
 * 1. When using access_cache() you do not need to provide a "real" memory
 * addresses. You can use any convenient integer value as a memory address,
 * you should not be able to cause a segmentation fault by providing a memory
 * address out of your programs address space as the argument to access_cache.
 *
 * 2. Do NOT change the provided main function, especially the print statement.
 * If you do so, the autograder may fail to grade your code even if it produces
 * the correct result.
 */

#include <stdlib.h>
#include <stdio.h>

#include "support/mystery-cache.h"


/* Returns the size (in B) of each block in the cache. */
int get_block_size(void) {
  int block_size = 0;
  flush_cache();
  access_cache(0);
  while(access_cache(block_size + 1)){
    block_size++;
  }
  return block_size + 1;
}

/* Returns the size (in B) of the cache. */
int get_cache_size(int block_size) {
  int i = 0;
  int cache_size = 0;
  flush_cache();
  access_cache(0);
  while (access_cache(0)) {
    cache_size += block_size;
    for (i = 0 + block_size; i <= cache_size; i += block_size) {
      access_cache(i);
    }
  }
  return cache_size;
}

/* Returns the associativity of the cache. */
int get_cache_assoc(int cache_size) {
  int count = 0;
  int start = 0;
  flush_cache();  
  access_cache(start);
  while (access_cache(0)) {
    count++;
    for (int i = 0; i <= count; i++){
      access_cache(start + i * cache_size);  
    }
  }
  return count;
}

/* Run the functions above on a given cache and print the results. */
int main(void) {
  int size;
  int assoc;
  int block_size;

  cache_init(0, 0);

  block_size = get_block_size();
  size = get_cache_size(block_size);
  assoc = get_cache_assoc(size);

  printf("Cache block size: %d bytes\n", block_size);
  printf("Cache size: %d bytes\n", size);
  printf("Cache associativity: %d\n", assoc);

  return EXIT_SUCCESS;
}
