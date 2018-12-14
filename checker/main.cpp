#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<bool> visited;
int numOfBanks;
vector<vector<int> > adjList;
void bfs(int num){
    visited[num]=true;
    for (int i=0;i<adjList[num].size();i++){
        if(!visited[adjList[num][i]])
            bfs(adjList[num][i]);
    }
}
int main(int argc, char* argv[]) {
    ifstream reelInput(argv[1]);
    ifstream ourOutput(argv[2]);

    reelInput>>numOfBanks;
adjList.resize(numOfBanks+1);
    visited.resize(numOfBanks+1,false);

    for(int i=1;i<=numOfBanks;i++){
        int keys;
        reelInput>>keys;
        for(int j=0;j<keys;j++){
            int key;
            reelInput>>key;
            adjList[i].push_back(key);
        }
    }
    int number;//number of cracked banks
    ourOutput>>number;
    for(int i=0;i<number;i++){
        int bankNo;
        ourOutput>>bankNo;
        bfs(bankNo);
    }


    bool result=true;
    for(int i=1;i<=numOfBanks;i++){
        if(visited[i]==false) {
            cout << "All banks are not open";
            result=false;
        break;
        }
    }
    if(result)
        cout<<"All banks are open";

     return 0;
}
