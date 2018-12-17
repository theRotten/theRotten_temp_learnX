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
			//cout<<theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1::Max(12, 14);//这种写法好像不标准不正规，因为IDE在现在就会报错
			cout << ::theRotten_temp_learnX_cppLearn1_subCode_template::templateLearn1::Max(12, 14);//这样完全指定似乎才是比较正规的//顶头加冒号，全局命名空间下的指定命名空间
			whoAmI();//不顶头加冒号，当前命名空间下的指定[“目标”]（中括号作为概念指示，双引号指示其为临时描述）
			//extern void whoAmI();
			//::whoAmI();//注意：当我对这个问题疑惑不解时，向Cpp标准委员会国内唯一的顶级成员、Cpp标准制定者道神请教时，据说这里，有一个Cpp的大bug被我发现了，特此记录 2018年12月17日14:54:14 记录者：theRotten 一个初学c++的小毛孩子，在中国
			subTemp1::whoAmI();//不加顶头冒号，就是当前所在命名空间下的指定[“目标”]（中括号作为概念指示，双引号指示其为临时描述）
			theRotten_temp_learnX_cppLearn1_subCode_template::subTemp1::whoAmI();//不加顶头冒号，就是当前所在命名空间下的指定[“目标”]（中括号作为概念指示，双引号指示其为临时描述）
		}

	}

}
