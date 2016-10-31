#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;

int n,m,a,b,t,n_SCC,k_visited;

vvi G;
vi num,low,visited;
si path;

void dfs(int node)
{	num[node] = low[node] = k_visited++;
	visited[node] = 1;
	path.push(node);

	for(int i=0;i<G[node].size();i++)
	{	int v = G[node][i];

		if(num[v] == -1)
			dfs(v);
		if(visited[v])
			low[node] = min(low[node],low[v]);

	}

	if(low[node] == num[node])
	{	n_SCC++;

		while(1)
		{	int v = path.top();
			path.pop();
			visited[v] = 0;

			if(v == node) break;
		}
	}

}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	while(cin >> n >> m && n)
	{	G.clear();
		G.resize(n);
		low.assign(n,-1);
		num.assign(n,-1);
		visited.assign(n,0);
		n_SCC = k_visited = 0;

		for(int i=0;i<m;i++)
		{	cin >> a >> b >> t;

			a--,b--;

			if(t == 1)
				G[a].push_back(b);
			else
			{	G[a].push_back(b);
				G[b].push_back(a);
			}
		}

		for(int i=0;i<n;i++)
			if(num[i] == -1)
				dfs(i);

		if(n_SCC == 1)
			cout << "1\n";
		else
			cout << "0\n";

	}

	return 0;
}
