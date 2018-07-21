#include "tstring.h"

void testfunc(int n) {
	tstring tstr = to_tstring("別翻訳単位から使用。");
    tcout << tstr << std::endl;
    tcout << _T("入力してください：") << std::endl;
    tcin >> tstr;
    tcout << tstr << std::endl;
}