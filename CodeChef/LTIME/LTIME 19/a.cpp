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
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	int n,x,y, a[100000], b[100000], flag[100000], ans = 0;
	vector<pair<int, pair<int, int> > >a2, b2;
	sd3(n,x,y);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	for(int i = 0; i < n; i++){
		sd(b[i]);
		if(a[i] >= b[i])
			a2.push_back(make_pair(a[i]-b[i],make_pair(a[i],i)));
		else
			b2.push_back(make_pair(b[i]-a[i],make_pair(b[i],i)));
	}
	sort(a2.begin(), a2.end(), greater<pair<int, pair<int, int> > >());
	if(x > a2.size())
		x = a2.size();
	for(int i = 0; i < x; i++){
		ans += a2[i].second.first;
		flag[a2[i].second.second] = 1;
	}
	if(y > b2.size())
		y = b2.size();
	for(int i = 0; i < y; i++){
		ans += b2[i].second.first;
		flag[b2[i].second.second] = 1;
	}
	
	for(int i = 0; i < n; i ++){
		if(flag[i] != 1)
			ans += b[i];
	}
	cout<<ans<<endl;
	return 0;
}
