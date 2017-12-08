#include <stdio.h>
int main(void)
{
	int t,i=0,j=0,k=0,s=0;
	scanf("%d",&t);
	while(t--)
	{
		int N;
		scanf("%d",&N);
		int HW[N],HM[N];
		for(i=0;i<N;i++)
		{
			scanf("%d",&HM[i]);
		}
		for(i=0;i<N;i++)
		{
			scanf("%d",&HW[i]);
		}
		int te;
		for(i=0;i<N-1;i++)
		{
			for(j=0;j<N-1-i;j++)
			{
				if(HM[j]>=HM[j+1])
				{
					te=HM[j];
					HM[j]=HM[j+1];
					HM[j+1]=te;
				}
			}
		}
		for(i=0;i<N-1;i++)
		{
			for(j=0;j<N-1-i;j++)
			{
				if(HW[j]>=HW[j+1])
				{
					te=HW[j];
					HW[j]=HW[j+1];
					HW[j+1]=te;
				}
			}
		}
		for(i=0;i<N;i++)
		{
			s=s+HM[i]*HW[i];
		}
		printf("%d\n",s);
		s=0;
	}
	return 0;
}
