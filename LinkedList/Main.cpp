#include <stdio.h>
#include <stdlib.h>



struct node
{
	int data; 
	int index; 
	struct node * next; 
	struct node * previous;
};

node* head = NULL;


void main()
{
	void addNodeFrontList();
	void addNodeBackList();
	void addNodeBeforePosition();
	void addNodeAfterPosition();
	void printForward();


	int optionMenu = 0; 
	do
	{
		printf("****************************MENU*************************************\n");
		printf("1 - Add a node to the front of the list.\n");
		printf("2 - Add a node to the back of the list.\n");
		printf("3 - Add a node to the middle of the list after a specific node.\n");
		printf("4 - Add a node to the middle of the list before a specific node.\n");
		printf("5 - Delete a node from the front of the list.\n");
		printf("6 - Delete a node from the back of the list.\n");
		printf("7 - Delete a node from the middle of the list after a specific node.\n");
		printf("8 - Delete a node from the middle of the list before a specific node.\n");
		printf("9 - Print a list forward.\n");
		printf("10- Print a list backward.\n");
		scanf("%d", &optionMenu);


		switch (optionMenu)
		{
		case 1:
			addNodeFrontList();
			break;
		case 2:
			addNodeBackList();
			break;
		case 3:
			addNodeBeforePosition();
			break;
		case 4:
			addNodeAfterPosition();
			break;
		case 9:
			printForward();
			break;
		default:
			break;
		}

	} while (optionMenu!=11);



}

void addNodeFrontList()
{
	node* createNode(int, node*, node*);

	node* newNode;
	int data; 
	system("cls");
	printf("****** ADD NODE ******\n");
	printf("Please insert a integer for the node:\n");
	scanf_s("%d", &data);

	if (head == NULL)
	{
		head = createNode(data, NULL, NULL);
	}
	else 
	{
		newNode = createNode(data, head,NULL);
		head->previous = newNode; 
		head = newNode;
	}
	printf("Node created successfully!\n");
	system("pause");
	system("cls");
}

void addNodeBackList()
{
	node* createNode(int, node*, node*);
	node* newNode;
	node* cursor;
	int data;

	system("cls");
	printf("****** ADD NODE ******\n");
	printf("Please insert a integer for the node:\n");
	scanf("%d", &data);

	if (head == NULL)
	{
		head = createNode(data, NULL, NULL);
	}
	else 
	{
		cursor = head;
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
		newNode = createNode(data, NULL, cursor);
		cursor->next = newNode;
	}
	system("pause");
	system("cls");
}

void addNodeBeforePosition(){
	
	node* createNode(int, node*, node*);
	node* newNode;
	node* cursor;
	int data;
	int position = 0;
	int currentPosition = 0;

	system("cls");
	printf("****** ADD NODE ******\n");
	printf("Please insert a integer for the node:\n");
	scanf("%d", &data);
	printf("Before each position?\n");
	scanf("%d", &position);

	cursor = head;
	while (currentPosition < position -1 )
	{
		if (cursor->next == NULL)
		{
			printf("Sorry, there is no node on position #%d\n",position);
			system("pause");
			exit(0);
		}
		cursor = cursor->next;
		currentPosition++;
	}

	newNode = createNode(data, cursor, cursor->previous);
	cursor->previous->next = newNode;
	cursor->previous = newNode;
	
	system("pause");
	system("cls");
}

void addNodeAfterPosition(){

	node* createNode(int, node*, node*);
	node* newNode;
	node* cursor;
	int data;
	int position = 0;
	int currentPosition = 0;

	system("cls");
	printf("****** ADD NODE ******\n");
	printf("Please insert a integer for the node:\n");
	scanf("%d", &data);
	printf("Before each position?\n");
	scanf("%d", &position);

	cursor = head;
	while (currentPosition < position - 1)
	{
		if (cursor->next == NULL)
		{
			printf("Sorry, there is no node on position #%d\n", position);
			system("pause");
			exit(0);
		}
		cursor = cursor->next;
		currentPosition++;
	}

	newNode = createNode(data, cursor->next, cursor);
	cursor->next = newNode;
	cursor->next->previous = newNode;
	
	system("pause");
	system("cls");
}

node* createNode(int data, node* next, node* prev)
{
	node* newNode = (node*)malloc(sizeof(node));
	
	if (newNode == NULL)
	{
		printf("Error creating a new node");
		exit(0);
	}

	newNode->data = data;
	newNode->next = next;
	newNode->previous = prev;
	return newNode;
}


node* getLasttNode()
{
	node* cursor = head; 
	while (cursor->next != NULL) cursor = cursor->next;
	return cursor;
}

void printForward()
{
	system("cls");
	node* cursor = head;
	while (cursor != NULL) {
		printf("Node data: %d\n", cursor->data);
		cursor = cursor->next;
	}
	system("pause");
	system("cls");
}

void printBackword()
{
	system("cls");
	node* cursor = head;
	while (cursor != NULL) {
		
		cursor = cursor->next;
	}

	do
	{
		printf("Node data: %d\n", cursor->data);
		cursor = cursor->previous;
	} while (cursor != head);
	system("pause");
	system("cls");

}