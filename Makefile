CC = clang
LD = ld

CCFLAGS = \
	-Wall -Wextra -std=c99 -pedantic -ansi -fPIC \
	-DIRE_BUILD_SHARED \
	-O0 -g

LDFLAGS = \
	-macosx_version_min 10.7 \
	-lc

INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = build
OBJECT_DIR = $(BUILD_DIR)/o

OBJECT_FILES = \
	$(OBJECT_DIR)/cpu.o


.PHONY: all clean


all: $(BUILD_DIR)/libire.dylib $(BUILD_DIR)/ire


clean:
	find $(BUILD_DIR) -type f | xargs rm -v


$(BUILD_DIR)/libire.dylib: $(OBJECT_FILES)
	$(LD) $(LDFLAGS) -dylib -o $@ $+


$(BUILD_DIR)/ire: $(BUILD_DIR)/libire.dylib $(OBJECT_DIR)/ire.o
	$(LD) $(LDFLAGS) -execute -L$(BUILD_DIR) -lire -o $@ /usr/lib/crt1.o $(OBJECT_DIR)/ire.o


$(OBJECT_DIR)/ire.o: $(SOURCE_DIR)/ire.c
	$(CC) $(CCFLAGS) -I$(INCLUDE_DIR) -o $@ -c $+


$(OBJECT_DIR)/cpu.o: $(SOURCE_DIR)/cpu.c
	$(CC) $(CCFLAGS) -I$(INCLUDE_DIR) -o $@ -c $+
