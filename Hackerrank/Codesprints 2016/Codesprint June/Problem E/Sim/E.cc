#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<unordered_set>
#include<queue>
#include<list>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<utility>
#include<sstream>
#include<iterator>
#include<functional>
#include<numeric>
#include<iomanip>
#include<ctime>
#include<climits>
#include<cctype>
#include<cassert>
#include<complex>
#include<cstdlib>
using namespace std;
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define pd(x) printf("%d", x)
#define pdn(x) printf("%d\n", x)
#define plld(x) printf("%I64d", x)
#define plldn(x) printf("%I64d\n", x)
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z); //spaces should not be there to avoid tle
#define slld(x) scanf("%I64d",&x)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

/*
ifstream fin("input.txt");
ofstream fout("output.txt");
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/

const long long base = 26;
const long long prime = 1344409044431ll;
const int N = 601;
const char off = 'a';
string rows[2];
int n;
long long expo[2*N];
unordered_set<long long> allHash;
unordered_set<long long> allHash2[2][N];

void generate(int left, int right)
{
	int i = left, j = right, len;
	__int128 polyhash = 0;
	while(j >= 0)
	{
		polyhash = ((polyhash * base % prime) + (rows[i][j]-off+1)) % prime;
		j--;
	}
	i = (1-i);
	j = 0;
	while(j <= right)
	{
		polyhash = ((polyhash * base % prime) + (rows[i][j]-off+1)) % prime;
		j++;
	}
	len = 2*n - (2 * (right+1));
	polyhash = (polyhash * expo[len]) % prime;
	
	foreach(it, allHash2[1^left][right+1])
		allHash.insert((polyhash + *it) % prime);
}

void compute()
{
	int left, right, len;
	long long value;
	for(int i = 0; i < 2; i++) 
		for(int j = 0; j < n; j++) 
			allHash2[i][j].clear();
	
	value = ((base * (rows[0][n-1]-off+1) % prime) + (rows[1][n-1]-off+1)) % prime;
	allHash2[0][n-1].insert(value);
	value = ((base * (rows[1][n-1]-off+1) % prime) + (rows[0][n-1]-off+1)) % prime;
	allHash2[1][n-1].insert(value);
	
	__int128 v, polyhash;
	for(int j = n-2; j >= 0; j--)
	{
		for(int i = 0; i < 2; i++)
		{
			polyhash = 0;
			left = i, right = j;
			while(right < n)
			{ 
				polyhash = (((polyhash * base)%prime) + (rows[left][right]-off+1)) % prime; 
				right++;
			}
			right = n-1; 
			left = (1-left);
			while(right >= j)
			{ 
				polyhash = (((polyhash * base)%prime) + (rows[left][right]-off+1)) % prime; 
				right--;
			}
			allHash2[i][j].insert(polyhash);
			len = (n-j)*2;
			
			polyhash = (((base * (rows[i][j]-off+1)) % prime) + (rows[i^1][j]-off+1)) % prime;
			polyhash = (polyhash * expo[len-2]) % prime;
			
			foreach(it, allHash2[1^i][j+1])
				allHash2[i][j].insert((polyhash + *it) % prime);
		}
	}
	
	for(int i = 0; i < 2; i++)
		for(int j = 1; j < n-1; j++)
			generate(i,j);
	
	foreach(it, allHash2[0][0]) 
		allHash.insert(*it);
	foreach(it, allHash2[1][0]) 
		allHash.insert(*it);
}

int main()
{
	FASTER;
	expo[0] = 1;
	for(int i = 1; i < N+N; i++)
		expo[i] = (expo[i-1] * base) % prime;
	int p; 
	cin >> p;
	while(p--){
		cin >> n;
		cin >> rows[0] >> rows[1];
	
		allHash.clear();
	
		if(n == 1)
		{
			if(rows[0] == rows[1]) 
				cout<<"1\n";
			else 
				cout <<"2\n";
			continue;
		}
	
		compute();
	
		for(int i = 0; i < 2; i++)
			reverse(rows[i].begin(), rows[i].end());
	
		compute();
	
		int ans = allHash.size();
		cout << ans << '\n';
	}
	
	return 0;
}
