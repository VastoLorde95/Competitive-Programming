#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
int tree[MAXN]; // Careful, indexing begins from 1.

int query(int idx, int sum = 0){
    for(; idx; idx -= (idx & -idx)) sum += tree[idx];
    return sum;
}

void update(int idx, int val){
    for(; idx < MAXN; idx += (idx & -idx)) tree[idx] += val;
}

int main(){
	return 0;
}
