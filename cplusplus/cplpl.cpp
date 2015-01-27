#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

int main(){
	string from, to;

	cin>>from>>to;
	ifstream is(from.c_str());
	ofstream os(to.c_str());
	istream_iterator<string> ii(is);
	istream_iterator<string> eos;

	vector<string> b(ii, eos);
	sort(b.begin(), b.end());

	ostream_iterator<string> oo(os, "\n");

	unique_copy(b.begin(), b.end(), oo);

	return 0;
}

