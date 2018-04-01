CXXFLAGS = -O3 -std=c++11

bf: bf.cpp cell.cpp cell.hpp cellList.cpp cellList.hpp config.hpp helper.hpp brainfuck.hpp
	$(CXX) $(CXXFLAGS) bf.cpp cell.cpp cellList.cpp -o bf
