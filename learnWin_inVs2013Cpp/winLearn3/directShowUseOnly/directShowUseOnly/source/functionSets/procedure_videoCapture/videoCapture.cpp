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
	
	//����GraphBuilder��ָ�� GraphBuilder����_����ָ�� ��ʼ----------------------------------2018��12��25��14:10:05
	IGraphBuilder **m_pGraph=NULL;//���ڽ���FilterGraph
	//����GraphBuilder��ָ�� GraphBuilder����_����ָ�� ����----------------------------------2018��12��25��14:10:05

	//�����豸ö����ָ�� �豸ö������_����ָ�� ��ʼ----------------------------------2018��12��25��11:25 : 26
	IEnumMoniker *pEnum;//���ڽ���ö��
	//�����豸ö����ָ�� �豸ö������_����ָ�� ����----------------------------------2018��12��25��11:25 : 26

	IBaseFilter *pCap = NULL;

	HRESULT hr;//���ڽ��շ��ؽ��

	//COM�����ʼ������ ����� ��ʼ--------------------------------------------------------2018��12��25��09:52:11
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	//COM�����ʼ������ ����� ����--------------------------------------------------------2018��12��25��09:52:11

	//����GraphBuilder��ʵ�� GraphBuilder����_ʵ���� ��ʼ----------------------------------2018��12��25��14:12:03
	//����һ��Graph ����� ��ʼ--------------------------------------------------------2018��12��24��21:49:42
	//2.������������CoCreateInstance�Դ���Filter Graph Manager��
	//IGraphBuilder *pGraph;
	hr = CoCreateInstance(CLSID_FilterGraph, NULL,
		CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)m_pGraph);//����CLSID_FilterGraph�����ʵ�����Ǿۺ�COM�����߳������������ģ�ͨѶ�ӿڣ���IID_IGraphBuilder���У�����m_pGraph���մ���������ʵ��//����ִ��֮�󣬳�����1�����̣߳�quartz.dll!ObjectThread
	//��ͼ��ʾ�����ʶ����CLSID����CLSID_FilterGraph��Filter Graph Manager�ɽ�����DLL�ṩ�����ִ��������ΪCLSCTX_INPROC_SERVER��DirectShow֧�������߳�ģ�ͣ������Ҳ����ʹ��COINIT_MULTITHREADED��־����CoInitializeEx��
	//����һ��Graph ����� ����--------------------------------------------------------2018��12��24��21:49:42
	//����GraphBuilder��ʵ�� GraphBuilder����_ʵ���� ����----------------------------------2018��12��25��14:12:03

	//������ͷ�����豸����ö�� ������ڲ��� ��ʼ----------------------------------2018��12��25��09:59:56
	hr = EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);//CLSID_VideoInputDeviceCategory������ͷ����Ƶ�����豸�����GUID
	//������ͷ�����豸����ö�� ������ڲ��� ����----------------------------------2018��12��25��09:59:56

	//��ʾö�ٳ��豸����Ϣ ����� ��ʼ----------------------------------2018��12��25��14:04:54
	DisplayDeviceInformation(pEnum);
	//��ʾö�ٳ��豸����Ϣ ����� ����----------------------------------2018��12��25��14:04:54

	//�����ͷš��豸��ö�١� �豸ö������_�ͷ� ��ʼ----------------------------------2018��12��25��11:25:26
	pEnum->Release();
	//�����ͷš��豸��ö�١� �豸ö������_�ͷ� ����----------------------------------2018��12��25��11:25:26

	//COM���Un��ʼ������ ����� ��ʼ--------------------------------------------------------2018��12��25��09:52:11
	CoUninitialize();
	//COM���Un��ʼ������ ����� ����--------------------------------------------------------2018��12��25��09:52:11

	


	//getCaptureMoniker(pMoniker);
	//createADirectShowCaptureFilterForTheDevice(pMoniker,*m_pGraph);//�������ͷ��captureFilter��graph

	//previewTheCapture(m_pGraph, IBaseFilter* &pCap);//��ĳ����ppGraph����preview ��pCap��
	

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

