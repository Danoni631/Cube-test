[bits 16]
[ORG 0x7E00]

%define KERNEL 0x1000
%define SECTORS 0x0008

call kernel_sectors
call load_gdt

jmp CODE_SEGMENT:protected_mode

kernel_sectors:
    mov ah, 0x02
    mov al, SECTORS
    mov ch, 0x00
    mov cl, 0x03
    mov dh, 0x00

    xor bx, bx
    mov es, bx

    mov bx, KERNEL
    int 0x13
    
    call end

end:
    ret

%include "cube/gdt.asm"
%include "cube/pmode.asm"

times 1024-($-$$) db 0