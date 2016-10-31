#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> i_ii;
typedef vector<i_ii> ve;

ve edges;
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

bool are_friends(int i,int j)
{	 return boss(i) == boss(j);	}

void make_friends(int i,int j)
{	if(boss(i) != boss(j))
		set[boss(i)] = boss(j);
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,m,a,b,ans;

	while(cin >> n >> m && n)
	{	edges.clear();
		edges.resize(m);
		init_sets(n);
		ans = 0;

		for(int i=0;i<m;i++)
		{	cin >> edges[i].y.x >> edges[i].y.y >> edges[i].x;
			ans += edges[i].x;
		}

		sort(edges.begin(),edges.end());

		for(int i=0;i<m;i++)
		{	a = edges[i].y.x;
			b = edges[i].y.y;

			if(!are_friends(a,b))
			{	ans -= edges[i].x;
				make_friends(a,b);
			}

		}

		cout << ans << '\n';
	}

	return 0;
}
