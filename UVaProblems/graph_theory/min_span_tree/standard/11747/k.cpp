#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ull,ii> iii;
typedef vector<iii> ve;
typedef vector<int> vi;

vi set;

void init_sets(int n)
{	set.assign(n,0);

	for(int i=0;i<n;i++)
		set[i] = i;
}

int boss(int i)
{	if(set[i] == i) return i;
	else return set[i] = boss(set[i]);
}

bool are_same(int i,int j)
{	return boss(i) == boss(j);	}

void union_set(int i,int j)
{	if(boss(i) != boss(j))
		set[boss(i)] = boss(j);
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,m,k_edges,a,b;
	ve edges;
	vi took;
	bool print_b;

	while(cin >> n >> m && n)
	{	edges.clear();
		edges.resize(m);
		took.assign(m,0);
		init_sets(n);
		k_edges = 0;

		for(int i=0;i<m;i++)
			cin >> edges[i].y.x >> edges[i].y.y >> edges[i].x;

		sort(edges.begin(),edges.end());

		for(int i=0;i<m;i++)
		{	a = edges[i].y.x;
			b = edges[i].y.y;

			if(!are_same(a,b))
			{	k_edges++;
				took[i] = 1;

				union_set(a,b);

			}
		}

		if(k_edges < m)
		{	print_b = 0;

			for(int i=0;i<m;i++)
				if(!took[i])
				{	if(print_b)
						cout << ' ';

					cout << edges[i].x;
					print_b = 1;
				}
			cout << '\n';
		}
		else
			cout << "forest\n";

	}


	return 0;
}
