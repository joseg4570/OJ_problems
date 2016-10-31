#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi color;
bool bipartite;

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
	{	G.clear();
		G.resize(n);
		color.assign(n,-1);
		bipartite = 1;

		while(cin >> a >> b && a != 0)
		{	G[--a].push_back(--b);
			G[b].push_back(a);
		}

		dfs(0,0);

		if(bipartite)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}
