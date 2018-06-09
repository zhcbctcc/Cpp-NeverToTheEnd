// Print each number in the range specified by two integers.

#include <iostream>

using std::cout;
using std::cin;

void print_range(int lo, int hi)
{
    if (lo > hi)
    {
        print_range(hi, lo); //默认是先输入小值，再输入大值；但是用户如果相反，就把大值看成小值，小值看成大值；这是一个方法
        return;
    }
    else //这里再加一个else会更好理解
    for (int i = lo; i != hi+1; ++i) //核心代码 问题是：如何判断输入的两个数大小
        cout << i << " ";
}

int main()
{
    int low = 0, high = 0;
    cout << "please input two integers:\n";
    cin >> low >> high;
    print_range(low, high);
    return 0;
}

//输入1和5，输出结果是1 2 3 4 5 ；输入5和1，也是同样的结果
