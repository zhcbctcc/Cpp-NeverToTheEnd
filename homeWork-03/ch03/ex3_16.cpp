//
//@Author  PEZY
//@Date    Aug. 2014
//@Brief 
// print the size and contents of the vectors from exercise 3.13.
// Check whether your answers to that exercise were correct. 
// If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<int> v1; //这是一个空向量容器
    cout << "{\n \"v1\":{\"size\":\"" << v1.size() << "\",\"value\":[";
    for (auto i : v1)
        cout << i << ",";
    if (!v1.empty()) cout << "\b"; //不是空的
    cout << "]}" << endl;

    vector<int> v2(10); //这是一个包含着10个0的向量容器
    cout << " \"v2\":{\"size\":\"" << v2.size() << "\",\"value\":[";
    for (auto i : v2)
        cout << i << ",";
    if (!v2.empty()) cout << "\b"; //  /b元字符通常用于查找位于单词的开头或结尾的匹配；在单词边界匹配的位置，单词字符后面或者前面不与另一个
                                   //单词字符直接相邻。
    cout << "]}" << endl;

    vector<int> v3(10, 42); //这是一个包含着10个42的向量容器 ；
    cout << " \"v3\":{\"size\":\"" << v3.size() << "\",\"value\":[";
    for (auto i : v3)
        cout << i << ",";
    if (!v3.empty()) cout << "\b";
    cout << "]}" << endl;
    //以上定义向量容器都是用（）括号符号
    
    vector<int> v4{ 10 }; //这是一个包含“10”一个字符的向量容器
    cout << " \"v4\":{\"size\":\"" << v4.size() << "\",\"value\":[";
    for (auto i : v4)
        cout << i << ",";
    if (!v4.empty()) cout << "\b";
    cout << "]}" << endl;

    vector<int> v5{ 10, 42 }; //这是一个包含着“10”“42”两个字符的向量容器
    cout << " \"v5\":{\"size\":\"" << v5.size() << "\",\"value\":[";
    for (auto i : v5)
        cout << i << ",";
    if (!v5.empty()) cout << "\b";
    cout << "]}" << endl;

    vector<string> v6{ 10 }; //不懂
    cout << " \"v6\":{\"size\":\"" << v6.size() << "\",\"value\":[";
    for (auto i : v6)
        if (i.empty()) cout << "(null)" << ",";
        else cout << i << ",";
        if (!v6.empty()) cout << "\b";
        cout << "]}" << endl;

        vector<string> v7{ 10, "hi" }; //10个“hi”
        cout << " \"v7\":{\"size\":\"" << v7.size() << "\",\"value\":[";
        for (auto i : v7)
            if (i.empty()) cout << "(null)" << ",";
            else cout << i << ",";
            if (!v7.empty()) cout << "\b";
            cout << "]}\n}" << endl;

            return 0;
}
