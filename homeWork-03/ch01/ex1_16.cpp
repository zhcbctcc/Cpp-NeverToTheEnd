#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int sum = 0;
	int i = 0;
	cin >> i;
	int j;
	for (int j = 0; j <= i; j++)
	{
		sum = sum + j;
		
	}
	cout << "Sum is: " << sum << endl;
	
	return 0;
}

//输入3，输出6，这是一个求1+2+3+...的程序
