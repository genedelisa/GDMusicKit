
#include <functional>
#include <gdmusickit/gdmusickit.h>
#include <iomanip>
#include <iostream>
#include <memory>

int main() {
  using gdmusickit::Pitch;

  // old skool
  Pitch pOnStack{60};
  std::cout << "pstack:" << pOnStack << std::endl;

  Pitch *p{nullptr};
  p = new Pitch(60);
  std::cout << "p:" << p << std::endl;

  std::unique_ptr<Pitch> up = std::make_unique<Pitch>(60);
  std::cout << "up:" << up << std::endl;

  auto p2 = std::make_unique<Pitch>(60);
  std::cout << "p2:" << p2 << std::endl;

  auto p3{std::make_unique<Pitch>(60)};
  std::cout << "p3:" << p3 << std::endl;

  return EXIT_SUCCESS;
}

using funStr = std::function<void(std::string)>;

void AFunctionThatTakesLambdaFunctionAsArgument(
    std::function<void(std::string)> greetings) {

  std::string hello("hello world");
  greetings(hello);
}

void lambdaExample1() {
  std::string prefix = "Method1 Using std::function";
  std::function<void(std::string)> lambda =
      [prefix](std::string message) -> int {
    std::cout << prefix.c_str() << ": " << message.c_str() << "\n";
    return 0;
  };
  AFunctionThatTakesLambdaFunctionAsArgument(lambda);
}

void lambdaExample2() {
  // using
  typedef int (*MyLambda)(std::string);
  MyLambda lambda =
      [/*cannot capture variables!*/](std::string message) -> int {
    std::cout << std::string("Method2 Using typedef function ").c_str() << ": "
              << message.c_str() << "\n";
    return 0;
  };
  AFunctionThatTakesLambdaFunctionAsArgument(lambda);
}

void lambdaExample3() {
  struct MyClosure {
    std::string m_prefix;
    int operator()(std::string message) {
      std::cout << m_prefix.c_str() << ": " << message.c_str() << "\n";
      return 0;
    }
  };
  MyClosure lambda;
  lambda.m_prefix = "Method3 Using struct"; // capture data

  AFunctionThatTakesLambdaFunctionAsArgument(lambda);
}
