[bits 16]
[ORG 0x7C00]

%define STAGE_2 0x7E00
%define VIDEO_MODE 0x0013
%define NULL_VOID 0x0000

xor ax, ax
mov es, ax
mov ds, ax

mov sp, 0x7C00
mov ss, ax

call stage_2_sectors
call set_video_mode

jmp NULL_VOID:STAGE_2

%include "cube/defs.asm"

times 510-($ - $$) db 0x00
dw 0xAA55