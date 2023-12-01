/*
 * CSE 351 Lab 1a (Pointers in C)
 *
 * Name(s): Ivan Belikov and Alan Li 
 * NetID(s): 1960882 and 1938332
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc compiler.
 * You can still use printf for debugging without including <stdio.h>. The
 * included file, "common.c" contains a function declaration that should
 * prevent a compiler warning. In general, it's not good practice to ignore
 * compiler warnings, but in this case it's OK.
 */

#ifndef COMMON_H
#include "common.h"
#endif

/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

#if 0
You will provide your solution to this homework by editing the collection of
functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one or more lines of C
  code that implements the function. Your code must conform to the following
  style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are not allowed to
     use big constants such as 0xFFFFFFFF. However, you are allowed to combine
     constants to produce values outside this range (e.g., 250 + 250 = 500) so
     long as the operator you are using to combine the constants is listed as
     "legal" at the top of the method you are writing.
  2. Function arguments and local variables (no global variables).
  3. Any operators listed as "ALLOWED" in the function header comment of the
     method you are writing.
  4. Casting.

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to one
  operator per line.

  You are expressly forbidden from:
  1. Using control constructs such as if, do, while, for, switch (unless
     otherwise stated).
  2. Defining or using macros.
  3. Defining additional functions in this file.
  4. Calling functions (unless otherwise stated).
  5. Using operators listed as "DISALLOWED" in the function header comment of
     the method you are writing.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has *undefined* behavior when shifting by a negative amount or an amount
     greater than or equal to the number of bits in the value being shifted.
     (i.e., x >> n is undefined when n < 0 or n >= *size of x*)
     (e.g., if x is a 32-bit int, shifts by >= 32 bits are undefined)
     Undefined behvaior means that the result of the operation may change in
     different environments -- this should be avoided.
#endif

/*
 * STEP 2: Modify the following functions according the coding rules.
 */

/*
 * Return the size of an integer in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int int_size() {
  int intArray[10];
  int* intPtr1;
  int* intPtr2;
  long int size;

  intPtr1 = intArray;
  intPtr2 = intArray + 1;

  size = (long int)intPtr2 -(long int)intPtr1;

  return size;
}

/*
 * Return the size of a double in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int double_size() {
  double doubArray[10];
  double* doubPtr1;
  double* doubPtr2;
  long int size;

  
  doubPtr1 = doubArray;
  doubPtr2 = doubArray + 1;

  size = (long int)doubPtr2 - (long int)doubPtr1;

  return size;
}

/*
 * Return the size of a pointer in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int pointer_size() {
  double* ptrArray[10];
  double** ptrPtr1;
  double** ptrPtr2;
  long int size;


  ptrPtr1 = ptrArray;
  ptrPtr2 = ptrArray + 1;

  size = (long int)ptrPtr2 - (long int)ptrPtr1;

  return size;
}

/*
 * Given pointers to two variables, exchange/swap the values of the variables.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
void swap_ints(int* ptr1, int* ptr2) {
  int a;
  int b;

  a = *ptr1;
  b = *ptr2;

  *ptr2 = a;
  *ptr1 = b;
  
}

/*
 * Modify intArray[5] to be the value 351 using only intArray and pointer
 * arithmetic.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: +=, *=, ++, --, ~= etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int change_value() {
  int intArray[10];
  int* intPtr1;
  int* intPtr5;
  int temp1;
  int temp2;
  int value;
  
  intPtr1 = intArray;
  intPtr5 = intPtr1 + 5;
  temp1 = 175;
  temp2 = 176;
  value = temp1 + temp2;

  *intPtr5 = value;
  return *intPtr5;
}

/*
 * Return 1 if the addresses stored in ptr1 and ptr2 are within the *same*
 * 64-byte aligned block of memory or return 0 otherwise. Check the spec for
 * examples if you are unsure of what this means.
 *
 * Note that loops and the operators / and % are NOT allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: <<=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int within_same_block(int* ptr1, int* ptr2) {
  long int block1;
  long int block2;

  block1 = (long int) ptr1 >> 6;
  block2 = (long int) ptr2 >> 6;
  
  return block1 == block2;
}

/*
 * Return 1 if ptr points to a byte within the specified intArray or return 0
 * otherwise. ptr does not have to point to the beginning of an element. Check
 * the spec for examples if you are unsure of what this means. size is the
 * size of intArray in number of ints; assume size != 0.
 *
 * Note that loops and the operators / and % are NOT allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: <<=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int within_array(int* intArray, int size, int* ptr) {
  int start;
  int end; 

  start = (long int) intArray;
  end = (long int) intArray + 4 * size;
  
  return (((unsigned) ((~start + 1) + (long int)ptr) >> 31) ^ ((unsigned) ((~end + 1) + (long int)ptr) >> 31));
  
}

/*
 * In C, the end of a "string" is indicated by the null terminator ('\0').
 * Given a pointer to the start of a "string," return the string length.
 * The null terminator is not counted as part of the string length.
 *
 * Note that loops ARE allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: <<=, *=, ++, --, etc.
 *   Control constructs: for, while
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /, %
 *   Unary integer operators: ~, -
 */
int string_length(char* s) {
  char* str;
  for(str = s; *str; str++);
  return str-s;
}

/*
 * Change the value pointed to by ptr byte-by-byte so that when returned as an
 * integer the value is 351351.
 *
 * Hints: Recall that an int is 4 bytes and how little endian works for
 * multibyte memory storage. We suggest starting by converting 351351 into
 * binary/hexadecimal.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Shorthand operators based on the above: +=, *=, ++, --, etc.
 *   Unary integer operators: !
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int endian_experiment(int* ptr) {
  char* bytePtr;
  bytePtr = (char*)ptr;
  *(bytePtr) = 0x77;
  *(bytePtr + 1) = 0x5C;
  *(bytePtr + 2) = 0x05;
  *(bytePtr + 3) = 0x00;
  
  return *ptr;
}

/*
 * Selection sort is a sorting algorithm that works by partitioning the array
 * into a sorted section and unsorted section. Then it repeatedly selects the
 * minimum element from the unsorted section and moves it to the end of the
 * sorted section.
 *
 * Pseudo-code for an array (arr) and its length (n) might look like:
 *
 *   for i = 0 to n - 1
 *     minIndex = i
 *     for  j = i + 1 to n
 *       if arr[minIndex] > arr[j]
 *         minIndex = j
 *       end if
 *     end for
 *     Swap(arr[i], arr[minIndex])
 *   end for
 *
 * Note that control constructs and calling swap_ints() ARE allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: +=, *=, ++, --, etc.
 *   Control constructs: for, while, if
 *   Function calls: swap_ints()
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /
 *   Unary integer operators: ~, -
 */
void selection_sort(int arr[], int arrLength) {
  int i, j, min_index;
  int* arrPtr;
  arrPtr = arr;
  for (i = 0; i < arrLength - 1; i++) {
    int* ptr1;
    int* ptr2;
    min_index = i;
    for (j = i + 1; j < arrLength; j++) {
      if (*(arrPtr + min_index) > *(arrPtr + j)) {
	min_index = j;
      }
    }
    ptr1 = arrPtr + i;
    ptr2 = arrPtr + min_index;
    
    swap_ints(ptr1, ptr2);
  }
  
}
