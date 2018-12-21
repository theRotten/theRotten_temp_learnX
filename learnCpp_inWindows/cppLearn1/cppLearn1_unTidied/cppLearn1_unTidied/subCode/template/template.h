#ifndef __cppLearn1_subCode_template_h
#define __cppLearn1_subCode_template_h

namespace theRotten_temp_learnX_cppLearn1_subCode_template
{
	namespace templateLearn1
	{
		template <typename T>
		inline T const& Max(T const& a, T const& b);

		void templateLearn1_test();
	}

	namespace templateLearn2
	{
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
//using namespace theRotten_temp_learnX_cppLearn1_subCode_template;

#endif



