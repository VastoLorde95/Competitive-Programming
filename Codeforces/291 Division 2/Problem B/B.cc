// Han Solo and Lazer Gun
#include <bits/stdc++.h>

using namespace std;

map<double, int> t;

int main(){
	int n, x, y, x1, y1;
	double m;
	int inf = 0;
	
	cin >> n >> x >> y;
	for(int i = 0; i < n; i++){
		cin >> x1 >> y1;
		if(x1 == x) inf = 1;
		else{
			m = (double) (y1 - y) / (double) (x1 - x);
			if(t.find(m) == t.end()){
				t[m] = 1;
			}
		}
	}
	
	int ans = inf + t.size();
	
	cout << ans << endl;
	
	return 0;
}
