#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

// g++ -std=c++17 - компилируем через стандарт 17

using namespace std;

int main() {
    
    int N = 0;
    cout << "Amount of graph's vertexes ";
    cin >> N;
    
    int S = 0;
    cout << "Vertex Start ";
    cin >> S;
    
    int F = 0;
    cout << "Vertex Finish ";
    cin >> F;
    
    if ( S < 0 || S > N-1) {
        cout << " Wrong vertex start format" << endl;
        return 0;
    }
    
    if ( F < 0 || F > N-1) {
        cout << " Wrong vertex finish format" << endl;
        return 0;
    }
    
    if ( N < 0) {
        cout << " Amount of vertexes is negative" << endl;
        return 0;
    }
        
    
    ifstream in("graph.txt");
    if (!in) {
      cout << "File is not open" << endl;
      return -1;
    }
    
    vector < vector<int> > graph (N, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in >> graph[i][j];
            
            if ( graph[i][j] < -1) {
                cout << " Wrong graph format" << endl;
                return 0;
            }
            
            if (i == j && graph[i][j] !=0) {
                cout << " Wrong graph format" << endl;
                return 0;
            }
           
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    unordered_map <int, int> list;
    int mindx = -1;
    
    for (int i = 0; i < N; i++) {
        if (graph[S][i] >= 0 && S != i) {
            list[i] = graph[S][i];
        }
    }
    
    if (list.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
        
    mindx = list.begin() -> first;
    for (auto& elem : list)
        if ( elem.second < list [mindx]) {
            mindx = elem.first;
        }
    
  while (mindx != F) {
      
        for (int i = 0; i < N; i++) {
            if (graph[mindx][i] >= 0 && mindx != i)
                if (list.count(i) == 0 | list[mindx] + graph[mindx][i] < list[i])
                    list[i] = list[mindx] + graph[mindx][i];
        }
        
      list.erase(mindx);
      
      if (list.size() == 0) {
          cout << -1 << endl;
          return 0;
      }
       
      mindx = list.begin() -> first;
      
      for (auto& elem : list)
        if ( elem.second < list [mindx]) {
                mindx = elem.first;
        }
        
       for (auto& elem : list) {
            cout << elem.first << " " << elem.second;
            cout << endl;
        }
        cout << endl;
      
    }
    
    cout << list[mindx] << endl;
    
    return 0;
}
