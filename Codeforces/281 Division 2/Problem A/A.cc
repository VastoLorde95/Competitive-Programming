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

using namespace std;

int main(){
	string t1, t2; 
	int n, h[100], a[100], t, m, x[100], y[100];
	char c, card;
	memset(h, 0, sizeof h);
	memset(a, 0, sizeof a);
	memset(x, 0, sizeof x);
	memset(y, 0, sizeof y);
	
	cin >> t1 >> t2 >> n;
	for(int i = 0; i < n; i++){
		scanf(" %d %c %d %c",&t, &c, &m, &card);
		if(c == 'h'){
			if(card == 'r'){
				h[m] = 2;
				if(x[m] != 1){
					x[m] = 1;
					cout<<t1<<" "<<m<<" "<<t<<endl;
				}
			}
			else{
				h[m]++;
				if(h[m] >= 2 and x[m] != 1){
					x[m] = 1;
					cout<<t1<<" "<<m<<" "<<t<<endl;
				}
			}	
		}
		else{
			if(card == 'r'){
				a[m] = 2;
				if(y[m] != 1){
					y[m] = 1;
					cout<<t2<<" "<<m<<" "<<t<<endl;
				}
			}
			else{
				a[m]++;
				if(a[m] >= 2 and y[m] != 1){
					y[m] = 1;
					cout<<t2<<" "<<m<<" "<<t<<endl;
				}
			}
		} 
	}
	return 0;
}
