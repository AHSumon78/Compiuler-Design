#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<stdlib.h>
using namespace std;
vector<string> split(string data, char delimeter)
{
    vector<string> words;
    int l = 0, r = 0;
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == delimeter)
        {
            r = i;
            words.push_back(data.substr(l, r - l));
            l = r + 1;
        }
    }
    words.push_back(data.substr(r + 1, data.length() - r - 1));
    return words;
}
int main()
{
    int t = 10;
    while (t--)
    {
        cout<<"Enter Course code Like \"CSE-3112\"\n";
        string line;
        cin >> line;
        system("CLS");
        vector<string> words = split(line, '-');
        fstream file, sfile;
        file.open(words[0] + ".txt", ios::in);
        string dept, years;
        getline(file, dept);
        string year = words[0] + "-";
        string toFind="";
        string course=" ";
        string newF="";
        if (words.size() > 1)
        {
            toFind = words[1].substr(0, 2);
            course = words[1].substr(2, 2);
            newF = year + toFind;
        }
        else
        {
            cout << "Sorry file not found!" << endl;
            return 0;
        }
        string fname;
        while (!file.eof())
        {
            file >> fname;
            if (fname.compare(newF))
            {
                break;
            }
        }
        file.close();
        if (!fname.compare(newF))
        {
            cout << "Sorry file not found!" << endl;
            return 0;
        }
        else
        {
            try
            {
                sfile.open(newF + ".txt", ios::in);
                getline(sfile, years);
                cout <<"=>>\n"<< dept << years;
                string courses;
                if(course.length()==2){
                while (!sfile.eof())
                {  
                    getline(sfile, courses);
                    if (courses.substr(0, 2).compare(course) == 0)
                    {
                        cout << courses.substr(3);
                        break;
                    }
                }
                sfile.close();
                cout<<endl;
                }
                else{
                    cout<<"Sorry the couse code is wrong!\n";
                }
            }
            catch (exception e)
            {
                cout << "Sorry file not found!" << endl;
                return 0;
            }
        }
    }
}