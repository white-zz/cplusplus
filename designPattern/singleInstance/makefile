CXX := g++    #指定编译器
CXXFLAGS := -Wall -g -lpthread -std=c++11 #指定编译选项
OBJS1 := singleInstance_1.cpp
OBJS2 := singleInstance_2.cpp
OBJS3 := task_queue.cpp


singleInstance_1:$(OBJS1)
	$(CXX) $(OBJS1) $(CXXFLAGS)

singleInstance_2:$(OBJS2)
	$(CXX) $(OBJS2) $(CXXFLAGS)



task:$(OBJS3)
	$(CXX) $(OBJS3) $(CXXFLAGS)
