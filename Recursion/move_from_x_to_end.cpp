#include<iostream>
#include<string>
using namespace std;

string endx(string s){
    if(s.length()==0) return "";
    char ch=s[0];
    string ans = endx(s.substr(1));
    if(ch=='x') return (ans+ch);
    return (ch+ans);
}

int main(){
    cout<<endx("axxbdxcefxhix")<<endl;
    return 0;
}