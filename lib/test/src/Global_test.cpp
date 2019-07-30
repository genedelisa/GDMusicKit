#include "gtest/gtest.h"

#include <memory>

#include <gdmusickit/gdmusickit.h>
using namespace gdmusickit;
using namespace std;

class MyEnvironment: public ::testing::Environment {
  public:
    virtual ~MyEnvironment() {}

    // Override this to define how to set up the environment.
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

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

//Environment* AddGlobalTestEnvironment(Environment* env);

// but they recommend writing your own main
::testing::Environment* const fooEnv =
    ::testing::AddGlobalTestEnvironment(new MyEnvironment);