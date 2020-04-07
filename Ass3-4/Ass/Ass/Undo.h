#pragma once
#include "DynamicArray.h"

typedef DynamicArray* RElement;

typedef struct {
	RElement *elems;
	int capacity;
	int length;
	int cur_index;
} UndoArray;


/// <summary>
/// Creates an undo array
/// </summary>
/// <param name="capacity">The capacity of the undo array.</param>
UndoArray* create_Undo_Array(int capacity);

/// <summary>
/// Destroys an undo array
/// </summary>
void destroy_Undo_Array(UndoArray *d);

/// <summary>
/// Resizes the undo array
/// </summary>
void resize_Undo_Array(UndoArray *d);

/// <summary>
/// Adds a Dynamic Array to the undo array
/// </summary>
void r_add(UndoArray *d, RElement e);

/// <summary>
/// Removes the all the elements after and including the cur_index
/// </summary>
void r_remove(UndoArray *d);