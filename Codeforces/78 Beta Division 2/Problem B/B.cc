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
#define fi first
#define se second

using namespace std;

int n, a[1000], s, x, cnt;
map<int, vector<int> > d;
int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		s += a[i];
	}
	
	
	//cout<< s << endl;	
	
	if(s%n == 0)
		x = s/n;
	else{
		cout<< "Unrecoverable configuration." << endl;
		return 0;
	}
	
	//cout<< x << endl;
	
	
	for(int i = 0; i < n; i++){
		if(x-a[i] != 0){
			cnt++;
			d[x-a[i]].push_back(i+1);
		}
	}		
	
	if(cnt > 2){
		cout<< "Unrecoverable configuration." << endl;
		return 0;
	}
	
	cnt = 0;
	
	for(map<int, vector<int> >::iterator it = d.begin(); it != d.end(); it++){
		int tmp = it->first;
		if(d[tmp].size() != d[-tmp].size()){
			cout<< "Unrecoverable configuration." << endl;
			return 0;
		}
		
		for(int i = 0; i < d[tmp].size(); i++){
			cnt++;
			int aa, b;
			if(tmp > -tmp){
				aa = d[tmp][i];
				b = d[-tmp][i];
			}
			else{
				aa = d[-tmp][i];
				b = d[tmp][i];
			}
			printf("%d ml. from cup #%d to cup #%d.\n",abs(tmp),aa,b);
		}
		
		d[tmp].clear();
		d[-tmp].clear();
	}
	
	if(cnt == 0){
		cout << "Exemplary pages." << endl;
	}
	
	
	return 0;
}
