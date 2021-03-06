#include "./videoCapture_include.hpp"
//该成分在该架构成分内当前结构版本 v0.3.1.2
//该成分在该结构成分所属架构位置描述：该独立[“功能集set成分”]构件的（实际实质）内容的parts成分。

//3.该CreateClassEnumerator方法返回一个指针IEnumMoniker接口。要枚举这些标记，请调用IEnumMoniker :: Next。
//以下代码为指定的设备类别创建枚举器。
HRESULT ____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum)//枚举出指定类型的设备//。。。。。。。。。。“难道。。混合命名空间？？？？。。。。WTF？？？？。。。。。。。。。。”
{
	//1.系统设备枚举器
	//System Device Enumerator枚举系统上安装的过滤器和硬件设备。应用程序可以使用此组件来定位给定类别中的过滤器和设备。通过调用CoCreateInstance创建此对象
	// Create the System Device Enumerator.
	ICreateDevEnum *pDevEnum;
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
		CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pDevEnum));//实例化一个设备枚举器

	if (SUCCEEDED(hr))
	{
		// Create an enumerator for the category.
		hr = pDevEnum->CreateClassEnumerator(category, ppEnum, 0);//返回一个枚举绰号（传递给ppEnum），IEnumMoniker接口，在绰号表中列举绰号或绰号的组件
		if (hr == S_FALSE)
		{
			hr = VFW_E_NOT_FOUND;  // The category is empty. Treat as an error.
		}
		pDevEnum->Release();//释放枚举器
	}
	return hr;
}

//以下代码示例演示如何枚举设备标记列表并获取属性。
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::DisplayDeviceInformation(IEnumMoniker *pEnum)//显示设备信息
{
	IMoniker *pMoniker = NULL;

	while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
	{
		IPropertyBag *pPropBag;
		HRESULT hr = pMoniker->BindToStorage(0, 0, IID_PPV_ARGS(&pPropBag));
		if (FAILED(hr))
		{
			pMoniker->Release();
			continue;
		}

		VARIANT var;
		VariantInit(&var);

		// Get description or friendly name.
		hr = pPropBag->Read(L"Description", &var, 0);
		if (FAILED(hr))
		{
			hr = pPropBag->Read(L"FriendlyName", &var, 0);
		}
		if (SUCCEEDED(hr))
		{
			printf("%S\n", var.bstrVal);//打印出摄像头的名字
			VariantClear(&var);
		}

		hr = pPropBag->Write(L"FriendlyName", &var);

		// WaveInID applies only to audio capture devices.
		hr = pPropBag->Read(L"WaveInID", &var, 0);
		if (SUCCEEDED(hr))
		{
			printf("WaveIn ID: %d\n", var.lVal);
			VariantClear(&var);
		}

		hr = pPropBag->Read(L"DevicePath", &var, 0);
		if (SUCCEEDED(hr))
		{
			// The device path is not intended for display.
			printf("Device path: %S\n", var.bstrVal);
			VariantClear(&var);
		}

		pPropBag->Release();
		pMoniker->Release();
	}
}

//以下代码示例演示如何枚举设备标记列表并获取属性。
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::getCaptureMoniker(IMoniker *&pMoniker)//获取设备昵称
{
	
	//枚举设备 开始-------------------------------------2018年12月24日22:47:09
	IEnumMoniker *pEnum=NULL;
	EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);
	//枚举设备 结束-------------------------------------2018年12月24日22:47:09

	while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
	{
		IPropertyBag *pPropBag;
		HRESULT hr = pMoniker->BindToStorage(0, 0, IID_PPV_ARGS(&pPropBag));
		if (FAILED(hr))
		{
		//	pMoniker->Release();
			continue;
		}

		VARIANT var;
		VariantInit(&var);

		// Get description or friendly name.
		hr = pPropBag->Read(L"Description", &var, 0);
		if (FAILED(hr))
		{
			hr = pPropBag->Read(L"FriendlyName", &var, 0);
		}
		if (SUCCEEDED(hr))
		{
			printf("%S\n", var.bstrVal);//打印出摄像头的名字
			VariantClear(&var);
		}

		hr = pPropBag->Write(L"FriendlyName", &var);

		// WaveInID applies only to audio capture devices.
		hr = pPropBag->Read(L"WaveInID", &var, 0);
		if (SUCCEEDED(hr))
		{
			printf("WaveIn ID: %d\n", var.lVal);
			VariantClear(&var);
		}

		hr = pPropBag->Read(L"DevicePath", &var, 0);
		if (SUCCEEDED(hr))
		{
			// The device path is not intended for display.
			printf("Device path: %S\n", var.bstrVal);
			VariantClear(&var);
		}

		pPropBag->Release();
		//pMoniker->Release();
	}
}

