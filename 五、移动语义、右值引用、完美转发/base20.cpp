//extern:声明变量和函数
//int value -- 定义，局部的话可能初始化为随机数字
//extern int  value --纯声明

//static int add (int a) --只能在在当前文件中存在
// a、修饰普通函数
// b、修饰全局变量
// c、局部变量延长生命周期
// d、修饰类成员函数，类名和类对象都可以访问
// e、类成员属性，类内只能声明，类外定义
// f、const static+类成员属性，可以类内声明并赋值。