FILES :=                              \
    .travis.yml                       \
    graph-tests/bmk447-TestDeque.c++ \
    graph-tests/bmk447-TestDeque.out \
    Graph.h                         \
    Graph.log                       \
    html                              \
    TestGraph.c++                   \
    TestGraph.out



ifeq ($(shell uname), Darwin)
    CXX       := g++
    CXXVER    := --version 2>&1 | grep c++
    GTESTVER  := head -1 /usr/local/src/gtest-1.7.0/CHANGES
    GCOV      := gcov
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
    GCOVVER   := -version | grep version
    BOOST     := /usr/local/src/boost_1_57_0/boost
    LDFLAGS   := -lgtest_main
    VALGRIND  :=
else ifeq ($(CXX), clang++)
    CXXVER    := --version 2>&1 | grep clang
    GTESTVER  := dpkg -l libgtest-dev | grep libgtest
    GCOV      := gcov-4.6
    GCOVFLAGS := --coverage
    GCOVVER   := -v | grep gcov
    BOOST     := /usr/include/boost
    LDFLAGS   := -lgtest -lgtest_main -pthread
    VALGRIND  := valgrind
else
    CXX       := g++-4.8
    CXXVER    := --version 2>&1 | grep g++
    GTESTVER  := dpkg -l libgtest-dev | grep libgtest
    GCOV      := gcov-4.8
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
    GCOVVER   := -v | grep gcov
    BOOST     := /usr/include/boost
    LDFLAGS   := -lgtest -lgtest_main -pthread
    VALGRIND  := valgrind
endif

CXXFLAGS := -pedantic -std=c++11 -Wall

.PRECIOUS: %.app

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f TestGraph



test: TestGraph.out

versions:
	uname -a
	@echo
	printenv
	@echo
	which $(CXX)
	@echo hi
	$(CXX) $(CXXVER)
	@echo hi
	$(GTESTVER)
	@echo
	which $(GCOV)
	@echo
	$(GCOV) $(GCOVVER)
	@echo
	grep "#define BOOST_VERSION " $(BOOST)/version.hpp

ifdef VALGRIND
	@echo
	which $(VALGRIND)
	@echo
	$(VALGRIND) --version
endif
	@echo
	which doxygen
	@echo
	doxygen --version

check:
	@for i in $(FILES);                                         \
	do                                                          \
        [ -e $$i ] && echo "$$i found" || echo "$$i NOT FOUND"; \
    done



html: Doxyfile Graph.h TestGraph.c++
	doxygen Doxyfile

graph-tests: 
	git clone https://github.com/cs378-summer-2015/graph-tests.git

log: 
	git log > Graph.log

Doxyfile:
	doxygen -g

sha: 
	git rev-parse HEAD

TestGraph: Graph.h TestGraph.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) TestGraph.c++ -o TestGraph $(LDFLAGS)

TestGraph.out: TestGraph
	./TestGraph
	$(VALGRIND) ./TestGraph  >  TestGraph.out 2>&1
	$(GCOV) -b TestGraph.c++ >> TestGraph.out
	cat TestGraph.out
