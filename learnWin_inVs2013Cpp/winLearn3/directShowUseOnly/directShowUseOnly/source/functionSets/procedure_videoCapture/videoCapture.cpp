#include "./videoCapture_include.hpp"
//该成分在该架构成分内当前结构版本 v0.3.1.2
//该成分在该结构成分所属架构位置描述：该独立[“功能集set成分”]构件的（实际实质）内容。

//参照：https://docs.microsoft.com/zh-cn/windows/desktop/directshow/selecting-a-capture-device
void ::aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture::SelectingACaptureDevice(void)//这样没毛病
{
	
	
}

//HRESULT ::aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::test_errorExample_201812241032(REFGUID category, IEnumMoniker **ppEnum)//这样却有毛病？？//。。暂且。。这里又需要迁就c++标准或编译器
//{
//
//
//}

void ::aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture::test(void)
{


}

void ::aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture::testX(void)
{


}

//3.该CreateClassEnumerator方法返回一个指针IEnumMoniker接口。要枚举这些标记，请调用IEnumMoniker :: Next。
//以下代码为指定的设备类别创建枚举器。
HRESULT aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture::EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum)//。。。。。。。。。。“难道。。混合命名空间？？？？。。。。WTF？？？？。。。。。。。。。。”
{
	// Create the System Device Enumerator.
	ICreateDevEnum *pDevEnum;
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
		CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pDevEnum));

	if (SUCCEEDED(hr))
	{
		// Create an enumerator for the category.
		hr = pDevEnum->CreateClassEnumerator(category, ppEnum, 0);
		if (hr == S_FALSE)
		{
			hr = VFW_E_NOT_FOUND;  // The category is empty. Treat as an error.
		}
		pDevEnum->Release();
	}
	return hr;
}

//以下代码示例演示如何枚举设备标记列表并获取属性。
void ::aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture::DisplayDeviceInformation(IEnumMoniker *pEnum)
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
			printf("%S\n", var.bstrVal);
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

void ::aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture::videoCapture_main(void)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (SUCCEEDED(hr))
	{
		IEnumMoniker *pEnum;

		hr = EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);
		if (SUCCEEDED(hr))
		{
			DisplayDeviceInformation(pEnum);
			pEnum->Release();
		}
		hr = EnumerateDevices(CLSID_AudioInputDeviceCategory, &pEnum);
		if (SUCCEEDED(hr))
		{
			DisplayDeviceInformation(pEnum);
			pEnum->Release();
		}
		CoUninitialize();
	}
}
