#include"./templateLearn_include.hpp"

namespace aRottenGeneralNameThisX_thisNamespace
{
	namespace sub
	{
		namespace templateLearn
		{
			namespace abc
			{
				template <class T1, class T2>
				Test<T1, T2>::Test() {}


				template <class T1, class T2>
				Test<T1, T2>::Test(T1 d1, T2 d2) :
					data1(d1), data2(d2) {}


				template <class T1, class T2> template <class U, class V>
				Test<T1, T2>::Test(const Test<U, V> &t) :
					data1(t.data1), data2(t.data2) {};
			
				void demo(void)
				{
				::aRottenGeneralNameThisX_thisNamespace::sub::templateLearn::abc::Test <int, double> t1(10, 5.4);
				::aRottenGeneralNameThisX_thisNamespace::sub::templateLearn::abc::Test <int, double> t2(t1);
				}
			
			}
		}
	}

}
