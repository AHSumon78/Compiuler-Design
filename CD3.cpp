#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
vector<string> split(string data,char delimeter){
    vector<string> words;
    int l=0,r=0;
    for(int i=0;i<data.length();i++){
        if(data[i]==delimeter){
        r=i;  
         words.push_back(data.substr(l,r-l));
        l=r+1;
        }
     
    }
     words.push_back(data.substr(r+1,data.length()-r-1));
     return words;


}
int main(){
    string line;
    cin>>line;
    vector<string> words=split(line,'-');
    fstream file,sfile ;
    file.open(words[0]+".txt",ios:: in);
    string year=words[0]+"-";
    string toFind=words[1].substr(0,2);
    string course=words[1].substr(2,2);
    cout<<year<<endl;
    cout<<toFind<<endl;
    cout<<course<<endl;
    string newF=year+toFind;
    string fname;
    while(!file.eof()){
        file>>fname;
        if(fname.compare(newF)){
            break;
        }
    }
    file.close();
     if(!fname.compare(newF)){
          cout<<"Sorry file not found!"<<endl;
      }
      else{
          sfile.open(newF+".txt",ios::in);
          cout<<newF;
          
          string courses;
          while(!sfile.eof()){
              getline(sfile,courses);
              cout<<courses<<endl;
          }
        
      }
}