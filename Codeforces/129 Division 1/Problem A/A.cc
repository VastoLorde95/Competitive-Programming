#include<cstdio>
#include<cstdlib>
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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

long long l, r, cnt, pows[20], res;
string num;

int len(long long x){
	int len = 0;
	while(x > 0){
		x /= 10;
		len++;
	}
	
	return len;
}

long long first(long long x){
	int l = len(x);
	
	int msb = x/pows[l-1], lsb = x%10;
	
	while(msb != lsb){
		 x++;
		 msb = x/pows[l-1], lsb = x%10;
	}

	return x;
}

long long second(long long x){
	int l = len(x);
	
	int msb = x/pows[l-1], lsb = x%10;
	
	while(msb != lsb){
		 x--;
		 l = len(x);
		 msb = x/pows[l-1], lsb = x%10;
	}

	return x;
}

long long up(long long x){
	int l = len(x);
	
	if(l == 1){
		return first(++x);
	}
	
	long long msb = x/pows[l-1], lsb = x%10;
	
	return first((msb+1)*pows[l-1]);
	
}

long long low(long long x){
	int l = len(x);
	
	if(l == 1){
		return --x;
	}
	
	long long msb = x/pows[l-1], lsb = x%10;
	
	return (msb*pows[l-1] + msb);
}

int main(){ _
	cin >> l >> r;
	
	pows[0] = 1;
	
	for(int i = 1; i < 20; i++)
		pows[i] = pows[i-1]*10;	
	
	l = first(l);
	
	if(l > r){
		puts("0");
		return 0;
	}
	
	r = second(r);
	
	if(l == r){
		puts("1");
		return 0;
	}
	
	int l1 = len(l), l2 = len(r);
	int msb1 = l/pows[l1-1], lsb1 = l%10;
	int msb2 = r/pows[l2-1], lsb2 = r%10;
	
	if(l1 == l2 and l1 == 1){
		cout << r-l+1 << endl;
		return 0;
	}
	if(l1 == l2 and msb1 == msb2){
		cout << ((r%pows[l2-1])/10) - ((l%pows[l1-1])/10)+ 1 << endl;
		return 0;
	}
	
	
//	tr2(l,r);
	
	if(l1 > 2)
		res += pows[l1-2] - ((l%pows[l1-1])/10);
	else
		res++;
	
	if(l2 > 1)
		res += ((r%pows[l2-1])/10) + 1;
	
	
	l = up(l);
	r = low(r);
	
//	tr3(res,l,r);
	
	while(l < r){	
		l1 = len(l);
		if(l1 > 1)
			res += pows[l1-2];
		else
			res++;
		l = up(l);
	}

	cout << res << endl;
	
	return 0;
}
