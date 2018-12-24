#include "./videoCapture_include.hpp"
//�óɷ��ڸüܹ��ɷ��ڵ�ǰ�ṹ�汾 v0.3.1.2
//�óɷ��ڸýṹ�ɷ������ܹ�λ���������ö���[�����ܼ�set�ɷ֡�]�����ģ�ʵ��ʵ�ʣ����ݵ�parts�ɷ֡�

//3.��CreateClassEnumerator��������һ��ָ��IEnumMoniker�ӿڡ�Ҫö����Щ��ǣ������IEnumMoniker :: Next��
//���´���Ϊָ�����豸��𴴽�ö������
HRESULT ____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum)//ö�ٳ�ָ�����͵��豸//�����������������������ѵ�������������ռ䣿��������������WTF������������������������������
{
	//1.ϵͳ�豸ö����
	//System Device Enumeratorö��ϵͳ�ϰ�װ�Ĺ�������Ӳ���豸��Ӧ�ó������ʹ�ô��������λ��������еĹ��������豸��ͨ������CoCreateInstance�����˶���
	// Create the System Device Enumerator.
	ICreateDevEnum *pDevEnum;
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
		CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pDevEnum));//ʵ����һ���豸ö����

	if (SUCCEEDED(hr))
	{
		// Create an enumerator for the category.
		hr = pDevEnum->CreateClassEnumerator(category, ppEnum, 0);//����һ��ö�ٴºţ����ݸ�ppEnum����IEnumMoniker�ӿڣ��ڴºű����оٴºŻ�ºŵ����
		if (hr == S_FALSE)
		{
			hr = VFW_E_NOT_FOUND;  // The category is empty. Treat as an error.
		}
		pDevEnum->Release();//�ͷ�ö����
	}
	return hr;
}

//���´���ʾ����ʾ���ö���豸����б�����ȡ���ԡ�
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::DisplayDeviceInformation(IEnumMoniker *pEnum)//��ʾ�豸��Ϣ
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
			printf("%S\n", var.bstrVal);//��ӡ������ͷ������
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

//ҪΪ�豸����DirectShow����ɸѡ���������IMoniker :: BindToObject�����Ի�ȡIBaseFilterָ�롣Ȼ�����IFilterGraph :: AddFilter�����������ӵ�������ͼ���У�
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::createADirectShowCaptureFilterForTheDevice(IMoniker *pMoniker, IGraphBuilder *m_pGraph)//��������ͷ��captureFilter
//�������У�
//pMoniker:����ͷ�ǳ�
//m_pGraph:��������Graph��
{
	IBaseFilter *pCap = NULL;

	HRESULT hr = pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pCap);
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddFilter(pCap, L"Capture Filter");
	}
}

//Ԥ����Ƶ
//���գ�https://docs.microsoft.com/zh-cn/windows/desktop/directshow/previewing-video
//Ҫ������ƵԤ��ͼ���밴���·�ʽ����ICaptureGraphBuilder2 :: RenderStream������
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::previewTheCapture(IGraphBuilder **&ppGraph, IBaseFilter* &pCap)//��ĳ����ppGraph����preview ��pCap��
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