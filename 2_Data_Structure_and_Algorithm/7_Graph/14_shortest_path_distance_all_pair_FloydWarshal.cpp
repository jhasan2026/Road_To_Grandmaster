#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"


using namespace std;

class WeiGraph{
public:
    unordered_map<int,list<pair<int,int>>> adjList;
    vector<vector<int>> edges;
    vector<vector<int>> adjMatrix;

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

    void prepareAdjMatrix(int vertex){
        for (int i = 0; i <= vertex; ++i) {
            vector<int> temp(vertex+1,INT_MAX);
            temp[i] = 0;
            adjMatrix.push_back(temp);
        }
    }

    void addEdgeAdjMatrix(int from,int to,int weight,bool direction){
        adjMatrix[from][to] = weight;

        if(!direction){
            adjMatrix[to][from] = weight;
        }
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

void shortestPathAllPairFloydWarshal(vector<vector<int>> adjMatrix){
    int vertex = adjMatrix.size();

    for (int k = 0; k < vertex; ++k) {
        for (int i = 0; i < vertex; ++i) {
            for (int j = 0; j < vertex; ++j) {
                if(adjMatrix[i][k]!=INT_MAX && adjMatrix[k][j]!=INT_MAX){
                    adjMatrix[i][j] = min(adjMatrix[i][j] , adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            cout<<adjMatrix[i][j]<<" ";

        }
        cout<<endl;
    }

}

int main(){
    WeiGraph g;
    g.prepareAdjMatrix(4);
    g.addEdgeAdjMatrix(0,1,3,true);
    g.addEdgeAdjMatrix(0,2,8,true);
    g.addEdgeAdjMatrix(0,4,-4,true);
    g.addEdgeAdjMatrix(1,3,1,true);
    g.addEdgeAdjMatrix(1,4,7,true);
    g.addEdgeAdjMatrix(2,1,4,true);
    g.addEdgeAdjMatrix(3,0,2,true);
    g.addEdgeAdjMatrix(3,2,-5,true);
    g.addEdgeAdjMatrix(4,3,6,true);

    shortestPathAllPairFloydWarshal(g.adjMatrix);

}