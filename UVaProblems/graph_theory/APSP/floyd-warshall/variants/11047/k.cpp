#include <iostream>
#include <map>
#include <queue>
using namespace std;

#define NMAX 105
#define INF 1000000000

int ma[NMAX][NMAX];
int pa[NMAX][NMAX];
int t,n,q,u,v;
string name,A,B;
map<string,int> reg;
map<int,string> reg_i;
queue<string> print;

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> t;

	while(t--)
	{	reg.clear();
		reg_i.clear();

		cin >> n;

		for(int i=0;i<n;i++)
		{	cin >> name;
			reg[name] = i;
			reg_i[i] = name;
		}

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{	cin >> ma[i][j];

				if(ma[i][j] == -1)
					ma[i][j] = INF;

				pa[i][j] = j;
			}

		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(ma[i][j] > ma[i][k] + ma[k][j])
					{	ma[i][j] = ma[i][k] + ma[k][j];
						pa[i][j] = pa[i][k];
					}

		cin >> q;

		while(q--)
		{	cin >> name >> A >> B;
			u = reg[A];
			v = reg[B];

			if(ma[u][v] == INF)
			{	cout << "Sorry Mr " << name << " you can not go from "
				     << A << " to " << B << '\n';
				continue;
			}

			cout << "Mr " << name << " to go from " << A << " to "
			     << B << ", you will receive " << ma[u][v]
			     << " euros\n";

			cout << "Path:";

			cout << reg_i[u];

			for(u = pa[u][v];u != v;u = pa[u][v])
				cout << ' ' << reg_i[u];

			cout << ' ' << reg_i[v] << '\n';
		}
	}



	return 0;
}
