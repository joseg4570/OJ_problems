#include <iostream>
using namespace std;

#define NMAX 100
#define INF 1000000000

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int T,n,m,u,v,w,ans;
	int ma[NMAX+5][NMAX+5];

	cin >> T;

	for(int I=1;I<=T;I++)
	{	cin >> n >> m;

		for(int i=0;i<n;i++)
		{	for(int j=0;j<n;j++)
				ma[i][j] = INF;
			ma[i][i] = 0;
		}

		ans = 0;

		for(int i=0;i<m;i++)
		{	cin >> u >> v;

			ma[u][v] = ma[v][u] = 1;
		}

		cin >> u >> v;

		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					ma[i][j] = min(ma[i][j],ma[i][k] + ma[k][j]);

		for(int i=0;i<n;i++)
			ans = max(ans,ma[u][i] + ma[i][v]);

		cout << "Case " << I << ": " << ans << '\n';
	}

	return 0;
}
