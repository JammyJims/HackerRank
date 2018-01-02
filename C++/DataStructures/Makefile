target := RemoveDuplicates
CCFLAGS := g++ -std=c++11
LD_FLAGS := -I /usr/include -L/usr/lib -lgtest -lgtest_main -pthread

test:
	$(CCFLAGS) test.cpp $(LD_FLAGS) -o test
	
$(target):
	$(CCFLAGS) main.cpp -o driver

clean:
	rm -f *.o *.out
