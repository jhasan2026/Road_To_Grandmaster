#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"


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

int shortestPathNegEdgeBellmonfordAlgo(vector<vector<int>> edges,int src,int dest,int vertex){
    vector<int> distance(vertex+1,INT_MAX);
    distance[src] = 0;

    for (int i = 0; i < vertex; ++i) {                  //Do the work for n timers ::
        for (int j = 0; j < edges.size(); ++j) {        //get [from and to and weight]
            int from = edges[j][0];
            int to = edges[j][1];
            int weight = edges[j][2];

            if(distance[from]!=INT_MAX && distance[from] + weight < distance[to]){      //if summation of( distance of from and weight)  is less than distance of to
                distance[to] = distance[from] + weight;                             //assign the minimum distance (better way to move)
            }
        }
    }

    bool flag = false;
    for (int j = 0; j < edges.size(); ++j) {                        //Do the same work another time ::
        int from = edges[j][0];
        int to = edges[j][1];
        int weight = edges[j][2];

        if(distance[from]!=INT_MAX && distance[from] + weight < distance[to]){      //distance[to] = distance[from] + weight;
            return -1;                  //if any change occur :: there is a negative cycle (meaning infinity cycle)
        }
    }
    return distance[dest];
}


int main(){
    WeiGraph g;
//    g.addEdge(1,2,4, true);
//    g.addEdge(1,3,3, true);
//    g.addEdge(2,4,7, true);
//    g.addEdge(3,4,-2, true);

    //Negative cycle contain graph
    g.addEdge(1,0,4, true);
    g.addEdge(0,2,-2, true);
    g.addEdge(2,3,2, true);
    g.addEdge(3,1,-1, true);
    g.addEdge(1,2,-3, true);


    int ans = shortestPathNegEdgeBellmonfordAlgo(g.edges,1,4,4);

    if(ans == -1){
        cout<<"There is negative cycle in the graph";
    }
    else{
        cout<<ans;
    }

}