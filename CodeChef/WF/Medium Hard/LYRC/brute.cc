#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
//typedef __int64 LL;

struct Node
{
	int next[100];
	int parent;
	int fail;
	char ch;
	int count;
	int done;
} node[2000000];

int sz;
char pattern[5003];
char text[50004];
int finish[5003];
queue<int> Q;

//insert into trie
int insert()
{
	int now = 0, i = 0, len = strlen(pattern);
	char ch;
	
	for(i = 0; i < len; i++)
	{
		ch = pattern[i];
		
		//if no node exists, create new one
		if(node[now].next[ ch ] == 0)
		{
			++sz;
			node[now].next[ ch ] = sz;
			node[sz].parent = now;
			node[sz].ch = ch;
		}
		
		now = node[now].next[ ch ];
	}
	
	return now;
}
//creates new links so that transition is made in O(1)
void construct_transition()
{
	int i, now, prev;
	
	for(i = 0; i < 100; i++)
		if(node[0].next[i])
			Q.push( node[0].next[i] );

		while(!Q.empty())
		{
			now = Q.front();
			Q.pop();
			
			for(i = 0; i < 100; i++)
				if(node[now].next[i])
				{
					Q.push( node[now].next[i] );
				}
				else
				{
					if(node[now].parent == 0)
					{
						node[now].fail = 0;
						node[now].next[i] = node[node[now].fail].next[i];
					}
					else
					{
						prev = node[node[now].parent].fail;
						node[now].fail = node[prev].next[ node[now].ch ];
						node[now].next[i] = node[node[now].fail].next[i];
					}
				}
				
				node[ node[now].fail ].done++;
		}
}

//just traverse through the trie with the chars in text
void process()
{
	int now = 0, len = strlen(text), i;
	for(i = 0; i < len; i++)
	{
		now = node[now].next[text[i]];
		node[now].count++;
	}
}

//propagate the count to upwards
void result()
{
	int i, z, j, u;
	
	for(i = 0; i <= sz; i++)
	{
		if(node[i].done == 0)
			Q.push( i );
	}
	
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		
		node[node[u].fail].done--;
		if(node[node[u].fail].done == 0)
		{
			Q.push( node[u].fail );
		}
		
		node[ node[u].fail ].count += node[u].count;
	}
}

int main()
{
//	freopen("1.in", "r", stdin);
	
	int nPattern, nText, i, j;
	
	scanf("%d", &nPattern);
	IN(nPattern, 1, 500);
	
	for(i = 0; i < nPattern; i++)
	{
		scanf("%s", pattern);
		IN(strlen(pattern), 1, 5000);
		for(j = strlen(pattern) - 1; j >= 0; j--)
		{
			assert(pattern[j]=='-' || (pattern[j]>='a' && pattern[j]<='z') || (pattern[j]>='A' && pattern[j]<='Z') || (pattern[j]>='0' && pattern[j]<='9'));
			pattern[j] -= '-' - 10;
		}

		//make a trie with the input pattern
		finish[i] = insert();
	}

	//construct failure transition in the trie
	construct_transition();
	
	scanf("%d", &nText);
	IN(nText, 1, 100);
	for(i = 0; i < nText; i++)
	{
		scanf("%s", text);
		IN(strlen(text), 1, 50000);
		for(j = strlen(text) - 1; j >= 0; j--)
		{
			assert(text[j]=='-' || (text[j]>='a' && text[j]<='z') || (text[j]>='A' && text[j]<='Z') || (text[j]>='0' && text[j]<='9'));
			text[j] -= '-' - 10;
		}

		//process text in trie
		process();
	}

	//finally make up the solution through failure function
	result();
	
	for(i = 0; i < nPattern; i++)
		printf("%d\n", node[finish[i]].count);
	return 0;
}