#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
bool isVowel(char ch);
bool isCharacter(char ch);
bool isDigit(char ch);
vector<int> countVowel(string data){
    int l= data.length();
    int vowel=0,letters=0,c=0; 
     vector<int> v(2);
    for(int i=0;i<l;i++){
      if(isCharacter(data[i])){
          letters++;
          if(isVowel(data[i])){
              vowel++;
          }
        }
    }
    v[0]=vowel;
    v[1]=letters-vowel;
    return v;
}
map<char,int> whichVowel(string data){
    map<char,int> mp;
    for(int i=0;i<data.length();i++){
        if(isVowel(data[i])){
              mp[tolower(data[i])]++;
          }
    }
    return mp;
}
vector<string> split(string data,char delimeter){
    vector<string> words;
    int l=0,r=0;
    for(int i=0;i<data.length();i++){
        if(data[i]==' '){
        r=i;  
         words.push_back(data.substr(l,r-l));
        l=r+1;
        }
     
    }
     words.push_back(data.substr(r+1,data.length()-r-1));
     return words;


}
bool isVowel(char ch){
    ch=tolower(ch);
    if(ch=='a'|| ch=='e' || ch=='i' || ch=='o' ||ch=='u'){
        return true;
    }
    else{
        return false;
    }
}
bool isCharacter(char ch){
    ch=tolower(ch);
    if(ch>='a' && ch<='z')
    return true;
    else
    return false;
}
bool isDigit(char ch){
    if(ch>='0' && ch<='9')
    return true;
    else 
    return false;
}
int main(){
    string data ="Munmun is the student of Computer Science & Engineering";
   //a
   vector<int> v=countVowel(data);
   cout<<"vowel :"<<v[0]<<endl;
   cout<<"consonent :"<<v[1]<<endl;
   //b
   map<char,int> mp=whichVowel(data);
   cout<<"The vowel present in this string \""<<data<<"\" is \n";
 
   map<char,int> :: iterator it=mp.begin();
   vector<string> words=split(data,' ');
   string startWithVowel="",startWithConsonant="";
   for(string s:words){
       cout<<s<<endl;
       if(isVowel(s[0])){          
           startWithVowel+=s;
           startWithVowel+=" ";
       }
       else{
           startWithConsonant+=s;
           startWithConsonant+=" ";
       }
   }
   cout<<startWithConsonant<<endl;
   cout<<startWithVowel<<endl;
}