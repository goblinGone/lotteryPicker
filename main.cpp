#include <iostream>
#include <list>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> lowNum;
vector<int> highNum;

void lowgen(){
    int num;
    int i;
    srand(time(0));
    for (i =1; i <=3; i++){
        num = rand() %20;
        lowNum.push_back(num);
        sort(lowNum.begin(), lowNum.end());
    }
    
    // for (const int& i : lowNum){
    //     cout << i << " ";
    // }
}

void highgen(){
    int num2;
    int j;
    srand(time(0));
    for (j =1; j <=3; j++){
        num2 = rand() %20 + 20;
        highNum.push_back(num2);
        sort(highNum.begin(), highNum.end());        
    }
    
    // for (const int& j : highNum){
    //     cout << j << " ";
    // }  
}

void resultOut(){
    cout<<"results are :";
    for (const int& i : lowNum){
        cout << i << " ";
    }
    for (const int& j : highNum){
        cout << j << " ";
    }  
}

int main(){

    lowgen();
    highgen();
    resultOut();




    // for (ln_iter = lowNums.begin(); ln_iter != lowNums.end(); ln_iter++)
    //     cout<< *ln_iter<<endl;


    // int number2;
    // int j;
    // srand(time(0));
    // for (j =1; j <=3; j++){
    //     number2 = rand() %20 + 20;
    //     cout <<number2 << " ";
    // }

    return 0;
}