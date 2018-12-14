#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include "vector"
#include <map>
#include <iterator>
#include <list>
#include <stack>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

#define UNVISITED -1
class Graph
{
    int V;    // Number of vertices or nodes
    list<int> *adj;    // Keeps graphs edges
    void DFS(int u, int visited[], int lowLink[], bool onStack[], stack<int> *seen, int identity[],map<int,int> *map);
    void DFS2(int u, int visited[], int identity[], Graph *g, map<int,int> *m);
    int sccCount = 0;
    int sccID = 0;
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void findSCC(ofstream& dumFile);
    int getSCCNumber();
};

int Graph::getSCCNumber(){
    return sccCount;
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::findSCC(ofstream& dumFile)
{
    int *visited = new int[V]; //id
    int *lowLink = new int[V];
    bool *onStack = new bool[V];
    stack<int> *seen = new stack<int>();
    int *identity = new int[V];
    int *visited2 = new int[V]; //id
    map<int,int> *m = new map<int,int>();
    map<int,int> *m2 = new map<int,int>();
    //Initialization
    for(int i = 0; i < V; i++){
        visited[i] = UNVISITED;
        lowLink[i] = UNVISITED;
        onStack[i] = false;
        identity[i] = UNVISITED;
        visited2[i] = UNVISITED;
    }
    for(int i = 0; i <V; i++){
        if(visited[i] == UNVISITED){
            DFS(i,visited,lowLink,onStack,seen,identity,m2);
        }
    }
    int count = 0;
    int noEdges = 0;
    //Graph SCC(sccCount);
    Graph *SCC = new Graph(sccCount);
    for(int i = 0; i <V; i++){
        if(visited2[i] == UNVISITED){
            DFS2(i,visited2,identity, SCC,m);
        }
    }
    priority_queue<int, vector<int>, greater<int> > printer;

    for (map<int, int>::iterator it = m->begin(); it != m->end(); ++it ){

        if (it->second != 2 || it->second == 3){  // || it->second == 3
            count++;
            //  map->find(it->first)->second;
            printer.push((m2->find(it->first)->second) +1);
        }
    }
    dumFile << count << " ";
    while(!printer.empty()){
        dumFile << printer.top() << " ";
        printer.pop();
    }
}
// u vertex currently discovering
void Graph::DFS(int u, int visited[], int lowLink[], bool onStack[],
                stack<int> *seen,int identity[],map<int,int> *map)
{
    static int ID = 0;
    seen->push(u);
    onStack[u] = true;
    visited[u] = lowLink[u] = ++ID;

    //visit all neighbours
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;  // v is current adjacent of u

        // If v is not visited yet go DFS for v
        if (visited[v] == -1) {
            DFS(v,visited,lowLink,onStack,seen,identity,map);
            lowLink[u] = min(lowLink[u], lowLink[v]); //callback
        }
        else if(onStack[v]){
            lowLink[u] = min(lowLink[u], visited[v]);
        }

    }

    //after visited all neighbours of u
    int w = 0;
    if (lowLink[u] == visited[u]){
        while (seen->top() != u){
            w = (int) seen->top();
            identity[w] = sccID; //Assign each scc an identity
            (*map)[identity[w]] = w;
            onStack[w] = false;
            seen->pop();
        }
        w = (int) seen->top();
        identity[w] = sccID; //Assign each scc an identity
        (*map)[identity[w]] = w;
        onStack[w] = false;
        seen->pop();
        sccCount++;

        sccID++;
    }
}

// u vertex currently discovering
void Graph::DFS2(int u, int visited2[],int identity[], Graph *SCC,map<int,int> *m)
{
    static int ID = 0;
    visited2[u] = ++ID;
    //visit all neighbours
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;  // v is current adjacent of u
        (*m)[identity[u]] = 1;
        if (visited2[v] == -1) {
            DFS2(v,visited2,identity,SCC,m);
        }
        if(identity[u] != identity[v]){
            //SCC->addEdge(identity[u],identity[v]);
            if((*m)[identity[u]] == 1){
                (*m)[identity[v]] = 2;//TODO
            }
        }
    }
    if(adj[u].size() == 0){ //No childs
        if((*m)[identity[u]] != 2 ){
            (*m)[identity[u]] = 3;//TODO
        }
    }
}

//Input processing
template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Run the code with the following command: ./project3 [input_file] [output_file]" << endl;
        return 1;
    }
    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;
    ifstream infile(argv[1]);
    string line;
    getline(infile, line);
    vector<string> words;
    split1(line,words);
    int N;//piggy banks 1 2 3 4 5
    N = stoi(words[0]);
    Graph g(N);

    for(int i=0;i<N;i++) {
        getline(infile, line);
        vector<string> words;
        split1(line, words);
        int a = stoi(words[0]);
        for (int j = 1; j <= a; j++) {
            int b = stoi(words[j]) - 1;
            g.addEdge(i,b);
        }
    }
    ofstream myFile;
    myFile.open(argv[2]);
    g.findSCC(myFile);
}
