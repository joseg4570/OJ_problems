#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi num,low,p_node,art;
int n_visit,ans,n,a,b,root,n_children;
char h;

void dfs(int node)
{	num[node] = low[node] = n_visit++;

	for(int i=0;i<G[node].size();i++)
	{	int v = G[node][i];

		if(num[v] == -1)
		{	if(node == root)
				n_children++;

			p_node[v] = node;
			dfs(v);

			if(num[node] <= low[v])
				art[node] = 1;

			low[node] = min(low[node],low[v]);
		}
		else if(p_node[node] != v)
			low[node] = min(low[node],num[v]);
	}
}

int main()
{
	while(scanf("%d",&n) && n)
	{	G.clear();
		G.resize(n);
		num.assign(n,-1);
		low.assign(n,-1);
		p_node.assign(n,-1);
		art.assign(n,0);
		n_visit = ans = 0;

		while(scanf("%d%*c",&a) && a)
		{	//printf("%d\n",a);
			a--;

			while(scanf("%d%c",&b,&h) && h != '\n')
			{	G[a].push_back(--b);
				G[b].push_back(a);
			}

			G[a].push_back(--b);
			G[b].push_back(a);
		}

		/*
		cout << "\n\n";

		for(int i=0;i<n;i++)
		{	for(int j=0;j<G[i].size();j++)
				cout << G[i][j] << ' ';

			cout << '\n';
		}

		cout << "\n\n";
		*/

		for(int i=0;i<n;i++)
			if(num[i] == -1)
			{	root = i;
				n_children = 0;

				dfs(i);

				art[root] = n_children > 1;
			}

		for(int i=0;i<n;i++)
			ans += art[i];

		printf("%d\n",ans);
	}

	return 0;
}
