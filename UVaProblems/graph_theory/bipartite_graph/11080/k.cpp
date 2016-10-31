#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi color;
bool bipartite;
int a,b;

void dfs(int node,int c)
{	if(color[node] != -1)
	{	if(color[node] != c)
			bipartite = 0;

		return;
	}

	color[node] = c;

	if(c) a++;
	else  b++;

	for(int i=0;i<G[node].size();i++)
		dfs(G[node][i],(c+1)%2);
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int T,n,m,ans;

	cin >> T;

	while(T--)
	{	cin >> n >> m;

		G.clear();
		G.resize(n);
		color.assign(n,-1);
		bipartite = 1;
		ans = 0;

		for(int i=0;i<m;i++)
		{	cin >> a >> b;

			G[a].push_back(b);
			G[b].push_back(a);
		}

		for(int i=0;bipartite && i<n;i++)
			if(color[i] == -1)
			{	a = b = 0;

				dfs(i,0);

				if(a == 0)
					ans += b;
				else if(b != 0)
					ans += min(a,b);
			}

		if(!bipartite)
			ans = -1;

		cout << ans << '\n';
	}

	return 0;
}
