#ifndef _CPU_H
#define _CPU_H

#ifndef _BYTE
typedef unsigned char byte;
typedef unsigned short word;
#define _BYTE
#endif

typedef struct _CPU {
  word stack[3];
  byte sp;
  byte a;
  byte i[16];
  byte opr;
  byte opa;
  byte cy;
  byte ts;
  byte cm;
  byte halt;
  byte x2;
  byte x3;
  byte t;
  void (*Inst[256])(struct _CPU *cpu);
  } CPU;

#endif

