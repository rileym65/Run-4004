.list

; ************************************************************
; ***** This program demonstrates reading/writing ports  *****
; ***** by reading the input port on ROM 5 and writing   *****
; ***** the result to the output port on RAM 3           *****
; ***** Before running this program you should do this:  *****
; *****    IN5=7                                         *****
; ***** To set a value on input port5                    *****
; ************************************************************

              org     $0
start:        fim     1,%0101_0000     ; select ROM chip 5
              src     1                ; write X register
              rdr                      ; read ROM port
              fim     1,%11_00_0000    ; select RAM chip 3
              src     1                ; write to X register
              wmp                      ; write value to port

              db      $ff              ; cause emulator to halt

              end     start

