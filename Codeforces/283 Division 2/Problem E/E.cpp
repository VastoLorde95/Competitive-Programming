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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;

int n, m, a, b, c, d, t, k[100000], assigned[100000];
vector<pair<pair<int, int>, pair<int, int> > > x;		//lower, type, upper, index
set<pair<int, int> >actors;					//upper, index
set<pair<int, int> >::iterator it;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd2(a, b);
		x.push_back(make_pair(make_pair(a,1), make_pair(b, i)));
	}
	
	for(int i = 0; i < n; i++){
		assigned[i] = -1;
	}
	
	sd(m);
	
	for(int i = 0; i < m; i++){
		sd3(c, d, k[i]);
		x.push_back(make_pair(make_pair(c,0), make_pair(d, i)));
	}
	
	sort(x.begin(), x.end());
	
	t = n+m;
	
	for(int i = 0; i < t; i++){
		if(x[i].first.second == 0){
				actors.insert(x[i].second);
			}
		else{
			it = actors.lower_bound(make_pair(x[i].second.first, -1));
			if(it == actors.end()){
				cout<<"NO"<<endl;
				return 0;
			}
			else{
				b = (*it).second;
				k[b]--;
				if(k[b] == 0){
					actors.erase(it);
				}
				assigned[x[i].second.second] = b;
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i = 0; i < n; i++){
		printf("%d ",assigned[i] + 1);
	}
	cout<<endl;
	return 0;
}
