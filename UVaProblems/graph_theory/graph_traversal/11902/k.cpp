#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define NMAX 100

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef bitset<NMAX> reg;

vvi la;
vi visit;
reg h,reach;
int n;

void dfs(int act,reg &visit,int &avoid)
{	if(visit[act] || act == avoid) return;
	visit[act] = 1;

	for(int i=0;i<la[act].size();i++)
		dfs(la[act][i],visit,avoid);
}

void print_line()
{	cout << '+';

	for(int i=1;i<2*n;i++)
		cout << '-';

	cout << "+\n";
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	bool conect;

	cin >> T;

	for(int t=1;t<=T;t++)
	{	cin >> n;
		la.clear();
		visit.clear();
		la.resize(n);
		visit.assign(n,0);
		reach.reset();
		h.reset();

		for(int i=0;i<n;i++)
		{	for(int j=0;j<n;j++)
			{	cin >> conect;

				if(conect)
					la[i].push_back(j);
			}
		}

		cout << "Case " << t << ":\n";

		dfs(0,reach,n);
		print_line();

		for(int i=0;i<n;i++)
			cout << '|' << ((reach[i]) ? 'Y' : 'N');
		cout << "|\n";

		for(int i=1;i<n;i++)
		{	h.reset();

			if(reach[i])
			{	dfs(0,h,i);
				h.flip();
				h &= reach;
			}

			print_line();

			for(int i=0;i<n;i++)
				cout << '|' << ((h[i]) ? 'Y' : 'N');
			cout << "|\n";
		}

		print_line();
	}

	return 0;
}
