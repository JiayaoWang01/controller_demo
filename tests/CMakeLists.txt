file(GLOB_RECURSE ALL_TEST_SOURCES "*.cpp")

find_package(GTest REQUIRED)

add_executable(test_controllers ${ALL_TEST_SOURCES})

target_link_libraries(test_controllers gtest pthread controllers)

add_test(NAME test_controllers COMMAND test_controllers)

install(TARGETS test_controllers DESTINATION bin)