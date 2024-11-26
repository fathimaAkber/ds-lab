#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Disjoint
{
 int parent[10];
 int rank[10];
 int n;
}dis;
void makeSet()
 {
  int i;
  for(i=0;i<dis.n;i++)
   {
     dis.parent[i]=i;
     dis.rank[i]=0;
   }
 }
 void displaySet()
  {
   int i;
   printf("parent array:");
    for(i=0;i<dis.n;i++)
     {
      printf("%d",dis.parent[i]);
     }
   printf("Rank array:");
    for(i=0;i<dis.n;i++)
     {
      printf("%d",dis.rank[i]);
     }
  }


int find(int x)
 {
  if(dis.parent[x]!=x)
   {
    dis.parent[x]=find(dis.parent[x]);
   }
   return dis.parent[x];
 }

void Union(int x,int y)
 {
   int xset=find(x);
   int yset=find(y);
   if(xset==yset)
   return;
   if(dis.rank[xset]<dis.rank[yset])
    {
      dis.parent[xset]=yset;
      dis.rank[xset]=-1;
    }

    else if(dis.rank[xset]>dis.rank[yset])
     {
      dis.parent[yset]=xset;
      dis.rank[yset]=-1;
     }
    else
     {
      dis.parent[yset]=xset;
      dis.rank[xset]=dis.rank[xset]+1;
      dis.rank[yset]=-1;
     }
 }
 void main()
  {
   int n,x,y,choice;
   clrscr();
   printf("How many elements:");
   scanf("%d",&dis.n);
   while(1)
    {
      printf("\n1.union\n2.find\n3.display\n4.exit");
      printf("\nEnter your choice:");
      scanf("\n%d",&choice);
      switch(choice)
      {

      case 1:printf("Enter the elements to perform union:");
	     scanf("%d%d",&x,&y);
	     Union(x,y);
	     break;
     case 2:printf("Enter the elements to check:");
	    scanf("%d%d",&x,&y);
	    if(find(x)==find(y))
	     {
	      printf("%d and%d are connected components:");
	     }
	     else
	      {
	       printf("%d and %d are not connected components");
	      }
	     break;
    case 3:displaySet();
	   break;
    case 4:exit(1);
	   break;
    default:printf("Invalid choice");

   }
  }

 }