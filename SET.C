#include<stdio.h>
#include<conio.h>
void input();
void output();
void setUnion();
void intersection();
void difference();
int a[]={0,0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0,0},c[]={0,0,0,0,0,0,0,0,0};

int main()
{
   int ch,wish;
   clrscr();
   while(1)
   {
       printf("\n Menu \n");
       printf("\n 1.Input\n 2. Union\n 3.Intersection\n 4.Difference\n 5.Exit\n");
       printf("\n Enter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	  case 1:input();
		 break;

	  case 2: setUnion();
		  break;

	  case 3: intersection();
		  break;

	  case 4: difference();
		  break;

	  case 5: exit(0);
		  break;

	  default : printf("\n Wrong Choice");
       }
       getch();
   }
}

void input()
{
   int n,ele,i;
   printf("\n Enter the size of the first set:");
   scanf("%d",&n);
   printf("\n Enter the elements \n");
   for(i=1;i<=n;i++)
   {
      scanf("%d",&ele);
      a[ele]=1;
   }
   printf("Enter the size of the Second set");
   scanf("%d",&n);
   printf("\n Enter the elements \n");
   for(i=1;i<=n;i++)
   {
      scanf("%d",&ele);
      b[ele]=1;
   }
   printf("\n Set 1:{");
   for(i=1;i<=9;i++)
   {
      printf("%d",a[i]);
   }
   printf("}");
   printf("\n Set 2:{");
   for(i=1;i<=9;i++)
   {
      printf("%d" ,b[i]);
   }
   printf("}");
}

void output(int c[])
{
   int i;
   printf("\n Set:{");
   for(i=1;i<=9;i++)
   {
      if(c[i]!=0)
      {
	 printf("%d \t",i);
      }
   }
   printf("}");
}

void setUnion()
{
   int i,c[10];
   for(i=1;i<=9;i++)
   {
      if(a[i]!=b[i])
      {
	 c[i]=1;
      }
      else
      {
	 c[i]=a[i];
      }
   }
   printf("Union of Set 1 and Set 2 is :{" );
   for(i=1;i<=9;i++)
   {
      printf("%d" ,c[i]);
   }
   printf("}");
   output(c);
}

void intersection()
{
   int i,c[10];
   for(i=1;i<=9;i++)
   {
      if(a[i]==b[i])
      {
	 c[i]=a[i];
      }
      else
      {
	 c[i]=0;
      }
   }
   printf("Intersection of Set 1 and Set 2 is:{");
   for(i=1;i<=9;i++)
   {
      printf("%d" ,c[i]);
   }
   printf("}");
   output(c);
}

void difference()
{
   int i;c[10];
   for(i=1;i<=9;i++)
   {
      if(a[i]==1&&b[i]==0)
      {
	 c[i]=1;
      }
      else
      {
	 c[i]=0;
      }
   }
   printf("Differnce between of Set 1 and Set 2 is:{");
   for(i=1;i<=9;i++)
   {
      printf("%d",c[i]);
   }
   printf("}");
   output(c);
}





