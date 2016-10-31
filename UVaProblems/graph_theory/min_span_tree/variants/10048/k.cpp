#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define x first
#define y second
#define NMAX 105

typedef pair<int,int> ii;
typedef pair<int,ii> edge;
typedef vector<edge> ve;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> graph;

graph G;
vi visited;
vi set;
int sp[NMAX][NMAX];
int root;

void init(int n)
{	set.assign(n,0);

	for(int i=0;i<n;i++)
		set[i] = i;
}

int boss(int i)
{	if(set[i] == i) return i;
	return set[i] = boss(set[i]);
}

bool same_set(int i,int j)
{	return boss(i) == boss(j);	}

void join_sets(int i,int j)
{	if(boss(i) != boss(j))
		set[boss(i)] = boss(j);
}


void dfs(int node,int d)
{	visited[node] = 1;

	sp[root][node] = d;

	for(int i=0;i<G[node].size();i++)
	{	int v = G[node][i].x;

		if(!visited[v])
			dfs(v,max(d,G[node][i].y));
	}

}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,m,q,a,b,n_case;
	ve e;

	n_case = 0;

	while(cin >> n >> m >> q && n)
	{	if(n_case)
			cout << '\n';

		cout << "Case #" << ++n_case << '\n';

		if(e.size() < m)
			e.resize(m);
		init(n);

		G.clear();
		G.resize(n);

		for(int i=0;i<m;i++)
		{	cin >> e[i].y.x >> e[i].y.y >> e[i].x;

			e[i].y.x--,e[i].y.y--;
		}

		sort(e.begin(),e.begin()+m);

		for(int i=0;i<m;i++)
		{	a = e[i].y.x;
			b = e[i].y.y;

			if(!same_set(a,b))
			{	join_sets(a,b);

				G[a].push_back(make_pair(b,e[i].x));
				G[b].push_back(make_pair(a,e[i].x));
			}
		}

		for(int i=0;i<n;i++)
		{	visited.assign(n,0);

			root = i;
			dfs(i,0);
		}

		for(int i=0;i<q;i++)
		{	cin >> a >> b;

			a--,b--;

			if(!same_set(a,b))
				cout << "no path\n";
			else
				cout << sp[a][b] << '\n';
		}
	}

	return 0;
}
