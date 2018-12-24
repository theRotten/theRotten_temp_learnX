#include "./main_include.hpp"


void mainTempX(void)
{
	using namespace std;
	cout << "gpk多字节" << endl;
	wcout << "w多字节编码" << endl;
}

void mainTemp(void)
{
	using namespace std;
	cout << "gpk多字节" << endl;
	wcout << "w多字节编码" << endl;
}

void mainTest(void)
{
	::aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture::test();

}

void mainTestX(void)
{
	//测试procedure_videoCapture模块videoCapture_main();
	//::aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture::videoCapture_main();

	//测试procedure_playAFile模块playAFile_main();
	//::aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_playAFile::playAFile_main();
}

void mainStopHere(void)
{
	std::cout << std::endl << "mainStopHere" << std::endl;
	std::system("pause");
}

void mainStopWith(void)
{
	std::cout << std::endl << "mainStopWith" << std::endl;
	system("pause");
}

void mainPauseWith(void)
{
	std::cout << std::endl << "mainPauseWith" << std::endl;
	system("pause");
}

void mainStopWait(void)
{
	std::cout << std::endl << "mainStopWait" << std::endl;
	system("pause");
}

void mainPauseWait(void)
{
	std::cout << std::endl << "mainPauseWait" << std::endl;
	system("pause");
}


int main()
{
	mainTemp();
	mainTest();
	mainTestX();
	
	mainStopWait();
	return 0;

}
