#include "tstring.h"

void testfunc(int n) {
	tstring tstr = to_tstring("�ʖ|��P�ʂ���g�p�B");
    tcout << tstr << std::endl;
    tcout << _T("���͂��Ă��������F") << std::endl;
    tcin >> tstr;
    tcout << tstr << std::endl;
}