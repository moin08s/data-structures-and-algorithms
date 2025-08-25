#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Function prototypes updated to match the function definitions
void push(int* stack, int size, int* top);
int pop(int* stack, int* top);
void display(int* stack, int* top,int size);
bool is_empty(int* top);
bool is_full(int size, int* top);

int main()
{
	int size;
	int* stack;
	int top = -1;

	printf("Enter the stack size:");
	scanf("%d", &size);

	// Dynamically allocate memory for the stack using malloc
	stack = (int*)malloc(size * sizeof(int));
	
	if(stack == NULL)
	{
		printf("Memory is not sufficient\n");
	}
	else
	{
		int ch;
		
		do
		{
			printf("********************\n");
			printf("Stack Operations:\n");
			printf("1. Check if empty\n");
			printf("2. Check if full\n");
			printf("3. Push\n");
			printf("4. Pop\n");
			printf("5. Display\n");
			printf("6. Exit\n");
			printf("********************\n");
			printf("Choice:");
			
			scanf("%d", &ch);
			
			switch(ch)
			{
				case 1:
					if(is_empty(&top))
					{
						printf("Stack is Empty\n");
					}
					else
					{
						printf("Stack is not Empty\n");
					}
					break;
				
				case 2:
					if(is_full(size, &top))
					{
						printf("Stack is Full\n");
					}
					else
					{
						printf("Stack is not Full\n");
					}
					break;
				
				case 3:
					push(stack, size, &top);
					break;
				
				case 4:
					pop(stack, &top);
					break;
				
				case 5:
					display(stack, &top,size);
					break;
				
				case 6:
					printf("Exiting...\n");
					break;
					
				default:
					printf("Invalid choice. Please try again.\n");
					break;
			}
		} while(ch != 6);

		// Free the dynamically allocated memory
		free(stack);
	}

	return 0;
}

// is_empty now returns a boolean
bool is_empty(int* top)
{
	if(*top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// is_full now returns a boolean
bool is_full(int size, int* top)
{
	if(size - 1 == (*top))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// push function now returns void
void push(int* stack, int size, int* top)
{
	if(!is_full(size, top))
	{
		int number;
		printf("Enter the number to push:");
		scanf("%d", &number);
		
		(*top)++;
		stack[(*top)] = number;
		printf("%d added to stack\n", number);
	}
	else
	{
		printf("Stack is Full\n");
	}	
}

// pop function now returns void
int pop(int* stack, int* top)
{
	if(!is_empty(top))
	{
		printf("%d is removed from the stack\n", stack[*top]);
		(*top)--;
	}
	else
	{
		printf("Stack is empty\n");
	}
	return 0; // Added a return value to satisfy the function signature
}

// display function now returns void and takes a pointer to top
void display(int* stack, int* top,int size)
{
	
		
		printf("Stack:\n");
		
		for(int i=size-1;i>*(top)-1;i--)
		{ 
		printf("........\n");
		printf("|      |\n");
		printf("........\n");
		 
		}
		
		// Loop from the bottom of the stack to the top
		for(int i = *top; i >= 0; i--)
		{     	if(i==*top)
			{
			printf("........\n");
			printf("|  %d  | ---> Top\n", stack[i]);
			printf("........\n");
			}
			else
			{
			printf("........\n");
			printf("|  %d  |\n", stack[i]);
			printf("........\n");
			}
			
			
			
			
		}
		
		
		
}
