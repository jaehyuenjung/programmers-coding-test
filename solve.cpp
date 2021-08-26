#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> inputCitations = {3, 0, 6, 1,5};
const int outputReturn = 3;

int solution(vector<int> citations) {
    int answer = 0;
    int size = (citations.size() - 1) / 2;
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = citations.size() - 1; i >= size; i--)
        if(i+1 <= citations[i] && citations.size() - (i+1) <= i + 1){
            answer = i+1;
            break;
        }
    
    return answer;
}

int main(){
    const int result = solution(inputCitations);
    cout << result << "\n";
    if(outputReturn == result){
        cout << "O" << "\n";
    }else{
        cout << "X" << "\n";
    }
}
