#include <iostream>
#include <string>
#include <vector>

//满足函数重载的四个条件：
//a、基类函数必须是virtual;
//b、函数名；形参类型一致；
//c、返回值和异常类型与派生类型必须兼容
//d、引用限定符必须一致
//override是为了确认上述四点，不是必须的
//final可以防止派生类重写

//引用限定符：
//1\DataType &data() & 
//2\DataType data() &&

//auto val1 = w.data();调用1
//auto val2 = makeWidget().data();调用2