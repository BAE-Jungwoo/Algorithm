#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> temp;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') continue;
        
		string ss = "";
		while (i < s.length() && s[i] != ' ') {
			ss += s[i];
			i++;
		}
		temp.push_back(stoi(ss));
	}
	int maxNum = *max_element(temp.begin(), temp.end());
	int minNum = *min_element(temp.begin(), temp.end());
	answer = to_string(minNum) + " " + to_string(maxNum);
	return answer;
}