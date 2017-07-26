#include <bits/stdc++.h>

using namespace std;

const int MAX_X = 1001, MAX_Y = 1001;
int tree[MAX_X][MAX_Y];

void update(int x, int y, int val){
    int yy;
    while (x < MAX_X){
        yy = y;
        while(yy < MAX_Y){
			tree[x][yy] += val, yy += (yy & -yy);
		}
        x += (x & -x); 
    }
}

int query(int x, int y){
    int yy, sum = 0;
    while (x){
        yy = y;
        while(yy){
			sum += tree[x][yy], yy -= (yy & -yy);
		}
        x -= (x & -x); 
    }
    return sum;
}

int main(){
	return 0;
}
