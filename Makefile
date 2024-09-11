CXX := cc

# Directories
SRCDIR := src
INCDIR := includes
BUILDDIR := build
TARGETDIR := bin

# Target executable name
TARGET :=  BlockChain

# Source files
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

# Object files
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Includes
INC := -I$(INCDIR)

# Flags
CXXFLAGS = -Wall -Wextra -Werror

# Final executable
EXECUTABLE := $(TARGETDIR)/$(TARGET)

all: directories $(EXECUTABLE)

directories:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(TARGETDIR)

# Rule for linking object files into executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $(EXECUTABLE)

# Rule for compiling source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

# Clean build artifacts
clean:
	@rm -rf $(BUILDDIR)

fclean: clean
	@rm -rf $(TARGETDIR)

# Run the executable
run:
	@./$(EXECUTABLE)

# Phony targets
.PHONY: all clean fclean run