//要为设备创建DirectShow捕获筛选器，请调用IMoniker :: BindToObject方法以获取IBaseFilter指针。然后调用IFilterGraph :: AddFilter将过滤器添加到过滤器图形中：
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::createADirectShowCaptureFilterForTheDevice(IMoniker *&pMoniker, IGraphBuilder * &m_pGraph)//添加摄像头的captureFilter
//参数表列：
//pMoniker:摄像头昵称
//m_pGraph:“过滤器Graph”
{
	IBaseFilter *pCap = NULL;

	HRESULT hr = pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pCap);
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddFilter(pCap, L"Capture Filter");
	}
}

//预览视频
//参照：https://docs.microsoft.com/zh-cn/windows/desktop/directshow/previewing-video
//要构建视频预览图，请按如下方式调用ICaptureGraphBuilder2 :: RenderStream方法：
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::previewTheCapture(IGraphBuilder **&ppGraph, IBaseFilter* &pCap)//在某个【ppGraph】上preview 【pCap】
{
	HRESULT hr;
	ICaptureGraphBuilder2 *pBuild; // Capture Graph Builder
	// Initialize pBuild (not shown).

	 // Video capture filter.

	/* Initialize pCap and add it to the filter graph (not shown). */

	InitCaptureGraphBuilder(ppGraph,  // Receives the pointer.
		&pBuild  // Receives the pointer.
		);
	
	hr = pBuild->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video,
		pCap, NULL, NULL);

}


//代码记录2018年12月25日09:29:41
//以下代码示例演示如何枚举设备标记列表并获取属性。
//void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::getCaptureMoniker(IMoniker *&pMoniker)//获取设备昵称
//{
//
//	//枚举设备 开始-------------------------------------2018年12月24日22:47:09
//	IEnumMoniker *pEnum = NULL;
//	EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);
//	//枚举设备 结束-------------------------------------2018年12月24日22:47:09
//
//	while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
//	{
//		IPropertyBag *pPropBag;
//		HRESULT hr = pMoniker->BindToStorage(0, 0, IID_PPV_ARGS(&pPropBag));
//		if (FAILED(hr))
//		{
//			pMoniker->Release();
//			continue;
//		}
//
//		VARIANT var;
//		VariantInit(&var);
//
//		// Get description or friendly name.
//		hr = pPropBag->Read(L"Description", &var, 0);
//		if (FAILED(hr))
//		{
//			hr = pPropBag->Read(L"FriendlyName", &var, 0);
//		}
//		if (SUCCEEDED(hr))
//		{
//			printf("%S\n", var.bstrVal);//打印出摄像头的名字
//			VariantClear(&var);
//		}
//
//		hr = pPropBag->Write(L"FriendlyName", &var);
//
//		// WaveInID applies only to audio capture devices.
//		hr = pPropBag->Read(L"WaveInID", &var, 0);
//		if (SUCCEEDED(hr))
//		{
//			printf("WaveIn ID: %d\n", var.lVal);
//			VariantClear(&var);
//		}
//
//		hr = pPropBag->Read(L"DevicePath", &var, 0);
//		if (SUCCEEDED(hr))
//		{
//			// The device path is not intended for display.
//			printf("Device path: %S\n", var.bstrVal);
//			VariantClear(&var);
//		}
//
//		pPropBag->Release();
//		pMoniker->Release();
//	}
//}
