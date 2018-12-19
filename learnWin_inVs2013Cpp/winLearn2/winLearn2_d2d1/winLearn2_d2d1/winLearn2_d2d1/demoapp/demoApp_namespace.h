#ifndef __demoApp_namespace_h
#define __demoApp_namespace_h

#include "./demoApp_namespace_referanceUse.h"

namespace DemoApp
{
	HRESULT LoadBitmapFromFile(
		ID2D1RenderTarget *pRenderTarget,
		IWICImagingFactory *pIWICFactory,
		PCWSTR uri,
		UINT destinationWidth,
		UINT destinationHeight,
		ID2D1Bitmap **ppBitmap
		);
}

#endif
