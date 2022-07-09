#include <iostream>
#include <string>
using namespace std;

int main() {
    string line, abb[4] = { "U", "C", "P", "C" };
    getline(cin, line); // 공백 포함 문자열을 받음
    int idx = 0;
    bool flag = false;
    for (int i = 0; i < 4 && flag == false; i++) {
        idx = line.find_first_of(abb[i], idx);
        if (idx == -1) flag = true; // abb[i]가 line에 없을 때
    }
    if (flag) cout << "I hate UCPC";
    else cout << "I love UCPC";
}