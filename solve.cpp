#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

const vector<vector<string>> inputOperations = {{"I 16","D 1"}, {"I 7","I 5","I -5","D -1"}};
const vector<vector<int>> outputReturn = {{0, 0}, {7, 5}};

vector<int> solution(vector<string> operations) {
    deque<int> dq;
    while(operations.size()){
        string el = "";
        char comm;
        int number;
        comm = number = 0;
        while(operations.size() && comm != 'D'){
            el = operations.front();
            operations.erase(operations.begin());
            comm = el[0];
            number = stoi(el.substr(1, el.size() - 1));
            if(comm == 'I')
                dq.push_back(number);
        }
        sort(dq.begin(), dq.end(), greater<int>());
        if(comm == 'D' && dq.size()){
            if(number > 0)
                dq.pop_front();
            else
                dq.pop_back();
        }
    }
    return (dq.size()) ? vector<int>({dq.front(), dq.back()}) : vector<int>({0, 0});
}

int main(){
    for (int i = 0; i<2; i++){
        vector<int> result = solution(inputOperations[i]);

        string output = "O";
        for(int j=0; j<result.size(); j++){
            if(outputReturn[i][j] != result[j]){
                output = "X";
                
            }
            cout << result[j] << "\n";
        }
        cout << output << "\n";
    }
}
