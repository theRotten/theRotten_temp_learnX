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
	
	//::theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn2::Test <int, double> t1(10, 5.4);
	//cout << t1.GetData1() << "   " << t1.GetData2() << endl;
	//::theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn2::Test <int, double> t2(t1);
	//cout << t2.GetData1() << "   " << t2.GetData2() << endl;
	//int һ�����Ե���������=123456;
	//һ������<int> ����ʵ��(һ�����Ե���������);
	
	theRotten_temp_learnX_cppLearn1_unTidied_main::beforeMain();
	system("pause");
	{
		//using namespace theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1;
		//templateLearn1_test();

		using namespace ::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1;
		theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1::operatorLearn1_test();//������Cpp��׼���Ҷ�����Bug�ͱ�����Bug����������д������Ĭ��Ϊȫ�ֿ�ʼ�ң�����Ĭ��Ϊ::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1�����ռ��ڿ�ʼ�ң�
		operatorLearn1_test();//������Cpp��׼���Ҷ�����Bug�ͱ�����Bug����������д������Ĭ��Ϊȫ�ֿ�ʼ�ң�����Ĭ��Ϊ::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1�����ռ��ڿ�ʼ�ң�
	}
	//templateLearn1_test();
	theRotten_temp_learnX_cppLearn1_unTidied_main::endOfMain();
	return 0;
}

