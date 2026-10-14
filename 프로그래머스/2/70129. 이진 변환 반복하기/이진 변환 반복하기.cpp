#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void conv(string& s, int& conversion, int& zero) {
    string tmp = "";
    for (char c : s) {
        if (c == '0')
            zero++;
        else
            tmp += c;
    }
    s = tmp;
    conversion++;
}

vector<int> solution(string s) {
    vector<int> answer;
    int conversion = 0, zero = 0;

    while (s != "1") {
        conv(s, conversion, zero);

        string binary = "";
        int len = s.length();
        while (len > 0) {
            if (len % 2 == 0)
				binary += "0";
            else
                binary += "1";
			len /= 2;
        }
        reverse(binary.begin(), binary.end());
        s = binary;
    }
    answer.push_back(conversion);
	answer.push_back(zero);
	return answer;
}