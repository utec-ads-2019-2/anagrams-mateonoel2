#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string palabra;
    string temporary = "0";
    vector<string> ordered;
    vector<string> desordered;
    vector<string> passed;
    vector<string> print;
    vector<int> not_pass;

    while(cin>>palabra){
        if(palabra == "#")
            break;
        desordered.push_back(palabra);

        for_each(palabra.begin(), palabra.end(), [](char & c) {
            c = ::tolower(c);
        });

        sort(palabra.begin(), palabra.end());
        ordered.push_back(palabra);
    }

    for(int i=0; i < ordered.size(); i++){
        temporary = ordered[i];
        ordered[i]="0";
            if((find(ordered.begin(), ordered.end(), temporary) != ordered.end())){
                not_pass.push_back(i);
            }
        ordered[i]=temporary;
    }

    for(int i=0; i < desordered.size(); i++) {
        if (!(find(not_pass.begin(), not_pass.end(), i) != not_pass.end())){
            print.push_back(desordered[i]);
        }
    }

    sort(print.begin(), print.end());

    for(int i=0; i < print.size(); i++){
        cout<<print[i]<<'\n';
    }

    return 0;
}
