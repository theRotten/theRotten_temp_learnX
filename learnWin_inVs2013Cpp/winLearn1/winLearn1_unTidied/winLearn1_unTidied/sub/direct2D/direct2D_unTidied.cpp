#include "./direct2D_unTidied_include.h"

namespace direct2D
{
	namespace testlist
	{
		namespace operationTest
		{

		}

		namespace test
		{
			

			namespace test1_test1
			{
				//��2��������ID2D1Factory	2018��12��18��10:01:32------from:https://docs.microsoft.com/zh-cn/windows/desktop/Direct2D/getting-started-with-direct2d
				/*void createID2D1Factory(void)
				{
					ID2D1Factory* pD2DFactory = NULL;
					HRESULT hr = D2D1CreateFactory(
						D2D1_FACTORY_TYPE_SINGLE_THREADED,
						&pD2DFactory
						);
				}*/

				void createID2D1Factory(ID2D1Factory* pD2DFactory )
				{
					
					HRESULT hr = D2D1CreateFactory(
						D2D1_FACTORY_TYPE_SINGLE_THREADED,
						&pD2DFactory
						);
				}

				//��3��������ID2D1HwndRenderTarget	2018��12��18��10:01:32------from:https://docs.microsoft.com/zh-cn/windows/desktop/Direct2D/getting-started-with-direct2d
				//void createID2D1HwndRenderTarget(HWND hwnd, ID2D1Factory*pD2DFactory)
				//{
				//	// Obtain the size of the drawing area.
				//	RECT rc;
				//	GetClientRect(hwnd, &rc);

				//	// Create a Direct2D render target          
				//	ID2D1HwndRenderTarget* pRT = NULL;
				//	HRESULT hr = pD2DFactory->CreateHwndRenderTarget(
				//		D2D1::RenderTargetProperties(),
				//		D2D1::HwndRenderTargetProperties(
				//		hwnd,
				//		D2D1::SizeU(
				//		rc.right - rc.left,
				//		rc.bottom - rc.top)
				//		),
				//		&pRT
				//		);
				//}

				//void createID2D1HwndRenderTarget(HWND hwnd, ID2D1Factory*pD2DFactory, HRESULT& hr, ID2D1HwndRenderTarget* pRT = NULL)
				//{
				//	// Obtain the size of the drawing area.
				//	RECT rc;
				//	GetClientRect(hwnd, &rc);

				//	// Create a Direct2D render target          
				//	//ID2D1HwndRenderTarget* pRT = NULL;
				//	hr = pD2DFactory->CreateHwndRenderTarget(
				//		D2D1::RenderTargetProperties(),
				//		D2D1::HwndRenderTargetProperties(
				//		hwnd,
				//		D2D1::SizeU(
				//		rc.right - rc.left,
				//		rc.bottom - rc.top)
				//		),
				//		&pRT
				//		);
				//}

				//��4������������	2018��12��18��10:01:32------from:https://docs.microsoft.com/zh-cn/windows/desktop/Direct2D/getting-started-with-direct2d
				/*
				void createbrush(hresult hr, id2d1hwndrendertarget* prt)
				{
					id2d1solidcolorbrush* pblackbrush = null;
					if (succeeded(hr))
					{

						prt->createsolidcolorbrush(
							d2d1::colorf(d2d1::colorf::black),
							&pblackbrush
							);
					}
				}
				*/

				//void createBrush(HRESULT &hr, ID2D1HwndRenderTarget* pRT)
				//{
				//	ID2D1SolidColorBrush* pBlackBrush = NULL;
				//	if (SUCCEEDED(hr))
				//	{

				//		pRT->CreateSolidColorBrush(
				//			D2D1::ColorF(D2D1::ColorF::Black),
				//			&pBlackBrush
				//			);
				//	}
				//}

				////��5�������ƾ���	2018��12��18��10:01:32------from:https://docs.microsoft.com/zh-cn/windows/desktop/Direct2D/getting-started-with-direct2d
				//void drawTheRectangle(ID2D1HwndRenderTarget* pRT, ID2D1SolidColorBrush*pBlackBrush, RECT rc)
				//{
				//	pRT->BeginDraw();

				//	pRT->DrawRectangle(
				//		D2D1::RectF(
				//		rc.left + 100.0f,
				//		rc.top + 100.0f,
				//		rc.right - 100.0f,
				//		rc.bottom - 100.0f),
				//		pBlackBrush);

				//	HRESULT hr = pRT->EndDraw();
				//}

				//��6�����ͷ���Դ
				//void releaseResources(ID2D1HwndRenderTarget* pRT, ID2D1SolidColorBrush*pBlackBrush, ID2D1Factory* pD2DFactory)
				//{
				//	using namespace ::theRotten_this::sub::direct2D::specificNeeds::d2d1Needs::SafeRelease;
				//	//pRT->Release();
				//	SafeRelease(pRT);
				//	SafeRelease(pBlackBrush);

				//	SafeRelease(pD2DFactory);
				//}
			}
		}

		namespace unTidied
		{
			void direct2Dtest(void)
			{

			}


			void direct2Dtest(HWND hwnd)
			{
				using namespace direct2D::testlist::test::test1_test1;

				//�ڶ���
				ID2D1Factory* pD2DFactory = NULL;
				direct2D::testlist::test::test1_test1::createID2D1Factory(pD2DFactory);
				//createID2D1Factory(pD2DFactory);

				//������
				//HRESULT hr; ID2D1HwndRenderTarget* pRT=NULL;
				////direct2D::testlist::test::test1_test1::createID2D1HwndRenderTarget(hwnd, pD2DFactory, hr, pRT);
				//createID2D1HwndRenderTarget(hwnd, pD2DFactory, hr, pRT);
				
				//{
				//	//void createBrush(HRESULT hr, ID2D1HwndRenderTarget* pRT);//typeA
				//	//void ::direct2D::testlist::test::test1_test1::createBrush(HRESULT &hr, ID2D1HwndRenderTarget* pRT);//typeB
				//	
				//	// ������������ ���������ֶ�ָ������typeB��������
				//	createBrush(hr, pRT);
				//}

			}

			
		}
	}
}
