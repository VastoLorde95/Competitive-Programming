#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;
int t, n, m, a[100], dp[100][20000], prev[100][20000], cur;
int main(){	
	vector<int> op;
	sd(t);
	while(t--){
		sd2(n,m);
		for(int i = 0; i < n; i++){
			sd(a[i]);
		}
		memset(dp, 0, sizeof(dp));
		op.clear();
		dp[0][10000+a[0]] = 1;
		prev[0][10000+a[0]] = -1;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < 20000; j++){
				if(a[i] + j < 20000 and dp[i-1][j+a[i]]){
					dp[i][j] = 1;
					prev[i][j] = 1;
				}
				if(i > 1 and j >= a[i] and dp[i-1][j-a[i]]){
					dp[i][j] = 1;
					prev[i][j] = 2;
				}
			}
		}
		//cout<<"yo"<<endl;
		for(int i = n-1, j = 10000 + m; i > 0; i--){
			op.push_back(prev[i][j]);
			j = (prev[i][j] == 1)? j + a[i] : j - a[i];
		}
		//reverse(op.begin(), op.end());
		
		cur = 0;
		for(int i = op.size()-1; i >= 0; i--){
			if(op[i] == 1) cur++;
			else if(op[i] == 2)printf("%d\n",cur+1);
		}
		while(cur--)printf("1\n");
		cout<<endl;
	}
	return 0;
}
	
