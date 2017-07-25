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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

struct person{
	int x, y, z;
	
	void assign(int a, int b, int c){
		x = a; y = b; z = c;
	}
	
	bool operator<(const person& o) const
	{
		return x < o.x;
	}
	
};

int t, n, a, b, c, res;
person ranks[100000];
set<person> S;
vector<person> to_erase;

bool comp(const person& p1, const person& p2){
	return p1.z < p2.z;
}

bool is_inside(int i){
	set<person>::iterator j = S.lower_bound(ranks[i]);
	// j  is the first element that fails the comaprison test
	if(j == S.begin()) return false;
	j--;
	return j->y < ranks[i].y;
}


int main(){
	sd(t);
	while(t--){
		sd(n);
		S.clear();
		for(int i = 0; i < n ; i++){
			sd3(a,b,c);
			ranks[i].assign(a,b,c);
		}
		sort(ranks, ranks+n, comp);
		S.insert(ranks[0]);		//The first person is assumed to be excellent
		res = 1;
		for(int i = 1; i < n; i++){
			if (is_inside(i)) continue; //There is some person better than the ith person so we dont need to consider i in our result.
			
			// Nobody is better than i yet, so increase our count
			res++;
			to_erase.clear();
			for(set<person>::iterator it = S.lower_bound(ranks[i]); it	!= S.end(); it++){
				
				if(it->y > ranks[i].y)
					to_erase.push_back(*it);
			}
			for(unsigned j = 0; j < to_erase.size(); j++){
				S.erase(to_erase[j]);
			}
			S.insert(ranks[i]);
		}
		printf("%d\n",res);
	}
	return 0;
}
