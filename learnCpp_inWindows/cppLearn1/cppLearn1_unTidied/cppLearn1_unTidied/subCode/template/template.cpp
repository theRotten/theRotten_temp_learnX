#include "./template_include.h"

namespace theRotten_temp_learnX_cppLearn1_subCode_template
{
	namespace templateLearn2//�Լ�дһ��ģ�庯��
	{
		template <typename anyType2, typename anyType3> anyType2 templateFunction1(anyType2 a, typename anyType3 b)
		{
			cout << endl << "sizeOfA=" << sizeof(a) << endl;
			cout << endl << "ValueOfA=" << a << endl;
			cout << endl << "sizeOfB=" << sizeof(b) << endl;
			cout << endl << "ValueOfB=" << b << endl;
			return a;
		}

		//��һ����������
		template <typename ������>class һ������
		{
			������ һ�������͵����ݳ�Ա;
			һ������() :һ�������͵����ݳ�Ա(������ һ���������)
			{
				//this = һ���������;//��䲻�԰ɡ���������this��ָ����񡣡�
			}
		};

		//���岢ʹ��һ������
		void ���岢ʹ��һ������(void)
		{
			int һ�����Ե���������;
			//��δ��ɣ�����
		}

	}
	
	namespace templateLearn1//������������
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

		void templateLearn1_test()//��ģ��д�ĵ�һ��ģ�巺�ຯ���ĵ��� 2018��12��17��15:52:23
		{
			cout << endl << "templateLearn1_test start" << endl;
			::theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn2::templateFunction1("a",234);
			
		}

		void templateLearn1_test1()//���Բ�ͬ�����ռ�ĵ��ü������ռ��ڶ�ȫ�ֺ����ĵ��ã�����˵����������з����˱�������Cpp��׼��Bug 2018��12��17��15:51:45
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
