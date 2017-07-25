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

using namespace std;

long long a1, b1;
long long a2, b2;
int cnt[4][2];

long long strip(long long x){
	while(x%2 == 0) x /= 2;
	while(x%3 == 0) x /= 3;
	return x;
}


int main(){
	cin >> a1 >> b1 >> a2 >> b2;
	
	long long t1 = a1, t2 = b1, t3 = a2, t4 = b2;
	
	if(strip(t1)*strip(t2) != strip(t3)*strip(t4)){
		cout << -1 << endl;
		return 0;
	}
	
	vector<int> num;
	num.pb(a1);
	num.pb(b1);
	num.pb(a2);
	num.pb(b2);
	
	for(int i = 0; i < 4; i++){
		int tmp = num[i];
		while(tmp%2 == 0){
			tmp /= 2;
			cnt[i][0]++;
		}
		while(tmp%3 == 0){
			tmp /= 3;
			cnt[i][1]++;
		}
		
//		tr3(num[i], cnt[i][0], cnt[i][1]);
	}

	int m = 0;	
	
	while(cnt[0][1] + cnt[1][1] > cnt[2][1] + cnt[3][1]){
		m++;
		if(cnt[0][1] > 0) cnt[0][1]--, cnt[0][0]++;
		else if(cnt[1][1] > 0) cnt[1][1]--, cnt[1][0]++;
	}
	
	while(cnt[0][1] + cnt[1][1] < cnt[2][1] + cnt[3][1]){
		m++;
		if(cnt[2][1] > 0) cnt[2][1]--, cnt[2][0]++;
		else if(cnt[3][1] > 0) cnt[3][1]--, cnt[3][0]++;
	}
		
	while(cnt[0][0] + cnt[1][0] > cnt[2][0] + cnt[3][0]){
		m++;
		if(cnt[0][0] > 0) cnt[0][0]--;
		else if(cnt[1][0] > 0) cnt[1][0]--;
	}
	while(cnt[0][0] + cnt[1][0] < cnt[2][0] + cnt[3][0]){
		m++;
		if(cnt[2][0] > 0) cnt[2][0]--;
		else if(cnt[3][0] > 0) cnt[3][0]--;
	}
	
	a1 = strip(a1);
	a2 = strip(a2);
	b1 = strip(b1);
	b2 = strip(b2);
	
	while(cnt[0][0] > 0){
		cnt[0][0]--;
		a1 *= 2;
	}
	while(cnt[0][1] > 0){
		cnt[0][1]--;
		a1 *= 3;
	}
	while(cnt[1][0] > 0){
		cnt[1][0]--;
		b1 *= 2;
	}
	while(cnt[1][1] > 0){
		cnt[1][1]--;
		b1 *= 3;
	}
	while(cnt[2][0] > 0){
		cnt[2][0]--;
		a2 *= 2;
	}
	while(cnt[2][1] > 0){
		cnt[2][1]--;
		a2 *= 3;
	}
	while(cnt[3][0] > 0){
		cnt[3][0]--;
		b2 *= 2;
	}
	while(cnt[3][1] > 0){
		cnt[3][1]--;
		b2 *= 3;
	}
	
	cout << m << endl;
	cout << a1 << " " << b1 << endl;
	cout << a2 << " " << b2 << endl;
	
	return 0;
}
