#include "train_structs.h"

void update_train_schedule(struct train *p, int num_reserve)
{
	printf("Enter name of Train:");
	scanf("%s",(p + num_reserve)->name);
	printf("From:");
	scanf("%s",(p + num_reserve)->from);
	printf("Destination:");
	scanf("%s",(p + num_reserve)->to);
	printf("Cost:");
	scanf("%f",&(p + num_reserve)->cost);
	(p + num_reserve)->train_id =num_reserve;
	(p + num_reserve)->seats =200; //assumed that total number of seats in a train is 200
}
void disp_train(struct train *p, int n)
{
	printf("        Trains Available        \n");
	for(int i=0; i<n; i++)
	{
		printf("Train number/id: %d\n",(p+i)->train_id);
		printf("Train Name: %s\n",(p+i)->name);	
		printf("From: %s\n",(p+i)->from);
		printf("Destination: %s\n",(p+i)->to);
		printf("Cost: Rs %f\n",(p+i)->cost);
		printf("-------------------------------------------------\n");
	}	
}

void disp_cust(struct person *p, int n)
{
	for(int i=0; i<n; i++)
	{
		printf("Customer ID: %d\n",(p+i)->id);
		printf("Name: %s\n",(p+i)->name);
		printf("Phone num: %s\n",(p+i)->phone);	
		printf("-------------------------------------------------\n");
	}	
}
float total_cost(int num_seats, float cost)
{
	return (num_seats*cost);
}									
void reservation(struct train *p1, struct person *p2, struct booking *p3, int id, int count)
{
	int trainid,train_seat;
	float value,price;
	(p3 + id)->id = id;
	disp_train(p1,count);
	printf("Enter the train ID of your choice:");
	scanf("%d",&trainid);
	(p3 + id)->train_id = trainid;
	price = (p1+trainid)->cost;
	if((p1 + trainid)->seats >= 0)
	{
		printf("Seats available: %d\n",(p1 + trainid)->seats);
		printf("Enter required no. of seats: ");
		scanf("%d",&train_seat);
		(p1+trainid)->seats = (p1+trainid)->seats - train_seat;
		if((p1 + trainid)->seats >= 0)
		{
			printf("Seats Booked!\n");
			(p3 + id)->seats = train_seat;
			value = total_cost(train_seat, price);
			(p2+id)->cost = value;
			printf("Total Amount to be paid: %f\n",(p2+id)->cost);
		}
		else
		{
			printf("Booking failed\n");
		}
	}
	else
	{
		printf("Sorry, Reservation seats are full.\n");
	}			
}				
					
void disp_train_details(struct train *p1, int n)
{
	printf("        Train Details       \n");
	printf("Train Number/ID: %d\n",(p1+n)->train_id);
	printf("Train Name: %s\n",(p1+n)->name);
	printf("From: %s\n",(p1+n)->from);
	printf("Destination: %s\n",(p1+n)->to);	
	printf("Cost: Rs %f\n",(p1+n)->cost);
	printf("Seats: %d\n",(p1+n)->seats);
	printf("-------------------------------------------------\n");	
}					
					
void disp_cust_details(struct person *p1, struct booking *p2, int n)
{
	printf("        Customer details       \n");
	printf("Customer ID: %d\n",(p1+n)->id);
	printf("Name: %s\n",(p1+n)->name);
	printf("Phone num: %s\n",(p1+n)->phone);
	printf("Train booked: %d\n",(p2+n)->train_id);
	printf("No. of seats: %d\n",(p2+n)->seats);	
	printf("-------------------------------------------------\n");
}					
void cust_details_entry(struct person *p1, int nperson)
{
	printf("Name:");
	scanf("%s",(p1 + nperson)->name);
	printf("Phone Number:");
	scanf("%s",(p1 + nperson)->phone);
	(p1 + nperson)->id = nperson;
}

