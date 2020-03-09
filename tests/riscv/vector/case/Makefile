SRC = $(wildcard *.c)
SRS = $(wildcard *.S)
OBJFILE = $(SRS:%.S=%.o) $(SRC:%.c=%.o)
CFLAGS = -g2 -static -march=rv64g -Wa,-march=rv64gv
TARGET_CROSS = riscv64-unknown-linux-gnu
CC = $(TARGET_CROSS)-gcc
INCLUDE = -I../../include -I.
rvv_case: case

case: $(OBJFILE)

%.o: %.S rvv_insn.h
	@echo "  CC    case/$@"
	@$(CC) $(CFLAGS) -c $(INCLUDE) -o $@  $<

%.o: %.c rvv_insn.h
	@echo "  CC    case/$@"
	@$(CC) $(CFLAGS) -c $(INCLUDE) -o $@  $<
	@echo "  CC    case/$*.elf"
	$(CC) $(CFLAGS) rvv_insn.o  $(INCLUDE)   $*.o -o $*.elf
clean:
	rm -rf  *.o *.a *.asm *.elf
