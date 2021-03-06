#include "tstring.h"
#include <iostream>

void testfunc(int n = 0);

int main(int argc, char* argv[]) {
    _tsetlocale(LC_ALL, _T(""));

    tstring tstr = to_tstring("こんにちは tstring");
    tcout << tstr << std::endl;
    tstr = to_tstring(L"wideでこんにちは tstring");
    tcout << tstr << std::endl;

    auto tstr2 = to_tstring("T文字列です");
    if (tstring_func::t2string(tstr2) == "T文字列です") {
        tcout << "t2string func succeeded!" << std::endl;
    }
    else {
        tcout << "t2string func failed!" << std::endl;
    }
    if (tstring_func::t2wstring(tstr2) == L"T文字列です") {
        tcout << "t2wstring func succeeded!" << std::endl;
    }
    else {
        tcout << "t2wstring func failed!" << std::endl;
    }

    testfunc();

    return 0;
}