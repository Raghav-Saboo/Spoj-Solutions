#include <stdio.h>
void quicksort(int x[10000],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
         pivot=first;
         i=first;
         j=last;

         while(i<j)
         {
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j)
             {
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
	int t,i,si,j,flag=0;
	long int n,c;
	int x[10000];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		flag=0;
		scanf("%ld%d",&n,&si);
		c=0;
		for(j=0;j<si;j++)
		{
			scanf("%d",&x[j]);
		}
		quicksort(x,0,si-1);
		for(j=si-1;j>=0;j--)
		{
			c+=x[j];
			if(c>=n)
			{
				flag=1;
				printf("Scenario #%d:\n",i);
				printf("%d\n",si-j);
				break;
			}
		}
		if(flag==0)
		{
			printf("Scenario #%d:\n",i);		
			printf("impossible\n");
		}
	}
	return 0;
}
