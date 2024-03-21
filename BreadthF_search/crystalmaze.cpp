
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Допустим, имеется лабиринт, такой, как на следующем рисунке, и мы хотим перейти от входа к выходу за наименьшее возможное количество шагов. За один шаг будем считать любой переход из одной комнаты в другую. В нашем лабиринте 11 комнат, и у каждой из них – уникальное имя, например, “A”, “B”, т.д. Итак, наша цель – перейти из комнаты “S” в комнату “I”.

// g++ -std=c++17 - компилировать через стандарт 17

int main() {
    
   
    unordered_map <char, vector<char> > maze;
    
    maze['A'] = {'S'};
    maze['S'] = {'A', 'E', 'D', 'B'};
    maze['E'] = {'S', 'G'};
    maze['D'] = {'S', 'B', 'G'};
    maze['B'] = {'S', 'D', 'C'};
    maze['G'] = {'E', 'D', 'F', 'H', 'J'};
    maze['C'] = {'B', 'J'};
    maze['J'] = {'G', 'C', 'I'};
    maze['F'] = {'G', 'H'};
    maze['H'] = {'F', 'G', 'I'};
    maze['I'] = {'H', 'J'};
    
    
    vector<char> checked;
    checked.clear();
    
    vector <string> buf;
    buf.clear();
    
    string vertex;
    string load = "";
    int status = 0;
    
    buf.push_back("S");
   
    while(buf[0][0]!= 'I') {
        
        vertex = buf[0];
   //     cout << vertex[0] << endl;
        checked.push_back(vertex[0]);
        
        for (int j = 0; j < maze[vertex[0]].size(); j++) {
            
            for (int i = 0; i < checked.size(); i++) {
                
                if (maze[vertex[0]][j] == checked[i]) {
                    status = 1;
                    break;
                }
            }
            
            for (int i = 0; i < buf.size(); i++) {
                
                if (maze[vertex[0]][j] == buf[i][0]) {
                    status = 1;
                    break;
                }
            }
            
            if (status == 0) {
                
                load = maze[vertex[0]][j];
                load = load + vertex;
                buf.push_back(load);
                load = "";
                
            }
            
            status = 0;
            
        }
        
        buf.erase(buf.cbegin());
        
   /*     cout << " __----____-" << endl;
        
        for (int i = 0; i < buf.size(); i++) {
            cout << "____" << buf[i] << endl;
        } */
        
    }
    
    for (int i = buf[0].size() - 1; i > 0; i--) {
        cout << buf[0][i] << " -> ";
    }
    cout << buf[0][0] << endl;
    
    
    return 0;
}
