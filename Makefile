CC = riscv64-unknown-elf-gcc
ASM = riscv64-unknown-elf-as
OBJC = riscv64-unknown-elf-objcopy
ARCH = riscv/rv32i
PLATFORM = qemu
SRC_DIR = src/arch/$(ARCH)/$(PLATFORM)
BUILD_DIR = build
BIN = begonios

default: $(BUILD_DIR)/$(BIN)
	@echo "Building $(BIN)...Done"
	
$(BUILD_DIR)/$(BIN): $(BUILD_DIR)/$(BIN).elf
	$(OBJC) -O binary $(BUILD_DIR)/$(BIN).elf $(BUILD_DIR)/$(BIN)

$(BUILD_DIR)/$(BIN).elf: $(BUILD_DIR)/$(BIN).o
	$(CC) -T $(SRC_DIR)/common/platform_links.ld -march=rv32i -mabi=ilp32 -nostdlib -static -o $(BUILD_DIR)/$(BIN).elf $(BUILD_DIR)/$(BIN).o 

$(BUILD_DIR)/$(BIN).o : 
	$(ASM) -march=rv32i -mabi=ilp32 $(SRC_DIR)/boot.S -o $(BUILD_DIR)/$(BIN).o

run:
	@echo "Ctrl-A C for QEMU console, then quit to exit"
	qemu-system-riscv32 -nographic -serial mon:stdio -machine virt -bios $(BUILD_DIR)/$(BIN)

clean:
	rm -f ./build/*