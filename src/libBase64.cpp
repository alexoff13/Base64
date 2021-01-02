#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "libBase64.h"

using namespace std;

const string Base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
string gettingBinaryCode(int N, int CountDigits) {
    unsigned int i;
    string res;
    i = 1 << CountDigits-1;
    do {
        if (N & i) {
            res+= '1';
        } else
            res+='0';
        i >>= 1;
    } while (i != 0);
    return res;
}

vector<int> gettingIndexes(string line,Table table){
    int countDigits=table==ASCII? 8:6;
    int leng=line.length();
    int count=leng/countDigits;
    bool flag=false;
    if(count*countDigits!=leng){
        count+=1;
        flag=true;
    }
    vector<int> indexes(count);
    for (int i=0;i<count;++i){
        if ((i==count-1)&&flag){
            string buf;
            buf+=line.substr(0,line.length()%countDigits);
            buf.append(countDigits-line.length()%countDigits,'0');
            indexes[i]=strtol(buf.c_str(), NULL, 2);
        } else{
            indexes[i]=strtol(line.substr(0,countDigits).c_str(), NULL, 2);
        }
        line.erase(0,countDigits);
    }
    return indexes;
}

string CodeBase64(string line,Table table){
    int countDigits=table==ASCII? 6:8;
    string binaryRepresentation;
    string res;
    for(char c:line){
        int index=table==ASCII?Base64Table.find(c):(int)(c);
        binaryRepresentation+=gettingBinaryCode(index,countDigits);
    }
    vector<int> indexes=gettingIndexes(binaryRepresentation,table);
    for(int i:indexes){
        res+=table==ASCII?(char)(i):Base64Table[i];
    }
    return res;
}
#include "libBase64.h"