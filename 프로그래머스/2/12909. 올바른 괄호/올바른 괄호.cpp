#include <string>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
	stack<char> parent;
	int i = 0;
    while(i < s.length()) {
        if (parent.empty()) {
			parent.push(s[i]);
			i++;
		}
		else {
            if (parent.top() == '(') {
				if(s[i] == ')') {
					parent.pop();
					i++;
					continue;
				}
				else {
					parent.push(s[i]);
					i++;
				}
			}
			else {
				parent.push(s[i]);
				i++;
			}
		}
	}

	if (!parent.empty()) answer = false;
	return answer;
}