
.PHONY:compile

src=
obj=$(src:.cpp=.o)
exe=$(src:.cpp=.exe)

exedir=../exe/
case=

CXX=g++
CXXFLAGS=-O0 -g -Wall

compile:
ifneq ($(src),)
	$(CXX) $(CXXFLAGS) -c $(src) -o $(exedir)$(obj)
	$(CXX) $(exedir)$(obj) -o $(exedir)$(exe)
endif

test:
ifneq ($(src),)
	$(exedir)$(exe) $(testcase)
endif

all:
ifneq ($(src),)
	make compile src=$(src)
	make test src=$(src)
endif

clean:
ifneq ($(src),)
	rm -rf $(exedir)$(obj)
	rm -rf $(exedir)$(exe)
endif

all-clean:
	rm -rf $(exedir)*

