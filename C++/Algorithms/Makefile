target := LeftRotation
CCFLAGS := g++ -std=c++11
LD_FLAGS := -I /usr/include -L/usr/lib -lgtest -lgtest_main -pthread

$(target):
	$(CCFLAGS) $(target).cpp -o driver
	$(CCFLAGS) $(target)_TEST.cpp $(LD_FLAGS) -o test
