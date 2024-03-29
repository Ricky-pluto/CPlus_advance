#include <iostream>
#include <string>
#include <tuple>

//未限域enum问题
enum Color
{
    black = 5,
    white = 5,
    red
};

enum School : int;
class A
{
    private:
    School _enumSchool;
};

enum School : int
{
    teacher,
    student
};

//限域enum
enum class EnumInt:short
{
    e1 = 1,
    e2 = 2,
    e3
};
using UserInfo = std::tuple<std::string, std::string, std::size_t>;

enum class UserInfoFieldsScoped
{
    uiName,
    uiEmail,
    uiReputation
};

template <typename E>
constexpr std::underlying_type_t<E>
toUType(E enumrator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumrator);
}

int main()
{
    School a = student;
    int b = student;

    School e = static_cast<School>(10);

    EnumInt aa = EnumInt::e1;
    UserInfo uinfo{"hhh", "2736@gmail.com", 20};
    auto val1 = std::get<1>(uinfo);
    auto val2 = std::get<static_cast<int>(UserInfoFieldsScoped::uiName)>(uinfo);
    auto val3 = std::get<toUType(UserInfoFieldsScoped::uiName)>(uinfo);
    using enum UserInfoFieldsScoped;
    auto val4 = std::get<static_cast<int>(uiName)>(uinfo);



}

