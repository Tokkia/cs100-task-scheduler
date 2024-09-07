CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

PROJECT(final-project-leetcodelemons)

ADD_SUBDIRECTORY(tests/googletest)

ADD_EXECUTABLE(taskManager
  src/main.cpp
  src/Grocery.cpp
  src/School.cpp
  src/Social.cpp
  src/Work.cpp
  src/TaskManager.cpp
  src/Task.cpp
)

ADD_EXECUTABLE(test
  tests/test.cpp 
  src/Grocery.cpp
  src/School.cpp
  src/Social.cpp
  src/Work.cpp
  src/TaskManager.cpp
  src/Task.cpp
)

TARGET_LINK_LIBRARIES(test gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

