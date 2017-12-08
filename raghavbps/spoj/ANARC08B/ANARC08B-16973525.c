#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	char a[100],b[100];
	char s1[100],s2[100],s3[200];
	int al,i,p,l1,l2,l3,j,r;
	long long int n1,n2,n3;
	while(1)
	{
		scanf("%s",a);
		l1=0;
		l2=0;
		if(strcmp(a,"BYE")==0)
		{
			break;
		}
		al=strlen(a);
		for(i=0;a[i]!='+';i++);
		p=i;
		for(i=0;i<=p-3;i+=3)
		{
			r=0;
			for(j=i;j<i+3;j++)
			{
				b[r++]=a[j];
			}
			b[r]='\0';
			if(strcmp(b,"063")==0)
			{
				s1[l1++]='0';
			}
			else if(strcmp(b,"010")==0)
			{
				s1[l1++]='1';
			}
			else if(strcmp(b,"093")==0)
			{
				s1[l1++]='2';
			}
			else if(strcmp(b,"079")==0)
			{
				s1[l1++]='3';
			}
			else if(strcmp(b,"106")==0)
			{
				s1[l1++]='4';
			}
			else if(strcmp(b,"103")==0)
			{
				s1[l1++]='5';
			}
			else if(strcmp(b,"119")==0)
			{
				s1[l1++]='6';
			}
			else if(strcmp(b,"011")==0)
			{
				s1[l1++]='7';
			}
			else if(strcmp(b,"127")==0)
			{
				s1[l1++]='8';
			}
			else if(strcmp(b,"107")==0)
			{
				s1[l1++]='9';
			}
		}
		s1[l1]='\0';
		for(i=p+1;i<=al-4;i+=3)
		{
			r=0;
			for(j=i;j<i+3;j++)
			{
				b[r++]=a[j];
			}
			b[r]='\0';
			if(strcmp(b,"063")==0)
			{
				s2[l2++]='0';
			}
			else if(strcmp(b,"010")==0)
			{
				s2[l2++]='1';
			}
			else if(strcmp(b,"093")==0)
			{
				s2[l2++]='2';
			}
			else if(strcmp(b,"079")==0)
			{
				s2[l2++]='3';
			}
			else if(strcmp(b,"106")==0)
			{
				s2[l2++]='4';
			}
			else if(strcmp(b,"103")==0)
			{
				s2[l2++]='5';
			}
			else if(strcmp(b,"119")==0)
			{
				s2[l2++]='6';
			}
			else if(strcmp(b,"011")==0)
			{
				s2[l2++]='7';
			}
			else if(strcmp(b,"127")==0)
			{
				s2[l2++]='8';
			}
			else if(strcmp(b,"107")==0)
			{
				s2[l2++]='9';
			}
		}
		s2[l2]='\0';
		l3=0;
		/*for(i=0;i<l1;i++)
		{
			printf("%c",s1[i]);
		}
		printf("\n");
		for(i=0;i<l2;i++)
		{
			printf("%c",s2[i]);
		}
		printf("\n");*/
		/*if(l1>=l2)
		{
			j=l2-1;
			l3=0;
			s3[l3]='0';
			for(i=l1-1;j>=0;j--,i--)
			{
				p=(s1[i]-'0')+(s2[j]-'0')+(s3[l3]-'0');
				s3[l3]=p%10+48;
				if(p>=10)
				{

					s3[l3+1]='1';
				}
				else
				{
					s3[l3+1]='0';
				}
				l3++;
			}
			while(i>=0)
			{
				p=(s1[i]-'0')+(s3[l3]-'0');
				s3[l3]=p%10+48;
				if(p>=10)
				{
					s3[l3+1]='1';
				}
				else
				{
					s3[l3+1]='0';
				}
				l3++;
				i--;
			}
		}
		else
		{
			j=l1-1;
			l3=0;
			s3[l3]='0';
			for(i=l2-1;j>=0;j--,i--)
			{
				p=(s1[i]-'0')+(s2[i]-'0')+(s3[l3]-'0');
				s3[l3]=p%10+48;
				if(p>=10)
				{
					s3[l3+1]='1';
				}
				else
				{
					s3[l3+1]='0';
				}
				l3++;
			}
			while(i>=0)
			{
				p=(s1[i]-'0')+(s3[l3]-'0');
				s3[l3]=p%10+48;
				if(p>10)
				{

					s3[l3+1]='1';
				}
				else
				{
					s3[l3+1]='0';
				}
				l3++;
				i--;
			}
		}
		if(s3[l3]=='0')
		{
			l3--;
		}
		for(i=l3;i>=0;i--)
		{
			printf("%c",s3[i]);
		}*/
		n1=0;
		for(i=l1-1;i>=0;i--)
		{
			n1=(n1+(s1[i]-'0')*pow(10,l1-1-i));
		}
		n2=0;
		for(i=l2-1;i>=0;i--)
		{
			n2=(n2+(s2[i]-'0')*pow(10,l2-1-i));
		}
		n3=n1+n2;
		l3=0;
		while(n3>0)
		{
			s3[l3++]=n3%10+48;
			n3/=10;
		}		
		printf("%s",a);
		for(i=l3-1;i>=0;i--)
		{
			if(s3[i]=='0')
			{
				cout<<"063";
			}
			else if(s3[i]=='1')
			{
				cout<<"010";
			}
			else if(s3[i]=='2')
			{
				cout<<"093";
			}
			else if(s3[i]=='3')
			{
				cout<<"079";
			}
			else if(s3[i]=='4')
			{
				cout<<"106";
			}
			else if(s3[i]=='5')
			{
				cout<<"103";
			}
			else if(s3[i]=='6')
			{
				cout<<"119";
			}
			else if(s3[i]=='7')
			{
				cout<<"011";
			}
			else if(s3[i]=='8')
			{
				cout<<"127";
			}
			else if(s3[i]=='9')
			{
				cout<<"107";
			}
		}
		cout<<endl;
	}
	return 0;
}

