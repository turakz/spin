#compiler used
CXX = g++
#language version
cv = -std=++17
#dependencies
FILES = string_c.h case_c.h algos_c.h main.cpp 
#flags
FLAGS = -ggdb -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Wno-sign-compare
#libraries
LIBS = -lncurses -I /usr/lib/boost_1_64_0/
#executable name
OUT_EXE = sc.exe

#target definition
spin: $(FILES)
	$(CXX) $(CV) $(FLAGS) -o $(OUT_EXE) $(FILES)

clean:
	rm .*.* | rm .*.*~ | rm *.*~ | rm *.*.gch | rm *.exe.stackdump

