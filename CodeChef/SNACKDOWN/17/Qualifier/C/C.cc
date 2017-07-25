#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

bool intersect(int a, int b, int c, int d){
	if(a > b) swap(a, b);
	if(c > d) swap(c, d);
	
	if(b < c) return false;
	if(a > d) return false;
	
	return true;
}

int x[4];
int y[4];

void solve(){
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	cin >> x[2] >> y[2] >> x[3] >> y[3];
	
	// check if in same row
	if(y[0] == y[1] and y[2] == y[3] and y[0] == y[2]){
		if(intersect(x[0], x[1], x[2], x[3])){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
		return;
	}
	
	// check if in same col
	if(x[0] == x[1] and x[2] == x[3] and x[0] == x[2]){
		if(intersect(y[0], y[1], y[2], y[3])){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
		return;
	}
	
	// else it should be an L shape
	if(x[0] == x[2] and y[0] == y[2]){
		cout << "yes\n";
	}
	else if(x[0] == x[3] and y[0] == y[3]){
		cout << "yes\n";
	}
	else if(x[1] == x[2] and y[1] == y[2]){
		cout << "yes\n";
	}
	else if(x[1] == x[3] and y[1] == y[3]){
		cout << "yes\n";
	}
	else{
		cout << "no\n";
	}
	
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
