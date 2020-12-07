
// 当前源文件编码格式：UTF-8

// 测试Unicode与ANSI字符串的相互转换: 这是windows 系统API
// MultiByteToWideChar与WideCharToMultiByte
// 当前编码格式： UTF-8(执行字符集也是UTF-8，而运行环境是GBK，所以产生乱码。)

// 此测试程序：将UTF-8 转换为 UTF-16， 再转换为GBK，就可以实现正常输出

#include <iostream>
#include <string>
#include <atlstr.h>
#include <cassert>

using namespace std;


int main()
{
  string str = "这是中文";  // UTF-8
  cout << str << endl;

  // ANSI(UTF-8) 转 UNICODE(UTF-16)
  // 第一个参数指定源字符串是什么编码格式
  // 第四个参数为-1，让该函数自动判断源字符串的长度, 第六个参数为0， 返回 转换后的宽字符串 应有的[字符数]
  int ws_len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
  assert(ws_len > 0);
  wchar_t *ws_buf = new wchar_t[ws_len];  // 分配缓冲区内存

  int ws_ret = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, ws_buf, ws_len);
  assert(ws_len > 0);
  wcout.imbue(locale("", LC_CTYPE));
  wstring wstr(ws_buf);  // UTF-16
  wcout << wstr << endl;


  int as_len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
  assert(as_len > 0);
  char *as_buf = new char[as_len]; // 分配缓冲区内存

  int as_ret = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, as_buf, as_len, NULL, NULL);
  string astr(as_buf);
  cout << astr << endl;

  cout << endl;
  return 0;
}
