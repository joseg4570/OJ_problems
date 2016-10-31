#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef vector<int> vi;
typedef pair<double,double> dd;
typedef vector<dd> vdd;
typedef pair<int,int> ii;
typedef pair<double,ii> dii;
typedef vector<dii> edges;

vi set;
int num_sets;

void init(int n)
{	set.assign(n,0);
	num_sets = n;

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
	{	num_sets--;
		set[boss(i)] = boss(j);
	}

}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(2);

	int r,n,T,te,count,a,b;
	vdd ns;
	edges e;
	double ans;

	cin >> T;

	while(T--)
	{	cin >> r >> n;

		if(ns.size() < n)
			ns.resize(n);

		te = n*(n-1)/2;

		if(e.size() < te)
			e.resize(te);

		init(n);

		count = ans = 0;

		for(int i=0;i<n;i++)
		{	cin >> ns[i].x >> ns[i].y;

			for(int j=0;j<i;j++)
			{	e[count].x = sqrt(pow((ns[i].x - ns[j].x),2) + pow(ns[i].y - ns[j].y,2));
				e[count].y = make_pair(i,j);
				count++;
			}
		}

		sort(e.begin(),e.begin()+te);

		for(int i=0;num_sets > r && i<te;i++)
		{	a = e[i].y.x;
			b = e[i].y.y;

			if(!same_set(a,b))
			{	join_sets(a,b);
				ans = max(ans,e[i].x);
			}

		}

		cout << ans << '\n';
	}

	return 0;
}
