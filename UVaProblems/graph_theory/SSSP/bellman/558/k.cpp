#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
using namespace std;

#define INF 1000000000
#define NMAX 1000
#define MMAX 2000
#define x first
#define y second

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int T,n,m,a,b,w;

	cin >> T;

	while(T--)
	{	cin >> n >> m;

		vvii G(n);
		vi d(n,INF);
		bool ok = 0;

		for(int i=0;i<m;i++)
		{	cin >> a >> b >> w;

			G[a].push_back(make_pair(b,w));
		}

		for(int i=1;i<n;i++)
			for(int u=0;u<n;u++)
				for(int j=0;j<G[u].size();j++)
				{	int v = G[u][j].x;
					w = G[u][j].y;

					d[v] = min(d[v],d[u] + w);
				}

		for(int u=0;u<n;u++)
			for(int j=0;j<G[u].size();j++)
			{	int v = G[u][j].x;
				w = G[u][j].y;

				if(d[u] + w < d[v])
					ok = 1;
			}

	if(ok)
		cout << "possible\n";
	else
		cout << "not possible\n";

	}

	return 0;
}

