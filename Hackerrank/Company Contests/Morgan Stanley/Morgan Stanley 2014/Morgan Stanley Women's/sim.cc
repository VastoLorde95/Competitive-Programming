#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

using namespace std;

int main()
{
	int crops, seasons, money, i, j, temp, minn, amt_left = 0, cash, profit_gained = 0, ans = 0, pro = 0, flag;
	cin>>crops>>seasons>>money;
	int cost[crops+1][seasons+1], profit[crops+1][seasons+1];
	for(i = 1; i <= crops; i++)
	{
		for(j = 1; j <= seasons; j++)
			cin>>cost[i][j];
	}
	for(i = 1; i <= crops; i++)
	{
		for(j = 1; j <= seasons; j++)
			cin>>profit[i][j];
	}
	
	for(j = 1; j <= seasons; j++)
	{
		pro = 0, flag = 0;
		for(i = 1; i <= crops; i++)
		{
			//cout<<"COST: "<<cost[i][j]<<endl;
			if(cost[i][j] <= money and pro < profit[i][j])
			{
				cash = cost[i][j];
				profit_gained = profit[i][j];
				pro = profit[i][j];
				flag = 1;
				//cout<<cash<<" "<<profit_gained<<endl;
			}
			else
				continue;
		}
		if(flag == 1)
		{
			amt_left = money - cash + profit_gained;
			ans += profit_gained;
			money = amt_left;
		}
	}
	cout<<amt_left<<endl;
	return 0;
}​



