#include <bits/stdc++.h>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 struct node{
    char c;
    int cnt=0;
    vector<node*> children;
    node(char c):c(c){}
 }*root;

void construct(string s,node* current){
    current->cnt++;
    if(s.size()==0) return;
    for(node* child:current->children){
        if(child->c==*(s.begin())){
            construct(s.substr(1),child);
            return;
        }
    }
    node* n=new node(*(s.begin()));
    current->children.push_back(n);
    construct(s.substr(1),n);
    return;
}

int anti_prefix(string s,node* current){ // lol i named it anti prefix because i cant get the length of the prefix but i do have the length of rest of the string
    if(s.size()==0&&!current->children.empty()){
        return 0;
    }
    if(current->cnt<2||current->children.empty()){
        return s.size();
    }
    for(node* child:current->children){
        if(child->c==*(s.begin())){
            return anti_prefix(s.substr(1),child);
        }
    }
    assert(false);
}

int main()
{
    root=new node(0);
    int N;
    cin >> N; cin.ignore();
    string a[N];
    for (int i = 0; i < N; i++) {
        char c;
        while((c=getc(stdin))!='\n'){
            a[i]+=tolower(c);
        }
        // cerr<<a[i]<<endl;
        construct(a[i],root);
    }
    for(int i=0; i<N; i++){
        cout<<a[i].substr(0,a[i].size()-anti_prefix(a[i],root))<<endl;
    }
}