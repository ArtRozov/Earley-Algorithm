mkdir cmake_build
cd cmake_build || return
cmake ..
cmake --build .
cd ../bin
./Test
./FormalPrac2
cd ..
lcov -t /cmake_build/CMakeFiles/FormalPrac2.dir/"main.cpp" -o main.info -c -d .
genhtml -o report main.info
lcov -t /cmake_build/CMakeFiles/CYK_Parser.dir/src/"Earley.cpp" -o earley.info -c -d .
genhtml -o report earley.info
lcov -t /cmake_build/CMakeFiles/Grammar.dir/src/"Grammar.cpp" -o grammar.info -c -d .
genhtml -o report grammar.info
