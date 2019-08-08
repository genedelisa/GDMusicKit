#include <memory>

#include "gtest/gtest.h"

#include <gdmusickit/gdmusickit.h>

using namespace gdmusickit;
using namespace std;

/**
 * @brief Global settings for all tests
 * @detail Currently sets the Logging severity
 * 
 */
class MyEnvironment: public ::testing::Environment {
  public:
    virtual ~MyEnvironment() = default;

    // NOLINTNEXTLINE(readability-identifier-naming)
    void SetUp() override {
        cout << "global test setup" << endl;
        cout << "logging severity is debug" << endl;

        boost::log::core::get()->set_filter(
            [](const boost::log::attribute_value_set& attr_set) {
                return attr_set["Severity"]
                           .extract<boost::log::trivial::severity_level>() <=
                       boost::log::trivial::debug;
            });
    }

    // NOLINTNEXTLINE(readability-identifier-naming)
    void TearDown() override {}
};

// Environment* AddGlobalTestEnvironment(Environment* env);

// The authors prefer that you write your own main instead.
::testing::Environment* const fooEnv =
    ::testing::AddGlobalTestEnvironment(new MyEnvironment);