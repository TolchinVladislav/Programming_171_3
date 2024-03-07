#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Написать программу, сортирующую список студентов группы по алфавиту и использующую стандартную сортировку qsort

using namespace std;

int main() {
   
    vector<string> group;
    group.push_back("Чулюков Дмитрий");
    group.push_back("Слюсарев Кирилл");
    group.push_back("Язынин Максим");
    group.push_back("Шин Даниил");
    group.push_back("Яковлев Никита");
    group.push_back("Фесенко Максим");
    group.push_back("Толчин Владислав");
    group.push_back("Степанов Александр");
    
    
   
 sort(begin(group), end(group));
    
    for (int i = 0; i < group.size(); i++) {
        cout << group[i] << endl;
    }

 
    return 0;
}
