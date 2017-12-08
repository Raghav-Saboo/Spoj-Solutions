#include <stdio.h>

int main(void) {
	int g,b,res;
	while(1)
	{
		scanf("%d %d",&g,&b);
		if(g==-1&&b==-1)
		{
			break;
		}
		if(g>=b)
        {
            b++;
            res = g/b;
            if(g%b)
                res++;
        }
        else
        {
            g++;
            res = (b/g);
            if(b%g)
                res++;
        }
        printf("%d\n",res);
	}
	return 0;
}
