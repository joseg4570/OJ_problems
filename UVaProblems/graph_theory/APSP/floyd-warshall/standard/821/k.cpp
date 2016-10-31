#include <iostream>
#include <map>
#include <cstring>
#include <iomanip>
using namespace std;

#define INF 1000000000
#define NMAX 100

typedef map<int,int> i_i;

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(3);

	int a,b,u,v,n,k_case = 0;
	int ma[NMAX+5][NMAX+5];
	double ans;

	while(cin >> a >> b && a)
	{	i_i reg;
		n = ans = 0;

		for(int i=1;i<=NMAX;i++)
			for(int j=1;j<=NMAX;j++)
				ma[i][j] = INF;

		do{
			if(!reg[a])
				reg[a] = ++n;

			if(!reg[b])
				reg[b] = ++n;

			u = reg[a];
			v = reg[b];

			ma[u][v] = 1;

		}while(cin >> a >> b && a);

		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ma[i][j] = min(ma[i][j],ma[i][k] + ma[k][j]);

		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i != j)
					ans += ma[i][j];

		ans /= n*(n-1);

		cout << "Case " << ++k_case
		     << ": average length between pages = " << ans
		     << " clicks\n";
	}

	return 0;
}
