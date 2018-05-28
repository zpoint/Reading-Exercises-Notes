#include <string>
#include <iostream>
#include <codecvt>

int main()
{
		// create input stream reading UTF-8 sequences:
		std::wbuffer_convert<std::codecvt_utf8<wchar_t>> utf8inBuf(std::cin.rdbuf());
		std::wistream utf8in(&utf8inBuf);

		// create output stream writing UTF-16 sequences:
		std::wbuffer_convert<std::codecvt_utf16<wchar_t, 0xFFFF, std::generate_header>> utf16outBuf(std::cout.rdbuf());
		std::wostream utf16out(&utf16outBuf);

		// write each character read:
		wchar_t c;
		while (utf8in.get(c))
				utf16out.put(c);

		return 0;
}
