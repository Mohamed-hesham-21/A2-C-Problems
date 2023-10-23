// File: A2_S21_20221133_P3.cpp
// Purpose: solving problem 3 in Problem Sheet 1 – Version 2.0
// Author: Mohamed Hesham
// Section: S21;
// ID: 20221133
// TA:
// Date: 23 Oct 2023
#include <bits/stdc++.h>
#include <cmath>
#define ll long long
#define int long long
#define ld long double
#define each const auto &
#define fk(i,n) for(ll i=0;i<ll n;i++)
#define uwu(t) while(t--)
#define endl '\n'
#define coder ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
const int N=1e6+1;
vector<string> split(string target, string delimiter){
      string temp = "";
      vector<string> ans;
      for (int i = 0; i < target.size(); ++i) {
                  temp.push_back(target[i]);
         if(temp.size() >= delimiter.size() ){
         string push="";
         for (int j = temp.size() - delimiter.size() ; j < temp.size() ; ++j) {
            push.push_back(temp[j]);
            }
            if(push == delimiter){
                for (int j = 0; j < delimiter.size(); ++j) {
                    temp.pop_back();
                }
                ans.push_back(temp);
                push=temp="";
            }
          }
  }
  ans.push_back(temp);
    return ans;
};
signed main(){
    coder
    string target , delimiter;

    getline(cin , target);
    getline(cin,delimiter);
    vector<string> answer = split(target ,delimiter );
    for (int i = 0; i < answer.size(); ++i) {
         cout<<answer[i]<<" ";
    }


}
