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

int m, x, y, indx, l, p, flag, removable[100000], removed[100000];
long long MOD = 1000000009, ans, pw, order[100000];
map<int, pair<int, int> > a;
map<int, pair<int, int> >::iterator it;
map<pair<int, int>, int> c;

pair<int, int> p1, p2, p3, cubes[100000];
vector<int> below[100000], above[100000];

int isremovable(int k){
	if(removed[k] == 1) return 0;
	
	int cnt;
	
	for(int i = 0; i < above[k].size(); i++){
		if(removed[above[k][i]] == 1) continue;
		
		cnt = 0;
		for(int j = 0; j < below[above[k][i]].size(); j++){
			if(removed[below[above[k][i]][j]] == 0) cnt++;
		}
		
		if(cnt == 1) return 0;
	}
	
	return 1;
}

void fix(int k){
	for(int i = 0; i < below[k].size(); i++){
		if(removed[below[k][i]] == 1) continue;
		
		if(isremovable(below[k][i])){
			if(removable[below[k][i]] == 0){
				a[below[k][i]] = cubes[below[k][i]];
				removable[below[k][i]] = 1;
			}
		}
		else if(removable[below[k][i]] == 1){
			a.erase(below[k][i]);
			removable[below[k][i]] = 0;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>> m;
	for(int i = 0; i < m; i++){
		cin>> x >> y;
		cubes[i] = make_pair(x,y);
		c[cubes[i]] = i;
		
		p1 = make_pair(x-1, y-1);
		p2 = make_pair(x, y-1);
		p3 = make_pair(x+1, y-1);
		
		if(c.find(p1) != c.end()){
			above[c[p1]].push_back(i);
			below[i].push_back(c[p1]);
		}
		if(c.find(p2) != c.end()){
			above[c[p2]].push_back(i);
			below[i].push_back(c[p2]);
		}
		if(c.find(p3) != c.end()){
			above[c[p3]].push_back(i);
			below[i].push_back(c[p3]);
		}
		
		p1 = make_pair(x-1, y+1);
		p2 = make_pair(x, y+1);
		p3 = make_pair(x+1, y+1);
		
		if(c.find(p1) != c.end()){
			above[i].push_back(c[p1]);
			below[c[p1]].push_back(i);
		}
		if(c.find(p2) != c.end()){
			above[i].push_back(c[p2]);
			below[c[p2]].push_back(i);
		}
		if(c.find(p3) != c.end()){
			above[i].push_back(c[p3]);
			below[c[p3]].push_back(i);
		}
	}
	
	for(int i = 0; i < m; i++){
		flag = 1;
		for(int j = 0; j < above[i].size(); j++){
			if(below[above[i][j]].size() == 1){
				flag = 0;
				break;
			}
		}
		if(flag){
			a[i] = cubes[i];
			removable[i] = 1;
		}
	}
	
	l = 0;
	
	while(!a.empty()){
		indx = 1 - indx;
		
		if(indx == 1){
			it = a.end(); it--;
		}
		else{
			it = a.begin();
		}
		
		
		order[l] = it->first;
		
		x = (it->second).first;
		y = (it->second).second;
		p = it->first;
		
		//cout<<p<<endl;
		
		removed[p] = 1;
		
		a.erase(it->first);
		
		fix(p);
		
		for(int i = 0; i < above[p].size(); i++){
			if(removed[above[p][i]] == 0){
				fix(above[p][i]);
			}
		}
		
		l++;
	}
	
	ans = 0; pw = 1;
	
	for(int i = m-1; i >= 0; i--){
		ans = (ans + (order[i] * pw)%MOD)%MOD;
		pw = (pw*m)%MOD;
	}
	
	cout<< ans << endl;	
	return 0;
}
