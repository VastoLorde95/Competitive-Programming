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
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int main(){
	int n, k, temp;
	pair<int, int> val[100];
	vector<int> ans;
	sd2(n,k);
	for(int i = 0; i < n; i++){
		sd(temp);
		val[i] = make_pair(temp, i+1);
	}
	sort(val, val+n);
	int res = 0, tot = 0 ;
	for(int i = 0; i < n; i++){
		if(tot + val[i].first <= k){
			res++;
			tot += val[i].first;
			ans.push_back(val[i].second);
		}
	}
	cout<<res<<endl;
	for(int i = 0; i < ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
