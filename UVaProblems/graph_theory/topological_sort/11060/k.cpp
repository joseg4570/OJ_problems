#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef map<string,int> s_i;
typedef map<int,string> i_s;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef priority_queue<int> pq;

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	vvi G;
	vi has_parent;
	vi inserted;
	s_i reg;
	i_s reg_inv;
	int n,m,a,b,k_printed,T;
	string namea,nameb;
	pq next_node;

	T = 0;

	while(cin >> n)
	{	G.clear();
		reg.clear();
		reg_inv.clear();

		G.resize(n);
		has_parent.assign(n,0);
		inserted.assign(n,0);
		k_printed = 0;

		for(int i=n-1;i>=0;i--)
		{	cin >> namea;
			reg[namea] = i;
			reg_inv[i] = namea;
		}

		cin >> m;

		for(int i=0;i<m;i++)
		{	cin >> namea >> nameb;

			a = reg[namea];
			b = reg[nameb];

			G[a].push_back(b);
			++has_parent[b];
		}

		cout << "Case #"  << ++T << ": Dilbert should drink beverages in this order: ";

		while(k_printed < n)
		{	for(int i=0;i<n;i++)
				if(has_parent[i] == 0 && !inserted[i])
					next_node.push(i),inserted[i] = 1;



			while(!next_node.empty())
			{	a = next_node.top(),next_node.pop();

				cout << reg_inv[a];

				if(++k_printed == n)
					cout << ".\n";
				else
					cout << ' ';

				for(int i=0;i<G[a].size();i++)
				{	b = G[a][i];

					has_parent[b]--;

					if(!inserted[b] && has_parent[b] == 0)
						next_node.push(b),inserted[b] = 1;
				}

			}
		}

		cout << '\n';

	}

	return 0;
}
