.list
.sym

; **********************************************************
; ***** Program to demonstrate how to select RAM banks *****
; ***** After running you can find the written value   *****
; ***** by doing: ?r2                                  *****
; **********************************************************

              org     $0
start:        ldm     2                ; want to use RAM bank 2
              dcl                      ; write to bank selection register
              fim     1,%01_10_0100    ; chip 1, register 2, cell 4
              src     1                ; send to RAM chips
              ldm     7                ; will store the number 7
              wrm                      ; write to RAM
              db      $ff              ; cause the emulator to halt
              end     start

