#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;

#define x first
#define y second
#define NMAX 1000010

typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<dd> vdd;
typedef pair<double,ii> dii;
typedef vector<dii> ve;
typedef vector<int> vi;

int set[NMAX];

void init(int n)
{	for(int i=0;i<n;i++)
		set[i] = i;
}

int boss(int i)
{	if(set[i] == i) return i;
	return set[i] = boss(set[i]);
}

bool same_set(int i,int j)
{	return boss(i) == boss(j);	}

void union_sets(int i,int j)
{	if(boss(i) != boss(j))
		set[boss(i)] = boss(j);
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(0);

	int T,n,count,te;
	double a,b,ic,oc,dist,r;
	ve edges;
	vdd ns;

	cin >> T;

	for(int I=0;I<T;I++)
	{	cin >> n >> r;

		te = n*(n-1)/2;

		if(edges.size() < te)
			edges.resize(te);
		if(ns.size() < n)
			ns.resize(n);

		init(n);
		oc = ic = count = 0;

		for(int i=0;i<n;i++)
		{	cin >> ns[i].x >> ns[i].y;

			for(int j=0;j<i;j++)
			{	edges[count].x = sqrt((ns[i].x-ns[j].x)*(ns[i].x-ns[j].x) + (ns[i].y-ns[j].y)*(ns[i].y-ns[j].y));
				edges[count].y = make_pair(i,j);
				count++;
			}
		}

		sort(edges.begin(),edges.begin() + te);

		count = 0;

		for(int i=0;i<te;i++)
		{	a = edges[i].y.x;
			b = edges[i].y.y;

			if(!same_set(a,b))
			{	union_sets(a,b);

				if(edges[i].x <= r)
				{	ic += edges[i].x;
					count++;
				}
				else
					oc += edges[i].x;
			}
		}

		cout << "Case #" << I + 1 << ": " << n - count << ' ' << ic << ' ' << oc << '\n';
	}

	return 0;
}
