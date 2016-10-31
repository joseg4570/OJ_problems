#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000
#define NMAX 30

typedef map<char,int> c_i;
typedef map<int,char> i_c;

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,m,w,u,v,s1,s2,ans_n;
	int ma1[NMAX+1][NMAX+1],ma2[NMAX+1][NMAX+1];
	char tipo,sentido,a,b;

	while(cin >> m && m)
	{	for(int i=1;i<=NMAX;i++)
			for(int j=1;j<=NMAX;j++)
				ma1[i][j] = ma2[i][j] = INF;

		for(int i=1;i<=NMAX;i++)
			ma1[i][i] = ma2[i][i] = 0;

		n = 0;
		ans_n = INF;
		c_i reg;
		i_c reg_inv;

		for(int i=0;i<m;i++)
		{	cin >> tipo >> sentido >> a >> b >> w;

			if(!reg[a]) reg[a] = ++n,reg_inv[n] = a;
			if(!reg[b]) reg[b] = ++n,reg_inv[n] = b;

			u = reg[a];
			v = reg[b];

			if(tipo == 'Y')
			{	if(sentido == 'U')
					ma1[u][v] = min(w,ma1[u][v]);
				else
				{	ma1[u][v] = min(w,ma1[u][v]);
					ma1[v][u] = min(w,ma1[v][u]);
				}
			}
			else
			{	if(sentido == 'U')
					ma2[u][v] = min(w,ma2[u][v]);
				else
				{	ma2[u][v] = min(w,ma2[u][v]);
					ma2[v][u] = min(w,ma2[v][u]);
				}
			}

		}

		cin >> a >> b;

		if(!reg[a]) reg[a] = ++n,reg_inv[n] = a;
		if(!reg[b]) reg[b] = ++n,reg_inv[n] = b;

		s1 = reg[a];
		s2 = reg[b];

		/*
		for(int i=1;i<=n;i++)
		{	for(int j=1;j<=n;j++)
				cout << ma1[i][j] << ' ';
			cout << '\n';
		}
		*/

		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{	ma1[i][j] = min(ma1[i][j],ma1[i][k] + ma1[k][j]);
					ma2[i][j] = min(ma2[i][j],ma2[i][k] + ma2[k][j]);
				}

		/*
		for(int i=1;i<=n;i++)
		{	for(int j=1;j<=n;j++)
				if(ma2[i][j] != INF)
					cout << ma2[i][j] << ' ';
				else
					cout << "INF ";
			cout << '\n';
		}
		*/

		/*
		for(int i=1;i<=n;i++)
		{	for(int j=1;j<=n;j++)
				if(ma1[i][j] != INF)
					cout << ma1[i][j] << ' ';
				else
					cout << "INF ";
			cout << '\n';
		}
		*/

		//cout << "\n\nafasdfas\n\n";
		//cout << s1 <<  ' ' << s2 << '\n';

		for(int i=1;i<=n;i++)
			if(ma1[s1][i] + ma2[s2][i] < ans_n)
				ans_n = ma1[s1][i] + ma2[s2][i];

		if(ans_n == INF)
			cout << "You will never meet.\n";
		else
		{	vector<char> ans;

			for(int i=1;i<=n;i++)
				if(ma1[s1][i] + ma2[s2][i] == ans_n)
					ans.push_back(reg_inv[i]);

			sort(ans.begin(),ans.end());

			cout << ans_n << ' ' << ans[0];

			for(int i=1;i<ans.size();i++)
				cout << ' ' << ans[i];

			cout << '\n';
		}
	}

	return 0;
}
