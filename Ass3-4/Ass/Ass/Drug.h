#pragma once

typedef struct
{
	char name[20];
	int conc;
	int quantity;
	int price;
} Drug;

/// <summary>
/// Creates a a drug with the given properties.
/// </summary>
/// <returns> A drug object </returns>
Drug create_drug(char *name, int conc, int quantity, int price);

/// <summary>
///	Prints a drug
/// </summary>
/// <param name="*drug">The drug to print</param>
/// <returns>None</returns>
void print_drug(Drug drug);

/// <summary>
/// Compares two Drug elements
/// </summary>
/// <returns>
/// 1 if the name and concentration match, 0 if not
/// </returns>
int compare(Drug *a, Drug *b);

void test_drug();