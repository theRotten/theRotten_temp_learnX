#ifndef __videoCapture_namespace_hpp
#define __videoCapture_namespace_hpp
//�óɷ��ڸüܹ��ɷ��ڵ�ǰ�ṹ�汾 v0.3.1.2
//�óɷ��ڸýṹ�ɷ������ܹ�λ���������ö���[�����ܼ�set�ɷ֡�]�����ģ�ʵ��ʵ�ʣ����ݵ������ռ䡣

#include "./videoCapture_namespace_include.hpp"

//��@ע�⣺�����ͷ�ļ������ռ������ṹ��ʱ��һ��Ҫ������һ�к궨���ֵ������궨�屾���ܺ������궨���ظ�������궨���ֵҪ��ʵ�������ռ�ƥ��
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

			void createADirectShowCaptureFilterForTheDevice(IMoniker *pMoniker);
			void SelectingACaptureDevice(void);
			HRESULT EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum);
			void DisplayDeviceInformation(IEnumMoniker *pEnum);

			HRESULT test_errorExample_201812241032(REFGUID category, IEnumMoniker **ppEnum);

		}
		
	}
}

#endif
