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

void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::test(void)//类似试验尝试测试（这个，还不一定能达到结果，（。。尚未看到或确定结果的。。未知测试。。））
{
	//测试试验 目的：去实现一个让摄像头在屏幕上预览

	IMoniker *pMoniker;//用于接收摄像头设备的昵称
	IGraphBuilder **m_pGraph=NULL;//用于接收画布
	HRESULT hr;//用于接收返回结果

	//创建一个Graph 代码段 开始--------------------------------------------------------2018年12月24日21:49:42
	//2.接下来，调用CoCreateInstance以创建Filter Graph Manager：
	//IGraphBuilder *pGraph;
	hr = CoCreateInstance(CLSID_FilterGraph, NULL,
		CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)m_pGraph);//这条执行之后，出现了1个新线程：quartz.dll!ObjectThread
	//如图所示，类标识符（CLSID）是CLSID_FilterGraph。Filter Graph Manager由进程内DLL提供，因此执行上下文为CLSCTX_INPROC_SERVER。DirectShow支持自由线程模型，因此您也可以使用COINIT_MULTITHREADED标志调用CoInitializeEx。


	//创建一个Graph 代码段 结束--------------------------------------------------------2018年12月24日21:49:42


	getCaptureMoniker(pMoniker);
	createADirectShowCaptureFilterForTheDevice(pMoniker,*m_pGraph);//添加摄像头的captureFilter到graph
	//previewTheCapture(m_pGraph, IBaseFilter* &pCap);//在某个【ppGraph】上preview 【pCap】
	

	//EnumerateDevices(CLSID_VideoInputDeviceCategory, IEnumMoniker **ppEnum);//枚举出指定类型的设备
	//createADirectShowCaptureFilterForTheDevice(IMoniker *pMoniker, IGraphBuilder *m_pGraph);//添加摄像头的captureFilter到graph
	//previewTheCapture(IGraphBuilder **&ppGraph, IBaseFilter* &pCap);//在某个【ppGraph】上preview 【pCap】

}

void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen::testX(void)//测试某个作出的成分
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

