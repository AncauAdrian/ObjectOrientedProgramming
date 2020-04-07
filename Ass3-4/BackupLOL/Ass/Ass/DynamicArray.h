#pragma once
#include "Drug.h"

typedef Drug TElement;

typedef struct {
	TElement *elems;
	int length;
	int capacity;
} DynamicArray;


/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray* create_Dynamic_Array(int capacity);

/// <summary>
/// Destroys the dynamic array.
/// </summary>
/// <param name="d">The dynamic array to be destoyed.</param>
/// <returns>A pointer the the created dynamic array.</returns>
void destroy_Dynamic_Array(DynamicArray *d);

/// <summary>
/// Adds a generic element to the dynamic array.
/// </summary>
/// <param name="d">The dynamic array.</param>
/// <param name="e">The element to be added.</param>
void d_add(DynamicArray *d, TElement e);

/// <summary>
/// Resizes a Dynamic array
/// </summary>
/// <param name="d">The dynamic array.</param>
void resize_Dynamic_Array(DynamicArray* d);

/// <summary>
/// Finds an element inside the array
/// <param name="d">The dynamic array.</param>
/// <param name="e">The element to find.</param>
/// <param name="comp">The comparison function that compares the elements</param>
/// <returns>The index of the element, -1 if not found</returns>
int d_find(DynamicArray *d, TElement e, int(*comp)(TElement *a, TElement *b));

/// <summary>
/// Removes an element from the dynamic array
/// <param name="d">The dynamic array.</param>
/// <param name="e">The element to be removed.</param>
/// <param name="comp">The comparison function that compares the elements</param>
/// <returns>1 if successful, 0 if not </returns>
int d_remove(DynamicArray *d, TElement e, int(*comp)(TElement *a, TElement *b));

/// <summary>
/// Removes an element from the dynamic array
/// <param name="arr">The dynamic array.</param>
/// <param name="_print">The print function for an individual element</param>
void d_print(DynamicArray *arr, void(*_print)(TElement e));

/// <summary>
/// Modifies an element from the array
/// <param name="arr">The dynamic array.</param>
/// <param name="e">The modified element</param>
/// <param name="comp">The comparison function that compares the elements</param>
/// <returns>1 if successful, 0 if not </returns>
int d_update(DynamicArray *arr, TElement e, int(*comp)(TElement *a, TElement *b));

void test_darray();