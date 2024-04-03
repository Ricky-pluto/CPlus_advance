//返回不具名对象的优化
// Test gettest(){new Test(1)};
//int main() {Test result = getTest();}

// URVO:
// void GetTest2(Test &_test){ new(&_test) Test(2);}
// int main() {char buffer[4]; Test *ptr = reinterpret_cast<Test *>(buffer);GetTest2(*ptr)}
 

//返回具名对象的优化
// Test getTest() {Test a(1); return a;}

//不具名优化
// void GetTest()(Test &_test)
// {
    // Test a(1); new (&_test) Test(std::move(a));
// }

//具名优化
// void GetTest()(Test &_test)
// {
    // new (&_test) Test(1);
// }
 
 