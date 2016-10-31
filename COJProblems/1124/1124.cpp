#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

typedef unsigned long long ull;
#define NMAX 1000000


bitset<NMAX+1> is_prime;
vector<ull> prime;

void do_sieve()
{	is_prime.set();

	is_prime[0] = is_prime[1] = 0;

	for(ull i=2;i<=NMAX;i++)
		if(is_prime[i])
		{	prime.push_back(i);

			for(ull j=i*i;j<=NMAX;j+=i)
				is_prime[j] = 0;
		}
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	do_sieve();

	ull n;

	while(cin >> n && n!=0)
	{	for(ull i = 0;prime[i]<=n;i++)
			if(is_prime[n-prime[i]])
			{	cout << n << " = " << prime[i] << " + " << n-prime[i] << '\n';
				break;
			}
	}

	return 0;
}
