#include <string>
#include <vector>
#include <stack>
using namespace std;

void correct(string& s, stack<char>& stk, int& answer) {
	bool open = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			open = true;
			stk.push(s[i]);
		} else {
			if (!stk.empty() && s[i] == ')' && stk.top() == '(') stk.pop();
			else if (!stk.empty() && s[i] == '}' && stk.top() == '{') stk.pop();
			else if (!stk.empty() && s[i] == ']' && stk.top() == '[') stk.pop();
		}
	}

	if (open && stk.empty()) {
		answer++;
	}
	stk = stack<char>();
}

int solution(string s) {
	int answer = 0;
	stack<char> stk;
	
    correct(s, stk, answer);
	for (int i = 0; i < s.length() - 1; i++) {
		char temp = s[0];
		s += temp;
		s.erase(s.begin(), s.begin() + 1);
		correct(s, stk, answer);
	}
	return answer;
}