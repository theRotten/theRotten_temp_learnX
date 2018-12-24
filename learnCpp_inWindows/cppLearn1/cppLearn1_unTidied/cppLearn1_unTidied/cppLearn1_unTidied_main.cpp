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
	
	//::theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn2::Test <int, double> t1(10, 5.4);
	//cout << t1.GetData1() << "   " << t1.GetData2() << endl;
	//::theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn2::Test <int, double> t2(t1);
	//cout << t2.GetData1() << "   " << t2.GetData2() << endl;
	//int 一个测试的整形数据=123456;
	//一个泛类<int> 泛类实例(一个测试的整形数据);
	
	theRotten_temp_learnX_cppLearn1_unTidied_main::beforeMain();
	system("pause");
	{
		//using namespace theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1;
		//templateLearn1_test();

		using namespace ::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1;
		theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1::operatorLearn1_test();//这又有Cpp标准混乱多意性Bug和编译器Bug，这里这样写，是在默认为全局开始找，还是默认为::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1命名空间内开始找？
		operatorLearn1_test();//这又有Cpp标准混乱多意性Bug和编译器Bug，这里这样写，是在默认为全局开始找，还是默认为::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1命名空间内开始找？
	}
	//templateLearn1_test();
	theRotten_temp_learnX_cppLearn1_unTidied_main::endOfMain();
	return 0;
}

