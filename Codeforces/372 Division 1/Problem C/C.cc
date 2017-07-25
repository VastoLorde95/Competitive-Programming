#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

int n;
const int MAXDEPTH = 18;
const int MAXN = 1 << MAXDEPTH;
vector <int> e[MAXN];
int cntNodes[MAXN];
int minValue, center;

vector <int> cache[MAXDEPTH][4];
int cache_ans[MAXDEPTH][4][MAXN];
int ans[MAXN];
int temp1[MAXN];
int temp2[MAXN];
int temp3[MAXN];
int temp[MAXN];
int saveN[MAXDEPTH];

// find the minimal n such that 2**n > x
int minimalPow2(int x)
{
	int ret = 0;
	int t = 1;
	while(t < x)
	{
		ret ++;
		t = t + t;
	}
	return ret;
}

// use dfs to find the center of a tree
int dfs(int cur, int from, int d, int n, bool special = false, int depth = -1)
{
	if(special)
		cache_ans[depth][0][d] ++; 
	cntNodes[cur] = 1;
	int maxSubTree = 0, cnt = 0;
	for(int i = 0; i < e[cur].size(); i++)
		if(e[cur][i] != from)
		{

			int t = dfs(e[cur][i], cur, d+1, n, special, depth);
			cntNodes[cur] += cntNodes[e[cur][i]];
			cnt += t;
			maxSubTree = max(maxSubTree, t);
		}
	maxSubTree = max(maxSubTree, n-1-cnt);
	if(n > 0 && maxSubTree < minValue)
	{
		center = cur;
		minValue = maxSubTree;
	}
	return cnt + 1;
}

int totNodes;

int findCenter(int root, int depth)
{
	int n = dfs(root, -1, 0, 0, true, depth);
	minValue = 100000000;
	totNodes = dfs(root, -1, 0, n, false, depth);
	dfs(center, -1, 0, n, false, depth);
	return center;
}

// A[i]: number of nodes have a distance i from subtree A
// B[i]: number of nodes have a distance i from subtree B
// Update all pathes between subtree A and subtree B
void calcPair(int *A, int *B, int N)
{
	for(int i = 0; i < (1<<N); i++)
	{
		x[i] = complex <double> (A[i], 0);
		y[i] = complex <double> (B[i], 0);
	}
	Fourier :: cyclic_convolution(x, y, r, 1<<N);

	for(int i = 1; i < (1<<N); i++)
		ans[i] += (long long)(r[i].real() + 0.5);
}

void solve(int root, int depth, int reqN)
{
	for(int i = 0; i < (1<<reqN); i++)
	{
		cache_ans[depth][0][i] = 0;
		cache_ans[depth][1][i] = 0;
		cache_ans[depth][2][i] = 0;
		cache_ans[depth][3][i] = 0;
	}
	int center = findCenter(root, depth); // centroid
	int totalNodes = cntNodes[center];

	cache_ans[depth][0][0] = 1;
	if(totalNodes <= 2)
	{
		if(totalNodes == 2)
		{
			cache_ans[depth][0][1] = 1;
			ans[1] ++;
		}
		return;
	}
	cache[depth][0] = e[center];
	cache[depth][1].clear(), cache[depth][2].clear(), cache[depth][3].clear();
	int cnt = 1;

	// The subtree will be grouped into 3 parts, each one has a size no more than N/2.
	for(int i = 0; i < e[center].size(); i++)
	{
		int before = cnt;
		int after = cnt + cntNodes[e[center][i]];
		cnt = after;
		if(after <= totalNodes / 2)
			cache[depth][1].push_back(e[center][i]);
		else if(before <= totalNodes / 2)
			cache[depth][2].push_back(e[center][i]);
		else
			cache[depth][3].push_back(e[center][i]);
	}
	int N = minimalPow2(totalNodes);
	N = max(N, 2);

	e[center] = cache[depth][1];
	solve(center, depth + 1, N);
	for(int i = 1; i < (1<<N); i++)
		cache_ans[depth][1][i] = cache_ans[depth+1][0][i];
	
	e[center] = cache[depth][2];
	solve(center, depth + 1, N);
	for(int i = 1; i < (1<<N); i++)
		cache_ans[depth][2][i] = cache_ans[depth+1][0][i];
	
	e[center] = cache[depth][3];
	solve(center, depth + 1, N);
	for(int i = 1; i < (1<<N); i++)
		cache_ans[depth][3][i] = cache_ans[depth+1][0][i];
	
	e[center] = cache[depth][0];

	for(int i = 0; i < (1<<reqN); i++)
	{
		temp1[i] = cache_ans[depth][1][i];
		temp2[i] = cache_ans[depth][2][i];
		temp3[i] = cache_ans[depth][3][i];
	}
	calcPair(temp1, temp2, reqN);
	calcPair(temp1, temp3, reqN);
	calcPair(temp2, temp3, reqN);
}

bool isPrime[1000001];


int MAIN()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i <= 1000000; i++)
		if(isPrime[i])
			for(int j = i+i; j <= 1000000; j+=i)
				isPrime[j] = false;

	memset(ans, 0, sizeof(ans));
	memset(cache_ans, 0, sizeof(cache_ans));
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	solve(1, 0, minimalPow2(n));
	
	double total = 0, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		total += ans[i];
		if(isPrime[i])
			sum += ans[i];
	}
	cout << sum / total << endl;
	return 0;
}


int main() { _ 
	return MAIN();
}
