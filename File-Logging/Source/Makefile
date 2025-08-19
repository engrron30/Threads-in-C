TOP_DIR ?= ..
SRC_DIR ?= $(TOP_DIR)/Source
INC_DIR	?= $(TOP_DIR)/Include

TARGET := ron_logger
CFLAGS := -I$(INC_DIR)

all:
	gcc $(CFLAGS) main.c logger.c -o $(TARGET)

clean:
	rm ron_logger ron_file.dat
