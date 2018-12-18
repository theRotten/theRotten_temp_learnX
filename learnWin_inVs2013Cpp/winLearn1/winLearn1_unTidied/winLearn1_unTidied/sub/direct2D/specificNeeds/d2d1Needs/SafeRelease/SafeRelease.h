#ifndef __SafeRelease_h
#define __SafeRelease_h

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
						template <class T> void SafeRelease(T **ppT);
						template <class T> void SafeRelease(T *pT);
					}
				}
			}
		}
	}
}

#endif
