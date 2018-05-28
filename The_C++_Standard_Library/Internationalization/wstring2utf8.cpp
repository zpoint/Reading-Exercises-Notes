#include <locale>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include "wstring2string.hpp"
#include "wstring2utf8.hpp"

int main()
{
		try
		{
				// string with Chinese (in utf8 encoding):
				std::string s = "\xe4\xbd\xa0\xe5\xa5\xbd"; // 你好, in utf8

				// convert to wide-character string (using ISO Latin- 9 encoding)
				// std::wstring ws = to_wstring(s, std::locale("zh_CN"));
				
				// print string as UTF-8 sequence:
				// std::wcout << utf8_to_wstring(s) << std::endl; 
		}
		catch (const std::exception& e)
		{
				std::cerr << "Exception: " << e.what() << std::endl;
				return EXIT_FAILURE;
		}
		return 0;
}
