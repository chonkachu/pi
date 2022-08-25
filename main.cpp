#include<bits/stdc++.h>
#include "num.hpp"
using namespace std;

// argv[1] -> len 
// argv[2] -> p_size
int main(int argc, char **argv){
    ifstream is("./pi-billion.txt", ifstream::binary);
    int p_size = 9, len = 130000 ;

    if(argc == 3){
        len = stoi(string(argv[1]));
        p_size = stoi(string(argv[2]));
        cout << len << " " <<  p_size << endl;
    }
    else{
        cout << "bad arguments" << endl;
    }
    is.seekg(0, is.end);
    is.seekg(0, is.beg);

    char *buffer = new char [len+1];
    is.read(buffer, len);
    buffer[len] = '\0';

    for(int i = 2; i < len; i++){
        char *c = new char[p_size+1];
        if(i <= len-p_size){
            strncpy(c, buffer+i, p_size);
            c[p_size] = '\0';
            Num num(c);
            delete[] c;
//            puts(&test[0]);
            if(num.is_palindrome() && num.is_prime()){
              vector<char> ans;
              num.print(ans);
              puts(&ans[0]);                                
              printf("pos: %d\n", i);
            } 
        } 
    }                                         
    

    is.close();
    delete[] buffer;

    return 0;
}
