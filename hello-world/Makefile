TRACY_ROOT=../../tracy

CXXFLAGS=-O2 -march=native -Wall -g -fno-omit-frame-pointer

main:
	$(CXX) $(CXXFLAGS) -flto ./main.cpp -o main

tracy: TracyClient.o
	$(CXX) $(CXXFLAGS) -flto ./main.cpp TracyClient.o -o main


TracyClient.o: $(TRACY_ROOT)/public/TracyClient.cpp
	$(CXX) -DTRACY_ENABLE=1 -c $(CXXFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -rf main
