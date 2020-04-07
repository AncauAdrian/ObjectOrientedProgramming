#include "UI.h"
#include "Drug.h"
#include "Repository.h"
#include "Controller.h"
#include "DynamicArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show_menu()
{
	printf("Smiles Pharmacy\n");
	printf("________________________\n");
	printf("Commands:\n");
	printf("add <name> <concentration> <quantity> <price> -- adds a drug\n");
	printf("update <name> <concentration> <quantity> <price> -- updates an existing drug\n");
	printf("delete <name> <concentration> -- deletes an existing drug\n");
	printf("list <string>\n");
	printf("listc <string>\n");
	printf("help -- shows this menu\n");
	printf("exit -- exits the application\n\n");
}

void initialize(Array *repo)
{
	add_drug(repo, create_drug("Ibusinus", 10, 32, 151));
	add_drug(repo, create_drug("Paracetamol", 10, 11, 12));
	add_drug(repo, create_drug("Faringosept", 10, 8, 11));
	add_drug(repo, create_drug("Aspirin", 15, 6, 20));
	add_drug(repo, create_drug("Tantum", 12, 15, 35));
	add_drug(repo, create_drug("Paracetamol", 20, 22, 45));
	add_drug(repo, create_drug("Decasept", 15, 6, 61));
	add_drug(repo, create_drug("Raffaello", 99, 9, 50));
	add_drug(repo, create_drug("Nutella", 999, 99, 1295));
	add_drug(repo, create_drug("Ibusinus", 20, 4, 150));
	add_drug(repo, create_drug("Ibusinus", 30, 1, 40));
}


void start()
{
	test_drug();
	test_repo();
	test_controller();
	test_darray();
	show_menu();

	Array repo;
	repo.length = 0;

	initialize(&repo);

	while (1)
	{
		printf(">>");
		char input[50];
		fgets(input, sizeof(input), stdin);
		int argv = 0;
		char argc[5][20];
		char *next_token = NULL;
		char *token = strtok_s(input, " \n", &next_token);
		while (token != NULL && argv < 5)
		{
			strcpy_s(argc[argv], sizeof(argc[argv]), token);
			token = strtok_s(NULL, " \n", &next_token);
			argv++;
		}

		if (argv > 5)
		{
			puts("[ERROR] Too many arguments!");
		}

		if (argv == 1)
		{
			if (strcmp(argc[0], "exit") == 0)
			{
				break;
			}
			else if (strcmp(argc[0], "help") == 0)
			{
				show_menu();
			}
			else if (strcmp(argc[0], "list") == 0)
			{
				Array a = print_sorted(&repo);
				print_elems(&a);
			}
			else puts("[ERROR] Invalid command!");
		}
		else if (argv == 2)
		{
			if (strcmp(argc[0], "list") == 0)
			{
				Array a = search_string(&repo, argc[1]);
				print_elems(&a);
			}
			else if (strcmp(argc[0], "listc") == 0)
			{
				Array a = search_string_c(&repo, argc[1]);
				print_elems(&a);
			}
			else puts("[ERROR] Invalid parameter(s)!");
		}
		else if (argv == 3)
		{
			if (strcmp(argc[0], "delete") == 0)
			{
				int conc = strtol(argc[2], NULL, 10);

				if (conc == 0)
					puts("[ERROR] Invalid argument(s)!");

				remove_drug(&repo, create_drug(argc[1], conc, 0, 0));
			}
			else puts("[ERROR] Invalid command!");
		}
		else if (argv == 5)
		{
			if (strcmp(argc[0], "add") == 0)
			{
				int conc = strtol(argc[2], NULL, 10);
				int quant = strtol(argc[3], NULL, 10);
				int price = strtol(argc[4], NULL, 10);

				if (conc * quant * price == 0)
					puts("[ERROR] Invalid argument(s)!");

				Drug n = create_drug(argc[1], conc, quant, price);

				if (!add_drug(&repo, n))
					puts("[ERROR] Could not add the new drug!");
			}
			else if (strcmp(argc[0], "update") == 0)
			{
				int conc = strtol(argc[2], NULL, 10);
				int quant = strtol(argc[3], NULL, 10);
				int price = strtol(argc[4], NULL, 10);

				if (conc * quant * price == 0)
					puts("[ERROR] Invalid argument(s)!");

				Drug n = create_drug(argc[1], conc, quant, price);

				if (!update_drug(&repo, n))
					puts("[ERROR] Could update the drug!");
			}
			else puts("[ERROR] Invalid command!");
		}
		else
			puts("[ERROR] Invalid number of arguments!");
		
	}
}