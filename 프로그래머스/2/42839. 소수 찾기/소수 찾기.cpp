#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
	}
	return true;
}

int solution(string numbers) {
    int answer = 0;
	
    set<int> s;
	sort(numbers.begin(), numbers.end());

    do {
		string temp;
		for (int i = 0; i < numbers.size(); i++) {
			temp += numbers[i];
            if(isPrime(stoi(temp)))
				s.insert(stoi(temp));
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	answer = s.size();
	return answer;
}