#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;
typedef map<int,int> i_i;

vvi G;
vi low,num,visited,r;
int n,m,T,a,b,k_visited,n_scc,ans;
si S;
i_i scc;

void dfs(int node)
{	num[node] = low[node] = ++k_visited;

	visited[node] = 1;
	S.push(node);

	for(int i=0;i<G[node].size();i++)
	{	int v = G[node][i];

		if(num[v] == -1)
			dfs(v);

		if(visited[v])
			low[node] = min(low[node],low[v]);
	}


	if(num[node] == low[node])
	{	while(1)
		{	int v = S.top();
			S.pop();

			visited[v] = 0;
			scc[v] = n_scc;

			if(v == node)
				break;
		}

		n_scc++;
	}

}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> T;

	while(T--)
	{	cin >> n >> m;

		G.clear();
		G.resize(n);
		low.assign(n,-1);
		num.assign(n,-1);
		visited.assign(n,0);
		scc.clear();

		k_visited = n_scc = 0;

		for(int i=0;i<m;i++)
		{	cin >> a >> b;

			G[--a].push_back(--b);
		}

		for(int i=0;i<n;i++)
			if(num[i] == -1)
				dfs(i);

		r.assign(n_scc,1);

		for(int i=0;i<n;i++)
		{	a = scc[i];
			for(int j=0;j<G[i].size();j++)
			{	b = scc[G[i][j]];
				if(a != b)
					r[b] = 0;
			}
		}

		ans = 0;

		for(int i=0;i<n_scc;i++)
			ans += r[i];

		cout << ans << '\n';
	}

	return 0;
}
