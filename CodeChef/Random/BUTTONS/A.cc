#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int t, n, a[1000][1000], b[1000][1000], f[1000][1000];
bool ok1, ok2;
vector<int> r1, c1, r2, c2;

bool allzero(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] != f[i][j]) return false;
		}
	}
	return true;
}

void toggle_column1(int col){
	for(int i = 0; i < n; i++) a[i][col] = 1 - a[i][col];
}

void toggle_column2(int col){
	for(int i = 0; i < n; i++) b[i][col] = 1 - b[i][col];
}

bool equalrow1(int row){
	for(int i = 0; i < n; i++){
		if(a[row][i] != f[row][i]) return false;
	}
	return true;
}

bool equalrow2(int row){
	for(int i = 0; i < n; i++){
		if(b[row][i] != f[row][i]) return false;
	}
	return true;
}

bool opprow1(int row){
	for(int i = 0; i < n; i++){
		if(a[row][i] == f[row][i]) return false;
	}
	return true;
}

bool opprow2(int row){
	for(int i = 0; i < n; i++){
		if(b[row][i] == f[row][i]) return false;
	}
	return true;
}

void match1(){
	for(int i = 0; i < n; i++){
		if(equalrow1(i)) continue;
		if(opprow1(i)) r1.pb(i);
		else ok1 = false;
	}
	return;
}

void match2(){
	for(int i = 0; i < n; i++){
		if(equalrow2(i)) continue;
		if(opprow2(i)) r2.pb(i);
		else ok2 = false;
	}
	return;
}

void print1(){
	printf("%d\n", (int) r1.size());
	foreach(it, r1) printf("%d\n", *it);
	printf("%d\n", (int) c1.size());
	foreach(it, c1) printf("%d\n", *it);
}

void print2(){
	printf("%d\n", (int) r2.size());
	foreach(it, r2) printf("%d\n", *it);
	printf("%d\n", (int) c2.size());
	foreach(it, c2) printf("%d\n", *it);
}

int main(){
	sd(t);
	while(t--){
		sd(n);
		r1.clear(), r2.clear(), c1.clear(), c2.clear();
		ok1 = ok2 = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				sd(a[i][j]);
				b[i][j] = a[i][j];
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				sd(f[i][j]);
			}
		}
		
		if(allzero()){
			puts("0"); continue;
		}
		
		for(int i = 0; i < n; i++){
			if(a[0][i] != f[0][i]){
				toggle_column1(i);
				c1.pb(i);
			}
		}
		match1();
		
		for(int i = 0; i < n; i++) b[0][i] ^= 1;
		r2.pb(0);
		for(int i = 0; i < n; i++){
			if(b[0][i] != f[0][i]){
				toggle_column2(i);
				c2.pb(i);
			}
		}
//		for(int i = 0; i < n; i++){
//			for(int j = 0; j < n; j++){
//				tr4(i,j,b[i][j], f[i][j]);
//			}
//		}
		match2();
		
		if(!ok1 and !ok2){
			puts("-1");
		}
		else{
			if(ok1 and ok2){
				if(r1.size() + c1.size() <= r2.size() + c2.size()){
					print1();
				}
				else{
					print2();
				}
			}
			else if(ok1){
				print1();
			}
			else{
				print2();
			}
		}
	}
	return 0;
}
