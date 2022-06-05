# include <stdio.h>
# include <stdlib.h>

int first_choice, manager_choice, customer_choice;

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
	char discount[10][100];
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

void Eliminate(char , char ch);
void manage_procuts1(int num_product);
void manage_prdocuts2(int num_product2);

void customer_screen();
void check_products_info1(int *i);
void check_products_info2(int *j);

void show_all_products(int num_product, int num_product2);
void products_with_discounts(int num_product, int num_product2);
void search_products(int num_product, int num_product2);


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
					printf("\n");
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
		
		switch (customer_choice)
		{
			case 1:
				show_all_products(num_product, num_product2);
				break;
			case 2:
				products_with_discounts(num_product, num_product2);
				break;
			case 3:
				search_products(num_product, num_product2);
				break;
			case 4:
				main();
				break;
		}
	}
	
	if (first_choice == 3)
	{
		system("cls");
		printf("program exits");
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

	int i, j;
	int removing_choice, editing_choice;
	
	int editing_price, editing_quantity;
	char editing_name[100],editing_name2[100], editing_discount[100], editing_date[100];
	
	int num[10];	
	
	switch (manager_choice)
	{
		case 1:
			printf("*** Store 1 ***\n");
			printf("Shopkeeper: Eldor\n");
			printf("=====================================\n");
			printf("    Products List:\n\n");
			printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
		
			for(i = 0; i < num_product; i++)
			{
				printf("    %s %s\t  %d	  %d	   %s	     %s\n\n", store1.name[i], store1.name2[i], store1.price[i], store1.quantity[i], store1.discount[i], store1.expire_date[i]);
			
			}
			printf("\n    Press any key to continue");
			break;
		
		case 2:
			printf("*** Store 1 ***\n");
			printf("Shopkeeper: Eldor\n");
			printf("=====================================\n");
			printf("    Products List by Expire Date:\n\n");
			printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
			
			
			for (i = 0; i<num_product; i++)
			{
				for(j = 0; store1.expire_date[i][j] != '\0'; j++)
				{
					if(store1.expire_date[i][j] == '-')
					{
						strcpy(store1.expire_date[i][j],store1.expire_date[i][j+1]);
						j--;
					}
				}
				num[i] = atoi(store1.expire_date[i]);
			}
			
			
			
			
			
			break;
		case 3:
			printf("*** Store 1 ***\n");
			printf("Shopkeeper: Eldor\n");
			printf("=====================================\n");
			printf("    Products List with Discounts:\n\n");
			printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
			for(i = 0; i < num_product; i++)
			{
				if (strcmp(store1.discount[i],"None") != 0)
					printf("    %s %s\t  %d	  %d	   %s	      %s\n\n", store1.name[i], store1.name2[i], store1.price[i], store1.quantity[i], store1.discount[i], store1.expire_date[i]);
			}
			printf("\n\n    Press any key to continue");
			break;
		case 4:
			printf("*** Store 1 ***\n");
			printf("Shopkeeper: Eldor\n");
			printf("=====================================\n");
			printf("    Add New Product:\n\n");
			printf("    Product Name:"); scanf("%s %s", store1.name[num_product+1], store1.name2[num_product+1]);
			printf("    Price (per item):"); scanf("%d", &store1.price[num_product+1]);
			printf("    Quantity:"); scanf("%d", &store1.quantity[num_product+1]);
			printf("    Discount:"); scanf("%s", store1.discount[num_product+1]);
			printf("    Expire date:"); scanf("%s", store1.expire_date[num_product+1]);
			
			FILE *fp;
			fp = fopen("store 1.txt","a");
			
			fprintf(fp,"\n");
			fprintf(fp, "%s %s	%d	%d	%s	%s", store1.name[num_product+1],store1.name2[num_product+1],store1.price[num_product+1],store1.quantity[num_product+1],store1.discount[num_product+1],store1.expire_date[num_product+1]);
			
			fclose(fp);
			
			system("cls");
			main();
			break;
		case 5:
			printf("*** Store 1 ***\n");
			printf("Shopkeeper: Eldor\n");
			printf("=====================================\n");
			printf("    Products List:\n\n");      
			printf("    Product ID	Product Name\n\n");
			for(i = 0; i<num_product; i++)
			{
				printf("    %d		%s %s\n\n",i+1,store1.name[i],store1.name2[i]);
			}
			printf("\n=====================================\n\n");
			printf("Enter ID of removing product: ");
			scanf("%d", &removing_choice);
			
			FILE *fp2;
			fp2 = fopen("store 1.txt", "w");
			
			for(i = 0; i < num_product; i++)
			{
				if ((i+1) != removing_choice)
				{
					fprintf(fp2, "%s %s		%d	%d	%s	%s\n",store1.name[i],store1.name2[i],store1.price[i],store1.quantity[i],store1.discount[i],store1.expire_date[i]);
				}

			}
			
			fclose(fp2);
			
			system("cls");
			main();
			break;
		case 6:
			printf("*** Store 1 ***\n");
			printf("Shopkeeper: Eldor\n");
			printf("=====================================\n");
			printf("    Products List:\n\n");
			printf("    Product ID	Product Name  Price  Quantity  Discount  Expire Date\n\n");
			for(i = 0; i<num_product; i++)
			{
				printf("    %d		%s %s	%d	%d	%s	%s\n\n",i+1,store1.name[i],store1.name2[i],store1.price[i],store1.quantity[i],store1.discount[i],store1.expire_date[i]);
			}
			printf("\n=====================================\n");
			printf("Enter ID of editing product: ");
			scanf("%d", &editing_choice);
			
			system("cls");
			printf("*** Store 1 ***\n");
			printf("Shopkeeper: Eldor\n");
			printf("=====================================\n");
			printf("    Editing Product:\n");
			printf("    Product ID: %d\n\n", editing_choice);
			printf("    Product Name: "); scanf("%s %s", editing_name, editing_name2);
			printf("    Price (per item): "); scanf("%d", &editing_price); printf("\n");
			printf("    Quantity: "); scanf("%d", &editing_quantity); printf("\n");
			printf("    Discount: "); scanf("%s", editing_discount); printf("\n");
			printf("    Expire Date: "); scanf("%s", editing_date);
			
			FILE *fp3;
			fp3 = fopen("store 1.txt","w");
			
			for(i = 0; i < num_product; i++)
			{
				if ((i+1) != editing_choice)
				{
					fprintf(fp3, "%s %s		%d	%d	%s	%s\n",store1.name[i],store1.name2[i],store1.price[i],store1.quantity[i],store1.discount[i],store1.expire_date[i]);
				}
				else if ((i+1) == editing_choice)
				{
					fprintf(fp3, "%s %s		%d	%d	%s	%s\n",editing_name,editing_name2,editing_price,editing_quantity,editing_discount,editing_date);
				}

			}
			
			fclose(fp3);
			system("cls");
			main();
			
			break;
		case 7:
			main();
			break;
	}
	
}

