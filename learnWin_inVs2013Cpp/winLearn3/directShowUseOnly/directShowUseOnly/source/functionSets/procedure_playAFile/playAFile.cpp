#include"./playAFile_include.hpp"

//���������գ�https://docs.microsoft.com/zh-cn/windows/desktop/directshow/how-to-play-a-file
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812202044_adoifbnpadnfbabisdufvbao::playAFile_demo(void)
{
	//1.���ȵ���CoInitialize��CoInitializeEx����ʼ��COM�⣺
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		// Add error-handling code here. (Omitted for clarity.)
	}

	//2.������������CoCreateInstance�Դ���Filter Graph Manager��
	IGraphBuilder *pGraph;
	hr = CoCreateInstance(CLSID_FilterGraph, NULL,
		CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pGraph);

	//3.Filter Graph Manager�������������ӿڡ�ʹ�÷��ص�IGraphBuilderָ������ѯ���ǣ�
	IMediaControl *pControl;
	IMediaEvent   *pEvent;
	hr = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
	hr = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);

	//4.���������Թ���������ͼ���ˡ������ļ��طţ�����ͨ����������������ɵģ�
	hr = pGraph->RenderFile(L"G:\\files\\using\\classified\\githubLocalDir\\theRotten\\theRotten_temp_learnX\\learnWin_inVs2013Cpp\\winLearn3\\directShowUseOnly\\directShowUseOnly\\test\\testFile\\functionSets_procedure_playAFile_test_testAviFile_input.avi", NULL);

	//5.���ָ�����ļ������ڣ������޷�ʶ���ļ���ʽ����˷������ܻ�ʧ�ܡ����ǣ�����÷����ɹ��������ڿ���ʹ�ù�����ͼ����лطš�Ҫ����ͼ�Σ������IMediaControl :: Run������
	hr = pControl->Run();

	//6.��������ͼ������ʱ�����ݽ��ڹ��������ƶ���������Ϊ��Ƶ����Ƶ�����ŷ����ڵ������߳��ϡ�������ͨ������IMediaEvent :: WaitForCompletion�����ȴ�������ɣ�
	long evCode = 0;
	pEvent->WaitForCompletion(INFINITE, &evCode);

	//7.Ӧ�ó�����ɺ��ͷŽӿ�ָ�벢�ر�COM�⣺
	pControl->Release();
	pEvent->Release();
	pGraph->Release();
	CoUninitialize();
}
