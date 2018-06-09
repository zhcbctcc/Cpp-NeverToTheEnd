//
//@Author  @PEZY @Yue Wang 
//@Date    Aug. 2014 Jun.2015
//@Brief
// read a sequence of ints from cin and
// store those values in a vector.程序的作用是读入一系列的int数字，并存在向量容器中
//vector是一个能够存放任意类型的动态数组

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    for (int i; std::cin >> i; vec.push_back(i)); //在vector类中的作用是在vector尾部加入一个数据

    return 0;
}
