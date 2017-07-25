#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

int n, m, res[4000000], cnt, cnt2, i, tot;

int main(){
	sd2(n,m);
	
	if(n >= m+2 or m > 2*(n+1)){
		cout<<-1;
		return 0;
	}
	
	// m is in the range [n-1, 2*(n+1)]
	if(n == m+1){
		for(int i = 0; i < n+m; i++){
			if(!(i&1))
				cout<<0;
			else
				cout<<1;
		}
		return 0;
	}
	if(n+1 == m or n == m){
		for(int i = 0; i < n+m; i++){
			if(!(i&1))
				cout<<1;
			else
				cout<<0;
		}
		return 0;
	}
	
	tot = m+n;
	
	while( m > 0 and n > 0 and m > n+1 ){
		cout << "110";
		m -= 2;
		n--;
	}
	
	if(m > 0 and n > 0){
		if(m == n+1){
			for(int i = 0; i < n+m; i++){
				if(!(i&1))
					cout<<'1';
				else
					cout<<'0';
			}
			return 0;
		}
	
		else{
			for(int i = 0; i < n+m; i++){
				if(!(i&1))
					cout<<'0';
				else
					cout<<'1';
			}
			return 0;
		}
	}
	else if(m == 1)
		cout<<'1';
	else if(m == 2)
		cout<<"11";
	
	return 0;
}
