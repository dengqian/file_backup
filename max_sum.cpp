#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

#define N 100000

using namespace std;

int seq[N];

int main(){
	int n, m;
	while(cin>>n) {
		for (int i=0; i<n; i++) {
			cin >> m;
			int start = 0, end = 0, pos = 0;
			for (int j=0; j< m; j++){
				cin>>seq[j];
			}
			int max_sum = seq[0], sum = seq[0];
			for (int j=1; j<m; j++) {
				sum += seq[j];
				if (seq[j] > sum) {
					sum = seq[j];
					pos = j;
				}
				if (sum > max_sum) {
					start = pos;
					max_sum = sum;
					end = j;
				}
			}
			cout<<"Case "<<i+1<<":"<<endl;
			cout<<max_sum<<" "<<start+2<<" "<<end+1<<endl;
			if(i<n-1)
				cout<<endl;
		}		
	}
	return 0;
}
