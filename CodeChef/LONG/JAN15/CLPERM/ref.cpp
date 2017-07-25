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
 
int t, b[100000], lost[1000000], num[1000000];
vector<int> x;
long long n, k, s;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(k == 0){
			s = ((n*(n+1))/2); //last number that is possible to play
			if(s%2 == 1) cout<<"Mom"<<endl;
			else cout<<"Chef"<<endl;
			continue;
		}
		memset(num, 0, sizeof num);
		memset(lost, 0, sizeof lost);
		for(int i = 0; i < k; i++){
			cin>>b[i];
			lost[b[i]] = 1;
		}
		for(int i = 1; i <= n; i++){
			if(lost[i] != 1){
				x.clear();
				x.push_back(i);
				for(int j = 1; j <= 1000000; j++){
					if(num[j] == 1){
						x.push_back(i+j);
					}
				}
				for(int j = 0; j < x.size(); j++){
					num[x[j]] = 1;
				}
			}
		}
		for(int i = 1; i <= 1000000; i++){
			if(num[i] != 1){
				if(i%2 == 0) cout<<"Mom"<<endl;
				else cout<<"Chef"<<endl;
				break;
			}
		}
	}
	return 0;
} 
