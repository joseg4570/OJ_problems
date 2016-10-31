#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n,m,a,b,n_print;
vvi G;
vi has_parent;
vi visit;

void dfs(int node)
{	if(visit[node])
		return;

	visit[node] = 1;

	cout << node + 1;

	if(++n_print == n)
		cout << '\n';
	else
		cout << ' ';

	for(int i=0;i<G[node].size();i++)
		dfs(G[node][i]);
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	while(cin >> n >> m && n)
	{	G.clear();
		G.resize(n);
		has_parent.assign(n,0);
		visit.assign(n,0);
		n_print = 0;

		for(int i=0;i<m;i++)
		{	cin >> a >> b;

			G[--a].push_back(--b);
			has_parent[b] = 1;
		}

		for(int i=0;i<n;i++)
			if(!has_parent[i] && !visit[i])
				dfs(i);
	}


	return 0;
}
