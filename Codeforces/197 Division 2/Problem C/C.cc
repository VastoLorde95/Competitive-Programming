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

string weight;
int m, w[11];
vector<int> res;

int recur(int b, int prev, int s){
	if(s == m+1){
		return 1;
	}	
	
	if(s%2 == 0){
		for(int i = 1; i <= 10; i++){
			if(w[i] and b-i < 0 and i != prev){
				if(recur(b-i, i, s+1)){
					res.push_back(i);
					return 1;
				}
			}
		}
	}
	else{
		for(int i = 1; i <= 10; i++){
			if(w[i] and b+i > 0 and i != prev){
				if(recur(b+i, i, s+1)){
					res.push_back(i);
					return 1;
				}
			}
		}
	}
	
	return 0;
}

int main(){ _
	cin >> weight >> m;
	
	for(int i = 0; i < 10; i++){
		w[i+1] = weight[i]-'0';
	}
	
	for(int i = 1; i <= 10; i++){
		if(w[i])
			if(recur(i, i, 2)){
				res.push_back(i);
				cout << "YES\n";
				
				for(int i = res.size()-1; i >= 0; i--){
					cout << res[i] << " ";
				}
				
				cout << "\n";
				return 0;
			}
	}
	
	cout << "NO\n";
	
	return 0;
}
