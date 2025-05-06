#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"
#include "stack"

using namespace std;

class WeiGraph{
public:
    unordered_map<int,list<pair<int,int>>> adjList;
    vector<vector<int>> edges;

    void addEdge(int from,int to,int weight,bool direction){
        adjList[from].push_back({to,weight});
        adjList[to];

        if(!direction){
            adjList[to].push_back({from,weight});
        }

        vector<int> edge;
        edge.push_back(from);
        edge.push_back(to);
        edge.push_back(weight);
        edges.push_back(edge);
    }
    void printAdjList(){
        for (auto node:adjList) {
            cout<<node.first<<"--> ";
            for (auto neighbour:node.second) {
                cout<<"["<<neighbour.first<<","<<neighbour.second<<"] ";
            }
            cout<<endl;
        }
    }
};


void dfs(unordered_map<int,list<pair<int,int>>> &adjList,unordered_map<int,bool> &visited,stack<int> &st,int source){
    visited[source] = true;                             //make visited of base(source) as true
    for (auto neighbour:adjList[source]) {      //traverse it's neighbour(pair of node and weight)
        if(!visited[neighbour.first]){                      //if its node(first of pair) is not visited
            dfs(adjList,visited,st,neighbour.first);        //recursively traver traverse its neighbour
        }
    }
    st.push(source);        //make dfs order(topologically) into the stack
}

unordered_map<int,int> shortestPathDAGSingleSrc(unordered_map<int,list<pair<int,int>>> &adjList,int src){
    unordered_map<int,bool> visited;
    stack<int> st;                              //for getting topological sorted list into the stack
    for (auto node:adjList) {
        if(!visited[node.first]){                       //if adjList member is not visited  :: call dfs for base(source)
            dfs(adjList,visited,st,node.first);
        }
    }

    unordered_map<int,int> distance;        //distance calculate vector from (source node) to (rest of the node)
    for (auto node:adjList) {
        distance[node.first] = INT_MAX;     //make vector full of infinity(INT_MAX) value
    }

    distance[src] = 0;              //distance to source is zero

    while (!st.empty()){
        int topVal = st.top();          //getting element from topologically sorted stack one by one as :: topNode
        st.pop();

        if(topVal != INT_MAX){                                  //if distance between source to topNode is not infinity
            for (auto neighbour:adjList[topVal]) {                              //get topNode's neighbour
                distance[neighbour.first] = min(distance[neighbour.first] , distance[topVal] + neighbour.second);   //if sum of[distance of topNode(as parent)] and [weight of neighbour] is less than [distance of neighbour]
                        //[distance of neighbour] will become sum of [distance of topNode(as parent)] and [weight of neighbour]

            }
        }
    }
    return distance;

}


int main(){
    WeiGraph g;
    g.addEdge(0,1,5, true);
    g.addEdge(0,2,3, true);
    g.addEdge(1,2,2, true);
    g.addEdge(1,3,6, true);
    g.addEdge(2,3,7, true);
    g.addEdge(2,4,4, true);
    g.addEdge(2,5,2, true);
    g.addEdge(3,4,-1, true);
    g.addEdge(4,5,-2, true);

    unordered_map<int,int> ans = shortestPathDAGSingleSrc(g.adjList,0);

    for (auto node:ans) {
        cout<<node.first<<" --> "<<node.second<<endl;
    }
}
