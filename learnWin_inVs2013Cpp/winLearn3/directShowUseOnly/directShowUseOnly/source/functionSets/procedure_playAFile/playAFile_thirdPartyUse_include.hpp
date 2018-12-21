#ifndef __playAFile_thirdPartyUse_include_hpp
#define __playAFile_thirdPartyUse_include_hpp

//#include "./thirdPartUse_include/directShow_use/playAFile_wantToUseDirectShow_playMovie.hpp"//这样写编辑器会报错？？。。全路径名过长？？
#include "./thirdPartyUse_include/directShow_use/plAF_wTUseDirectShow_pMo.hpp"//(这里，如果这个字符串再长1个字符，编译器就会报error C1081错了，而且这里是指字符串的长度，即./算2个字符 ../ 算3个字符 ../../ 算6个字符 / 算1个字符 不写相对位置头，算额外多加0个字符 )//卧槽？？。。这样写编辑器就暂时没出错。。？？。。什么情况。。写相对目录进行限制还特么的不对了么。。？？fuck。。扯吧。。给你指定好了位置，你特么报什么错 瞎啊。。？？。。这样还特么怎么构建大规模工程。。路径特别深特别长的那种。。擦的。。visual studio，你特么是故意的么？。。 真特么的有点坑啊。。。。fuck。。。。..........//“等你工程规模发展得足够大了，然后限制你？。。避免你与微软抗衡（从提供给你使用的工具上也对你作出限制）。。？？。。。。..........。。。。。。。。。。fuck。。。。。。。。。。..........”。。。。。。。。。。....................

#endif
