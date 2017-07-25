// Little Pony and Crystal Mine
#include <bits/stdc++.h>

using namespace std;

int n, g[101][101];

int main(){
	cin >> n;
	
	for(int i = 0; i <= n/2; i++){
		for(int j = n/2-i; j <= n/2 +i; j++){
			g[i][j] = 1;
			g[n-i-1][j] = 1;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(g[i][j]) cout << "D"; else cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
