COMPILER = g++
CFLAGS  = -g -MMD -MP -Wall  
INCLUDE = -I./Inc
TARGET  = ./$(shell basename `readlink -f .`)
SRCDIR  = ./Src
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJDIR  = ./Obj
OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))
DEPENDS = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS)
	$(COMPILER) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean :
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGER)

-include $(DEPENDS)
