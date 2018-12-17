#include "./template_include.h"

namespace theRotten_temp_learnX_cppLearn1_subCode_template
{
	namespace templateLearn1
	{
		template <typename T>
		inline T const& Max(T const& a, T const& b)
		{
			return a < b ? b : a;
		}

		void whoAmI(void)
		{
			cout << endl << "i'm from the namespace theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1" << endl;
		}

	}

	namespace subTemp1
	{
		void whoAmI(void)
		{
			cout << endl << "i'm from the namespace theRotten_temp_learnX_cppLearn1_subCode_template::subTemp1" << endl;
		}
	}
		
}

//void whoAmI(void)
//{
//	cout << endl << "i'm from the template.cpp barely" << endl;
//}
//extern void whoAmI();

namespace theRotten_temp_learnX_cppLearn1_subCode_template
{
	namespace theRotten_temp_learnX_cppLearn1_subCode_template
	{
		namespace subTemp1
		{
			void whoAmI(void)
			{
				cout << endl << "i'm from the namespace theRotten_temp_learnX_cppLearn1_subCode_template::theRotten_temp_learnX_cppLearn1_subCode_template::subTemp1" << endl;
			}
		}
	}

	namespace templateLearn1
	{
		namespace subTemp1
		{
			void whoAmI(void)
			{
				cout << endl << "i'm from the namespace theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1::subTemp1" << endl;
			}
		}

		namespace theRotten_temp_learnX_cppLearn1_subCode_template
		{
			namespace subTemp1
			{
				void whoAmI(void)
				{
					cout << endl << "i'm from the namespace theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1::theRotten_temp_learnX_cppLearn1_subCode_template::subTemp1" << endl;
				}
			}
		}

		void templateLearn1_test()
		{
			cout << endl << "templateLearn1_test start" << endl;
			//cout<<theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1::Max(12, 14);//����д�����񲻱�׼�����棬��ΪIDE�����ھͻᱨ��
			cout << ::theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1::Max(12, 14);//������ȫָ���ƺ����ǱȽ������//��ͷ��ð�ţ�ȫ�������ռ��µ�ָ�������ռ�
			whoAmI();//����ͷ��ð�ţ���ǰ�����ռ��µ�ָ��[��Ŀ�ꡱ]����������Ϊ����ָʾ��˫����ָʾ��Ϊ��ʱ������
			//extern void whoAmI();
			//::whoAmI();//ע�⣺���Ҷ���������ɻ󲻽�ʱ����Cpp��׼ίԱ�����Ψһ�Ķ�����Ա��Cpp��׼�ƶ��ߵ������ʱ����˵�����һ��Cpp�Ĵ�bug���ҷ����ˣ��ش˼�¼ 2018��12��17��14:54:14 ��¼�ߣ�theRotten һ����ѧc++��Сë���ӣ����й�
			subTemp1::whoAmI();//���Ӷ�ͷð�ţ����ǵ�ǰ���������ռ��µ�ָ��[��Ŀ�ꡱ]����������Ϊ����ָʾ��˫����ָʾ��Ϊ��ʱ������
			theRotten_temp_learnX_cppLearn1_subCode_template::subTemp1::whoAmI();//���Ӷ�ͷð�ţ����ǵ�ǰ���������ռ��µ�ָ��[��Ŀ�ꡱ]����������Ϊ����ָʾ��˫����ָʾ��Ϊ��ʱ������
		}

	}

}
