#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

//int get_digitsum(string a);
//bool SHT_is_leapyear(string a);
int get_digitsum(string a);
bool SHT_is_leapyear(string a);
string int_to_string(int a);

int main(int argc, char const *argv[])
{
	int ptr_one = 0;
	//string a ="│  │  │  │  │  │  │ 1│  ";
	//string b= "│13│14│15│16│17│18│19│  ";
	/*
	for (int i = 0;i<5;i++)
	{
		ptr_one = a.find_first_of("2",ptr_one+1);
		cout << ptr_one <<endl;
		i = i+1;
	}*/
	string a = "012222233223022";
	//string &append(const string &s,int pos,int n);//把字符串s中从pos开始的n个字符连接到当前字符串的结尾
	//int b = a.find_first_of("2");
	string b="05200";
	a.append(b,1,3);
	cout << a  << endl;

	//cout << b<<endl;
	//cout << a.size()<<endl;
	//cout << b.size()<<endl;
	return 0;
}