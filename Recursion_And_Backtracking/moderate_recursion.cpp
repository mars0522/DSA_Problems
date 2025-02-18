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

void GetMaizePath(int sr, int sc, int dr, int dc, string path, vector<string>& res) {
    if (sr < 0 || sr > dr) return ;
    if (sc < 0 || sc > dc) return ;

    if (sr == dr && sc == dc) {
        res.push_back(path);
        return;
    }

    if (sr < dr) {
    GetMaizePath(sr+1,sc,dr,dc,path + "D",res);
    }
    if (sc < dc){
    GetMaizePath(sr,sc+1,dr,dc,path + "R",res);
    } 
}

void GetMaizePathWithJumps(int sr, int sc, int dr, int dc , string path, vector<string> & res) {
    if (sr > dr || sc > dc) return ;
    if (sr == dr && sc == dc) {
        res.push_back(path);
        return;
    }
    for(int i=1; i<=3;i++){
        if (sr + i <= dr) {
            GetMaizePathWithJumps(sr+i,sc,dr,dc,path + "V" + to_string(i),res);
        }
        if (sc + i <= dc ) {
            GetMaizePathWithJumps(sr,sc+i,dr,dc,path + "H" + to_string(i),res);
        }
        if (sr + i <= dr && sc + i <= dc) {
            GetMaizePathWithJumps(sr+i,sc+i,dr,dc,path + "D" + to_string(i),res);
        }
    }

}

void swapchar(string& input, int i, int j){
    if (i==j) return;
    char temp;
    temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

void PrintPermutations(string& input , int index, vector<string> & output){
    if (index >= input.size()-1){
        output.push_back(input);
        return ;
    }
    for(int i=index;i < input.size();i++){
        swapchar(input,index,i);
        PrintPermutations(input,index+1,output);
        swapchar(input,index,i);
    }

}

void PrintEncoding(string& input,string str, unordered_map<string,char> & mp, int index, vector<string>& output ){
    if (index >= input.size()) {
       output.push_back(str);
       return ;
    }
    string lookup(1,input[index]);  
    str += mp[lookup];
    PrintEncoding(input,str,mp,index+1,output);
    if (index <= input.size()-2){
        lookup = input.substr(index,2);
        if (stoi(lookup) >= 27) return ;
        str.pop_back();
        str += mp[lookup];
        PrintEncoding(input,str,mp,index+2,output);
    }
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

    // int n;
    // cin>>n;
    // vector<vector<int>> res;
    // vector<int> path;
    // GetStairsPath(n,res,path);
    // for(auto arr: res) {
    //     for(auto e:arr) {
    //         cout<<e<<" ";
    //     }
    //     cout<<endl;
    // }

    // vector<string> output;
    // string str = "";
    // int sr, sc, dr, dc;
    // cin>>sr>>sc>>dr>>dc;
    // // GetMaizePath(sr,sc,dr,dc,str,output);
    // GetMaizePathWithJumps(sr,sc,dr,dc,str,output);

    // for(auto path : output) {
    //     for(auto x: path)
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    unordered_map<string,char> mp;
    mp["1"] = 'a';
    mp["2"] = 'b';
    mp["3"] = 'c';
    mp["4"] = 'd';
    mp["5"] = 'e';
    mp["6"] = 'f';
    mp["7"] = 'g';
    mp["8"] = 'h';
    mp["9"] = 'i';
    mp["10"] = 'j';
    mp["11"] = 'k';
    mp["12"] = 'l';
    mp["13"] ='m';
    mp["14"] = 'n';
    mp["15"] = 'o';
    mp["16"] = 'p';
    mp["17"] = 'q';
    mp["18"] = 'r';
    mp["19"] ='s';
    mp["20"] = 't';
    mp["21"] = 'u';
    mp["22"] = 'v';
    mp["23"] = 'w';
    mp["24"] = 'x';
    mp["25"] = 'y';
    mp["26"] = 'z';
    string input;
    cin>>input;
    vector<string> output;
    // PrintPermutations(input,0,output);
    PrintEncoding(input,"",mp,0,output);
    for(auto x: output) {
        cout<<x<<endl;
    }
}
