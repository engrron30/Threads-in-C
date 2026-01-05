TOP_DIR ?= ..
SRC_DIR ?= $(TOP_DIR)/Source
INC_DIR	?= $(TOP_DIR)/Include

TARGET := logger
LOGGER_FILE_NAME = logger_file.dat
CFLAGS := -I$(INC_DIR)

# Commands Defines
GCC = gcc
RM = rm

all:
	$(GCC) $(CFLAGS) *.c -o $(TARGET)

clean:
	$(RM) $(TARGET) $(LOGGER_FILE_NAME)
