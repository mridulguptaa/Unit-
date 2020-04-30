#include<bits/stdc++.h>
using namespace std;

/****************FUNCTION DECLARATIONS**************************/
template<typename T>
bool compare(T a,T b);

template<typename T>
void verdict(T a);

template<typename T>
void TEST(T actual);

void clrscr();

/*****************CUSTOM FUNCTIONS******************************/
void clrscr() 
{
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}

template<typename T>
bool compare(T a,T b)
{
	if(a.size()!=b.size()) return false;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i]) return false;
	return true;
}

template<typename T>
void print_verdict(T a)
{
	int ptr=1;
	int correct=0;
	for(auto it:a)
	{
		cout<<"TestCase #"<<ptr<<"....";
		if(it==0) cout<<"Failed"<<endl;
		else cout<<"Passed"<<endl;
		correct+=it;
	}
	cout<<endl<<"Total Passed : "<<correct<<"/"<<a.size();
}

template<typename T>
void TEST(T actual)
{
	clrscr();
	string line;
	ifstream infile("Sample_Expected.txt");
	vector<int>verdict;
	while (getline(infile, line)){	
		vector <string> tokens;
	    stringstream check1(line); 
    	string intermediate; 
	    while(getline(check1, intermediate, ' '))  
	        tokens.push_back(intermediate); 
	    if(tokens.size()) tokens.erase(tokens.begin(),tokens.begin()+1);
	    if(compare(tokens,actual)) verdict.push_back(1);
	    else verdict.push_back(0);
	}
	print_verdict(verdict);
}