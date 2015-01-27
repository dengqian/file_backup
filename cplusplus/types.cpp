#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

int main(){
//	cout<<char(-1)<<endl;
	wchar_t c;
	const char *p = "hello";
	const char *q = "hello";
	cout<<p<<q<<endl;
	cout<<*p<<*q<<endl;
	cout<<&p<<endl<<&q<<endl;
	cout<<sizeof(const char *)<<endl;
	if(q == p) {
		cout<<"yes"<<endl;
	} else {
		cout<<"no"<<endl;
	}
	//c = 10;
	//enum e {aaa};
	//cout<<sizeof(e)<<endl;
//	cout<<sizeof(wchar_t)<<endl;
//	cout<<int(c)<<endl;

	int v[] = {0, 1};
	int *pp = &v[0];
	char a[] = "hello";
	char *aa = &a[0];
	cout<<pp<<endl;
	cout<<aa<<endl;
	char b = '3';
	if(isdigit(b)) {
		cout<<"isdigit"<<endl;
	} else {
		cout<<"not digit"<<endl;
	}
	return 0;
}
