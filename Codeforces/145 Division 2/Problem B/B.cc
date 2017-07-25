#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cin fin
#define cout fout

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, k;
pair<int, int> a[1000];
vector<int> res;

int main(){	_
	cin>> n >> k;
	
	for(int i = 0; i < n; i++){
		cin>> a[i].fi;
		a[i].se = i+1;
	}	
	
	sort(a, a+n);
	
	cout<< a[n-k].fi << endl;
	
	for(int i = n-k; i < n; i++){
		cout << a[i].se << " ";
	}
	
	
	
	return 0;
}
