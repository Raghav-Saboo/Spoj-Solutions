#include <stdio.h>
void quicksort(long long int x[100],int first,int last){
    int pivot,j,i;
    long int temp;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}
int main(void) {
	// your code goes here
	long long int a[100];
	int t,n,i,j,c;
	scanf("%d",&t);
	while(t--)
	{
		c=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		quicksort(a,0,n-1);
		for(i=0;i<n;i++)
		{
			if(a[i]!=-1)
			{
				for(j=i+1;j<n;j++)
				{
					if(2*a[i]==a[j])
					{
						c++;
						a[j]=-1;
						break;
					}
				}
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
