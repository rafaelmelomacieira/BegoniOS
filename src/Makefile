all:
	riscv64-unknown-elf-as -o begonia.elf main.s


bin:
	objcopy -O binary begonia.elf begonia.bin

clean:
	rm -Rf *.bin *~ *.x
