#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
	vector<int> v;
	for (int i = 0; i < number.length(); i++)
		v.push_back(number[i] - '0');

	int start = 0;
	int total_size = number.length() - k;
	while(total_size > answer.length()) {
		int max_idx = max_element(v.begin() + start, v.begin() + start + k + 1) - v.begin();
		answer += to_string(v[max_idx]);
		k -= (max_idx - start);
		start = max_idx + 1;
	}
	return answer;
}