.list
.sym

; *********************************************************
; ***** Program to demonstrat multi-byte BCD addition *****
; *********************************************************

              org     $0
start:        fim     0,arg1           ; point to first number
              fim     1,%00_00_0000    ; chip 0, register 0, cell 0
              jms     copy             ; copy argument to RAM
              fim     0,arg2           ; point to second number
              fim     1,%00_01_0000    ; chip 0, register 1, cell 0
              jms     copy             ; copy argument to RAM
              fim     0,%00_00_0000    ; point to first arg in RAM
              fim     1,%00_01_0000    ; point to second arg in RAM
              fim     2,%00_10_0000    ; result to chip 0, register 2, cell 0
              jms     add4             ; call routine to add

              db      $ff              ; cause emulator to halt

; *************************************************
; ***** Copy 4-digit argument from ROM to RAM *****
; ***** pair 0 - pointer to ROM argument      *****
; ***** pair 1 - pointer to RAM location      *****
; *************************************************
copy:         ldm     $f-1
              xch     6                ; use R0 for the counter
loop:         fin     2                ; retrieve next pair of digits
              src     1                ; set RAM address
              ld      5                ; get high nybble
              wrm                      ; write to RAM
              inc     3                ; point to next cell
              src     1                ; set RAM address
              ld      4                ; get high nybble
              wrm                      ; write to RAM
              inc     3                ; point to next cell
              inc     1                ; increment source pointer
              isz     6,loop           ; loop until all nybbles copied
              bbl     0                ; return to caller

; **************************************
; ***** 4-digit BCD addition       *****
; ***** pair 0 - pointer to arg1   *****
; ***** pair 1 - pointer to arg2   *****
; ***** pair 2 - pointer to result *****
; **************************************
add4:         ldm     $f-3             ; 4 bytes to add
              xch     $f               ; use register 15 to count
              clc                      ; clear the carry flag
add4_lp:      src     0                ; set RAM to retrieve first number
              rdm                      ; read it
              src     1                ; set RAM to add second number
              adm
              daa                      ; perform bcd adjust
              src     2                ; where to put result
              wrm                      ; write result
              inc     1                ; point to next digit
              inc     3
              inc     5
              isz     $f,add4_lp       ; loop until all done
              tcc                      ; get final carry
              src     2                ; setup RAM address
              wrm                      ; write final carry
              bbl     0                ; then return
            
arg1:         db      $34,$12
arg2:         db      $78,$96

              end     start

