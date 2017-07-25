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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

// if alredy in an A.P. - two values = first-d, last+d
// if exactly one number - infinitely many choices
// if exactly one number is missing from the sequence - print that number
// else there are zero numbers

int n, cards[100000], d;
pair<int, int> a[2];
map<int, int> diffs;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(cards[i]);
	}
	
	if(n == 1){
		cout << -1 << endl;
		return 0;
	}
	
	sort(cards, cards+n);
	
	if(n == 2){
		if(cards[0] == cards[1]){
			cout << 1 << endl;
			cout << cards[0] << endl;
		}
		else if((cards[0] + cards[1])%2 == 0){
			cout << 3 << endl;
			d = cards[1]-cards[0];
			
			cout << cards[0]-d << " " << (cards[0]+cards[1])/2 << " " << cards[1]+d << endl;
		}
		else{
			cout << 2 << endl;
			d = cards[1]-cards[0];
			
			cout << cards[0]-d << " " << cards[1] + d << endl;
		}
		return 0;
	}
	
	for(int i = 1; i < n; i++){
		diffs[cards[i] - cards[i-1]]++;
	}
	
	if(diffs.size() > 2){
		cout << 0 << endl;
	}
	else if(diffs.size() == 1){
		if(cards[0] == cards[n-1]){
			cout << 1 << endl;
			cout << cards[0] << endl;
		}
		else{
			d = (diffs.begin())->fi;
			cout << 2 <<  endl;
			cout << cards[0]-d << " " << cards[n-1]+d << endl;
		}
	}
	else if(diffs.size() == 2){
		int i = 0;
		
		for(map<int, int>::iterator it = diffs.begin(); it != diffs.end(); it++){
			a[i] = mp(it->fi, it->se);
			i++;
		}
		
		if(a[1].se == 1){
			for(int i = 0; i < n; i++){
				if(cards[i]+a[0].fi != cards[i+1] and cards[i]+a[0].fi+a[0].fi == cards[i+1]){
					cout << 1 << endl;
					cout << cards[i]+a[0].fi << endl;
					return 0;
				}
			}
			
			cout << 0 << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	
	return 0;
}
