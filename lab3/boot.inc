; macros definition

MBR_BASE_ADDR          equ  0x7C00
LOADER_BASE_ADDR       equ  0x8000
LOADER_START_SECTOR    equ  1

;********************************** gdt ***************************************;
DESC_G_4K  equ  1 << 23
DESC_D_32  equ  1 << 22
DESC_L_32  equ  0 << 21
DESC_AVL   equ  0 << 20

DESC_P      equ  1 << 15

DESC_DPL_0  equ  00b << 13
DESC_DPL_1  equ  01b << 13
DESC_DPL_2  equ  10b << 13
DESC_DPL_3  equ  11b << 13

DESC_S_CODE  equ  1 << 12
DESC_S_DATA  equ  1 << 12
DESC_S_SYS   equ  0 << 12

DESC_TYPE_CODE equ 1000b << 8
DESC_TYPE_DATA equ 0010b << 8

; code segment
DESC_LIMIT_CODE_0_15    equ   0xFFFF
DESC_LIMIT_CODE_16_19   equ   0xF << 16

DESC_CODE_HIGH_32       equ   (0 << 24) + \
                              DESC_G_4K + \
                              DESC_D_32 + \
                              DESC_L_32 + \
                              DESC_AVL + \
                              DESC_LIMIT_CODE_16_19 + \
                              DESC_P + \
                              DESC_DPL_0 + \
                              DESC_S_CODE + \
                              DESC_TYPE_CODE + \
                              0

DESC_CODE_LOW_32        equ   (0 << 16) + DESC_LIMIT_CODE_0_15

; data segment
DESC_LIMIT_DATA_0_15    equ   0xFFFF
DESC_LIMIT_DATA_16_19   equ   0xF << 16

DESC_DATA_HIGH_32       equ   (0 << 24) + \
                              DESC_G_4K + \
                              DESC_D_32 + \
                              DESC_L_32 + \
                              DESC_AVL + \
                              DESC_LIMIT_DATA_16_19 + \
                              DESC_P + \
                              DESC_DPL_0 + \
                              DESC_S_DATA + \
                              DESC_TYPE_DATA + \
                              0

DESC_DATA_LOW_32        equ   (0 << 16) + DESC_LIMIT_DATA_0_15

; video segment
DESC_LIMIT_VIDEO_0_15   equ   0x0007  ; video has 8 pages
DESC_LIMIT_VIDEO_16_19  equ   0 << 16

DESC_VIDEO_HIGH_32      equ   (0 << 24) + \
                              DESC_G_4K + \
                              DESC_D_32 + \
                              DESC_L_32 + \
                              DESC_AVL + \
                              DESC_LIMIT_VIDEO_16_19 + \
                              DESC_P + \
                              DESC_DPL_0 + \
                              DESC_S_DATA + \
                              DESC_TYPE_DATA + \
                              0xB

DESC_VIDEO_LOW_32       equ   (0x8000 << 16) + DESC_LIMIT_VIDEO_0_15


;*************************** segment selector *********************************;
RPL0 equ 00b ; 定义常量，特权等级
RPL1 equ 01b
RPL2 equ 10b
RPL3 equ 11b

TI_GDT equ 000b
TI_LDT equ 100b

SELECTOR_CODE    equ (0x0001 << 3) + TI_GDT + RPL0
SELECTOR_DATA    equ (0x0002 << 3) + TI_GDT + RPL0
SELECTOR_VIDEO   equ (0x0003 << 3) + TI_GDT + RPL0
