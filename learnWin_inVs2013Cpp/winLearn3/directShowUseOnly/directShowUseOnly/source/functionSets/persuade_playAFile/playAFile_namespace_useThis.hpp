
//本文件用法迁就版描述：在要用某个头命名空间的时候，在用的段落部分紧接着的空白行直接“#include [“这个头文件”]”
#include "./playAFile_namespace_include.hpp"
using namespace ::____aRottenGeneralNameThisX_thisNamespace_thisUse_randomMacro_201812202044_adoifbnpadnfbabisdufvbao;//这里假设不会重复出现这个宏定义，这个宏定义用固定前缀样式+时间+胡乱随便手动输入的一串字，实际上不一定不会重复出现；这个文件的主要作用是让用某个指定的命名空间范围更明白，而且即使命名空间修改了也不用换代码（因为这个文件名不变，用的是宏定义，宏定义由之前一层的头文件保证正确更新）。
