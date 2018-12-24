#ifndef __videoCapture_namespace_hpp
#define __videoCapture_namespace_hpp
//该成分在该架构成分内当前结构版本 v0.3.1.2
//该成分在该结构成分所属架构位置描述：该独立[“功能集set成分”]构件的（实际实质）内容的命名空间。

#include "./videoCapture_namespace_include.hpp"

//！@注意：改这个头文件命名空间声明结构的时候，一定要下面这一行宏定义的值，这个宏定义本身不能和其它宏定义重复，这个宏定义的值要和实际命名空间匹配
#define ____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812241356_faasdfanopaen aRottenGeneralNameThisX_thisNamespace::functionSets::procedure_videoCapture
namespace aRottenGeneralNameThisX_thisNamespace
{
	namespace functionSets
	{
		namespace procedure_videoCapture
		{
			
			void videoCapture_main(void);

			void test(void);
			void testX(void);
			
			void previewTheCapture(void);//预览视频
			void createADirectShowCaptureFilterForTheDevice(IMoniker *pMoniker, IGraphBuilder *m_pGraph);//为一个设备创建一个Filter
			void SelectingACaptureDevice(void);//选择一个捕获设备（初始尝试尝试试图）
			HRESULT EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum);//进行【枚举】这个动词行为，进行这个行为的目标是【设备】
			void DisplayDeviceInformation(IEnumMoniker *pEnum);//显示设备信息

			HRESULT test_errorExample_201812241032(REFGUID category, IEnumMoniker **ppEnum);

		}
		
	}
}

#endif
