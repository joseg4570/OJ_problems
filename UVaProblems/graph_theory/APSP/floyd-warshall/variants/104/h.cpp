#include <iostream>
#include <stack>
using namespace std;

#define NMAX 30
#define INF 1000000000

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,u,v,l;
	double ma[NMAX][NMAX][NMAX];
	int p[NMAX][NMAX][NMAX];
	bool ok;

	while(cin >> n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i == j)
					ma[i][j][0] = 1;
				else
					cin >> ma[i][j][0];

				p[i][j][0] = i;
			}

		for(int s=1;s<n;s++)
		{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					ma[i][j][s] = -1;

			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						if(ma[i][j][s] < ma[i][k][s-1] * ma[k][j][0])
						{
							ma[i][j][s] = ma[i][k][s-1] * ma[k][j][0];
							p[i][j][s] = k;
						}
		}

		ok = 0;

		for(int s=1;!ok && s<n;s++)
			for(int i=0;!ok && i<n;i++)
				if(ma[i][i][s] > 1.01)
				{
					ok = 1;
					u = v = i;
					l = s + 1;
				}

		if(ok)
		{
			stack<int> print;

			print.push(v + 1);

			for(;l--;)
			{
				print.push(p[u][v][l] + 1);
				v = p[u][v][l];
			}

			cout << print.top();
			print.pop();

			while(!print.empty())
			{
				cout << ' ' << print.top();
				print.pop();
			}

			cout << '\n';
		}
		else
			cout << "no arbitrage sequence exists\n";

	}

	return 0;
}
