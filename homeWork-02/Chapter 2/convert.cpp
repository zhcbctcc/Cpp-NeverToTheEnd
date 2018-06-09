// convert.cpp -- converts stone to pounds
#include <iostream>
int stonetolb(int sts);     // function prototype
int main()
{
    using namespace std;
    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int pounds = stonetolb(stone);//可以这样运用一个函数来定义一个输出
    cout << stone << " stone = ";
    cout << pounds << " pounds." << endl;
	// cin.get();
    // cin.get();
    return 0;
}

int stonetolb(int sts)//定义这个函数，函数作用是返回14*sts
{
     return 14 * sts;
}
