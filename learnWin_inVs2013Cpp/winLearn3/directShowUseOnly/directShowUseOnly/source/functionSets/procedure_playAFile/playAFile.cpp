#include"./playAFile_include.hpp"

//本函数参照：https://docs.microsoft.com/zh-cn/windows/desktop/directshow/how-to-play-a-file
void ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812202044_adoifbnpadnfbabisdufvbao::playAFile_demo(void)
{
	//1.首先调用CoInitialize或CoInitializeEx来初始化COM库：
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		// Add error-handling code here. (Omitted for clarity.)
	}

	//2.接下来，调用CoCreateInstance以创建Filter Graph Manager：
	IGraphBuilder *pGraph;
	hr = CoCreateInstance(CLSID_FilterGraph, NULL,
		CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pGraph);

	//3.Filter Graph Manager公开了这两个接口。使用返回的IGraphBuilder指针来查询它们：
	IMediaControl *pControl;
	IMediaEvent   *pEvent;
	hr = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
	hr = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);

	//4.现在您可以构建过滤器图形了。对于文件回放，这是通过单个方法调用完成的：
	hr = pGraph->RenderFile(L"G:\\files\\using\\classified\\githubLocalDir\\theRotten\\theRotten_temp_learnX\\learnWin_inVs2013Cpp\\winLearn3\\directShowUseOnly\\directShowUseOnly\\test\\testFile\\functionSets_procedure_playAFile_test_testAviFile_input.avi", NULL);

	//5.如果指定的文件不存在，或者无法识别文件格式，则此方法可能会失败。但是，假设该方法成功，则现在可以使用过滤器图表进行回放。要运行图形，请调用IMediaControl :: Run方法：
	hr = pControl->Run();

	//6.当过滤器图形运行时，数据将在过滤器中移动，并呈现为视频和音频。播放发生在单独的线程上。您可以通过调用IMediaEvent :: WaitForCompletion方法等待播放完成：
	long evCode = 0;
	pEvent->WaitForCompletion(INFINITE, &evCode);

	//7.应用程序完成后，释放接口指针并关闭COM库：
	pControl->Release();
	pEvent->Release();
	pGraph->Release();
	CoUninitialize();
}
