#include <stdio.h>

int main(void) {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int c,d,e,f,s;
		scanf("%d %d",&c,&d);
		e=rev(c);
		f=rev(d);
		s=rev(e+f);
		printf("%d\n",s);
	}

	return 0;
}
int rev(int a)
{
	int r=0,d;
	while(a>0)
{
	d=a%10;
	r=r*10+d;
	a=a/10;
}
return r;
}