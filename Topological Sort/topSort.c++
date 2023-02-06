#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class AdjListNode{
    int v;
    int w;
    
    public:
    AdjListNode(int v,int w){
        this->v=v;
        this->w=w;
    }
    int getV(){
        return v;
    }
    int getW(){
        return w;
    }
};

class Graph{
    int V;
    list<AdjListNode> *adj;
    
    public:
    
    Graph(int V){
        this->V=V;
        adj = new list<AdjListNode>[V];
    }
    
    void addEdge(int u,int v,int weight){
        AdjListNode node(v,weight);
        adj[u].push_back(node);
    }
    
    void print(){
        for(int i=0 ; i<V ; i++){
            cout<<i<<" : ";
            list<AdjListNode>::iterator j;
            for( j=adj[i].begin() ; j != adj[i].end() ; ++j)
                cout<<j->getV()<<",";
            cout<<"\n";
        }
    }
    
    vector<int> topSort(int ran){
        int n=V;
        vector<bool> v(n,false);
        vector<int> ordering(n,0);
        int i=n-1;
        
        for(int at=ran;at<n;at++){
            if(v[at]==false){
                vector<int> visitedNode;
                dfs(at,v,visitedNode);
                for(auto node:visitedNode){
                    ordering[i]=node;
                    i=i-1;
                }
            }
        }
        return ordering;
    }
    
    void dfs(int at,vector<bool> &v, vector<int> &visitedNode){
        if(v[at]==true)
            return;
        v[at]=true;
        list<AdjListNode>::iterator i;
        for( i=adj[at].begin();i!=adj[at].end();i++){
            dfs(i->getV(),v,visitedNode);
        }
        visitedNode.push_back(at);
    }
    
};

int main()
{
    Graph g(5);
    g.addEdge(0,1,5);
    g.addEdge(0,3,7);
    g.addEdge(1,2,3);
    g.addEdge(2,4,6);
    g.addEdge(3,4,1);
    g.addEdge(1,2,4);
    g.addEdge(1,3,4);
    g.addEdge(2,4,4);
    g.addEdge(3,0,4);
    g.print();
    vector<int> o;
    cout<<"\n";
    o=g.topSort(0);
    for(int i=0 ; i<o.size() ; i++){
        cout<<">>"<<o[i];
    }

    return 0;
}