#ifndef __templateLearn_namespace_include_hpp
#define __templateLearn_namespace_include_hpp

//注意：改这个头文件命名空间声明结构的时候，一定要下面这一行宏定义的值，这个宏定义本身不能和其它宏定义重复，这个宏定义的值要和实际命名空间匹配
#define ____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812220304_nseuianfbiaonboanbonbweanbn aRottenGeneralNameThisX_thisNamespace::sub::templateLearn
namespace aRottenGeneralNameThisX_thisNamespace
{
	namespace sub
	{
		namespace templateLearn
		{
			class demoClass
			{

			};

			template <class T1, class T2>
			class Test
			{
			public:
				Test();
				Test(T1 d1, T2 d2);
				template <class U, class V> Test(const Test<U, V> &t);
				void SetData1(T1 val)
				{
					data1 = val;
				}
				void SetData2(T2 val)
				{
					data2 = val;
				}
				T1 GetData1()
				{
					return data1;
				}
				T2 GetData2()
				{
					return data2;
				}
			private:
				T1 data1;
				T2 data2;
			};

		}
	}
}

#endif
