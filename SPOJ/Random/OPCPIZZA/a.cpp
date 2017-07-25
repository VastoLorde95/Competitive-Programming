#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;
int a[MAX];
int main()
{
	int n, m, i, j, ans, test;
	scanf("%d", &test);
	while(test--)
		{
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
			sort(a, a + n);
			for(i = ans = 0; i < n; i++)
			{
				j = lower_bound(a, a + n, m - a[i]) - a;
				if(j != i && j != n && a[j] == m - a[i])
					ans++;
			}
			printf("%d\n", ans >> 1);
		}
	return 0;
}
