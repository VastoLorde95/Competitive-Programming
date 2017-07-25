#include<stdio.h>
int n,m;
int sc[105000];
int main()
{
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;n && i<=m;i<<=1)
	{
		for(j=i;j<=m;j+=i*2)
		{
			if(n)
				if(n&i || j+i*2<=m)
				{
					sc[++sc[0]]=j;
					n-=i;
				}
		}
	}
	if(n)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",sc[0]);
	for(i=1;i<sc[0];i++)
		printf("%d ",sc[i]);
	printf("%d\n",sc[sc[0]]);
	return 0;
}
