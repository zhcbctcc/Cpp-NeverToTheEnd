//reads a string of characters including punctuation and writes what you input同时，标点符号被空格代替，也可以被其他符号代替

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "Enter a string of characters including punctuation." << endl;
	for (string s; getline(cin, s); cout << endl)
		for (auto i : s) //这里的：也可以用in代替 比较好理解；这里的i也可以用j等字符代替
			if (!ispunct(i))
				cout << i;
			else
				cout << "(*^▽^*) ";
	return 0;
}
