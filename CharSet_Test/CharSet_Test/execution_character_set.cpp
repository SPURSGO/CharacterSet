
// 测试预编译选项 execution_character_set
// 当前源文件编码格式： UTF-8 BOM

#include <iostream>
#include <string>

#if _MSC_VER >= 1600  /* 1600 is Microsoft Visual Studio 2010 */
#pragma execution_character_set("utf-8")
#endif


using namespace std;

//int main(int argc, char *argv[])
//{
//  string str = "这是中文";
//
//  cout << str << endl;
//
//  return 0;
//}