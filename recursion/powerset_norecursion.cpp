#include <iostream> 
#include <cmath>
using namespace std;

void powerset(string s){
    int n = s.size();
    for(int i = 0; i <= pow(2,n)-1; i++){
        string tmp = "";
        for(int j = 0; j <= n-1; j++){
            if((i & (1 << j)) != 0) tmp += s[j];
        }
        cout  << "\""<< tmp << "\"\n";
    }
}

int main(){
    string s = "abc";
    powerset(s);
    return 0;
}

