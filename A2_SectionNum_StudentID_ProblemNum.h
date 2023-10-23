#include <iostream>
using namespace std;

void Sentences(){
    string s ;
    string sentence="";
    bool started = false;
    while (cin >> s ){
        for (int i = 0; i < s.size(); ++i) {
            s[i]= tolower(s[i]);
        }
        if (started){
            if (s==","||s=="."){}
            else if (s[0]==','){s[0]=' ';s=","+s;}
            else sentence+=" ";
        }
        sentence+=s;
        started=true;


        if (sentence[sentence.size()-1]=='.'){sentence[0]= toupper(sentence[0]);cout << sentence;return ;}
    }
}
