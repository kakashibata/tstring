#pragma once
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef std::basic_string<TCHAR> tstring;

namespace {
#ifdef UNICODE
std::wistream &tcin = std::wcin;
std::wostream &tcout = std::wcout;
#else
std::istream &tcin = std::cin;
std::ostream &tcout = std::cout;
#endif
}
// 注意: 以下の関数を使う場合は、使う前にsetlocale関数を呼ぶ必要がある。

namespace tstring_func {

inline std::wstring wstringFromString(const std::string &str) {
	std::vector<wchar_t> wbuf(str.size() + 1);
	size_t len;
	errno_t e = ::mbstowcs_s(&len, &wbuf[0], wbuf.size(), str.c_str(), _TRUNCATE);

	return &wbuf[0];
}

inline std::string stringFromWstring(const std::wstring &wstr) {
	std::vector<char> buf(wstr.size() * 2 + 1);
	size_t len;
	errno_t e = ::wcstombs_s(&len, &buf[0], buf.size(), wstr.c_str(), _TRUNCATE);

	return &buf[0];
}

inline std::string t2string(const tstring &tstr) {
#ifdef UNICODE
	return tstring_func::stringFromWstring(tstr);
#else
	return tstr;
#endif
}

inline std::wstring t2wstring(const tstring &tstr) {
#ifdef UNICODE
	return tstr;
#else
	return tstring_func::wstringFromString(tstr);
#endif
}

}// namespace tstring_func

inline tstring to_tstring(const std::string &str) {
#ifdef UNICODE
	return tstring_func::wstringFromString(str);
#else
	return str;
#endif
}

inline tstring to_tstring(const std::wstring &wstr) {
#ifdef UNICODE
	return wstr;
#else
	return  tstring_func::stringFromWstring(wstr);
#endif
}
