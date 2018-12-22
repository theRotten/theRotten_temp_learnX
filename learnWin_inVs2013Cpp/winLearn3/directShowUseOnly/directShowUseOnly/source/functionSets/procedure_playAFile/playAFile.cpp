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
		CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pGraph);//这条执行之后，出现了1个新线程：quartz.dll!ObjectThread
	//如图所示，类标识符（CLSID）是CLSID_FilterGraph。Filter Graph Manager由进程内DLL提供，因此执行上下文为CLSCTX_INPROC_SERVER。DirectShow支持自由线程模型，因此您也可以使用COINIT_MULTITHREADED标志调用CoInitializeEx。

	//3.Filter Graph Manager公开了这两个接口。使用返回的IGraphBuilder指针来查询它们：
	IMediaControl *pControl;//这个pControl用于控制开始播放。（可能还有其他控制）
	IMediaEvent   *pEvent;//这个pEvent用于看是不是播放完了。或者产生了什么事件，可以用于阻塞。
	hr = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
	hr = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);

	//4.现在您可以构建过滤器图形了。对于文件回放，这是通过单个方法调用完成的：
	hr = pGraph->RenderFile(L"G:\\files\\using\\classified\\githubLocalDir\\theRotten\\theRotten_temp_learnX\\learnWin_inVs2013Cpp\\winLearn3\\directShowUseOnly\\directShowUseOnly\\test\\testFile\\functionSets_procedure_playAFile_test_testBigAviFileWithAudio_input.avi", NULL);//这条执行完之后，出现了2个新线程：ntdll.dll!_TppWaiterpThread@4	quartz.dll!CAMThread::InitialThreadProc()	//发现本procedure流程中，智能播放avi（视频和音频都能播放），不能播放wmv
	//该IGraphBuilder :: RenderFile模块方法构建了一个筛选器图形，可以播放指定的文件。第一个参数是文件名，表示为宽字符（2字节）字符串。第二个参数是保留的，必须等于NULL。

	//5.如果指定的文件不存在，或者无法识别文件格式，则此方法可能会失败。但是，假设该方法成功，则现在可以使用过滤器图表进行回放。要运行图形，请调用IMediaControl :: Run方法：
	hr = pControl->Run();//这条启动执行后，新窗口开始播放，并多了6个进程，其中3个是ntdll.dll!_TppWorkerThread@4，1个是quartz.dll!CBaseReferenceClock::AdviseThreadFunction()，1个是quartz.dll!CAMThread::InitialThreadProc() ， 1个是 quartz.dll!CAsyncFile::InitialThreadProc()

	//6.当过滤器图形运行时，数据将在过滤器中移动，并呈现为视频和音频。播放发生在单独的线程上。您可以通过调用IMediaEvent :: WaitForCompletion方法等待播放完成：
	long evCode = 0;
	pEvent->WaitForCompletion(INFINITE, &evCode);
	//此方法将一直阻止，直到文件完成播放，或者直到指定的超时间隔结束。值INFINITE表示应用程序无限期阻塞，直到文件完成播放。有关事件处理的更实际示例，请参阅响应事件。

	//7.应用程序完成后，释放接口指针并关闭COM库：
	pControl->Release();
	pEvent->Release();
	pGraph->Release();
	CoUninitialize();
}
