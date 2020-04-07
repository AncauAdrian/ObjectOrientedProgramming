#pragma once
#include "Drug.h"
#include "Repository.h"


/// <summary>
/// Adds a new drug to the list.
/// </summary>
/// <returns> Returns 1 if successful, 0 otherwise </returns>
int add_drug(Array *repo, Drug drug);

/// <summary>
/// Removes an existing drug from the list.
/// </summary>
/// <returns> Returns 1 if successful, 0 otherwise </returns>
int remove_drug(Array *repo, Drug drug);

/// <summary>
/// Updates an existing drug from the list.
/// </summary>
/// <returns> Returns 1 if successful, 0 otherwise </returns>
int update_drug(Array *repo, Drug newdrug);

/// <summary>
/// Searches the list for the given string.
/// </summary>
Array search_string(Array *repo, char s[20]);

/// <summary>
/// Returns a list of medications that contain the given string sorted descending by concentration
/// </summary>
Array search_string_c(Array *repo, char s[20]);

/// <summary>
/// Prints the list in alphabetical order.
/// </summary>
Array print_sorted(Array *repo);

void test_controller();