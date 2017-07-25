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

typedef long long lli;
 
int ct[100010];
 
int N, temp;
 
lli tree[100010];
 
int mxn = 100000;
 
void upd(int x, lli val){
	while(x <= mxn){
		tree[x] += val;
		x += (x&-x);
	}
}
 
lli read(int x){
	if(x <= 0) return 0;
	lli sol = 0;
	while(x){
		sol +=tree[x];
		x -= (x&-x);
	}
	 
	return sol;
}
 
lli query(int i, int j){
	if(i > j) return 0;
	return read(j)-read(i-1);
}
 
int M;
 
int main(){
 
	lli tot = 0;
	int i;
	 
	scanf("%d",&N);
	 
	char c;
	int x,y;
	 
	for(i =0; i < N; ++i){
		sd2(x,temp);
		//scanf("%d",&ct[x]);
		ct[x] = temp;
		 
		tot += ct[x];	//total number of people in the tribe
		upd(x,1LL*ct[x]*x);	// update the total number of people in the tribe with family of size x
		 
	}
	 
	 
	int y2;
	scanf("%d",&M);
	lli sol = 0;
	while(M--){
	 
		scanf(" %c %d",&c,&x);
		 
		if(c^'?'){
			if(c == '+'){
				tot += 1;
				ct[x]++;
				upd(x,x);	//update the total number of people in the village with family size x
			}
			else{
				tot -= 1;
				ct[x]--;
				upd(x,-x); //update the total number of people in the village with family size x
			}
			continue;
		}
		 
		y=x;
		sol = 0;
		for(i = 1; i*i <= y; ++i){		//O(sqrt(n)
			sol += 1LL*ct[i]*i*(y/i);	//number of people in family with sixe i * family size * bananas per person for this group
		}
		 
		x = i;	// i is a sqrt(y) + 1 because you dont want to count sqrt(y) family size again
		for(y2 = y/i; y2 > 0; --y2){	// This will also run in O(sqrt(n))
			i = y/y2;	//x, i is the range of family size which gives us the same value of y/m. i is the maximum family size and x is the minumum family size
			sol += ((x>i)?0:read(i)-read(x-1))*1LL*y2;	//query returns the number of people with family size between x and i * y2 number of bananas per person
			x=i+1;	// once the current range has been considered we should keep x as i+1 and not i because the number of bananas per person for a family of size i and size i+1 will be different here
		 
		}
		 
		sol = (1LL*tot*y)-sol;			//total number of bananas to be given - number of bananas that the family keeps for themselves
		printf("%lld\n",sol);
	}
	 
	return 0;
}
