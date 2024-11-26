#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node* next;
   struct Node* prev;
};

struct Node* createNode(int data)
{
   struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->data=data;
   newNode->next=NULL;
   newNode->prev=NULL;
   return newNode;
}

void insertAtBegining(struct Node** head,int data)
{
   struct Node* newNode=createNode(data);
   newNode->next=*head;
   if(*head!=NULL)
   {
      (*head)->prev=newNode;
   }
   *head=newNode;
}

void insertAtEnd(struct Node** head,int data)
{
   struct Node* temp=*head;
   struct Node* newNode=createNode(data);
   if(*head==NULL)
   {
      *head=newNode;
      return;
   }
   while(temp->next!=NULL)
   {
      temp=temp->next;
   }
   temp->next=newNode;
   newNode->prev=temp;
}

void insertAtPosition(struct Node** head,int data,int position)
{
   int i;
   struct Node* newNode=createNode(data);
   struct Node* temp=*head;
   if(position==0)
   {
      insertAtBegining(head,data);
      return;
   }
   for(i=0;i<position-1 && temp!=NULL;i++)
   {
      temp=temp->next;
   }
   if(temp==NULL)
   {
      printf("Position out of bounds \n");
      free(newNode);
      return;
   }
   newNode->next=temp->next;
   newNode->prev=temp;
   if(temp->next!=NULL)
   {
      temp->next->prev=newNode;
   }
   temp->next=newNode;
}

void deleteAtBegining(struct Node** head)
{
   struct Node** temp=NULL;
   if(*head==NULL)
   {
      printf("List is empty\n");
      return;
   }
   *head=(*head)->next;
   if(*head!=NULL)
   {
      (*head)->prev=NULL;
   }
   free(temp);
}

void deleteAtEnd(struct Node** head)
{
   struct Node* temp=*head;
   if(*head==NULL)
   {
      printf("List is empty\n");
      return;
   }
   while(temp->next!=NULL)
   {
      temp=temp->next;
   }
   if(temp->prev!=NULL)
   {
      temp->prev->next=NULL;
   }
   else
   {
      *head=NULL;
   }
   free(temp);
}

void deleteAtPosition(struct Node** head,int position)
{
   int i;
   struct Node* temp=*head;
   if(*head==NULL)
   {
      printf("List is empty\n");
      return;
   }
   if(position==0)
   {
      deleteAtBegining(head);
      return;
   }
   for(i=0;i<position&&temp!=NULL;i++)
   {
      temp=temp->next;
   }
   if(temp==NULL)
   {
      printf("Position out of bounds\n");
      return;
   }
   if(temp->prev!=NULL)
   {
      temp->prev->next=temp->next;
   }
   if(temp->next!=NULL)
   {
      temp->next->prev=temp->prev;
   }
   free(temp);
}

struct Node* search(struct Node* head,int key)
{
   struct Node* temp=head;
   while(temp!=NULL)
   {
      if(temp->data==key)
      {
	  return temp;
      }
      temp=temp->next;
   }
   return NULL;
}

void printlist(struct Node* head)
{
   struct Node* temp=head;
   while(temp!=NULL)
   {
       printf("%d ",temp->data);
       temp=temp->next;
   }
   printf("\n");
}

int main()
{
   struct Node* head=NULL;
   int choice,data,position;
   struct Node* foundNode=search(head,data);
   clrscr();

   while(1)
   {
      printf("\n Doubly LinkedList Operations:\n");
      printf("1.Insert at Begining\n");
      printf("2.Insert at End\n");
      printf("3.Insert at any Position\n");
      printf("4.Delete at Begining\n");
      printf("5.Delete at End\n");
      printf("6.Delete at any Position\n");
      printf("7.Serach \n");
      printf("8.Print list\n");
      printf("9.Exit\n");
      printf("Enter your choice:");
      scanf("%d",&choice);

      switch(choice)
      {
	 case 1: printf("Enter the data to insert at begining:");
		 scanf("%d",&data);
		 insertAtBegining(&head,data);
		 break;
	 case 2: printf("Enter the data to insert at end:");
		 scanf("%d ",&data);
		 insertAtEnd(&head,data);
		 break;
	 case 3: printf("Enter the data and position to insert:");
		 scanf("%d %d ",&data,&position);
		 insertAtPosition(&head,data,position);
		 break;
	 case 4: deleteAtBegining(&head);
		 break;
	 case 5: deleteAtEnd(&head);
		 break;
	 case 6: printf("Enter position to delete:");
		 scanf("%d",&position);
		 deleteAtPosition(&head,position);
		 break;
	 case 7: printf("Enter data to search:");
		 scanf("%d ",&data);

		 if(foundNode)
		 {
		     printf("Element %d found in the list \n",foundNode->data);
		 }
		 else
		 {
		     printf("Elements not found\n");
		 }
		 break;
	 case 8: printf("Current List:");
		 printlist(head);
		 break;
	 case 9: exit(0);
		 break;
	 default : printf("Invalid Choice .please Try again");
      }
   }
   return 0;
}