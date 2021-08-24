#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> inputArray = {1, 5, 2, 6, 3, 7, 4};
const vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
const vector<int> ouputReturn = {5, 6, 3};

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(vector<int> comm : commands){
        vector<int> tmp;
        copy(array.begin() + --comm[0], array.begin() + comm[1],  back_inserter(tmp));
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[--comm[2]]);
    }
    return answer;
}

int main(){
    const vector<int> result = solution(inputArray, commands);
    string output = "O";
    for (int i = 0; i < ouputReturn.size(); i++){
        if(ouputReturn[i] != result[i]){
            output = "X";
            break;
        }
    }
    cout << output << "\n";
}
