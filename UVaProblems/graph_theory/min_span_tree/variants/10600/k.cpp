#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> edges;

vi set;
int num_sets;

void init(int n)
{	set.assign(n,0);

	for(int i=0;i<n;i++)
		set[i] = i;

	num_sets = n;
}

int boss(int i)
{	if(set[i] == i) return i;
	return set[i] = boss(set[i]);
}

bool same_set(int i,int j)
{	return boss(i) == boss(j);	}

void join_sets(int i,int j)
{	if(boss(i) != boss(j))
	{	set[boss(i)] = boss(j);
		num_sets--;
	}
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int T,n,m,a,b,ans1,ans2,c;
	edges e;
	vi e_used;

	cin >> T;

	while(T--)
	{	cin >> n >> m;

		e_used.clear();

		if(e.size() < m)
			e.resize(m);

		ans1 = ans2 = 0;

		for(int i=0;i<m;i++)
		{	cin >> a >> b >> e[i].x;

			e[i].y.x = --a;
			e[i].y.y = --b;
			ans2 += e[i].x;
		}

		sort(e.begin(),e.begin() + m);

		init(n);

		for(int i=0;i<m;i++)
		{	a = e[i].y.x;
			b = e[i].y.y;

			if(!same_set(a,b))
			{	join_sets(a,b);
				ans1 += e[i].x;
				e_used.push_back(i);
			}
		}

		for(int i=0;i<e_used.size();i++)
		{	init(n);
			c = 0;

			for(int j=0;j<m;j++)
			{	a = e[j].y.x;
				b = e[j].y.y;

				if(j != e_used[i] && !same_set(a,b))
				{	join_sets(a,b);
					c += e[j].x;
				}
			}

			if(num_sets == 1)
				ans2 = min(ans2,c);
		}

		cout << ans1 << ' ' << ans2 << '\n';

	}

	return 0;
}
