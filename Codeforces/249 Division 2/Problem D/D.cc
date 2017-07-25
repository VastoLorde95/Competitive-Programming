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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(a,b,w,x,y,z) cout<<a<<" "<<b<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int g[405][405], row[405][405], col[405][405], diag1[405][405], diag2[405][405], n, m, cnt;
string s;

bool inrange(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m) return true;
	return false;
}

bool isgood(int x, int y){
	if(g[x][y] == 1) return false;
	return true;
}

void preprocess(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			row[i][j] = row[i][j-1] + g[i][j];
		}
	}
	
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			col[i][j] += col[i-1][j] + g[i][j];
		}
	}
	
	// diag1 => \ diag2 => /
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			diag1[i][j] = diag1[i-1][j-1] + g[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			diag2[i][j] = diag2[i-1][j+1] + g[i][j];
		}
	}
}

int main(){ _
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 1; j <= m; j++){
			g[i][j] = (s[j-1] == '1');	
		}
	}	
	
	preprocess();
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]) continue;
			
//			tr6("\n","\nAt",i,j,cnt,"\n");
			
			bool ok1 = true, ok2 = true;
			for(int k = j+1; k <= m; k++){
				if(g[i][k]) break;
				if((k-j)%2 == 1) continue;
				
				int h = (k-j)/2;
				
				if(inrange(i+h,j+h)){
					if(isgood(i+h,j+h) and diag2[i+h][j+h]-diag2[i-1][k+1] == 0 and ok1){
						cnt++; 
					}
					else if(!isgood(i+h,j+h)) ok1 = false;
				}
				
				if(inrange(i-h,j+h)){
					if(isgood(i-h,j+h) and diag1[i][k]-diag1[i-h-1][j+h-1] == 0 and ok2){
						cnt++; 
//						tr3("Got",i-h,j+h);
					}
					else if(!isgood(i-h,j+h))ok2 = false;
				}
				
			}
			
			ok1 = true, ok2 = true;
			for(int k = i+1; k <= n; k++){
				if(g[k][j]) break;
				if((k-i)%2 == 1) continue;
				
//				tr3("2With",k,j);
				
				int h = (k-i)/2;
				
				if(inrange(i+h,j+h)){
					if(isgood(i+h,j+h) and diag2[k][j]-diag2[i+h-1][j+h+1] == 0 and ok1){
						cnt++; 
//						tr3("Got",i+h,j+h);
					}
					else if(!isgood(i+h,j+h)) ok1 = false;
				}
				if(inrange(i+h,j-h)){
					if(isgood(i+h,j-h) and diag1[k][j]-diag1[i+h-1][j-h-1] == 0 and ok2){
						cnt++; 
//						tr3("Got",i+h,j-h);
					}
					else if(!isgood(i+h,j-h)) ok2 = false;
				}
			}
			
			for(int k = i+1, l = j+1; k <= n and l <= m; k++, l++){
				if(g[k][l]) break;
				
//				tr3("3With",k,l);
				
				if(inrange(i,l)){
					if(isgood(i,l) and row[i][l]-row[i][j-1] == 0 and col[k][l]-col[i-1][l] == 0){
						cnt++;
//						tr3("Got",i,l);
					}
				}
				if(inrange(k,j)){
					if(isgood(k,j) and col[k][j]-col[i-1][j] == 0 and row[k][l]-row[k][j-1] == 0){
						cnt++;
//						tr3("Got",k,j);
					}
				}
			}
			
			for(int k = i-1, l = j+1; k >= 1 and l <= m; k--, l++){
				if(g[k][l]) break;
				
//				tr3("4With",k,l);
				
				if(inrange(i,l)){
					if(isgood(i,l) and row[i][j]-row[i][l-1] == 0 and col[i][l]-col[k-1][l] == 0){
						cnt++;
//						tr3("Got",i,l);
					}
				}
				if(inrange(k,j)){
					if(isgood(k,j) and row[k][j]-row[k][l-1] == 0 and col[i][j]-col[k-1][j] == 0){
						cnt++;
//						tr3("Got",k,j);
					}
				}
			}
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}
