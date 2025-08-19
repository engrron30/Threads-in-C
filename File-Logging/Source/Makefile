TOP_DIR ?= ..
SRC_DIR ?= $(TOP_DIR)/Source
INC_DIR	?= $(TOP_DIR)/Include

CFLAGS := -I$(INC_DIR)

all:
	gcc $(CFLAGS) main.c logger.c -o ron_logger

clean:
	rm ron_logger ron_file.dat
