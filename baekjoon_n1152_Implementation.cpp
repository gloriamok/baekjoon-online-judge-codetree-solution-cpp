#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	getline(cin, line); // 공백을 포함한 문자열을 받아오기 위해 getline 사용
	if (line.size() == 1 && line == " ") { // 만약 입력된 문자열이 공백뿐인 " "이라면 0을 출력한 뒤 프로그램 종료
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < line.size() ; i++) {
		if (line[i] == ' ' && i!=0 && i!=line.size()-1) cnt++;
	}
	cout << cnt + 1; // 센 공백의 수에서 1을 더해서 출력
}
