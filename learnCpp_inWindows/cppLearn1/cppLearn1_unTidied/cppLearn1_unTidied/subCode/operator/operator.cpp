#include ".\operator_include.h"

namespace theRotten_temp_learnX_cppLearn1_subCode_operator
{
	namespace operatorLearn1
	{
		void operatorLearn1_test()
		{
			testClass t1 = testClass(1);
			testClass t2 = testClass(1);
			testClass t4 = testClass(2);
			{
				//using namespace std;
				cout<<endl<<"t1==t2?" << (t1 == t2) << endl;
				cout << endl<<"t1==t4?" << (t1 == t4) << endl;
			}
		}

		
		//void operator
	}
}
