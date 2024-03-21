#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

// Дана последовательность целых чисел.
// Каждое прочитанное число обрабатывается следующим образом:
//   если число больше нуля, оно добавляется к текущему множеству чисел;
//   если число меньше нуля, противоположное ему число удаляется из текущего множества чисел;
//   если число равно нулю, множество чисел выводится в порядке возрастания и программа завершает работу.


// g++ -std=c++17 - компилируем через стандарт 17

using namespace std;

// вывод по возрастанию

bool compare (int a, int b) {
    
    return a < b;
}


int main() {
    
    unordered_map <int, int> numbers;
    int num = 0;
    
    ifstream in("input.txt");
    if (!in) {
      cout << "File is not open" << endl;
      return -1;
    }
    
    ofstream out("output.txt");
    if (!out) {
      cout << "File is not open" << endl;
      return -1;
    }
    
    while (in) {
        in >> num;
        
        if (num == 0)
            break;
        
        if (num > 0 && numbers.count(num) == 0)
            numbers.insert({num, num});
        
        if (num < 0)
            numbers.erase(-1*num);
        
    }
    
    vector <int> stand;
    
    for (auto& elem : numbers)
        stand.push_back(elem.second);
    
    
    sort(stand.begin(), stand.end(), compare);
    
    for (auto& elem : stand) {
        out << elem;
        out << ' ';
    }
    
    in.close();
    out.close();
 
    return 0;
}
