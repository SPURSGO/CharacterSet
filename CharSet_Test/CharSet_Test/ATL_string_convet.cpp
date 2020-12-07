
// 测试ATL 的字符串转换
// UTF-8 转换为 UTF-16， 再转换为 ANSI(GBK)

// 当前源文件编码格式：UTF-8

#include <iostream>
#include <fstream>
#include <string>
#include <atlstr.h>
#include <locale>

using namespace std;

//int main() {
//  string utf8_str = "这是中文";
//  cout << utf8_str << endl;
//  
//  wstring utf16_str(CA2T(utf8_str.c_str(), CP_UTF8));
//  wcout.imbue(locale("", LC_CTYPE));
//  wcout << utf16_str << endl;
//
//  string ansi_str(CT2A(utf16_str.c_str(), CP_ACP));
//  cout << ansi_str << endl;
//
//  //T2A
//}
