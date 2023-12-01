/*
 * CSE 351 Lab 1b (Manipulating Bits in C)
 *
 * Name(s): Alan Li, Ivan Belikov 
 * NetID(s): tianyl28, Ivanb13
 *
 * This is a file for managing a store of various aisles, represented by an
 * array of 64-bit integers. See aisle_manager.c for details on the aisle
 * layout and descriptions of the aisle functions that you may call here.
 *
 * Written by Porter Jones (pbjones@cs.washington.edu)
 */

#include <stddef.h>  // To be able to use NULL
#include "aisle_manager.h"
#include "store_client.h"
#include "store_util.h"

// Number of aisles in the store
#define NUM_AISLES 10

// Number of sections per aisle
#define SECTIONS_PER_AISLE 4

// Number of items in the stockroom (2^6 different id combinations)
#define NUM_ITEMS 64

// Global array of aisles in this store. Each unsigned long in the array
// represents one aisle.
unsigned long aisles[NUM_AISLES];

// Array used to stock items that can be used for later. The index of the array
// corresponds to the item id and the value at an index indicates how many of
// that particular item are in the stockroom.
int stockroom[NUM_ITEMS];


/* Starting from the first aisle, refill as many sections as possible using
 * items from the stockroom. A section can only be filled with items that match
 * the section's item id. Prioritizes and fills sections with lower addresses
 * first. Sections with lower addresses should be fully filled (if possible)
 * before moving onto the next section.
 */
void refill_from_stockroom() {
  unsigned long* currentAisle;
  unsigned short id;
  unsigned short numItemsNeeded;
  for (int i = 0; i < NUM_AISLES; i++) { //i represent aisle index
    currentAisle = &aisles[i];
    for (int j = 0; j < SECTIONS_PER_AISLE; j++) {
      id = get_id(currentAisle, j);
      numItemsNeeded = (unsigned short)(NUM_AISLES - num_items(currentAisle, j));
      if (stockroom[id] > numItemsNeeded) {
        add_items(currentAisle, j, stockroom[id]);
        stockroom[id] = stockroom[id] - numItemsNeeded;
      } 
      else {  
        add_items(currentAisle, j, stockroom[id]);
        stockroom[id] = 0;
      }
    }
  }
}
/* Remove at most num items from sections with the given item id, starting with
 * sections with lower addresses, and return the total number of items removed.
 * Multiple sections can store items of the same item id. If there are not
 * enough items with the given item id in the aisles, first remove all the
 * items from the aisles possible and then use items in the stockroom of the
 * given item id to finish fulfilling an order. If the stockroom runs out of
 * items, you should remove as many items as possible.
 */
int fulfill_order(unsigned short id, int num) {
  int count = 0;
  unsigned long* currentAisle;
  unsigned short sectionID;
  unsigned short numItems;
  for (int i = 0; i < NUM_AISLES; i++) {
    currentAisle = &aisles[i];
    for (int j = 0; j < SECTIONS_PER_AISLE; j++) {
      sectionID = get_id(currentAisle, j);
      if (sectionID == id) {
        numItems = num_items(currentAisle, j);
        if (numItems >= num){
          remove_items(currentAisle, j, num);
          count += num;
          return count;
        } else {
          remove_items(currentAisle, j, numItems);
          count += numItems;
          num -= numItems;
        }
      }
    }
  }
  if (stockroom[id] >= num){
    stockroom[id] = stockroom[id] - num;
    count += num;
  } else {
    count += stockroom[id];
    stockroom[id] = 0;
  }
  return count;
}

/* Return a pointer to the first section in the aisles with the given item id
 * that has no items in it or NULL if no such section exists. Only consider
 * items stored in sections in the aisles (i.e., ignore anything in the
 * stockroom). Break ties by returning the section with the lowest address.
 */
unsigned short* empty_section_with_id(unsigned short id) {
  unsigned long* currentAisle;
  unsigned short currentID;
  unsigned short currentSpace;
  int n = 0;
  for (int i = 0; i < NUM_AISLES; i++) {
    currentAisle = &aisles[i];
    for (int j = 0; j < SECTIONS_PER_AISLE; j++) {
      currentID = get_id(currentAisle, j);
      currentSpace = get_spaces(currentAisle, j);
      if ((currentID == id) & (currentSpace == 0)){
        return &((unsigned short*)aisles)[n];
      }
      n++;
    }
  }
  return NULL;
}

/* Return a pointer to the section with the most items in the store. Only
 * consider items stored in sections in the aisles (i.e., ignore anything in
 * the stockroom). Break ties by returning the section with the lowest address.
 */
unsigned short* section_with_most_items() {
  unsigned long* currentAisle;
  int n = 0; // counter that counts how many sections we have iterated
  int mostNumItems = 0;
  int mostNumItemsIndex = 0;
  int numItems = 0;
  for (int i = 0; i < NUM_AISLES; i++) {
    currentAisle = &aisles[i];
    for (int j = 0; j < SECTIONS_PER_AISLE; j++) {
      numItems = num_items(currentAisle, j);
      if (numItems > mostNumItems) {
        mostNumItems = numItems;
        mostNumItemsIndex = n;
      }
      n++;
    }
  }
  return &((unsigned short*)aisles)[mostNumItemsIndex];
}
