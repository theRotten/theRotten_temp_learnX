#include "cppLearn1_unTidied_main_include.h"

namespace theRotten_temp_learnX_cppLearn1_unTidied_main
{
	//此工程主函数专有命名空间

	void beforeMain(void)
	{
		cout << "abcd"<<endl;
	}
}

using namespace theRotten_temp_learnX_cppLearn1_unTidied_main;

int main()
{
	theRotten_temp_learnX_cppLearn1_unTidied_main::beforeMain();
	system("pause");
	return 0;
}