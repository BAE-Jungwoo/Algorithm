#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


int solution(string name) {
    int answer = 0;
    int length = name.length();
    int move = length - 1; // 좌우 이동 횟수 초기화

    map<char, int> alphabet_map;
    for(int i = 0; i < alphabet.size() / 2; i++) {
        // 알파벳과 인덱스 매핑
        alphabet_map[alphabet[i]] = i; 
        alphabet_map[alphabet[i + alphabet.size() / 2]] = alphabet.size() / 2 - i;
    }

    for(int i = 0; i < length; i++) {
        // 상하 이동 횟수 계산
        answer += alphabet_map[name[i]];
        int next_index = i + 1;
        while(next_index < length && name[next_index] == 'A') {
            next_index++;
        }

        // 좌우 이동 횟수 계산
        move = min(move, i + length - next_index + min(i, length - next_index));
    }
    answer += move;
    return answer;
}