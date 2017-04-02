#include "test/foo.hpp"

namespace pajadog {

using namespace settings;

Setting<int> Foo::i1("rootSetting1", 1);
Setting<int> Foo::i2("rootSetting2", 2);
Setting<int> Foo::i3("rootSetting3", 3);
Setting<std::string> Foo::s1("rootSetting4", "Default string");
Setting<float> Foo::f1("rootSetting5", 1.0101f);
Setting<double> Foo::d1("rootSetting6", 2.0202);

Setting<void> Foo::root("root");
Setting<int> Foo::rootInt1 = Setting<int>("i1", 1, &Foo::root);
Setting<int> Foo::rootInt2 = Setting<int>("i2", 1, &Foo::root);

}  // namespace pajadog