--//注意：此代码模块存在问题
namespace theRotten
{
	namespace toolsAndWheel
	{
		namespace safeRelease
		{
			template <class T> void safeRelease(T **ppT)
			{
				if (*ppT)
				{
					(*ppT)->Release();
					*ppT = NULL;
				}
			}
		}
	}
}