void manage_products2(int num_product2)
{
	
	int j;
	int removing_choice, editing_choice;
	
	int editing_price, editing_quantity;
	char editing_name[100],editing_name2[100], editing_discount[100], editing_date[100];
	
	switch (manager_choice)
	{
		case 1:
			printf("*** Store 2 ***\n");
			printf("Shopkeeper: Firuz\n");
			printf("=====================================\n");
			printf("    Products List:\n\n");
			printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
		
			for(j = 0; j < num_product2; j++)
			{
				printf("    %s %s\t  %d	  %d	   %s	     %s\n\n", store2.name[j], store2.name2[j], store2.price[j], store2.quantity[j], store2.discount[j], store2.expire_date[j]);
			
			}
			printf("\n    Press any key to continue");
			break;
		
		case 2:
			printf("*** Store 2 ***\n");
			printf("Shopkeeper: Firuz\n");
			printf("=====================================\n");
			printf("    Products List by Expire Date:\n\n");
			printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
			break;
		case 3:
			printf("*** Store 2 ***\n");
			printf("Shopkeeper: Firuz\n");
			printf("=====================================\n");
			printf("    Products List with Discounts:\n\n");
			printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
			for(j = 0; j < num_product2; j++)
			{
				if (strcmp(store1.discount[j],"None") != 0)
					printf("    %s %s\t  %d	  %d	   %s	      %s\n\n", store2.name[j], store2.name2[j], store2.price[j], store2.quantity[j], store2.discount[j], store2.expire_date[j]);
			}
			printf("\n\n    Press any key to continue");
			break;
		case 4:
			printf("*** Store 2 ***\n");
			printf("Shopkeeper: Firuz\n");
			printf("=====================================\n");
			printf("    Add New Product:\n\n");
			printf("    Product Name:"); scanf("%s %s", store2.name[num_product2+1], store2.name2[num_product2+1]);
			printf("    Price (per item):"); scanf("%d", &store1.price[num_product2+1]);
			printf("    Quantity:"); scanf("%d", &store2.quantity[num_product2+1]);
			printf("    Discount:"); scanf("%s", store2.discount[num_product2+1]);
			printf("    Expire date:"); scanf("%s", store2.expire_date[num_product2+1]);
			
			FILE *fp;
			fp = fopen("store 2.txt","a");
			
			fprintf(fp,"\n");
			fprintf(fp, "%s %s	%d	%d	%s	%s", store2.name[num_product2+1],store2.name2[num_product2+1],store2.price[num_product2+1],store2.quantity[num_product2+1],store2.discount[num_product2+1],store2.expire_date[num_product2+1]);
			
			fclose(fp);
			
			system("cls");
			main();
			break;
		case 5:
			printf("*** Store 2 ***\n");
			printf("Shopkeeper: Firuz\n");
			printf("=====================================\n");
			printf("    Products List:\n\n");      
			printf("    Product ID	Product Name\n\n");
			for(j = 0; j<num_product2; j++)
			{
				printf("    %d		%s %s\n\n",j+1,store2.name[j],store2.name2[j]);
			}
			printf("\n=====================================\n\n");
			printf("Enter ID of removing product: ");
			scanf("%d", &removing_choice);
			
			FILE *fp2;
			fp2 = fopen("store 2.txt", "w");
			
			for(j = 0; j < num_product2; j++)
			{
				if ((j+1) != removing_choice)
				{
					fprintf(fp2, "%s %s		%d	%d	%s	%s\n",store2.name[j],store2.name2[j],store2.price[j],store2.quantity[j],store2.discount[j],store2.expire_date[j]);
				}

			}
			
			fclose(fp2);
			
			system("cls");
			main();
			break;
		case 6:
			printf("*** Store 2 ***\n");
			printf("Shopkeeper: Firuz\n");
			printf("=====================================\n");
			printf("    Products List:\n\n");
			printf("    Product ID	Product Name  Price  Quantity  Discount  Expire Date\n\n");
			for(j = 0; j<num_product2; j++)
			{
				printf("    %d		%s %s	%d	%d	%s	%s\n\n",j+1,store2.name[j],store2.name2[j],store2.price[j],store2.quantity[j],store2.discount[j],store2.expire_date[j]);
			}
			printf("\n=====================================\n");
			printf("Enter ID of editing product: ");
			scanf("%d", &editing_choice);
			
			system("cls");
			printf("*** Store 2 ***\n");
			printf("Shopkeeper: Firuz\n");
			printf("=====================================\n");
			printf("    Editing Product:\n");
			printf("    Product ID: %d\n\n", editing_choice);
			printf("    Product Name: "); scanf("%s %s", editing_name, editing_name2);
			printf("    Price (per item): "); scanf("%d", &editing_price); printf("\n");
			printf("    Quantity: "); scanf("%d", &editing_quantity); printf("\n");
			printf("    Discount: "); scanf("%s", editing_discount); printf("\n");
			printf("    Expire Date: "); scanf("%s", editing_date);
			
			FILE *fp3;
			fp3 = fopen("store 2.txt","w");
			
			for(j = 0; j < num_product2; j++)
			{
				if ((j+1) != editing_choice)
				{
					fprintf(fp3, "%s %s		%d	%d	%s	%s\n",store2.name[j],store2.name2[j],store2.price[j],store2.quantity[j],store2.discount[j],store2.expire_date[j]);
				}
				else if ((j+1) == editing_choice)
				{
					fprintf(fp3, "%s %s		%d	%d	%s	%s\n",editing_name,editing_name2,editing_price,editing_quantity,editing_discount,editing_date);
				}

			}
			
			fclose(fp3);
			system("cls");
			main();
			
			break;
		case 7:
			main();
			break;
		
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
		fscanf(fp,"%s %s %d %d %s %s", &store1.name[*i], &store1.name2[*i], &store1.price[*i], &store1.quantity[*i], store1.discount[*i], store1.expire_date[*i]);
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
		fscanf(fp,"%s %s %d %d %s %s", &store2.name[*j], &store2.name2[*j], &store2.price[*j], &store2.quantity[*j], store2.discount[*j], store2.expire_date[*j]);
		(*j)++;
	}
	
	fclose(fp); 
	
}

