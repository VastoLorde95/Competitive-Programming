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

int n, m, e[16][16], x, y, mx, cnt, flag;
string a, b;
string names[16];
vector<int> ind, res;
map<string, int> d;
vector<string> ans;
int main(){
	cin>>n>>m;
	
	for(int i = 0; i < n; i++){
		cin >> names[i];
		d[names[i]] = i;
		
	}
	
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		x = d[a];
		y = d[b];
		e[x][y] = e[y][x] = 1;
	}
	
	
	
	for(int mask = 0; mask < (1<<n); mask++){
		cnt = 0;
		ind.clear();
		flag = 0;
		//cout << mask << endl;
		for(int j = 0; j < n; j++){
			if((mask&(1<<j)) > 0){
				ind.push_back(j);
				cnt++;
			}
		}
		
		//for(int i = 0; i < ind.size(); i++){
		//	cout<< ind[i]<< " ";
		//}
		//cout<< endl;
		
		for(int i = 0; i < ind.size(); i++){
			for(int j = 0; j < ind.size(); j++){
				if(e[ind[i]][ind[j]] == 1){
					//cout<< ind[i] << " " << ind[j] << endl;
					flag = 1;
					i = n+1;
					j = n+1;
					break;
				}
			}
		}
		
		//cout<< ind.size() << " " << cnt << endl;
		
		if(flag == 0 and ind.size() > 0	){
			if(cnt > mx){
				mx = cnt;
				res = ind;
			}
		}	
	}
	
	
	
	for(int i = 0; i < res.size(); i++){
		ans.push_back(names[res[i]]);
	}
	
	sort(ans.begin(), ans.end());
	
	cout<< ans.size() << endl;
	
	for(int i = 0; i < ans.size(); i++){
		cout<< ans[i] << "\n";
	}
	
	
	
	return 0;
}
