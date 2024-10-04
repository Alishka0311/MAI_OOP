# CMake generated Testfile for 
# Source directory: /workspaces/oop1/lr1
# Build directory: /workspaces/oop1/lr1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/oop1/lr1/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/oop1/lr1/CMakeLists.txt;33;add_test;/workspaces/oop1/lr1/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
