#include ".\operator_class-operatorLearn1_testClass_include.hpp"

void ::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1::testClass::testA(void)
{
	;//doSomething
}

void ::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1::testClass::testB(void)
{
	;//doSomething
}

bool ::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1::testClass::operator==(testClass personA)
{
	if (this->testValue == personA.testValue)
		return true;
	else
		return false;
}

::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1::testClass::testClass(int inputValue)
{
	this->testValue = inputValue;
}

::theRotten_temp_learnX_cppLearn1_subCode_operator::operatorLearn1::testClass::testClass()
{
	this->testValue = 0;
}
