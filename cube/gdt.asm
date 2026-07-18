load_gdt:
    cli
    lgdt [GDTR]
    mov eax, cr0
    or eax, 0x01
    mov cr0, eax
    ret

gdt:
    gdt.entry:
        dd 0x00
        dd 0x00

    gdt.code:
        dw 0xFFFF
        dw 0x00
        db 0x00
        db 0x9A
        db 0xCF
        db 0x00

    gdt.data:
        dw 0xFFFF
        dw 0x00
        db 0x00
        db 0x9A
        db 0xCF
        db 0x00

GDTR:
    dw GDTR - gdt - 1
    dd gdt

CODE_SEGMENT equ gdt.code - gdt
DATA_SEGMENT equ gdt.data - gdt