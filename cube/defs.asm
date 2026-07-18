stage_2_sectors:
    mov ah, 0x02
    mov al, 0x02
    mov ch, 0x00
    mov cl, 0x02
    mov dh, 0x00

    xor bx, bx
    mov es, bx

    mov bx, STAGE_2
    int 0x13
    call end

set_video_mode:
    mov ax, VIDEO_MODE
    int 0x10
    call end

end:
    ret