
namespace theRotten_this
{
	namespace sub
	{
		namespace direct2D
		{
			namespace specificNeeds
			{
				namespace d2d1Needs
				{
					namespace SafeRelease
					{
						template <class T> void SafeRelease(T **ppT)
						{
							if (*ppT)
							{
								(*ppT)->Release();
								*ppT = NULL;
							}
						}

						template <class T> void SafeRelease(typename T *pT)
						{
							if (*pT)
							{
								(*pT)->Release();
								*pT = NULL;
							}
						}
					}
				}
			}
		}
	}
}
