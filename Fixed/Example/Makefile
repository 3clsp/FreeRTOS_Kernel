CC = /home/sourag/Desktop/checkedc-llvm-project/build/bin/clang-12

FREERTOS_ROOT := /home/sourag/Desktop/FreeRTOS
FREERTOS_DIR := $(abspath $(FREERTOS_ROOT))/FreeRTOS
FREERTOS_PLUS_DIR := $(abspath $(FREERTOS_ROOT))/FreeRTOS-Plus


INCLUDE_DIRS := -I.
INCLUDE_DIRS += -I./include
INCLUDE_DIRS += -I$(FREERTOS_DIR)/Demo/Posix_GCC
INCLUDE_DIRS += -I$(FREERTOS_PLUS_DIR)/Source/FreeRTOS-Plus-Trace/Include

CFLAGS                :=    -ggdb3 -fPIE
LDFLAGS               :=    -ggdb3 -pthread
CPPFLAGS              +=    -D_WINDOWS_

ifeq ($(TRACE_ON_ENTER),1)
  CPPFLAGS              += -DTRACE_ON_ENTER=1
else
  CPPFLAGS              += -DTRACE_ON_ENTER=0
endif

ifeq ($(COVERAGE_TEST),1)
  CPPFLAGS              += -DprojCOVERAGE_TEST=1
else
  CPPFLAGS              += -DprojCOVERAGE_TEST=0
endif

ifdef PROFILE
  CFLAGS              +=   -pg  -O0
  LDFLAGS             +=   -pg  -O0
else
  CFLAGS              +=   -O3
  LDFLAGS             +=   -O3
endif

ifdef SANITIZE_ADDRESS
  CFLAGS              +=   -fsanitize=address -fsanitize=alignment
  LDFLAGS             +=   -fsanitize=address -fsanitize=alignment
endif

ifdef SANITIZE_LEAK
  LDFLAGS             +=   -fsanitize=leak
endif

ifeq ($(USER_DEMO),BLINKY_DEMO)
  CPPFLAGS            +=   -DUSER_DEMO=0
endif

ifeq ($(USER_DEMO),FULL_DEMO)
  CPPFLAGS            +=   -DUSER_DEMO=1
endif


SRC := .
OBJ := .

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(SOURCES:.c=.o)

all: $(OBJECTS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(INCLUDE_DIRS) $(CPPFLAGS) $(CFLAGS) -MMD -Wno-everything -c $< -o $@

.PHONY: clean

clean:
	-rm *.o
	-rm *.d
