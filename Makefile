# Defs Utils
RED="\\e[31m"
GREEN="\\e[32m"
BLUE="\\e[34m"
YELLOW="\\e[33m"
RESET="\\e[0m"

# Funções
define ppecho
    echo "${GREEN}>>${BLUE}[$(1)]: ${RESET}$(2)"
endef

# Funções
define ppecho_ok
    echo "${GREEN}<<${BLUE}[$(1)]: ${YELLOW}Done!\n${RESET}"
endef

# Ferramentas
LD = riscv64-unknown-elf-ld
CC = riscv64-unknown-elf-gcc
ASM = riscv64-unknown-elf-as
OBJC = riscv64-unknown-elf-objcopy

# Diretórios e arquivos
FAMILY = riscv
ARCH = rv32i
PLATFORM = qemu
SRC_DIR = src
ARCH_DIR = $(SRC_DIR)/arch/$(FAMILY)/$(ARCH)
PLATFORM_DIR = $(ARCH_DIR)/$(PLATFORM)
APP_DIR = $(SRC_DIR)/app
DRIVER_DIR = $(SRC_DIR)/driver


BUILD_DIR = build/$(ARCH)/$(PLATFORM)
BIN = begonios.elf

# Lista de arquivos fonte
# - C *****************************************
KERNEL_SRC_C = $(wildcard $(SRC_DIR)/*.c)
ARCH_SRC_C = $(wildcard $(ARCH_DIR)/*.c)
PLATFORM_SRC_C = $(wildcard $(PLATFORM_DIR)/*.c)
DRIVER_SRC_C = $(wildcard $(DRIVER_DIR)/*.c)
APP_SRC_C = $(wildcard $(APP_DIR)/*.c)
# - ASM ***************************************
KERNEL_SRC_S = $(wildcard $(SRC_DIR)/*.S)
ARCH_SRC_S = $(wildcard $(ARCH_DIR)/*.S)
PLATFORM_SRC_S = $(wildcard $(PLATFORM_DIR)/*.S)
DRIVER_SRC_S = $(wildcard $(DRIVER_DIR)/*.S)
APP_SRC_S = $(wildcard $(APP_DIR)/*.S)

# Lista de arquivos objeto
OBJ_C = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(KERNEL_SRC_C)) \
		$(patsubst $(ARCH_DIR)/%.c, $(BUILD_DIR)/%.o, $(ARCH_SRC_C)) \
		$(patsubst $(PLATFORM_DIR)/%.c, $(BUILD_DIR)/%.o, $(PLATFORM_SRC_C)) \
		$(patsubst $(DRIVER_DIR)/%.c, $(BUILD_DIR)/%.o, $(DRIVER_SRC_C)) \
		$(patsubst $(APP_DIR)/%.c, $(BUILD_DIR)/%.o, $(APP_SRC_C))

OBJ_S = $(patsubst $(SRC_DIR)/%.S, $(BUILD_DIR)/%.o, $(KERNEL_SRC_S)) \
		$(patsubst $(ARCH_DIR)/%.S, $(BUILD_DIR)/%.o, $(ARCH_SRC_S)) \
		$(patsubst $(PLATFORM_DIR)/%.S, $(BUILD_DIR)/%.o, $(PLATFORM_SRC_S)) \
		$(patsubst $(DRIVER_DIR)/%.S, $(BUILD_DIR)/%.o, $(DRIVER_SRC_S)) \
		$(patsubst $(APP_DIR)/%.S, $(BUILD_DIR)/%.o, $(APP_SRC_S))
OBJS = $(OBJ_C) $(OBJ_S)

# Regra padrão
default: $(BUILD_DIR)/$(BIN)
	@$(call ppecho_ok, "BegoniOS ELF: $(BIN)")

# Regra para criar o executável
$(BUILD_DIR)/$(BIN): $(OBJS)
	@$(call ppecho, "Building ELF $@", "from $^")
	@$(LD) -T $(PLATFORM_DIR)/common/platform_links.ld -m elf32lriscv -o $@ $^
	@$(call ppecho_ok, "Building ELF $@") 

# Regra para compilar arquivos .c do kernel
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@$(call ppecho, "Building Kernel $@", "from $<") 
	@$(CC) -I$(SRC_DIR)/include -march=rv32i -mabi=ilp32 -nostdlib -static -ffreestanding -c $< -o $@
	@$(call ppecho_ok, "Building Kernel $@") 

# Regra para compilar arquivos .c
$(BUILD_DIR)/%.o: $(PLATFORM_DIR)/%.c | $(BUILD_DIR)
	@$(call ppecho, "Building Platform $@", "from $<") 
	@$(CC) -I$(PLATFORM_DIR)/include -march=rv32i -mabi=ilp32 -nostdlib -static -ffreestanding -c $< -o $@
	@$(call ppecho_ok, "Building Platform $@") 

# Regra para montar arquivos .S
$(BUILD_DIR)/%.o: $(PLATFORM_DIR)/%.S | $(BUILD_DIR)
	@$(call ppecho, "Building Platform ASM $@", "from $<") 
	@$(ASM) -march=rv32i -g -mabi=ilp32 -c $< -o $@
	@$(call ppecho_ok, "Building Platform ASM $@") 

# Cria o diretório de build se não existir
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Executa o programa no QEMU
run: $(BUILD_DIR)/$(BIN)
	@echo "Stop Simulation: Ctrl-A C"
	qemu-system-riscv32 -nographic -serial mon:stdio -machine virt -bios $(BUILD_DIR)/$(BIN)

# Executa o programa no QEMU com depuração
debug: $(BUILD_DIR)/$(BIN)
	@echo "Stop DEBUG Simulation: Ctrl-A C"
	qemu-system-riscv32 -nographic -serial mon:stdio -machine virt -s -S -bios $(BUILD_DIR)/$(BIN)

# Limpa os arquivos gerados
clean:
	rm -rf $(BUILD_DIR)

.PHONY: default run debug clean