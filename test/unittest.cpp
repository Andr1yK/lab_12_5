#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../src/extends/Elem.cpp"
#include "../src/extends/process.cpp"
#include "../src/extends/BracketsInfo.cpp"

TEST(Brackets, BracketsT) {
  string test = "(logo(img) (res) test) (text())";

  BracketsInfo tmp = process(test, 0);

  EXPECT_EQ(tmp.text, "logo(img) (res) test");
  EXPECT_EQ(tmp.startPos, 0);
  EXPECT_EQ(tmp.endPos, 21);
}

TEST(Brackets, BracketsT2) {
  string test = "(logo(img) (res) test) (text())";

  BracketsInfo tmp = process(test, 5);

  EXPECT_EQ(tmp.text, "img");
  EXPECT_EQ(tmp.startPos, 5);
  EXPECT_EQ(tmp.endPos, 9);
}

TEST(Brackets, BracketsF) {
  string test = "(";

  BracketsInfo tmp = process(test, 0);

  EXPECT_EQ(tmp.text, "");
  EXPECT_EQ(tmp.startPos, -1);
  EXPECT_EQ(tmp.endPos, -1);
}

TEST(Brackets, BracketsF2) {
  string test = "(0)";

  BracketsInfo tmp = process(test, 1);

  EXPECT_EQ(tmp.text, "");
  EXPECT_EQ(tmp.startPos, -1);
  EXPECT_EQ(tmp.endPos, -1);
}