#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> umap;
    
    for(int i=0; i < participant.size(); i++) {
        umap[participant[i]]++;
    }
    
    for(int i=0; i < completion.size(); i++) {
        umap[completion[i]]--;
    }
    
    for(auto& iter : umap) {
        if(iter.second != 0)
            answer = iter.first;
    }
    return answer;
}