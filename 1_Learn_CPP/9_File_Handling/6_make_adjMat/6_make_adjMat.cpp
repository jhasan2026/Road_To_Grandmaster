#include "iostream"
#include "vector"
#include "fstream"

using namespace std;

void splitStringBySpace(string str,vector<string> &splitList){
    int j=0;
    for (int i = 0; i < str.length(); ++i) {
        if(str[i]==' '){
            string sub = str.substr(j,i-j);
            j=i+1;
            splitList.push_back(sub);
        }
    }
}

int main(){
    fstream graph;
    graph.open("1_Basic_programming/11_File_Handling/6_make_adjMat/ghaph.txt",ios::in);

    vector<string> lineSplit;

    int v=0,e=0;

    string line;
    if(graph.is_open()){
        getline(graph,line);
        splitStringBySpace(line,lineSplit);
        v = stoi(lineSplit[0]);
        e = stoi(lineSplit[1]);
        graph.close();
    }

    int adjMatrix[v][v];
    if(graph.is_open()){
        getline(graph,line);

        while (getline(graph,line)){
            splitStringBySpace(line,lineSplit);
            int from = stoi(lineSplit[0]);
            int to = stoi(lineSplit[1]);
            adjMatrix[from][to] = 1;
            adjMatrix[to][from] = 1;
        }
        graph.close();
    }

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}