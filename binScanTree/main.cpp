#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct node{
    node * lc;
    node * rc;
    int data;
};

node * seaBST(node * root, int a){
    if(root->data > a && root->lc == NULL || root->data < a && root->rc == NULL){
        return root;
    }
    if(root->data > a){
        return seaBST(root->lc, a);
    }else{
        return seaBST(root->rc, a);
    }
}
node * creBST(node * &root, int a){
    if(root == NULL){
        root = new node;
        root->lc = NULL;
        root->rc = NULL;
        root->data = a;
        return root;
    }
    node* tempnode = new node;
    tempnode->data = a;
    tempnode->lc = NULL;
    tempnode->rc = NULL;
    node * n = seaBST(root, a);
    if(n->data > a){
        n->lc = tempnode;
    }else{
        n->rc = tempnode;
    }
}
void preOrder(node * root, string &s){
    if(root == NULL){
        return;
    }
    s += root->data + '0';
    preOrder(root->lc, s);
    preOrder(root->rc, s);
}

void midOrder(node * root, string &s){
    if(root == NULL){
        return;
    }
    midOrder(root->lc, s);
    s += root->data + '0';
    midOrder(root->rc, s);
}
int main()
{
    int n;
    string a;
    while(cin>>n && n){
        node * root = NULL;
        cin >> a;
        for(int i=0; i<a.length(); i++){
            creBST(root, a[i] - '0');
        }
        string pre;
        preOrder(root, pre);
       // cout<<pre<<endl;
        string mid;
        midOrder(root, mid);
       // cout<<mid<<endl;
        for(int j=0; j<n; j++){
            node * root1 = NULL;
            string aa;
            cin >> aa;
            for(int i=0; i<aa.length(); i++){
                creBST(root1, aa[i] - '0');
            }
            string pre1;
            preOrder(root1, pre1);
            string mid1;
            midOrder(root1, mid1);
            if(pre == pre1 && mid == mid1){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
            delete root1;
        }
        delete root;
    }
    return 0;
}
