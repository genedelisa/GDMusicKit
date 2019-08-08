#include <gtest/gtest.h>

#include <gdmusickit/gdmusickit.h>

using namespace gdmusickit;

TEST(GDMusicTest, create) {
	auto p = new Pitch(60);
    EXPECT_EQ(60, p->midiPitchNumber());

    auto pitch = std::make_unique<Pitch>(72);
    EXPECT_EQ(72, pitch->midiPitchNumber());    
}


// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
