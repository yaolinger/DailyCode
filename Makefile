include Makefile.config

INCLUDE=$(BASE_INCLUDE) -I. -I.. -I../.. $(ZDB_INCLUDE) 

SRCS=$(wildcard */*.cpp)
OBJS=$(SRCS:.cpp=.o)
DEPS=$(SRCS:.cpp=.d)

NAME=Daily
TARGET=$(NAME).out

all : $(TARGET)

-include $(DEPS)

%.o : %.cpp
	$(CXX) $(CXXDEFINE) $(CXXFLAGS) -Wno-unused-variable $(INCLUDE) $(VERSION) -c $< -o $@ -MMD -MP

$(TARGET) : $(OBJS)
	$(CXX) $(BASE_LIB) $^ -o $@

clean :
	rm */*.d */*.o $(TARGET) -f

distclean :
	@echo "$(NAME) nothing to do~~"

.PHONY : all clean distclean
