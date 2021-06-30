cc_library(
  name = "vector",
  srcs = [
    "src/vector.h",
  ],
)

cc_test(
  name = "all_tests",
  srcs = [
    "src/vector_test.cc",
  ],
  deps = [
    "@gtest//:gtest",
    "@gtest//:gtest_main",
    ":vector",
  ]
)
