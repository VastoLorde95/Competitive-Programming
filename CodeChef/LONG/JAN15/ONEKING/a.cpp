#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;	


int t, n, a, b, low, high, mid, res;
vector<pair<int,int> > k;

int check(){
	int count = 1, end = k[0].first;
	for(int i = 1; i < n; i++){
		if(k[i].second > end){
			count++;
			end = k[i].first;
		}
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		k.clear();
		for(int i = 0; i < n; i++){
			cin>>a>>b;
			k.push_back(make_pair(b,a));
		}	
		sort(k.begin(), k.end());

		cout<<check()<<endl;
	}
	return 0;
}
