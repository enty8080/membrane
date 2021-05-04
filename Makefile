CXX       = g++
CXXFLAGS  = -Iinclude -std=c++17 -Wall -Wextra -pedantic-errors

LDFLAGS   = --static

Q         = @
TARGET    = membrane

SRCS      := $(wildcard src/*.cc)
OBJS      := $(patsubst %.cc, %.o, $(SRCS))

.PHONY: membrane

all: membrane

membrane: $(OBJS)
	$(Q) echo Linking... $@
	$(Q) $(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)
	$(Q) echo Done.

%.o: %.cc
	$(Q) echo Compiling... $<
	$(Q) $(CXX) -c $< -o $@ $(CXXFLAGS)
