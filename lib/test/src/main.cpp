#include <gtest/gtest.h>

#include <gdmusickit/gdmusickit.h>


using gdmusickit::Pitch;
//using GDMusicKit;

TEST(GDMusicTest, create) {
	Pitch *p = new Pitch(60);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
