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

int n, cnt, scr;
pair<int, int> cards[1000];

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd2(cards[i].se, cards[i].fi);
		cards[i].fi *= -1;
		cards[i].se *= -1;
	}
	
	sort(cards, cards+n);
	
	cnt = 1, scr = 0;
	for(int i = 0; i < n and cnt > 0; i++){
		scr -= cards[i].se;
		cnt = cnt-1-cards[i].fi;
	}
	
	printf("%d\n",scr);
	
	return 0;
}
