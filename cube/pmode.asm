protected_mode:
    mov ax, DATA_SEGMENT
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov ebp, 0x1000
    mov esp, ebp

    in al, 0x92
    or al, 0x02
    out 0x92, al
    jmp KERNEL