void show_all_products(int num_product, int num_product2)
{
	int i, j;
	
	printf("*** CUSTOMER PAGE ***\n");
	printf("=====================================\n");
	printf("    Show all products:\n\n");
	printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
		
	for(i = 0; i < num_product; i++)
	{
		printf("    %s %s\t  %d	  %d	   %s	     %s\n\n", store1.name[i], store1.name2[i], store1.price[i], store1.quantity[i], store1.discount[i], store1.expire_date[i]);
	}
	for(j = 0; j < num_product2; j++)
	{
		printf("    %s %s\t  %d	  %d	   %s	     %s\n\n", store2.name[j], store2.name2[j], store2.price[j], store2.quantity[j], store2.discount[j], store2.expire_date[j]);
	}
	printf("\n    Press any key ");
}

void products_with_discounts(int num_product, int num_product2)
{
	int i, j;
	
	printf("*** CUSTOMER PAGE ***\n");
	printf("=====================================\n");
	printf("    Show products with discounts:\n\n");
	printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
	for(i = 0; i < num_product; i++)
	{
		if (strcmp(store1.discount[i],"None") != 0)
			printf("    %s %s\t  %d	  %d	   %s	      %s\n\n", store1.name[i], store1.name2[i], store1.price[i], store1.quantity[i], store1.discount[i], store1.expire_date[i]);
	}
	for(j = 0; j < num_product2; j++)
	{	
		if (strcmp(store2.discount[i],"None") != 0)
			printf("    %s %s\t  %d	  %d	   %s	      %s\n\n", store2.name[j], store2.name2[j], store2.price[j], store2.quantity[j], store2.discount[j], store2.expire_date[j]);
	}
}

void search_products(int num_product, int num_product2)
{
	int i, j;
	char first_letter;
	
	printf("*** CUSTOMER PAGE ***\n");
	printf("=====================================\n");
	printf("    Search Product (Enter first letter): ");
	getchar();
	scanf("%c", &first_letter);
	//printf("%c\n", store1.name[0][0]);
	printf("    Product Name  Price  Quantity  Discount  Expire Date\n\n");
	for(i = 0; i < num_product; i++)
	{
		if (store1.name[i][0] == first_letter)
		{
			printf("    %s %s\t  %d	  %d	   %s	     %s\n\n", store1.name[i], store1.name2[i], store1.price[i], store1.quantity[i], store1.discount[i], store1.expire_date[i]);
		}
	}
	
	for(j = 0; j < num_product2; j++)
	{	
		if (store2.name[j][0] == first_letter)
			printf("    %s %s\t  %d	  %d	   %s	     %s\n\n", store2.name[j], store2.name2[j], store2.price[j], store2.quantity[j], store2.discount[j], store2.expire_date[j]);
	}
}


