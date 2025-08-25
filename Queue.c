#include<stdio.h>
#include<stdlib.h>

void enqueue(int* queue,int* front,int* rear,int* size);
int condition(int* front, int* rear,int* size);
void dequeue(int* queue,int* front,int* rear,int* size);
void display(int* queue,int* front, int* rear,int* size);

void main()
{ 
int size,front=0,rear=0;



printf("Enter the Size of Queue:");
scanf("%d",&size);

int* queue;
//Dynamic memory for Queue
queue=(int*)malloc(size * sizeof(int));

if(queue==NULL)//check if memory is assigned or mot
	{
		printf("Memory is not sufficient\n");
	}
else
	{
		int ch;
		do{     printf("-----------------\n");
			printf("Queue Operation:\n");
			printf("1.Enqueue():\n");
			printf("2.Dequeue():\n");
			printf("3.Check the Condition():\n");
			printf("4.Display:\n");
			printf("-----------------\n");
			printf("Choice:");
			
			
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1:enqueue(queue,&front,&rear,&size);
				      break;
				 case 2:dequeue(queue,&front,&rear,&size);
				 	break;
				 case 3:int var=condition(&front,&rear,&size);
				 	if(var==0)
				 printf("Queue has reach at his limit(Dequeue)\n");
				 	else if(var==1)
				 printf("Queue has reach at his limit(Enqueue)\n");
				        else 
				 {
				       if(rear==front)
				       {
				       printf("Queue is empty\n");
				       }
				       else
				       {
				       printf("Some data in queue\n");//
				       }
				 }
				 	break;
				 case 4:display(queue,&front,&rear,&size);
				        break;
				  default:printf("Invalid condition\n");
				 	printf("Exiting.....\n");
				  				
			}
			
		
			
			}
			while(ch<=4&&ch>0);
			free(queue);
			
	}
	
}
//Funcion for Enqueue
void enqueue(int* queue,int* front,int* rear,int* size)
{
	if(condition(front,rear,size)==1||*rear==*size)//check the queue has reached its limit or Queue is full by Fun()
	{     if(*rear==*size)
		printf("Queue has reach at his limit(Enqueue)\n");
	else
		printf("Queue is full\n");
	}
	else
	{
		int num;
		printf("Enter the number:");
		scanf("%d",&num);
		
		
		queue[*rear]=num;
		(*rear)++;
		
		
		printf("%d added to the queue\n",num);
		
		
	}
}
//Function for dequeue
void dequeue(int* queue,int* front,int* rear,int* size)
{
	if(condition(front,rear,size)==0||*front==*size)
	{
	if(*front==*size)
		printf("Queue has reach at his limit(Dequeue)\n");
		else
		printf("Queue is empty\n");
	}
	else
	{       
		  printf("Dequeue element:%d\n",queue[*front]);
		(*front)++;
	
		
	}
}
//Function for checking Queue Conditon
int condition(int* front, int* rear,int* size)//check the queue has reached its limit or Queue is empty by Fun()
{	if(*front==*size)//chech the enqueue  condition(limit)
	{
	   return 0;
	}
	else if(*rear==*size)//chech the dequeue  condition(limit)
	{
	return 1;
	}
	
	else 
	{
	return 2;
	
	}

	

}
//Function for display Queue
void display(int* queue,int* front, int* rear,int* size)
{ 

	
		printf("Queue:\n");
		
		                for(int k=0;k<*front;k++)
					{ 
					
					printf("........\n");	
					printf("|      |\n");
					printf("........\n");	
					
					}
			
				for(int i=*front;i<*rear;i++)
					{  		   
		
							if(i==*front)//Point to front
								{
							printf("........\n");
							printf("|  %d  |----->Front\n",queue[i]);
							printf("........\n");	
							
							
								}
							else if(i==(*rear)-1)//point to the rear
							{
							printf("........\n");
							printf("|  %d  |----->Rear\n",queue[i]);
							printf("........\n");	
							
							
							}
							else
							{
							printf("........\n");	
							printf("|  %d  |\n",queue[i]);
							printf("........\n");
							
							}
					}
				
					for(int j=(*rear)-1;j<(*size)-1;j++)
					{ if(j==(*size)-1)
					{
					printf("........\n");	
					printf("|      |\n");
					printf("........\n");
					 
					}
					else
					{
					printf("........\n");	
					printf("|      |\n");
					printf("........\n");
					
					}
					}
					
			  				
			   		
					
			
		
				
	
	
}

