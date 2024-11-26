#include<stdio.h>
#include<conio.h>

void mergeSortedArray(int arr1[],int size1,int arr2[],int size2,int result[])
{
   int i=0,j=0,k=0;
   while(i<size1&&j<size2)
   {
      if(arr1[i]<arr2[j])
      {
	 result[k++]=arr1[i++];
      }
      else
      {
	 result[k++]=arr2[j++];
      }
   }

   while(i<size1)
   {
      result[k++]=arr1[i++];
   }

   while(j<size2)
   {
      result[k++]=arr2[j++];
   }

}

int main()
{
   int i;
   int arr1[4]={1,3,5,7};
   int arr2[4]={2,4,6,8};
   int size1=4;
   int size2=4;
   int result[8];
   clrscr();
   mergeSortedArray(arr1,size1,arr2,size2,result);
   printf("First Array:");
   for(i=0;i<size1;i++)
   {
      printf("%d ",arr1[i]);
   }
   printf("\n");

   printf("Second Array:");
   for(i=0;i<size2;i++)
   {
      printf("%d ",arr2[i]);
   }
   printf("\n");
   printf("Merged array:");

   for(i=0;i<size1+size2;i++)
   {
      printf("%d ",result[i]);
   }
   printf("\n");
   getch();
   return 0;
}
