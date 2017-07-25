// Problem   Help Bob
// Algorithm exponential dynamic programming
// Runtime   O(m^2*2^m)
// Author    Christoph Schwirzer
// Date      2008.07.06
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
const int M = 16;
double d[M][M], p[M], a[M], dp[1<<M];
int main()
{
	int m;
	cin>>m;
	while (m)
	{
		if (m == 0)
			break;
		for (int i=0; i<m; i++)
			for (int j=0; j<m; j++)
				d[i][j] = 1.0;
		for (int i=0; i<m; i++)
		{
			int n;
			cin >> p[i] >> a[i] >> n;
			for (int j=0; j<n; j++)
			{
				int x, y;
				cin >> x >> y;
				--x;
				d[i][x] *= (100 - y) * 0.01;
			}
		}
		double res = 1e20;
		int k = 1 << m;
		for (int i=0; i<k; i++)
			dp[i] = res;
		dp[0] = 0.0;
		for (int mask=0; mask<k; mask++)
		{
			double area = 0.0;
			for (int i=0; i<m; i++)
				if (mask & (1 << i))
					area += a[i];
				else
				{
					double cost = p[i];
					for (int j=0; j<m; j++)
						if (mask & (1 << j))
							cost *= d[j][i];
					if (dp[mask] + cost < dp[mask | (1 << i)])
						dp[mask | (1 << i)] = dp[mask] + cost;
				}
			if (mask)
			{
				double tmp = dp[mask] / area;
				if (tmp < res)
					res = tmp;
			}
		}
		cout << res << endl;
		cin>>m;
	}
	return 0;
}
