#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
typedef long long LL;

int main(){
	//FILE *fin = freopen("B-small.in", "r", stdin);
	//assert( fin!=NULL );
	//FILE *fout = freopen("B-small.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		int n;
		cin >> n;
		int stuff[n];
		for(int i = 0; i < n; i++) cin >> stuff[i];
		int answer = 1000;
		for(int i = 1; i <= 4; i++){
			int cur = i;
			
			//cout << cur << endl;
			
			for(int j = 0; j < n; j++){
				cur += (stuff[j]-1)/i;
				
				//cout << (stuff[j]-1)/i << endl;
				
			}
			
			//cout << cur << "\n" << endl;
			
			answer = min(answer, cur);
		}
		cout << "Case #" << t << ": " << answer << endl;
	}
	exit(0);
}
