CC = clang
LD = ld
AR = ar

CCFLAGS = \
	-Wall -Wextra -Weverything -std=c99 -pedantic -fPIC \
	-DIRE_BUILD_SHARED \
	-O0 -g

LDFLAGS = \
	-macosx_version_min 10.7 \
	-lc

INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = .
OBJECT_DIR = $(BUILD_DIR)

OBJECT_FILES = \
	$(OBJECT_DIR)/code.o \
	$(OBJECT_DIR)/data.o \
	$(OBJECT_DIR)/binary.o \
	$(OBJECT_DIR)/cpu.o


.PHONY: all clean


all: $(BUILD_DIR)/libire.dylib $(BUILD_DIR)/libire.a $(BUILD_DIR)/ire


clean:
	rm $(BUILD_DIR)/libire.dylib
	rm $(BUILD_DIR)/libire.a
	rm $(OBJECT_DIR)/ire.o $(BUILD_DIR)/ire
	rm $(OBJECT_FILES)


$(BUILD_DIR)/libire.dylib: $(OBJECT_FILES)
	$(LD) $(LDFLAGS) -dylib -o $@ $+


$(BUILD_DIR)/libire.a: $(OBJECT_FILES)
	$(AR) rcs $@ $+


$(BUILD_DIR)/ire: $(BUILD_DIR)/libire.dylib $(OBJECT_DIR)/ire.o
	$(LD) $(LDFLAGS) -execute -L$(BUILD_DIR) -lire -o $@ /usr/lib/crt1.o $(OBJECT_DIR)/ire.o


$(OBJECT_DIR)/ire.o: $(SOURCE_DIR)/ire.c
	$(CC) $(CCFLAGS) -I$(INCLUDE_DIR) -o $@ -c $+


$(OBJECT_DIR)/code.o: $(SOURCE_DIR)/code.c
	$(CC) $(CCFLAGS) -I$(INCLUDE_DIR) -o $@ -c $+


$(OBJECT_DIR)/data.o: $(SOURCE_DIR)/data.c
	$(CC) $(CCFLAGS) -I$(INCLUDE_DIR) -o $@ -c $+


$(OBJECT_DIR)/binary.o: $(SOURCE_DIR)/binary.c
	$(CC) $(CCFLAGS) -I$(INCLUDE_DIR) -o $@ -c $+


$(OBJECT_DIR)/cpu.o: $(SOURCE_DIR)/cpu.c
	$(CC) $(CCFLAGS) -I$(INCLUDE_DIR) -o $@ -c $+
