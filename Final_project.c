# include <stdio.h>
hi
# include <stdlib.h>

int first_choice;
char manager_choice, customer_choice;

char login[5][100], password[5][100];


struct manager_info
{
	char login[100];
	char password[100];
	char storenumber[100];
};

struct manager_info manager1, manager2;

struct store
{
	char name[10][100];
	char name2[10][100];
	int price[100];
	int quantity[100];
	int discount[100];
	char expire_date[10][100];
};

struct store store1, store2;



int a = 0;

void first_screen();

void check_manager_info();

void trying_login();
void trying_login2();

void login_success_screen1();
void login_success_screen2();

void manage_procuts1(int num_product);
void manage_prdocuts2(int num_product2);

void customer_screen();
void check_products_info1(int *i);
void check_products_info2(int *j);

void show_all_products(int num_product, int num_product2);

void main(void)
{
	int num_product = 0;
	int num_product2 = 0;
	
	
	first_screen();
	
	check_manager_info();
	
	check_products_info1(&num_product);
	check_products_info2(&num_product2);

	
	if(first_choice == 1)
	{
		trying_login();
		
		if ((strcmp(manager1.login,login[a]) || strcmp(manager1.password, password[a])) && (strcmp(manager2.login,login[a]) || strcmp(manager2.password, password[a])))
		{
			int trial_count = 1;
			printf("You have entered wrong login or password (%d/3 trials)\n", trial_count);
			trial_count++;
			a++;
			
			trying_login2();
			
			if ((strcmp(manager1.login,login[a]) || strcmp(manager1.password, password[a])) && (strcmp(manager2.login,login[a]) || strcmp(manager2.password, password[a])))
			{
				printf("You have entered wrong login or password (%d/3 trials)\n", trial_count);
				trial_count++;
				a++;
				
				trying_login2();
				
				if ((strcmp(manager1.login,login[a]) || strcmp(manager1.password, password[a])) && (strcmp(manager2.login,login[a]) || strcmp(manager2.password, password[a])))
				{
					printf("You have entered wrong login or password (%d/3 trials)\n", trial_count);
					printf("    Program exits.");
					
				}
				else if (strcmp(manager1.login,login[a]) == 0 && strcmp(manager1.password, password[a]) == 0)
				{
					system("cls");
					login_success_screen1();
					manage_products1(num_product);
					
						
				}
				else if (strcmp(manager2.login,login[a]) == 0 && strcmp(manager2.password, password[a]) == 0)
				{
					system("cls");
					login_success_screen2();
					manage_products2(num_product2);	
				}
			}
			else if (strcmp(manager1.login,login[a]) == 0 && strcmp(manager1.password, password[a]) == 0)
			{
				system("cls");
				login_success_screen1();
				manage_products1(num_product);	
			}
			else if (strcmp(manager2.login,login[a]) == 0 && strcmp(manager2.password, password[a]) == 0)
			{
				system("cls");
				login_success_screen2();
				manage_products2(num_product2);	
				
			}
		}
		else if (strcmp(manager1.login,login[a]) == 0 && strcmp(manager1.password, password[a]) == 0)
		{
			system("cls");
			login_success_screen1();
			manage_products1(num_product);	
		}
		else if (strcmp(manager2.login,login[a]) == 0 && strcmp(manager2.password, password[a]) == 0)
		{
			system("cls");
			login_success_screen2();
			manage_products2(num_product2);	
		}
	}	
	
	if (first_choice == 2)
	{
		customer_screen();
		check_products_info1(&num_product);
		check_products_info2(&num_product2);
		
		switch customer_choice;
		{
			case '1':
				show_all_products();
		}
	}
}

void first_screen()
{
	printf("*** Welcome to SKKU Stores Management ***\n");
	printf("=====================================\n");
	printf("    1. Login as shopkeeper\n");
	printf("    2. Search products\n");
	printf("    3. Exit\n");
	printf("=====================================\n");
	printf("    Enter Your Choice: ");
	scanf("%d", &first_choice);
	system("cls");
}

void check_manager_info()
{
	FILE *fp, *fp2;
	
	fp = fopen("manager 1.txt", "r");
	fp2 = fopen("manager 2.txt", "r");
	
	fscanf(fp, "login: %s\n", manager1.login);
	fscanf(fp, "Password: %s\n", manager1.password);
	fscanf(fp, "Store name: %[^\n]", manager1.storenumber);
	
	fscanf(fp2, "login: %s\n", manager2.login);
	fscanf(fp2, "Password: %s\n", manager2.password);
	fscanf(fp2, "Store name: %[^\n]", manager2.storenumber);
	
	fclose(fp);
	fclose(fp2);
	
	
}

void trying_login()
{
	printf("*** SHOPKEEPER PAGE ***\n");
	printf("=====================================\n");
	printf("    Login: ");
	scanf("%s", login[a]);
	printf("    Password: "); 
	scanf("%s", password[a]);
}

void trying_login2()
{
	printf("\n");
	printf("    Login: ");
	scanf("%s", login[a]);
	printf("    Password: "); 
	scanf("%s", password[a]);
}

