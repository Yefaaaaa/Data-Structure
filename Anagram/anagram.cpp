#include "anagram.h"
#include <iostream>
#include <algorithm>
#include <String>
#include <cstdio>
#include <cmath>

using namespace std;

anagram::anagram()
{
    int num_repeat;
    cout<<"How many string you want to check? ";
    cin>>num_repeat;
    string input;
    while (num_repeat--){
        cout<<"Enter your string: ";
        cin>>input;
        string a = input.substr(0,input.size()/2);
        string b = input.substr(input.size()/2);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        string c;
        if(a.size()==b.size()){
            auto it = set_difference(a.begin(),a.end(),b.begin(),b.end(),c.begin());
            c.resize(it-c.begin());
            cout<<"Number of the different Character: "<<c.size()<<endl;
        }else{
            cout << "No comparable."<<endl;
        }




    }

}

anagram::~anagram()
{
    //dtor
}
