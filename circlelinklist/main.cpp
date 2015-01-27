#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

struct node{
    int n;
    node *next;
};

void createLinkList(node * &head, node * &tail, int n){
    for(int i=1; i<n+1; i++){
        node *temp = new node;
        temp->n = i;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
            temp->next = head;
        }
    }
}
int getans(node *tail, int a){
    node * sign = tail;
    while(sign->next->n != sign->n){
        for(int i=0; i<a-1; i++){
            sign = sign->next;
        }
        node * curr = sign->next;
        sign->next = sign->next->next;
        delete curr;
    }
    return sign->n;
}
int main()
{
    int n;
    while(cin >> n){
        node * head = NULL;
        node * tail = NULL;
        createLinkList(head, tail, n);
        int a = 3;
        int ans = getans(tail, a);
        cout<<ans<<endl;
    }
    return 0;
}
