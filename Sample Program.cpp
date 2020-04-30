/*
	Problem : Write a function that returns vector of strings containing prime numbers upto 20.
*/
#include<bits/stdc++.h>
#include "test.h"
using namespace std;

vector<string> GET_ANSWER()
{
	//Write your code here
	vector<string>ret;
	vector<int>prime;

	for(int i=2;i<=20;i++){
		bool flag=false;
		for(int j=2;j<i;j++)
			if(i%j==0){flag=true; break;}
		if(!flag) prime.push_back(i);
	}
	for(auto it:prime) ret.push_back(to_string(it));
	return ret;
}

int main()
{
	vector<string>actual;
	actual = GET_ANSWER();
	TEST(actual);	
	return 0;
}