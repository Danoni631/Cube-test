asm_compile:
	nasm -f bin "cube/boot.asm" -o "cube/binaries/boot.bin"
	nasm -f bin "cube/stage_2.asm" -o "cube/binaries/stage_2.bin"
	nasm -f elf "cube/entry.asm" -o "cube/binaries/entry.o"

FLAGS="-m32 -ffreestanding"

c_compile:
	gcc $FLAGS -c "cube/kernel.c" -o "cube/binaries/kernel.o"
	gcc $FLAGS -c "cube/3d.c" -o "cube/binaries/3d.o"
	gcc $FLAGS -c "cube/math.c" -o "cube/binaries/math.o"
	gcc $FLAGS -c "cube/graphics.c" -o "cube/binaries/graphics.o"
	gcc $FLAGS -c "cube/timer.c" -o "cube/binaries/timer.o"
	gcc $FLAGS -c "cube/payload.c" -o "cube/binaries/payload.o"

ld -m i386pe -T "cube/linker.ld" -Ttext 0xC90000 \
    "cube/binaries/kernel.o" \
    "cube/binaries/entry.o" \
    "cube/binaries/graphics.o" \
    "cube/binaries/math.o" \
    "cube/binaries/payload.o" \
    "cube/binaries/timer.o" \
	"cube/binaries/3d.o" \
	-o cube/binaries/kernel.bin

copy /b cube/binaries/boot.bin + cube/binaries/stage_2.bin + cube/binaries/kernel.bin disk.img