all:th
th:th.o
	$(CXX) -g -fPIC $^ -ldl -lpthread -lrt -lm  -o $@

%.o:%.cpp 
	$(CXX) -g -std=c99 -c -fPIC $<  -o $@

clean:
	rm *.o
	rm th
