#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node* left;
   struct Node* right;
};

struct Node* createNode(int data)
{
   struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->data=data;
   newNode->left=newNode->right=NULL;
   return newNode;
}

struct Node* insert(struct Node* root, int data)
{
   if(root==NULL)
   {
      return createNode(data);
   }
   if(data<root->data)
   {
      root->left=insert(root->left,data);
   }
   else
   {
      root->right=insert(root->right,data);
   }
   return root;
}


struct Node* search(struct Node* root,int data)
{
   if(root==NULL)
   {
      return 0;
   }
   else if(data==root->data)
   {
      return 1;
   }
   else if(data<root->data)
   {
      return search(root->left,data);
   }
   else
   {
      return search(root->right,data);
   }
}

struct Node* findmin(struct Node* root)
{
   while(root->left!=NULL)
   {
      root=root->left;
   }
   return root;
}

struct Node* deleteNode(struct Node* root,int data)
{
  struct Node* temp=findmin(root->right);
  if(root==NULL)
  {
     return root;
  }
  if(data<root->data)
  {
     root->left=deleteNode(root->left,data);
  }
  else if(data>root->data)
  {
     root->right=deleteNode(root->right,data);
  }
  else
  {
     if(root->left==NULL)
     {
       struct Node* temp=root->right;
       free(root);
       return temp;
     }
     else if(root->right==NULL)
     {
       struct Node* temp=root->left;
       free(root);
       return temp;
     }

     root->data=temp->data;
     root->right=deleteNode(root->right,temp->data);
  }
  return root;
}

void display(struct Node* root,int space)
{
   int i;
   if(root==NULL)
   {
      return;
   }
   space+=10;
   display(root->right,space);
    printf("\n");
   for(i=10;i<space;i++)
   {
      printf(" ");
   }
   printf("%d\n",root->data);
   display(root->left,space);
}

int main()
{
  struct Node* root=NULL;
  int choice,data;
  clrscr();
  while(1)
  {
    printf("\n Binary search tree operations \n");
    printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
       case 1: printf("Enter the value to be insert: ");
	       scanf("%d",&data);
	       root=insert(root,data);
	       printf("%d inserted \n",data);
	       break;

       case 2: printf("Enter the value to delete: ");
	       scanf("%d",&data);
	       root=deleteNode(root,data);
	       printf("%d deleted \n" ,data);
	       break;

       case 3: printf("Enter value to search: ");
	       scanf("%d",&data);
	       if(search(root,data))

	       {
		  printf("%d found in the tree \n",data);
	       }
	       else
	       {
		  printf("%d not found in the tree \n",data);
	       }
	       break;

       case 4: display(root,0);
	       break;

       case 5: exit(0);
	       break;

       default: printf("Invalid coice\n");
    }
    getch();
  }

}