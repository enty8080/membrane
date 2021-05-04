CXX       = g++
CXXFLAGS  = -Iinclude -std=c++17 -Wall -Wextra -pedantic-errors

LDFLAGS   = --static

Q         = @
TARGET    = membrane

SRCS      := $(wildcard src/*.cc)
OBJS       = $(patsubst src/%.cc, %.o, src)

.PHONY: membrane

all: membrane

membrane: $(OBJS)
	$(Q) echo [Linking] $@
	$(Q) $(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)
	$(Q) echo done

%.o: %.cc
	$(Q) echo [Compile] $<
	$(Q) $(CXX) -c $< -o $@ $(CXXFLAGS)
