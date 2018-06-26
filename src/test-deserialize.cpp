#include "libs/catch.hpp"
#include "testhelpers.hpp"

#include <pajlada/settings.hpp>

using namespace pajlada::Settings;

TEST_CASE("Deserialize", "[settings]")
{
    SettingManager::clear();
    REQUIRE(LoadFile("deserialize-samples.json"));

    SECTION("int")
    {
        Setting<int> *a3, *a4;
        Setting<int> a1("/int");
        Setting<int> a2("/float");
        DD_THROWS(a3 = new Setting<int>("/string"));
        DD_THROWS(a4 = new Setting<int>("/bool"));

        REQUIRE(a1.getValue() == 5);
        REQUIRE(a2.getValue() == 5);
        REQUIRE_IF_NOEXCEPT(a3, 0);
        REQUIRE_IF_NOEXCEPT(a4, 0);
    }

    SECTION("float")
    {
        Setting<float> *a3, *a4;
        Setting<float> a1("/int");
        Setting<float> a2("/float");
        DD_THROWS(a3 = new Setting<float>("/string"));
        DD_THROWS(a4 = new Setting<float>("/bool"));

        REQUIRE(a1.getValue() == Approx(5.f));
        REQUIRE(a2.getValue() == Approx(5.3f));
        REQUIRE_IF_NOEXCEPT(a3, 0);
        REQUIRE_IF_NOEXCEPT(a4, 0);
    }

    SECTION("double")
    {
        Setting<double> *a3 = nullptr;
        Setting<double> *a4 = nullptr;
        Setting<double> a1("/int");
        Setting<double> a2("/float");
        DD_THROWS(a3 = new Setting<double>("/string"));
        DD_THROWS(a4 = new Setting<double>("/bool"));

        REQUIRE(a1.getValue() == Approx(5.));
        REQUIRE(a2.getValue() == Approx(5.3));
        REQUIRE_IF_NOEXCEPT(a3, 0);
        REQUIRE_IF_NOEXCEPT(a4, 0);
    }

    SECTION("bool")
    {
        Setting<bool> *a2, *a3, *a4;
        Setting<bool> a1("/int");
        DD_THROWS(a2 = new Setting<bool>("/float"));
        DD_THROWS(a3 = new Setting<bool>("/string"));
        a4 = new Setting<bool>("/bool");

        Setting<bool> a5("/int1");

        REQUIRE(a1.getValue() == false);
        REQUIRE_IF_NOEXCEPT(a2, false);
        REQUIRE_IF_NOEXCEPT(a3, false);
        REQUIRE(a4->getValue() == true);
        REQUIRE(a5.getValue() == true);
    }

    SECTION("string")
    {
        Setting<std::string> *a1, *a2, *a3, *a4;
        DD_THROWS(a1 = new Setting<std::string>("/int"));
        DD_THROWS(a2 = new Setting<std::string>("/float"));
        a3 = new Setting<std::string>("/string");
        DD_THROWS(a4 = new Setting<std::string>("/bool"));

        REQUIRE_IF_NOEXCEPT(a1, "");
        REQUIRE_IF_NOEXCEPT(a2, "");
        REQUIRE(a3->getValue() == "xd");
        REQUIRE_IF_NOEXCEPT(a4, "");
    }
}
