#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int countWords(string data){
    int len= data.length();
    int count =0;
    for(int i=0;i<len;i++){
         if(data[i]==' '){
             count++;
         }
    }
    return count;
}
vector<int> numberOf(string data,int len){
    int letters=0;
    int digits=0;
    int others=0;
    int space=0;
    for(int i=0;i<len;i++){
        if((data[i]>='A') && (data[i]<='Z') || (data[i]>='a') && (data[i]<='z') ){
          letters++;
        }
             if((data[i]>='0') && (data[i]<='9') ){
          digits++;
        }
              if((data[i]==' ') ){
          space++;
        }
    }
    others=len-letters-digits-space;
    vector<int>v(4);
    v[0]=letters;
    v[1]=digits;
    v[2]=space;
    v[3]=others;
    return v;
}
map<char,int> separates(string data){
    map<char,int> mp;
    for(int i=0;i<data.length();i++){
        mp[data[i]]++;
    }
    return mp;
}
int main(){
    string  data="Md. Tareq Zaman, Part-3, 2011";
    //a
    cout<<data<<endl;
    int len= data.length();
    cout<<"Number of words :"<<countWords(data)<<endl;
    vector<int> v=numberOf(data,len);
    cout<<"Numbers of letters :"<< v[0]<<endl;
       cout<<"Numbers of digits :"<< v[1]<<endl;
          cout<<"Numbers of others :"<< v[3]<<endl;

}