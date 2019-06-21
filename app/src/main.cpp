
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
