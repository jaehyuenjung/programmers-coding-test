#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<int> inputPrices = {1, 2, 3, 2, 3};
const vector<int> outputReturn = {4, 3, 1, 1, 0};

vector<int> solution(vector<int> prices) {
    vector<int> time_stamp(prices.size());
    vector<int> answer(prices.size());
    time_stamp[prices.size() - 1] = prices.size();
    answer[prices.size() - 1] = 0;
    for (int i = prices.size() - 2; i >= 0; i--)
    {
        if(prices[i] <= prices[i+1]){
            answer[i] = answer[i+1] + 1;
            time_stamp[i] = time_stamp[i+1];
            while(time_stamp[i] < prices.size() && prices[i] <= prices[time_stamp[i]]){
                answer[i] += answer[time_stamp[i]];
                time_stamp[i] = time_stamp[time_stamp[i]];
            }
        }else{
            answer[i] = 1;
            time_stamp[i] = i + 1;
        }
    }
    return answer;
}

int main(){
    const vector<int> result = solution(inputPrices);

    string output = "O";
    for (int i = 0; i < outputReturn.size(); i++){
        if(result[i] != outputReturn[i]){
            output = "X";
        }
        cout << result[i] << "\n";
    }
    cout << output << "\n";
}
