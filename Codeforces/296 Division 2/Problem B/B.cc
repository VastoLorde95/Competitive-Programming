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

int n, cnt = 0, f = -1, se = -1, minu = 0;
string s, t;
set<int> a[100][100];
int b[26];
int c[26];

int main(){
	cin>> n;
	cin>> s >> t;
	for(int i = 0; i < 26; i++) b[i] = c[i] = -1;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			cnt++;
			int x = (int)(s[i] - 'a');
			int y = (int)(t[i] - 'a');
			if(minu < 2){
				if(!a[y][x].empty()){
					f = *(a[y][x].begin());
					se = i;
					minu = 2;
				}
				else if(b[x] != -1){
					if(minu != 2){
						f = b[x];
						se = i;
						minu = 1;
					}
				}	
				else if(c[y] != -1){
					f = c[y];
					se = i;
					minu = 1;
				}
				
			}
			a[x][y].insert(i);
			b[y] = i;
			c[x] = i;
		}
	}	
	if(minu == 0){
		cout<< cnt << endl;
		cout<< f << " " << se << endl;
	}
	else{
		cout<< cnt - minu <<endl;
		cout<< f+1 << " " << se+1 << endl;
	}
	return 0;
}
