#ifndef __operator_class_operatorLearn1_testClass_hpp
#define __operator_class_operatorLearn1_testClass_hpp
//Ω®¿‡
namespace theRotten_temp_learnX_cppLearn1_subCode_operator
{
	namespace operatorLearn1
	{
		class testClass
		{
		public:
			testClass(int);
			testClass(void);

			int testValue;

			void testA(void);
			void testB(void);


			bool operator==(testClass);
		};
	}
}


#endif
