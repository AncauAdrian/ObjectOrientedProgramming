#pragma once
#include "Drug.h"
//#include "Repository.h"
#include "DynamicArray.h"
#include "Undo.h"

/// <summary>
/// Updates the undo array
/// </summary>
void _undo_update(UndoArray *undo, DynamicArray *repo);

/// <summary>
/// Undoes the last action
/// </summary>
/// <returns>1 if successful, 0 if not</returns>
int _undo(UndoArray *undo, DynamicArray *repo);

/// <summary>
/// Redoes the last action
/// </summary>
/// <returns>1 if successful, 0 if not</returns>
int _redo(UndoArray *undo, DynamicArray *repo);

/// <summary>
/// Adds a new drug to the list.
/// </summary>
/// <returns> Returns 1 if successful, 0 otherwise </returns>
int add_drug(DynamicArray *repo, Drug drug);

/// <summary>
/// Removes an existing drug from the list.
/// </summary>
/// <returns> Returns 1 if successful, 0 otherwise </returns>
int remove_drug(DynamicArray *repo, Drug drug);

/// <summary>
/// Updates an existing drug from the list.
/// </summary>
/// <returns> Returns 1 if successful, 0 otherwise </returns>
int update_drug(DynamicArray *repo, Drug newdrug);

void search(DynamicArray *arr, DynamicArray *res, char s[20]);

/// <summary>
/// Searches the list for the given string.
/// </summary>
void search_string(DynamicArray *arr, DynamicArray *res, char s[20]);

/// <summary>
/// Returns a list of medications that contain the given string sorted descending by concentration
/// </summary>
void search_string_c(DynamicArray *arr, DynamicArray *res, char s[20]);

/// <summary>
/// Prints the list in alphabetical order.
/// </summary>
void print_sorted(DynamicArray *repo, DynamicArray *res);

/// <summary>
/// Gets the elements which are under the specified quantity
/// </summary>
void short_supply(DynamicArray *repo, DynamicArray *res, int quantity);

void test_controller();