// Continuous fraction expansion of a sqrt
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> expansion(int n,int lim = 10) {

	int mn, mnext, dn, dnext, an, anext;
	vector<int> v;

	int sq = sqrt(n);
	if(sq*sq == n) {
		return v;
	}

	mn = 0;
	dn = 1;
	an = sq;

	while(lim--) {

		v.push_back(an);

		mnext = (dn * an) - mn;
		dnext = (n - (mnext * mnext)) / dn;
		anext = (sq + mnext) / dnext;

		mn = mnext;
		dn = dnext;
		an = anext;
	}

	return v;
}

int main() {
	vector<int> s = expansion(123);

	cout<<"Expansion of 123 : ";
	for(int a:s) {
		cout<<a<<" ";
	}
	cout<<endl;

	return 0;
}