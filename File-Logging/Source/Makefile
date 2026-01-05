TOP_DIR ?= ..
SRC_DIR ?= $(TOP_DIR)/Source
INC_DIR	?= $(TOP_DIR)/Include

TARGET := logger
CFLAGS := -I$(INC_DIR)

all:
	gcc $(CFLAGS) *.c -o $(TARGET)

clean:
	rm ron_logger ron_file.dat
