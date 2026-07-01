#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> v(2);
    v[0] = sizes[0][0]; v[1] = sizes[0][1];
    answer = v[0] * v[1];

    for(int i = 1; i < sizes.size(); i++) {
        if(v[0] >= sizes[i][0] && v[1] >= sizes[i][1]) {
            continue;
        }
        else if (v[0] >= sizes[i][0] && v[1] < sizes[i][1]) {
            int temp = v[0] * sizes[i][1];   
            if(v[0] >= sizes[i][1] && v[1] >= sizes[i][0])  continue;
            else if(v[0] < sizes[i][1] && v[1] >= sizes[i][0]) {
                int rect = sizes[i][1] * v[1];
                if(rect < temp) {
                    v[0] = sizes[i][1]; 
                    answer = rect;
                }
                else {
                    v[1] = sizes[i][1];
                    answer = temp;
                }
            }
            else if(v[0] >= sizes[i][1] && v[1] < sizes[i][0]) {
                int rect = v[0] * sizes[i][0];
                if(rect < temp) {
                    v[1] = sizes[i][0];
                    answer = rect;
                }
                else {
                    v[1] = sizes[i][1];
                    answer = temp;
                }
            }
            else {
                v[0]= sizes[i][1];
                v[1] = sizes[i][0];
                answer = v[0] * v[1];
            }
        }
        else if (v[0] < sizes[i][0] && v[1] >= sizes[i][1]) {
            int temp = sizes[i][0] * v[1];
            if(v[0] >= sizes[i][1] && v[1] >= sizes[i][0])  continue;
            else if(v[0] < sizes[i][1] && v[1] >= sizes[i][0]) {
                int rect = sizes[i][1] * v[1];
                if(rect < temp) {
                    v[0] = sizes[i][1]; 
                    answer = rect;
                }
                else {
                    v[0] = sizes[i][0];
                    answer = temp;
                }
            }
            else if(v[0] >= sizes[i][1] && v[1] < sizes[i][0]) {
                int rect = v[0] * sizes[i][0];
                if(rect < temp) {
                    v[1] = sizes[i][0];
                    answer = rect;
                }
                else {
                    v[0] = sizes[i][0];
                    answer = temp;
                }
            }
            else {
                v[0]= sizes[i][1];
                v[1] = sizes[i][0];
                answer = v[0] * v[1];
            }
        }
        else {
            v[0] = sizes[i][0];
            v[1] = sizes[i][1];
            answer = v[0] * v[1];
        }
    }
    return answer;
}