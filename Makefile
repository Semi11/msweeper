COMPILER = g++
CFLAGS  = -g -MMD -MP -Wall -std=c++11
INCLUDE = -I./Inc
TARGET  = ./$(shell basename `readlink -f .`)
SRCDIR  = ./Src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJDIR  = ./Obj
OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPENDS = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS)
	$(COMPILER) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean :
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGER)

-include $(DEPENDS)
