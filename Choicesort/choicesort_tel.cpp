#include <iostream>
#include <string>
#include <vector>
#include <ctime>


// список телефонов по возрастанию и использующую  сортировку выбором.
// телефон задан в виде строки. Например, 23-45-67.

using namespace std;


int main() {
    
    int n = 10;
    int min = 0;
    string buf;
    
    char pull;
    vector <string> telbook(n);
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            pull = rand()%10 + 48;
            telbook[i] = telbook[i] + pull;
            
            pull = rand()%10 + 48;
            telbook[i] = telbook[i] + pull;
            
            telbook[i] = telbook[i] + "-";
        }
        telbook[i].pop_back();
        
        cout << telbook[i] << endl;
    }
    
    cout << endl;
    
    for (int i = 0; i < n-1; i++){
        min = i;
        for (int j = i; j < n; j++){
            if (telbook[j].compare(telbook[min]) < 0){
                min = j;
            }
        }
        buf = telbook[i];
        telbook[i] = telbook[min];
        telbook[min] = buf;
        
    }
    
    for (int i = 0; i < n; i++) {
        cout << telbook[i] << endl;
    }
    
    
    
    return 0;
}
