#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> m; 
void record(const string &s){
	m[s]++;
}
void print(const pair<const string, int> &r)
{
	cout<<r.first<<" "<<r.second<<"\n";
}
int main()
{
	istream_iterator<string> ii(cin);
	istream_iterator<string> eos;

	for_each(ii, eos, record);
	cout<<"input finished"<<endl;
	for_each(m.begin(), m.end(), print);
	return 0; 
}
