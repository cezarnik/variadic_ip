cmake_minimum_required(VERSION 3.2)

project(ip_filter)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter_cli main.cpp)

add_executable(filter_test test.cpp)

add_library(filter filter.cpp)

set_target_properties(ip_filter_cli filter_test filter PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
set_target_properties(filter_test PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)
target_link_libraries(ip_filter_cli filter)

target_link_libraries(filter_test ${Boost_LIBRARIES} filter)

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")

set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")

set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT n.gaivoronskiy@innopolis.ru)

include(CPack)

enable_testing()

add_test(filter_test filter_test)