void login_success_screen1()
{
	printf("*** Store 1 ***\n");
	printf("=====================================\n");
	printf("    1. Show my products\n");
	printf("    2. Sort products by expire date\n");
	printf("    3. Show products with discounts\n");
	printf("    4. Add products\n");
	printf("    5. Remove products\n");
	printf("    6. Edit products\n");
	printf("    7. Log out\n");
	printf("=====================================\n");
	printf("    Enter Your Choice: ");
	scanf("%d", &manager_choice);
	system("cls");
}

void manage_products1(int num_product)
{

	int i;
	
	switch manger_choice;
	{
		case '1':
			printf("*** Store 1 ***\n");
			printf("=====================================\n");
			printf("    Products List:\n");
			printf("    Product Name  Price  Quantity  Discount  Expire Date\n");
		
			for(i = 0; i < num_product; i++)
			{
				printf("    %s %s\t  %d	  %d	    %d	      %s\n", store1.name[i], store1.name2[i], store1.price[i], store1.quantity[i], store1.discount[i], store1.expire_date[i]);
			
			}
			printf("\n    Press any key to continue");
		
		case '2':
			printf("*** Store 1 ***\n");
			printf("=====================================\n");
		case '3':
			printf("*** Store 1 ***\n");
			printf("=====================================\n");
		case '4':
			printf("*** Store 1 ***\n");
			printf("=====================================\n");
		case '5':
			printf("*** Store 1 ***\n");
			printf("=====================================\n");
		case '6':
			printf("*** Store 1 ***\n");
			printf("=====================================\n");
		case '7':
			printf("*** Store 1 ***\n");
			printf("=====================================\n");
	}
	
}

void manage_products2(int num_product2)
{
	
	int j;
	if (manager_choice == 1)
	{
		printf("*** Store 2 ***\n");
		printf("=====================================\n");
		printf("    Products List:\n");
		printf("    Product Name  Price  Quantity  Discount  Expire Date\n");
		for(j = 0; j < num_product2; j++){
			printf("    %s %s\t  %d	  %d	    %d	      %s\n", store1.name[j], store1.name2[j], store1.price[j], store1.quantity[j], store1.discount[j], store1.expire_date[j]);
			
		}
		printf("\n    Press any key to continue");
		
	}
	else if (manager_choice == 2)
	{
		printf("*** Store 2 ***\n");
		printf("=====================================\n");
	}
	else if (manager_choice == 3)
	{
		printf("*** Store 2 ***\n");
		printf("=====================================\n");
	}
	else if (manager_choice == 4)
	{
		printf("*** Store 1 ***\n");
		printf("=====================================\n");
	}
	else if (manager_choice == 5)
	{
		printf("*** Store 2 ***\n");
		printf("=====================================\n");
	}
	else if (manager_choice == 6)
	{
		printf("*** Store 2 ***\n");
		printf("=====================================\n");
	}
	else if (manager_choice == 7)
	{
		printf("*** Store 2 ***\n");
		printf("=====================================\n");
	}
}

void login_success_screen2()
{
	printf("*** Store 2 ***\n");
	printf("=====================================\n");
	printf("    1. Show my products\n");
	printf("    2. Sort products by expire date\n");
	printf("    3. Show products with discounts\n");
	printf("    4. Add products\n");
	printf("    5. Remove products\n");
	printf("    6. Edit products\n");
	printf("    7. Log out\n");
	printf("=====================================\n");
	printf("    Enter Your Choice: ");
	scanf("%d", &manager_choice);
	system("cls");
}

void customer_screen()
{
	printf("*** CUSTOMER PAGE ***\n");
	printf("=====================================\n");
	printf("    1. Show all products\n");
	printf("    2. Show products with discounts\n");
	printf("    3. Search for specific product\n");
	printf("    4. Go to start page\n");
	printf("=====================================\n");
	printf("    Enter Your Choice: ");
	scanf("%d", &customer_choice);
	system("cls");
}

void check_products_info1(int *i)
{
	FILE *fp;
	
	fp = fopen("store 1.txt", "r");
	
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d %d %s", &store1.name[*i], &store1.name2[*i], &store1.price[*i], &store1.quantity[*i], &store1.discount[*i], store1.expire_date[*i]);
		(*i)++;
	}
	
	fclose(fp); 
	
}

void check_products_info2(int *j)
{
	FILE *fp;
	
	fp = fopen("store 2.txt", "r");
	
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d %d %s", &store2.name[*j], &store2.name2[*j], &store2.price[*j], &store2.quantity[*j], &store2.discount[*j], store2.expire_date[*j]);
		(*j)++;
	}
	
	fclose(fp); 
	
}

void show_all_products(int num_product, int num_product2)
{
	printf("*** CUSTOMER PAGE ***\n");
	printf("=====================================\n");
	printf("    Show all products:\n");
	printf("    Product Name  Price  Quantity  Discount  Expire Date\n");
		
	for(i = 0; i < num_product; i++)
	{
		printf("    %s %s\t  %d	  %d	    %d	      %s\n", store1.name[i], store1.name2[i], store1.price[i], store1.quantity[i], store1.discount[i], store1.expire_date[i]);
	}
	for(j = 0; j < num_product2; j++)
	{
		printf("    %s %s\t  %d	  %d	    %d	      %s\n", store1.name[j], store1.name2[j], store1.price[j], store1.quantity[j], store1.discount[j], store1.expire_date[j]);
	}
	printf("\n    Press any key ")
}

