//使用Pimpl惯用法.
#include "Widget.h"

int main()
{
    {
        Widget w;
        Widget w2(std::move(w));
    }
    return 0;
}

