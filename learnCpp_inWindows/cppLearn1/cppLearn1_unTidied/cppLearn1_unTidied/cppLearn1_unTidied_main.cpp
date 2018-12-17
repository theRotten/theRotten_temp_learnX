#include "cppLearn1_unTidied_main_include.h"

namespace theRotten_temp_learnX_cppLearn1_unTidied_main
{
	//此工程主函数专有命名空间

	void beforeMain(void)
	{using namespace theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1;
		cout << "start"<<endl;
	}
}

void whoAmI(void)
{
	cout << endl << "i'm from the cppLearn1_unTidied_main.cpp barely" << endl;
}

using namespace theRotten_temp_learnX_cppLearn1_unTidied_main;


namespace theRotten_temp_learnX_cppLearn1_unTidied_main
{
	//不连续的片段命名空间

	void endOfMain(void)
	{
		cout << "end" << endl;
	}

	void whoAmI(void)
	{
		cout << endl << "i'm from the namespace theRotten_temp_learnX_cppLearn1_unTidied_main" << endl;
	}
}

int main()
{
	
	theRotten_temp_learnX_cppLearn1_unTidied_main::beforeMain();
	system("pause");
	{
		using namespace theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1;
		templateLearn1_test();
	}
	//templateLearn1_test();
	theRotten_temp_learnX_cppLearn1_unTidied_main::endOfMain();
	return 0;
}

