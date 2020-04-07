#pragma once
#include "Drug.h"

typedef Drug TElement;

typedef struct
{
	TElement elems[100];
	int length;
	//int capacity;
} Array;

/// <summary>
/// Adds an element to the specified array.
/// </summary>
void add_element(Array *arr, TElement e);

/// <summary>
/// Finds an element from the specified array.
/// </summary>
/// <returns>
/// The index of the elements or -1 if it doesn't exist 
/// </returns>
int find_element(Array *arr, TElement e);

/// <summary>
/// Deletes an element from the specified array.
/// </summary>
/// <returns>
/// 1 if successfull, 0 if not
/// </returns>
int delete_element(Array *arr, TElement e);

/// <summary>
/// Modifies a given element in the array
/// </summary>
/// <returns>
/// 1 if successfull, 0 if not
/// </returns>
int modify_element(Array *arr, TElement olde, TElement newe);

/// <summary>
/// Searches for all drugs that cointain a given string
/// </summary>
/// <returns>
/// An array containing all results, 0 if no results were found
/// </returns>
Array search_elements(Array *arr, char s[20]);

void print_elems(Array *arr);

void test_repo();