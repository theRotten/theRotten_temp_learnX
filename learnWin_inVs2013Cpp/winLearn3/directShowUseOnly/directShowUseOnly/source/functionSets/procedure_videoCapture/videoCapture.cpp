#include "./videoCapture_include.hpp"
//�óɷ��ڸüܹ��ɷ��ڵ�ǰ�ṹ�汾 v0.3.1.2
//�óɷ��ڸýṹ�ɷ������ܹ�λ���������ö���[�����ܼ�set�ɷ֡�]�����ģ�ʵ��ʵ�ʣ����ݡ�

//���գ�https://docs.microsoft.com/zh-cn/windows/desktop/directshow/selecting-a-capture-device
void ::aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::SelectingACaptureDevice(void)//����ûë��
{
	
	
}

//HRESULT ::aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::test_errorExample_201812241032(REFGUID category, IEnumMoniker **ppEnum)//����ȴ��ë������//�������ҡ�����������ҪǨ��c++��׼�������
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

//3.��CreateClassEnumerator��������һ��ָ��IEnumMoniker�ӿڡ�Ҫö����Щ��ǣ������IEnumMoniker :: Next��
//���´���Ϊָ�����豸��𴴽�ö������
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
