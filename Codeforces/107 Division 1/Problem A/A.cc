#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

long long q, tmp;
vector<long long> p;
int main(){ _
	cin >> q;
	tmp = q;
	for(long long i = 2; i*i <= q; i++){
		if(q%i == 0){
			p.pb(i);
			while(q%i == 0) q /= i;
		}
	}
	
	if(q > 1) p.pb(q);
	
	if(tmp == 1){
		puts("1\n0");
		return 0;
	}
	
	
	if(p.size() == 1){
		if(p[0] == tmp or tmp == 1)
			puts("1\n0");
		else{
			if(p[0]*p[0] < tmp){
				cout << 1 << endl;
				cout << p[0]*p[0] << endl;
			}
			else{
				cout << 2 << endl;
			}
		}
	}
	else if(p.size() == 2){
		//cout << p[0] << " " <<  p[1] << endl;
		if(p[0]*p[1] < tmp){
			cout << 1 << endl;
			cout << p[0]*p[1] << endl;
		}
		else{
			cout << 2 << endl;
		}
	}
	else if(p.size() > 2){
		cout << 1 << endl;
		cout << p[0]*p[1] << endl;	
	}
	
	return 0;
}
