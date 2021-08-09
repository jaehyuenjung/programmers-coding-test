#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef map<string, bool> msb;
typedef vector<string> vs;


const bool compare(const string & x ,const string &y) {
    return x.length() > y.length();
}

vector<vs> input = {
    {"119", "97674223", "1195524421"},
    {"123","456","789"},
    {"12","123","1235","567","88"}
};


bool solution(vs phone_book){
    msb hash_map;
    sort(phone_book.begin(), phone_book.end(), compare);
    for(string& str : phone_book){
        if(hash_map[str])
            return false;
        for (int e = 1; e <= str.size(); e++)
            hash_map[str.substr(0, e)] = true;
    }

    return true;
}


int main(){
    for(vs e : input){
        cout << solution(e) << "\n";
    }
}
