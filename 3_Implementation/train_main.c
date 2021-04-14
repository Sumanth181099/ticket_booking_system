#include<stdio.h>
#include<string.h>
#include"train_structs.h"

void update_train_schedule(struct train *, int );
void disp_train(struct train *, int );
void cust_details_entry(struct person *, int );
void reservation(struct train *, struct person *, struct booking *, int , int );
void disp_cust(struct person *, int );
void disp_train_details(struct train *, int );
void disp_cust_details(struct person *, struct booking *, int );
float total_cost(int , float );

int main()
{
	struct train ptr1[100];
	struct person ptr2[100];
	struct booking ptr3[100];
	int x,num_reserve=0,nperson=0;
	char password[20];
	char actual_pass[20] = "Admin@123"; //Password
	int a = 0,b = 0;
	
	while(x!=6)
	{
		int choice;
		printf("                Train Reservation Seats Booking System\n");
		printf(" -------------------------------------------------------------------\n");
		printf("               1- Update Train Schedule (Admin):           \n");
		printf("               2- Check Reservations made (Admin):          \n");
		printf("               3- Book tickets:                              \n");
		printf("               4- Check Train Schedule:                             \n");
		printf("               5- Customer List:                                    \n");
		printf("               6- Exit system:                                    \n");
		printf(" ------------------------------------------------------------------ \n");
		printf("  Choose a suitable option of your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter Admin password:\n");
				scanf("%s",&password);
				if (strcmp(password,actual_pass)==0)
				{
				
					if(num_reserve>=0)
					{
						update_train_schedule(ptr1, num_reserve);
						num_reserve = num_reserve+1;
					}
				}
				break;
			case 2:
				printf("Enter Admin password:\n");
				scanf("%s",&password);
				if (strcmp(password,actual_pass)==0)
				{
					int y=0;
					while(y!=3)
					{	
						int ch;
						printf("                 Admin Options\n");
						printf(" -------------------------------------------------------------------\n");
						printf("               1- Check Train routes:           \n");
						printf("               2- Check Customer bookings:          \n");
						printf("               3- Exit:                              \n");
						printf(" ------------------------------------------------------------------ \n");
						printf("  Enter your choice: ");
						scanf("%d",&ch);
						
						switch(ch)
						{
							case 1:
								while(a!=3)
								{
									int train_details;
									printf(" -------------------------------------------------------------------\n");
									printf("               1- Print the train details:           \n");
									printf("               2- Search for a specific train number/ID:          \n");
									printf("               3- Exit:                              \n");
									printf(" ------------------------------------------------------------------ \n");
									printf("  Enter your choice: ");
									scanf("%d",&train_details);
									switch(train_details)
									{
										int req_id;
										case 1:
											disp_train(ptr1, num_reserve);			
											break;
										case 2:
											printf("Enter ID:\n");
											scanf("%d",&req_id);
											disp_train_details(ptr1,req_id);
											break;
										case 3:
											a=3;
											break;
										default: 
											printf("Incorret Entry\n");
											break;
									}
								}
								break;	
							case 2:
								while(b!=3)
								{
									int cust_details;
									printf(" -------------------------------------------------------------------\n");
									printf("               1- Print Customer details:           \n");
									printf("               2- Search for a specific customer ID:          \n");
									printf("               3- Exit:                              \n");
									printf(" ------------------------------------------------------------------ \n");
									printf("  Enter your choice: ");
									scanf("%d",&cust_details);
									switch(cust_details)
									{
										int customer_id;
										case 1:
											disp_cust(ptr2, num_reserve);			
											break;
										case 2:
											printf("Enter ID:\n");
											scanf("%d",&customer_id);
											disp_cust_details(ptr2,ptr3,customer_id);
											break;
										case 3:
											b=3;
											break;
										default: 
											printf("Incorret Entry\n");
											break;
									}
								}
								break;	
							case 3:
								y=3;
								break;
							default: 
								printf("Incorret Entry\n");
								break;
						}
					}
				}
				break;
			case 3:
				if(nperson>=0)
				{
					cust_details_entry(ptr2, nperson);
					reservation(ptr1,ptr2,ptr3,nperson,num_reserve);
					nperson = nperson+1;
				}
				break;
			case 4:
				disp_train(ptr1, num_reserve);			
				break;
			case 5:
				disp_cust(ptr2, nperson);
				printf("        Customers List        \n");			
				break;
			case 6:
				x=6;
				break;
			default: 
				printf("Incorret Entry\n");
				break;
		}
	}
	return 0;
}	


									
					
					
					
					
					
					
					
					
					
