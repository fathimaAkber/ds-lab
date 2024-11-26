#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node* next;
};

struct Node* createNode(int data)
{
   struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->data=data;
   newNode->next=NULL;
   return newNode;
}

void push(struct Node** top,int data)
{
   struct Node* newNode=createNode(data);
   newNode->next=*top;
   *top=newNode;
   printf("Inserted %d\n",data);
}

int pop(struct Node** top)
{
   struct Node*temp=*top;
   int poppedData=temp->data;
   if(*top==NULL)
   {
      printf("Stack Underflow\n");
   }
   *top=(*top)->next;
   free(temp);
   printf("Popped %d \n",poppedData);
   return poppedData;
}

void traverse(struct Node*top)
{
   struct Node* temp=top;
   if(top==NULL)
   {
      printf("Stack is empty\n");
      return;
   }
   printf("Stack elements:");
   while(temp!=NULL)
   {
      printf("%d->",temp->data);
      temp=temp->next;
   }
   printf("\n");
}

void peek(struct Node* top)
{
   if(top==NULL)
   {
      printf("The Stack is empty\n");
      return;
   }
   printf("The top element is %d \n",top->data);
}

int main()
{
   struct Node*top=NULL;
   int choice,value;
   clrscr();

   while(1)
   {
      printf("\n Menu:\n");
      printf("1.Push\n");
      printf("2.Pop\n");
      printf("3.Traverse\n");
      printf("4.Peek\n");
      printf("5.Exit\n");
      printf("Enter your choice\n");
      scanf("%d",&choice);

      switch(choice)
      {
	 case 1: printf("Enter the value to push:");
		 scanf("%d",&value);
		 push(&top,value);
		 break;

	 case 2: pop(&top);
		 break;

	 case 3: traverse(top);
		 break;

	 case 4: peek(top);
		 break;

	 case 5: printf("Exiting....\n");
		 exit(0);

	 default: printf("Invalid choice\n");
      }
   }

   return 0;
}
