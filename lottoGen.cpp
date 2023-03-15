/******************************************
 * 
 * 
 *Time:28/08/2022
 *
 ******************************************/

#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

vector<int> lowNum;
vector<int> highNum;
vector<int> lotto;

random_device rd;

auto start = high_resolution_clock::now();
auto is_even = 0;
auto loop_count = 0;
bool isUnique = true;
char selection {};

void picknum() {
			while (is_even != 3)
			{
			is_even = 0;
			loop_count = loop_count +1;
			lowNum.clear();
			highNum.clear();
			lotto.clear();
			cout<<"DEBUG LOOP COUNT :"<<loop_count<<endl;

			for (auto i = 1; i <=3; i++) 
			{
				auto num = rd() %19 +1;
				if (count(lowNum.begin(), lowNum.end(), num)) 
				{
					isUnique = false;
				}
				else
				{
					lowNum.push_back(num);
					sort(lowNum.begin(), lowNum.end());
				}
			}

			for (auto j = 1; j <=3; j++) 
			{
				auto num2 = rd() %20 + 20;
				if (count(highNum.begin(), highNum.end(), num2)) 
				{
					isUnique = false;
				}
				else
				{
					highNum.push_back(num2);
					sort(highNum.begin(), highNum.end());
				}
			}

			//merges the two vectors into a third and prints the output
			merge(lowNum.begin(), lowNum.end(), highNum.begin(), highNum.end(), back_inserter(lotto));
			cout<<"DEBUG LOTTO SET :";
			for (const int& j : lotto)
			{
				cout << j << " ";
			}  

			for(auto i = 0; i < lotto.size(); i++)
			{
				if (lotto[i]%2==0)
				{
					is_even = is_even +1;
				}
			}
				cout<<endl;
				cout<<"DEBUG PRINT is_even :"<<is_even<<endl;
				cout<<endl;
			}	
}



int main () {

	system("clear");

	do {	
		cout <<"*******************************"<<endl;
		cout <<"Lotto num picker "<<endl;
		cout <<"*******************************"<<endl;
		cout <<"Generate Irish Lotto numbers - 1"<<endl;
		cout <<"Quit - Q"<<endl;
		cin >> selection;

		switch (selection)
		{
		case '1':
		do {
			picknum();
		} while (!isUnique);
			
				cout << "Some Potential reslts may be :";
				for(const int&k:lotto)
				{
					cout << k << " ";
				};

			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			//DEBUGGING
			cout <<endl;
			cout <<"    Debug"<<endl;
			cout <<"    Time taken :"<< duration.count() <<" microseconds"<<endl;
			cout <<"    Loop count :"<<loop_count<<endl;
			cout <<"    Even number count :" << is_even<<endl;
			break;
		}
	}
	while (selection != 'q' && selection != 'Q');
    return 0;
}        
