#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<cstdio>
#include<climits>
#include<cmath>
using namespace std;

void Subsequences(string input, int length, int index, string output, vector<string>& res) {
    if (index >= length) {
        res.push_back("(" + output+ ")");
        return;
    }
    Subsequences(input, length, index + 1, output + input[index], res);
    Subsequences(input, length, index + 1, output, res);
}
void KeyPadCombinations(string input, int index, string output, vector<string>& res, unordered_map<char,string>& mp) {
    if (index >= input.size()) {
        res.push_back( output);
        return;
    }
    string str = mp[input[index]];
    for(auto x: str) {
        KeyPadCombinations(input, index+1, output + x, res, mp);
    }

}
void GetStairsPath(int n, vector<vector<int>> & res, vector<int> path) {
    if (n==0) {
        if (path.size() > 0){
        res.push_back(path);
        }
        return;
    }
    if (n < 0) return ;
    path.push_back(1);
    GetStairsPath(n-1,res,path);
    path.pop_back();
    path.push_back(2);
    GetStairsPath(n-2,res,path);
    path.pop_back();
    path.push_back(3);
    GetStairsPath(n-3,res,path);
}
int main() {
    #ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
    // string input;
    // cin>>input;
    // vector<string> res;
    // Subsequences(input,input.size(),0,"",res);
    // for(auto x: res) {
    //     cout<<x<<endl;
    // }
    // return 0;
    // unordered_map<char, string>mp;
    // mp['2'] = "abc";
    // mp['3'] = "def";
    // mp['4'] = "ghi";
    // mp['5'] = "jkl";
    // mp['6'] = "mno";
    // mp['7'] = "pqrs";
    // mp['8'] = "tuv";
    // mp['9'] = "wxyz";
    // string output = "";
    // KeyPadCombinations(input,0,output,res,mp);
    // for(auto x:res) {
    //     cout<<x<<endl;
    // }

    int n;
    cin>>n;
    vector<vector<int>> res;
    vector<int> path;
    GetStairsPath(n,res,path);
    for(auto arr: res) {
        for(auto e:arr) {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}
