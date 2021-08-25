#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const vector<vector<int>> inputNumbers = {{6, 10, 2}, {3, 30, 34, 5, 9}, {90, 908, 89, 898, 10, 101, 1, 8, 9}};
const vector<string> outputReturn = {"6210", "9534330", "990908898988110110"};

struct cmp{
    const bool operator()(const string &a, const string &b){
        string va = a + b;
        string vb = b + a;
        return va > vb;
    }
};

string solution(vector<int> numbers) {
    vector<string> array;
    for(auto num : numbers)
        array.push_back(to_string(num));
    sort(array.begin(), array.end(), cmp());
    if(array.front().compare("0")==0)
        return "0";
    return accumulate(array.begin(), array.end(), string(""), [](string result, string value) {
        return result + value;
    });
}

int main(){
    for (int i = 0; i < 3; i++){
        const string result = solution(inputNumbers[i]);
        if(outputReturn[i].compare(result) == 0){
            cout << "O" << "\n";
        }else{
            cout << "X" <<"\n";
        }
        cout << result << "\n";
    }
}
