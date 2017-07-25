/*
The concept for this problem is that there are only 6 layouts of the rectangles. There are 24 permutations * 16 orientations for each of these 6 layouts so we can now bruteforce into these reduced no of combinations with ease.
*/
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

int rect[4][2], MIN = 100000;
vector<pair<int,int> > rectangles;

map<pair<int, int>, int > dic;
int max(int a, int b){
	if(a>b)
		return a;
	return b;
}

void l1(pair<int,int> (&p1), pair<int,int> (&p2), pair<int,int> (&p3), pair<int,int> (&p4)){
	int x = p1.first + p2.first + p3.first + p4.first;
	int y = max(max(p1.second,p2.second),max(p3.second,p4.second));
	if(x*y < MIN){
		MIN = x*y;
		rectangles.clear();
		rectangles.push_back(pair<int,int>(x,y));
	}
	else if(x*y == MIN){
		rectangles.push_back(pair<int,int>(x,y));
	}
}

void l2(pair<int,int> (&p1), pair<int,int> (&p2), pair<int,int> (&p3), pair<int,int> (&p4)){
	int x = max(p1.first + p2.first + p3.first, p4.first);
	int y = max(max(p1.second,p2.second),p3.second) + p4.second;
	if(x*y < MIN){
		MIN = x*y;
		rectangles.clear();
		rectangles.push_back(pair<int,int>(x,y));
	}
	else if(x*y == MIN){
		rectangles.push_back(pair<int,int>(x,y));
	}
}

void l3(pair<int,int> (&p1), pair<int,int> (&p2), pair<int,int> (&p3), pair<int,int> (&p4)){
	int x = max(p1.first + p2.first + p3.first, p4.first + p3.first);
	int y = max(max(p1.second,p2.second)  + p4.second,p3.second);
	if(x*y < MIN){
		MIN = x*y;
		rectangles.clear();
		rectangles.push_back(pair<int,int>(x,y));
	}
	else if(x*y == MIN){
		rectangles.push_back(pair<int,int>(x,y));
	}
}

void l4(pair<int,int> (&p1), pair<int,int> (&p2), pair<int,int> (&p3), pair<int,int> (&p4)){
	int x = p1.first + max(p2.first, p3.first) + p4.first;
	int y = max(max(p1.second, p2.second + p3.second),p4.second);
	if(x*y < MIN){
		MIN = x*y;
		rectangles.clear();
		rectangles.push_back(pair<int,int>(x,y));
	}
	else if(x*y == MIN){
		rectangles.push_back(pair<int,int>(x,y));
	}
}
void l5(pair<int,int> (&p1), pair<int,int> (&p2), pair<int,int> (&p3), pair<int,int> (&p4)){
	int x = max(p1.first, p2.first) + p3.first + p4.first;
	int y = max(max(p1.second + p2.second, p3.second),p4.second);
	if(x*y < MIN){
		MIN = x*y;
		rectangles.clear();
		rectangles.push_back(pair<int,int>(x,y));
	}
	else if(x*y == MIN){
		rectangles.push_back(pair<int,int>(x,y));
	}
}
void l6(pair<int,int> (&p1), pair<int,int> (&p2), pair<int,int> (&p3), pair<int,int> (&p4)){
	int x = max(p1.first,p2.first) + max(p3.first, p4.first);
	int y = max(p1.second +p2.second, p4.second+p3.second);
	if(x*y < MIN){
		MIN = x*y;
		rectangles.clear();
		rectangles.push_back(pair<int,int>(x,y));
	}
	else if(x*y == MIN){
		rectangles.push_back(pair<int,int>(x,y));
	}
}


pair<int, int> swap(int x, int y){
	if(y)
		return pair<int, int>(rect[x][1], rect[x][0]);
	return pair<int, int>(rect[x][0], rect[x][1]);
}

int check_and_permute(int i, int j, int k, int l){
	pair<int, int> p1,p2,p3,p4;
	for(int a = 0; a< 2; a++){
		for(int b = 0; b < 2; b++){
			for(int c = 0; c < 2; c++){
				for(int d = 0; d < 2; d++){
					p1 = swap(i,a);
					p2 = swap(j,b);
					p3 = swap(k,c);
					p4 = swap(l,d);
					l1(p1,p2,p3,p4);
					l2(p1,p2,p3,p4);
					l3(p1,p2,p3,p4);
					l4(p1,p2,p3,p4);
					l5(p1,p2,p3,p4);
					l6(p1,p2,p3,p4);
				}
			}
		}
	}
}

int main(){
	int i,j,k,l;
	cin>>rect[0][0]>>rect[0][1];
	cin>>rect[1][0]>>rect[1][1];
	cin>>rect[2][0]>>rect[2][1];
	cin>>rect[3][0]>>rect[3][1];
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j != i){
				for(k = 0; k < 4; k++){
					if(k != j and k != i){
						for(l = 0; l < 4; l++){
							if(l!=k and l!= j and l != i){
								check_and_permute(i,j,k,l);
							}
						}
					}
				}
			}
		}
	}
	cout<<MIN<<endl;
	int m1, m2;
	for (i=0; i<rectangles.size();i++){
		if(dic.find(rectangles[i]) == dic.end()){
			if(rectangles[i].first > rectangles[i].second){
				m1 = rectangles[i].first;
				m2 = rectangles[i].second;
			}
			else{
				m1 = rectangles[i].second;
				m2 = rectangles[i].first;
			}
			dic[rectangles[i]] = 1;
		
			printf("%d %d\n",m2, m1);
    	}
  	}
	return 0;
}
