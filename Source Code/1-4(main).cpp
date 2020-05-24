//미리 컴파일된 헤더 사용안함, sdl검사 끄기
#include <iostream>
#include "1-4(NameSp2).h"

using namespace std;

//소스, 헤더파일 분리

int main()
{
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	return 0;
}