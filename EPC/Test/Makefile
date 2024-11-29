CXX_GPP = g++
CXX_CLANG = clang++
CXX = g++

all: clean SizeTest OperatorTest DictTest

.outputFolder:
	mkdir -p out

SizeTest: .outputFolder
	$(CXX) -std=c++20 -lstdc++ -lm SizeTest.cpp -Wall -Wextra -Werror -o out/SizeTest
	./out/SizeTest

OperatorTest: .outputFolder
	$(CXX) -std=c++20 -lstdc++ -lm OperatorTest.cpp -Wall -Wextra -Werror -o out/OperatorTest
	./out/OperatorTest
	
DictTest: .outputFolder
	$(CXX) -std=c++20 -lstdc++ -lm DictTest.cpp -Wall -Wextra -Werror -o out/DictTest
	./out/DictTest

clean:
	rm -rf ./out