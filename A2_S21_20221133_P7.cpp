// File A2_S21_20221133_P7.cpp
// Purpose:
// Author: ………………….
// Section: ……………………
// ID: ……………………
// TA: ……………………
// Date: 25 Oct 2023
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
bool sol=0;
struct dominoT {
    int leftDots;
    int rightDots;
    bool used =0;
};
deque<dominoT>ans,temp;
int visited_tiles=0;
bool FormsDominoChain(vector<dominoT> & dominos , int leftDots =0, int rightDots =0 ){
    bool valid=0;
    if(dominos.size()==visited_tiles){
        for(auto it: temp ){
            ans.push_back(it);
        }
        sol =1;
        return true;
    }
    for (int i = 0; i < dominos.size(); ++i) {
        if(leftDots==0){
            dominos[i].used=1 , visited_tiles++ , temp.push_back(dominos[i]);
           valid = valid || FormsDominoChain(dominos, dominos[i].leftDots, dominos[i].rightDots);
           temp.pop_back() , visited_tiles-- , dominos[i].used=0;
           if(sol)return true;
        }
        if( !dominos[i].used){
//           if(dominos[i].leftDots == leftDots){
//               swap(dominos[i].leftDots,dominos[i].rightDots);
//               dominos[i].used=1;
//               visited_tiles++;
//              valid = valid || FormsDominoChain(dominos, dominos[i].rightDots, rightDots);
//               visited_tiles--;
//               dominos[i].used=0;
//               swap(dominos[i].leftDots,dominos[i].rightDots);
//           }
//           if(dominos[i].rightDots == rightDots){
//               swap(dominos[i].leftDots,dominos[i].rightDots);
//               dominos[i].used=1;
//               visited_tiles++;
//              valid = valid || FormsDominoChain(dominos, leftDots, dominos[i].leftDots);
//               visited_tiles--;
//               swap(dominos[i].leftDots,dominos[i].rightDots);
//               dominos[i].used=0;
//           }
           if(dominos[i].leftDots == rightDots){
               dominos[i].used = 1;
               visited_tiles++;
               temp.push_back(dominos[i]);
              valid = valid || FormsDominoChain(dominos,leftDots, dominos[i].rightDots);
              temp.pop_back();
              visited_tiles--;
               dominos[i].used = 0;
               if(sol)return 1;
           }
           if(dominos[i].rightDots == leftDots){
               dominos[i].used = 1;
               visited_tiles++;
               temp.push_front(dominos[i]);
              valid = valid || FormsDominoChain(dominos,dominos[i].leftDots, rightDots);
              temp.pop_front();
              visited_tiles--;
               if(sol) return 1;
               dominos[i].used = 0;
           }
        }
    }
    return(valid);

};
signed main(){
    int num;
    cout << "enter the number of tiles you want to test : ";
    cin>>num;
    string chain;
    vector< dominoT >dominos(num);
    cout<<"enter the tiles you want to test :\n";
    for (int i = 0; i <num ; ++i) {
        cin>> dominos[i].leftDots >> dominos[i].rightDots;
    }
    if(FormsDominoChain(dominos)){
        pair<int,int> last={ans.back().leftDots,ans.back().rightDots};
        for (auto it : ans) {
            cout<<it.leftDots<<"|"<<it.rightDots;
            if(!(it.leftDots==last.first && it.rightDots == last.second)){
                cout<<"-";
            }
        }
    }
    else{
        cout<<"there's no chain to print";
    }


}
