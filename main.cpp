#include <iostream>
#include "libBase64.h"

using namespace std;

int main() {
    int i;
    string line;
    cout<<"Coding or Decoding? 1/2"<<endl;
    cin>>i;
    cin.ignore();
    cout<<"Enter the text:"<<endl;
    getline(cin, line);
    i==1? cout<<CodeBase64(line,Base64):cout<<CodeBase64(line,ASCII);
}
