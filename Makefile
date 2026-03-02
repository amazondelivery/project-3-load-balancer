CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
TARGET = main
SOURCES = main.cpp Request.cpp RequestQueue.cpp WebServer.cpp LoadBalancer.cpp Switch.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)