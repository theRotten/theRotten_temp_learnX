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
			
			void previewTheCapture(void);//Ԥ����Ƶ
			void createADirectShowCaptureFilterForTheDevice(IMoniker *pMoniker, IGraphBuilder *m_pGraph);//Ϊһ���豸����һ��Filter
			void SelectingACaptureDevice(void);//ѡ��һ�������豸����ʼ���Գ�����ͼ��
			HRESULT EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum);//���С�ö�١����������Ϊ�����������Ϊ��Ŀ���ǡ��豸��
			void DisplayDeviceInformation(IEnumMoniker *pEnum);//��ʾ�豸��Ϣ

			HRESULT test_errorExample_201812241032(REFGUID category, IEnumMoniker **ppEnum);

		}
		
	}
}

#endif
