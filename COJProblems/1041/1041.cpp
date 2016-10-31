#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{	string num = "A6789B";
	vector<double> p;
	stringstream ss;
	long price;

	cout << fixed << setprecision(2);

	for(int i='0';i<='9';i++)
	{	num[0] = i;

		for(int j='0';j<='9';j++)
		{	num[num.length()-1] = j;

			ss.clear();
			ss << num;
			ss >> price;

			p.push_back(price/720000.0);
		}
	}

	sort(p.begin(),p.end());

	for(int i=0;i<p.size();i++)
		cout << p[i] << '\n';

	return 0;
}
