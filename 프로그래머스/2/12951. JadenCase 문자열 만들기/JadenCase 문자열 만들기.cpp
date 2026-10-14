#include <string>
#include <vector>
using namespace std;

string solution(string s) {
	string answer = "";
	for (int i = 0; i < s.length(); i++) {
		int cnt = 0;
		while(i < s.length() && s[i] != ' ') {
            // 숫자
			if (s[i]-'0'>= 0 && s[i]-'0'<= 9) {
				answer += s[i];
				i++;
				cnt++;
			} 
            // 대문자
            else if (s[i] >= 65 && s[i] <= 90) {
				if (cnt != 0) 
					answer += s[i] + 32;
				else  // 첫 문자이면
					answer += s[i];
				i++;
				cnt++;
			}
			// 소문자
			else if (s[i] >= 97 && s[i] <= 122) {
				if (cnt != 0)
					answer += s[i];
				else  // 첫 문자이면
					answer += s[i] - 32;
				cnt++;
				i++;
			}
		}
		if (s[i] == ' ') {
			answer += s[i];
			continue;
		}
	}
	return answer;
}