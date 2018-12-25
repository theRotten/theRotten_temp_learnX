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
	
	//创建GraphBuilder类指针 GraphBuilder周期_创建指针 开始----------------------------------2018年12月25日14:10:05
	IGraphBuilder **m_pGraph=NULL;//用于接收FilterGraph
	//创建GraphBuilder类指针 GraphBuilder周期_创建指针 结束----------------------------------2018年12月25日14:10:05

	//创建设备枚举类指针 设备枚举周期_创建指针 开始----------------------------------2018年12月25日11:25 : 26
	IEnumMoniker *pEnum;//用于接收枚举
	//创建设备枚举类指针 设备枚举周期_创建指针 结束----------------------------------2018年12月25日11:25 : 26

	IBaseFilter *pCap = NULL;

	HRESULT hr;//用于接收返回结果

	//COM组件初始化流程 代码段 开始--------------------------------------------------------2018年12月25日09:52:11
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	//COM组件初始化流程 代码段 结束--------------------------------------------------------2018年12月25日09:52:11

	//创建GraphBuilder类实例 GraphBuilder周期_实例化 开始----------------------------------2018年12月25日14:12:03
	//创建一个Graph 代码段 开始--------------------------------------------------------2018年12月24日21:49:42
	//2.接下来，调用CoCreateInstance以创建Filter Graph Manager：
	//IGraphBuilder *pGraph;
	hr = CoCreateInstance(CLSID_FilterGraph, NULL,
		CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)m_pGraph);//创建CLSID_FilterGraph种类的实例，非聚合COM对象，线程内运行上下文，通讯接口（和IID_IGraphBuilder进行），用m_pGraph接收创建出来的实例//这条执行之后，出现了1个新线程：quartz.dll!ObjectThread
	//如图所示，类标识符（CLSID）是CLSID_FilterGraph。Filter Graph Manager由进程内DLL提供，因此执行上下文为CLSCTX_INPROC_SERVER。DirectShow支持自由线程模型，因此您也可以使用COINIT_MULTITHREADED标志调用CoInitializeEx。
	//创建一个Graph 代码段 结束--------------------------------------------------------2018年12月24日21:49:42
	//创建GraphBuilder类实例 GraphBuilder周期_实例化 结束----------------------------------2018年12月25日14:12:03

	//对摄像头类型设备进行枚举 代码段内部段 开始----------------------------------2018年12月25日09:59:56
	hr = EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);//CLSID_VideoInputDeviceCategory是摄像头（视频输入设备）类的GUID
	//对摄像头类型设备进行枚举 代码段内部段 结束----------------------------------2018年12月25日09:59:56

	//显示枚举出设备的信息 代码段 开始----------------------------------2018年12月25日14:04:54
	DisplayDeviceInformation(pEnum);
	//显示枚举出设备的信息 代码段 结束----------------------------------2018年12月25日14:04:54

	//用于释放‘设备的枚举’ 设备枚举周期_释放 开始----------------------------------2018年12月25日11:25:26
	pEnum->Release();
	//用于释放‘设备的枚举’ 设备枚举周期_释放 结束----------------------------------2018年12月25日11:25:26

	//COM组件Un初始化流程 代码段 开始--------------------------------------------------------2018年12月25日09:52:11
	CoUninitialize();
	//COM组件Un初始化流程 代码段 结束--------------------------------------------------------2018年12月25日09:52:11

	


	//getCaptureMoniker(pMoniker);
	//createADirectShowCaptureFilterForTheDevice(pMoniker,*m_pGraph);//添加摄像头的captureFilter到graph

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

