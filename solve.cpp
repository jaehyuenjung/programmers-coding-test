#include<iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;
typedef vector<string> vs;
typedef map<string, int> msi;
typedef vector<vector<string>> vvs;
typedef pair<string, int> psi;

const vector<vector<vector<string>>> input= {
    {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}},
    {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}},
};

const int answer[] = {5, 3};

int solution(vector<vector<string>> clothes){
    msi hash_map;
    for_each(clothes.begin(), clothes.end(), [&](const vs &cloth)
             { hash_map[cloth.back()] += 1; });
    return accumulate(hash_map.begin(), hash_map.end(), 1, [&](int result, const psi &p){
        return result * (hash_map[p.first] + 1);
    }) - 1;
}

int main(){
    for (int i = 0; i < input.size(); i++){
        const int result = solution(input[i]);
        if(result == answer[i]){
            cout << "O"
                 << "\n";
        }else{
            cout << "X"
                 << "\n";
        }
    }
}
