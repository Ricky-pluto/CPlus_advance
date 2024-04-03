//对auto&&形参使用decltype以及std::forward他们
//auto f = [](auto x){return func(normalize(x));};

//使用forward对参数进行转发
// auto f = [](auto &&x) { return func(normalize(std::forward<decltype(x)>));};

