#include "cppLearn1_unTidied_main_include.h"

namespace theRotten_temp_learnX_cppLearn1_unTidied_main
{
	//�˹���������ר�������ռ�

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
	//��������Ƭ�������ռ�

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

