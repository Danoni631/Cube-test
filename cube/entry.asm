section .text
    global _start

_start:
    [bits     32]
    [EXTERN _main]
    call _main
    jmp $