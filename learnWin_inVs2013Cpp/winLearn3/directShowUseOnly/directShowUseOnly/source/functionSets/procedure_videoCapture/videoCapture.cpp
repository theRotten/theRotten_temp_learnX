#include "./videoCapture_include.hpp"
//�óɷ��ڸüܹ��ɷ��ڵ�ǰ�ṹ�汾 v0.3.1.2
//�óɷ��ڸýṹ�ɷ������ܹ�λ���������ö���[�����ܼ�set�ɷ֡�]�����ģ�ʵ��ʵ�ʣ����ݡ�


//Ŀ��Ҫ�ṩ�����ݣ�
//���գ�https://docs.microsoft.com/zh-cn/windows/desktop/directshow/selecting-a-capture-device
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::SelectingACaptureDevice(void)//����ûë��
{
	
	
}

//HRESULT ::aRottenGeneralNameThisX_thisNamespace::functionSets::videoCapture::test_errorExample_201812241032(REFGUID category, IEnumMoniker **ppEnum)//����ȴ��ë������//�������ҡ�����������ҪǨ��c++��׼�������
//{
//
//
//}

void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::test(void)//�������鳢�Բ��ԣ����������һ���ܴﵽ�������������δ������ȷ������ġ���δ֪���ԡ�������
{
	//�������� Ŀ�ģ�ȥʵ��һ��������ͷ����Ļ��Ԥ��

	IMoniker *pMoniker;//���ڽ�������ͷ�豸���ǳ�
	IGraphBuilder *m_pGraph;//���ڽ��ջ���

	getCaptureMoniker(pMoniker);
	createADirectShowCaptureFilterForTheDevice(pMoniker,m_pGraph);//�������ͷ��captureFilter��graph

	//EnumerateDevices(CLSID_VideoInputDeviceCategory, IEnumMoniker **ppEnum);//ö�ٳ�ָ�����͵��豸
	//createADirectShowCaptureFilterForTheDevice(IMoniker *pMoniker, IGraphBuilder *m_pGraph);//�������ͷ��captureFilter��graph
	//previewTheCapture(IGraphBuilder **&ppGraph, IBaseFilter* &pCap);//��ĳ����ppGraph����preview ��pCap��

}

void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::testX(void)//����ĳ�������ĳɷ�
{


}


//Ŀǰ����ģ�����������ܣ����̣���΢�������и�����һ��ö������ͷ����˷������
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::videoCapture_main(void)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (SUCCEEDED(hr))
	{
		IEnumMoniker *pEnum;

		hr = EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);//CLSID_VideoInputDeviceCategory������ͷ����Ƶ�����豸�����GUID
		if (SUCCEEDED(hr))
		{
			DisplayDeviceInformation(pEnum);
			pEnum->Release();
		}
		hr = EnumerateDevices(CLSID_AudioInputDeviceCategory, &pEnum);//CLSID_VideoInputDeviceCategory����˷磨��Ƶ�����豸�����GUID
		if (SUCCEEDED(hr))
		{
			DisplayDeviceInformation(pEnum);
			pEnum->Release();
		}
		CoUninitialize();
	}
}

