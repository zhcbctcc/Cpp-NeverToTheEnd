// prints the numbers from ten down to zero.(use while)

#include <iostream>

int main()
{
    int i = 10;
    while (i >= 0)
        std::cout << i-- << " ";
    return 0;
}


//输出：从10到0
//如果是std::cout << --i << " ";那么结果是从10到-1
//i--是正常的逻辑，--i是正常的逻辑再-1
