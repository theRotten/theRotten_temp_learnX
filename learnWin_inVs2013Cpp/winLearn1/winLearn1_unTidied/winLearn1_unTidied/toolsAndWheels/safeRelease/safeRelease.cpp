--//ע�⣺�˴���ģ���������
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
