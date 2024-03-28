#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// В стране N городов, некоторые из которых соединены между собой дорогами.
// Для того, чтобы проехать по одной дороге, требуется один бак бензина.
// В каждом городе бак бензина имеет разную стоимость. Вам требуется добраться из первого города в N-ый, потратив как можно меньшее денег. Покупать бензин впрок нельзя.

int main() {
    
    int N = 0;
    cout << "Cities: ";
    cin >> N;
    
    if ( N < 0 || N > 100 ) {
        cout << "Wrong Cities format" << endl;
        return 0;
    }
    
    vector <int> gasprice (N,0);
    
    for (int i = 0; i < N; i++) {
        cout << "Price in city " << i << ": ";
        cin >> gasprice[i];
        
        if (gasprice[i] < 0 || gasprice[i] > 100) {
            cout << "Wrong gaspric format" << endl;
            return 0;
        }
    
    }
    
    vector < vector<int> > graph (N, vector<int>(N, -1));
    
    int M = 0;
    cout << " Roads: ";
    cin >> M;
    
    if ( M < 0 || M > 100 ) {
        cout << "Wrong Roads format" << endl;
        return 0;
    }
    
    int start = 0;
    int end = 0;
    for (int i = 0; i < M; i++) {
        cout << " Road " << endl;
        cin >> start;
        cin >> end;
        
        if (start == end || start < 0 || start > N -1 || end < 0 || end > N -1) {
            cout << "Wrong Road format" << endl;
            return 0;
        }
        
        graph[start][end] = gasprice[start];
        graph[end][start] = gasprice[end];
    }
    
    for (int i = 0; i < N; i++)
        graph[i][i] = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    int S = 0;
    int F = N-1;
    
    vector <bool> checked (N, false);
    unordered_map <int, int> list;
    int mindx = -1;
    
    for (int i = 0; i < N; i++) {
        if (graph[S][i] >= 0 && S != i) {
            list[i] = graph[S][i];
        }
    }
    
    checked[S] = true;
    
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
            if (graph[mindx][i] >= 0 && mindx != i && checked[i] == false)
                if (list.count(i) == 0 | list[mindx] + graph[mindx][i] < list[i])
                    list[i] = list[mindx] + graph[mindx][i];
        }
      
      checked[mindx] = true;
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
    
    cout << " Success, leight: " << list[mindx] << endl;
 
    return 0;
}
