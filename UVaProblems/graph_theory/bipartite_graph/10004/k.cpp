#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool bipartite;
vvi G;
vi color;


void dfs(int node,int c)
{	if(color[node] != -1)
	{	if(color[node] != c)
			bipartite = 0;

		return;
	}

	color[node] = c;

	for(int i=0;bipartite && i<G[node].size();i++)
		dfs(G[node][i],(c+1)%2);
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,m,a,b;

	while(cin >> n && n != 0)
	{	cin >> m;

		G.clear();
		G.resize(n);
		color.assign(n,-1);
		bipartite = 1;

		for(int i=0;i<m;i++)
		{	cin >> a >> b;

			G[a].push_back(b);
			G[b].push_back(a);
		}

		dfs(0,0);

		if(bipartite)
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";
	}

	return 0;
}
