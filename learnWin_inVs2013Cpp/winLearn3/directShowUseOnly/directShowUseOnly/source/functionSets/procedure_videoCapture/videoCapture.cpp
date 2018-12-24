#include "./videoCapture_include.hpp"
//该成分在该架构成分内当前结构版本 v0.3.1.2
//该成分在该结构成分所属架构位置描述：该独立[“功能集set成分”]构件的（实际实质）内容。


//目的要提供的内容：
//参照：https://docs.microsoft.com/zh-cn/windows/desktop/directshow/selecting-a-capture-device
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::SelectingACaptureDevice(void)//这样没毛病
{
	
	
}

//HRESULT ::aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::test_errorExample_201812241032(REFGUID category, IEnumMoniker **ppEnum)//这样却有毛病？？//。。暂且。。这里又需要迁就c++标准或编译器
//{
//
//
//}

void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::test(void)
{


}

void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::testX(void)
{


}

//3.该CreateClassEnumerator方法返回一个指针IEnumMoniker接口。要枚举这些标记，请调用IEnumMoniker :: Next。
//以下代码为指定的设备类别创建枚举器。
HRESULT ____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum)//。。。。。。。。。。“难道。。混合命名空间？？？？。。。。WTF？？？？。。。。。。。。。。”
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
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::DisplayDeviceInformation(IEnumMoniker *pEnum)
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

//要为设备创建DirectShow捕获筛选器，请调用IMoniker :: BindToObject方法以获取IBaseFilter指针。然后调用IFilterGraph :: AddFilter将过滤器添加到过滤器图形中：
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::createADirectShowCaptureFilterForTheDevice(IMoniker *pMoniker, IGraphBuilder *m_pGraph)//添加摄像头的captureFilter
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
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::previewTheCapture(void)
{

}

//目前，该模块主函数功能：流程，像微软样例中给出的一套枚举摄像头和麦克风的流程
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::videoCapture_main(void)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (SUCCEEDED(hr))
	{
		IEnumMoniker *pEnum;

		hr = EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);//CLSID_VideoInputDeviceCategory是摄像头（视频输入设备）类的GUID
		if (SUCCEEDED(hr))
		{
			DisplayDeviceInformation(pEnum);
			pEnum->Release();
		}
		hr = EnumerateDevices(CLSID_AudioInputDeviceCategory, &pEnum);//CLSID_VideoInputDeviceCategory是麦克风（音频输入设备）类的GUID
		if (SUCCEEDED(hr))
		{
			DisplayDeviceInformation(pEnum);
			pEnum->Release();
		}
		CoUninitialize();
	}
}

