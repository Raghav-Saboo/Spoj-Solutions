#include <stdio.h>
void quicksort(long long int x[20000],long long int first,long long int last){
    long long int pivot,j,temp,i;

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
	int t;
	long long int k,n,j,a[20000],i,min=1000000000;
	scanf("%d",&t);
	while(t--)
	{
		min=1000000000;
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		quicksort(a,0,n-1);
		
		if(k==1)
		{
			printf("0\n");
		}
		else
		{
			for(j=0;j<=n-k;j=j+1)
			{
				if((a[j+k-1]-a[j])<min)
				{
					min=a[j+k-1]-a[j];
				}
			}
			printf("%lld\n",min);
		}
	}
	return 0;
}

