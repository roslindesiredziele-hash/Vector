# CMake generated Testfile for 
# Source directory: C:/MyPROJECTS/Custom-Dynamic-Vector
# Build directory: C:/MyPROJECTS/Custom-Dynamic-Vector/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(VecTests "C:/MyPROJECTS/Custom-Dynamic-Vector/build/Debug/Vec_TDD.exe")
  set_tests_properties(VecTests PROPERTIES  _CMAKE_TEST_BUILD_DEPENDS "C:/MyPROJECTS/Custom-Dynamic-Vector/build/Debug/Vec_TDD.exe" _BACKTRACE_TRIPLES "C:/MyPROJECTS/Custom-Dynamic-Vector/CMakeLists.txt;21;add_test;C:/MyPROJECTS/Custom-Dynamic-Vector/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(VecTests "C:/MyPROJECTS/Custom-Dynamic-Vector/build/Release/Vec_TDD.exe")
  set_tests_properties(VecTests PROPERTIES  _CMAKE_TEST_BUILD_DEPENDS "C:/MyPROJECTS/Custom-Dynamic-Vector/build/Release/Vec_TDD.exe" _BACKTRACE_TRIPLES "C:/MyPROJECTS/Custom-Dynamic-Vector/CMakeLists.txt;21;add_test;C:/MyPROJECTS/Custom-Dynamic-Vector/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(VecTests "C:/MyPROJECTS/Custom-Dynamic-Vector/build/MinSizeRel/Vec_TDD.exe")
  set_tests_properties(VecTests PROPERTIES  _CMAKE_TEST_BUILD_DEPENDS "C:/MyPROJECTS/Custom-Dynamic-Vector/build/MinSizeRel/Vec_TDD.exe" _BACKTRACE_TRIPLES "C:/MyPROJECTS/Custom-Dynamic-Vector/CMakeLists.txt;21;add_test;C:/MyPROJECTS/Custom-Dynamic-Vector/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(VecTests "C:/MyPROJECTS/Custom-Dynamic-Vector/build/RelWithDebInfo/Vec_TDD.exe")
  set_tests_properties(VecTests PROPERTIES  _CMAKE_TEST_BUILD_DEPENDS "C:/MyPROJECTS/Custom-Dynamic-Vector/build/RelWithDebInfo/Vec_TDD.exe" _BACKTRACE_TRIPLES "C:/MyPROJECTS/Custom-Dynamic-Vector/CMakeLists.txt;21;add_test;C:/MyPROJECTS/Custom-Dynamic-Vector/CMakeLists.txt;0;")
else()
  add_test(VecTests NOT_AVAILABLE)
endif()
