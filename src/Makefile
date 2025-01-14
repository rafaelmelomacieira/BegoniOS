CC = riscv64-unknown-elf-gcc
ASM = riscv64-unknown-elf-as
ARCH = riscv
PLATFORM = qemu
SRC_DIR = ./src/$(ARCH)/$(PLATFORM)
BUILD_DIR = ./build
BIN = begonios

default: $(BIN)
	
$(BIN): $(BIN).elf
	objcopy -O binary $(BUILD_DIR)/$(BIN).elf $(BUILD_DIR)/$(BIN)

$(BIN).elf: $(BUILD_DIR)/platform_links.ld $(BUILD_DIR)/$(BIN).o
	$(CC) -T $(SRC_DIR)/common/platform_links.ld -march=rv32i -mabi=ilp32 -nostdlib -static -o $(BUILD_DIR)/$(BIN).elf $(BUILD_DIR)/$(BIN).o 

$(BIN).o : $(BUILD_DIR)/boot.S
	$(ASM) -march=rv32i -mabi=ilp32 $(SRC_DIR)/boot.S -o $(BUILD_DIR)/$(BIN).o

clean:
	rm -Rf ./build