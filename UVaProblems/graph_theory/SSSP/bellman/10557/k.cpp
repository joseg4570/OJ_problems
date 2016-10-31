#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi value;
vi dis;
vi visited;
string line;
int n,m,v,w;
bool ok;

void dfs(int u)
{	visited[u] = 1;

	for(int i=0;i<G[u].size();i++)
		if(!visited[G[u][i]])
			dfs(G[u][i]);
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	while(cin >> n && n != -1)
	{	G.clear();
		G.resize(n);
		value.assign(n,0);
		dis.assign(n,-1000000000);

		getline(cin,line);

		for(int u=0;u<n;u++)
		{	cin >> value[u] >> m;

			for(int i=0;i<m;i++)
			{	cin >> v;
				G[u].push_back(--v);
			}

		}

		dis[0] = 100;
		ok = 0;

		for(int i=0;i<n;i++)
		{	cout << i << '\n';
			for(int j=0;j<G[i].size();j++)
			{	v = G[i][j];
				cout << v << ' ';
			}

			cout << "\n\n";
		}

		for(int i=1;i<n-1;i++)
			for(int u=0;u<n;u++)
				for(int j=0;j<G[u].size();j++)
				{	v = G[u][j];
					w = value[v];

					if(dis[u] + w > 0)
						dis[v] = max(dis[v],dis[u] + w);
				}

		visited.assign(n,0);
		dfs(0);

		if(visited[n-1] && dis[n-1] > 0)
		{	cout << "winnable\n";
			continue;
		}

		vi visited1 = visited;

		for(int u=0;u<n;u++)
			for(int j=0;j<G[u].size();j++)
			{	v = G[u][j];
				w = value[v];

				if(dis[u] + w > 0 && dis[u] + w > dis[v])
				{	visited.assign(n,0);

					dfs(v);

					if(visited1[u] && visited[n-1])
						ok = 1;

				}
			}

		if(ok)
			cout << "winnable\n";
		else
			cout << "hopeless\n";

	}

	return 0;
}
