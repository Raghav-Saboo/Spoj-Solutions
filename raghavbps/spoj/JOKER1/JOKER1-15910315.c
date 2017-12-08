#include <stdio.h>
void quicksort(int x[100],int first,int last){
    int pivot,j,temp,i;

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
	int t,n,maxn[100],i;long long int z=1000000007,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&maxn[i]);
		}
		quicksort(maxn,0,n-1);
		p=maxn[0]%z;
		for(i=1;i<n;i++)
		{
			p*=(maxn[i]-i);
			p=p%z;
		}
		printf("%lld\n",p);
	}
	printf("KILL BATMAN\n");
	return 0;
}
