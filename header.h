#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"

#ifndef _BYTE
typedef unsigned char byte;
#define _BYTE
#endif

#ifndef _WORD
typedef unsigned short word;
#endif

#ifndef _DWORD
typedef unsigned int dword;
#endif

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

LINK CPU        cpu;
LINK byte       rom[4096];
LINK byte       ram[4096];
LINK byte       ramPort[32];
LINK byte       romPort[16];
LINK byte       status[1024];
LINK char       runDebugger;
LINK int        use6309;

extern void cpu_reset(CPU* cpu);
extern void cpu_cycle(CPU* cpu);
extern void cpu_prepare(CPU *cpu);
extern byte readRom(byte* ram, word address);
extern void writeRom(byte* ram, word address, byte value);
extern byte readRam(byte* ram, word address);
extern void writeRam(byte* ram, word address, byte value);


extern void Debugger();
extern word Disassem(word addr, char* dest);
extern int evaluate(char* expr);
extern int loadFile(char* filename);
extern void GotoXY(int x, int y);

#endif
