#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	vector<int> element(10000001, 0);

	for (int i = 0; i < tangerine.size(); i++)
		element[tangerine[i]]++;

	int j = 0;
	sort(element.begin(), element.end(), greater<>());
	while (k > 0) {
		if (k > element[j]) {
            k -= element[j];
			answer++;
		}
        else {
            answer++;
            break;
		}
		j++;
	}
    return answer;
}