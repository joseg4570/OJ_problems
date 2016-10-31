#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

ull sum(ull *a,ull p)
{	switch(p)
	{	case 0:
			return a[1] + a[2];
		case 1:
			return a[0] + a[2];
		default:
			return a[0] + a[1];
	}
}

string f(ull i)
{	switch(i)
	{	case 0:
			return "B";
		case 1:
			return "G";
		default:
			return "C";
	}
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	ull a[3],b[3],c[3],p[3],ans,j;
	string pans,h;

	p[0] = 0;
	p[1] = 1;
	p[2] = 2;

	while(cin >> a[0] >> a[1] >> a[2])
	{	cin >> b[0] >> b[1] >> b[2];
		cin >> c[0] >> c[1] >> c[2];

		ans = 1000000000000000;

		do
		{	j = sum(a,p[0]) + sum(b,p[1]) + sum(c,p[2]);

			if(ans >= j)
			{	if(ans>j)
				{	pans = f(p[0]) + f(p[1]) + f(p[2]);
					ans = j;
				}
				else if(ans == j)
				{	h = f(p[0]) + f(p[1]) + f(p[2]);

					if(h < pans)
						pans = h;
				}
			}

		}while(next_permutation(p,p+3));

		cout << pans << ' ' << ans << '\n';
	}

	return 0;
}
