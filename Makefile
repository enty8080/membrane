CXX       = g++
CXXFLAGS  = -std=c++17 -Wall -Wextra -pedantic-errors

LDFLAGS   = --static

Q         = @
TARGET    = membrane

SRCS      := $(shell find -name "*.cc" -print -type f)
OBJS       = $(patsubst %.cc, %.o, $(SRCS))

.PHONY: membrane

all: membrane

membrane: $(OBJS)
	$(Q) echo [Linking] $@
	$(Q) $(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)
	$(Q) echo done

%.o: %.cc
	$(Q) echo [Compile] $<
	$(Q) $(CXX) -c $< -o $@ $(CXXFLAGS)
