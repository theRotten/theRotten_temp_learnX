#include "./videoCapture_include.hpp"
//该成分在该架构成分内当前结构版本 v0.3.1.2
//该成分在该结构成分所属架构位置描述：该独立[“功能集set成分”]构件的（实际实质）内容。

//参照：https://docs.microsoft.com/zh-cn/windows/desktop/directshow/selecting-a-capture-device
void ::aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::SelectingACaptureDevice(void)//这样没毛病
{
	
	
}

//HRESULT ::aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::test_errorExample_201812241032(REFGUID category, IEnumMoniker **ppEnum)//这样却有毛病？？//。。暂且。。这里又需要迁就c++标准或编译器
//{
//
//
//}

void aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::test(void)
{


}

void aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::testX(void)
{


}

//3.该CreateClassEnumerator方法返回一个指针IEnumMoniker接口。要枚举这些标记，请调用IEnumMoniker :: Next。
//以下代码为指定的设备类别创建枚举器。
HRESULT aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum)
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
