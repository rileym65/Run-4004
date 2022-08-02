.list

; this program demonstrates write/read RAM as well as adding
; from a RAM locaiont

               org     $0
start:         fim     1,%01_10_0101      ; select chip 1, register 2, cell 5
               src     1                  ; send to RAM chips
               ldm     5                  ; value to output
               wrm                        ; write to RAM
               inc     3                  ; increment to cell 6
               src     1                  ; send to RAM chips
               ldm     6                  ; will write 6 to this cell
               wrm                        ; write to RAM
               fim     1,%01_10_0101      ; no decrement so reset whole register to 5
               src     1                  ; send to RAM chips
               rdm                        ; read value in cell 5
               inc     3                  ; point back to cell 6
               src     1                  ; send to RAM chips
               adm                        ; add in cell 6
               db      $ff                ; will cause Run/04 to halt program
               end     start

