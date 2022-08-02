#include "cpu.h"
#include "header.h"

byte readRom(byte* ram, word address) {
  if (address < 4096) return ram[address];
  return 0xff;
  }

void writeRom(byte* ram, word address, byte value) {
  if (address < 4096) ram[address] = value;
  }

byte readRam(byte* ram, word address) {
  if (address < 320) return ram[address];
  return 0xff;
  }

void writeRam(byte* ram, word address, byte value) {
  if (address < 320) ram[address] = value;
  }

void _P0(CPU *cpu) {                             /* NOP */
  }

void _P1(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P2(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P3(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P4(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P5(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P6(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P7(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P8(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P9(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _PA(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _PB(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _PC(CPU *cpu) {
  cpu->halt = 0xff;
  }
    
void _PD(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _PE(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _PF(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P10(CPU *cpu) {                            /* JCN cc,nn */
  word a;
  byte j;
  j = 0;
  a = rom[cpu->stack[0]++];
  a |= (cpu->stack[0] & 0xf00);
  if (cpu->opa & 0x08) {
    if (cpu->opa == 0x08) j = 0xff;
    if (cpu->opa & 0x04 && cpu->a != 0) j = 0xff;
    if (cpu->opa & 0x02 && cpu->cy == 0) j = 0xff;
    if (cpu->opa & 0x01 && cpu->t != 0) j = 0xff;
    }
  else {
    if (cpu->opa & 0x04 && cpu->a == 0) j = 0xff;
    if (cpu->opa & 0x02 && cpu->cy != 0) j = 0xff;
    if (cpu->opa & 0x01 && cpu->t == 0) j = 0xff;
    }
  if (j != 0) cpu->stack[0] = a;
  cpu->ts += 2;
  }

void _P20(CPU *cpu) {                            /* FIM i,nn */
  byte i;
  byte b;
  i = cpu->opa >> 1;
  b = rom[cpu->stack[0]++];
  cpu->i[i*2] = b >> 4;
  cpu->i[i*2+1] = b & 0x0f;
  cpu->ts += 2;
  }

void _P21(CPU *cpu) {                            /* SRC i */
  byte i;
  i = cpu->opa >> 1;
  cpu->x2 = cpu->i[i*2];
  cpu->x3 = cpu->i[i*2+1];
  cpu->ts++;
  }

void _P30(CPU *cpu) {                            /* FIN i */
  byte i;
  word a;
  a = (cpu->stack[0] & 0xf00) | (cpu->i[0] << 4) | (cpu->i[1]);
  i = cpu->opa >> 1;
  cpu->i[i*2] = rom[a] >> 4;
  cpu->i[i*2+1] = rom[a] & 0xf;
  cpu->ts += 2;
  }

void _P31(CPU *cpu) {                            /* JIN i */
  byte i;
  i = cpu->opa >> 1;
  cpu->stack[0] = (cpu->stack[0] & 0xf00) |
                  (cpu->i[i*2] << 4) |
                  (cpu->i[i*2+1]);
  cpu->ts++;
  }

void _P40(CPU *cpu) {                            /* JUN nnn */
  word a;
  a = rom[cpu->stack[0]++];
  cpu->stack[0] = a | (cpu->opa << 8);
  cpu->ts += 2;
  }

void _P50(CPU *cpu) {                            /* JMS nnnn */
  word a;
  a = rom[cpu->stack[0]++];
  cpu->stack[3] = cpu->stack[2];
  cpu->stack[2] = cpu->stack[1];
  cpu->stack[1] = cpu->stack[0];
  cpu->stack[0] = a | (cpu->opa << 8);
  cpu->ts += 2;
  }

void _P60(CPU *cpu) {                            /* INC i */
  cpu->i[cpu->opa] = (cpu->i[cpu->opa] + 1) & 0x0f;
  cpu->ts++;
  }

void _P70(CPU *cpu) {                            /* ISZ i */
  word a;
  a = rom[cpu->stack[0]++];
  cpu->i[cpu->opa] = (cpu->i[cpu->opa] + 1) & 0xf;
  if (cpu->i[cpu->opa] != 0) cpu->stack[0] = a | (cpu->stack[0] & 0xf00);
  cpu->ts += 2;
  }

void _P80(CPU *cpu) {                            /* ADD i */
  cpu->a = cpu->a + cpu->i[cpu->opa] + cpu->cy;
  cpu->cy = (cpu->a > 0x0f) ? 1 : 0;
  cpu->a = cpu->a & 0x0f;
  cpu->ts++;
  }

void _P90(CPU *cpu) {                            /* SUB i */
  cpu->a = cpu->a + (cpu->i[cpu->opa] ^ 0xf) + cpu->cy;
  cpu->cy = (cpu->a > 0x0f) ? 1 : 0;
  cpu->a = cpu->a & 0x0f;
  cpu->ts++;
  }

void _PA0(CPU *cpu) {                            /* LD  i */
  cpu->a = cpu->i[cpu->opa];
  cpu->ts++;
  }

void _PB0(CPU *cpu) {                            /* XCH i */
  byte b;
  b = cpu->a;
  cpu->a = cpu->i[cpu->opa];
  cpu->i[cpu->opa] = b;
  cpu->ts++;
  }

void _PC0(CPU *cpu) {                            /* BBL n */
  cpu->a = cpu->opa;
  cpu->stack[0] = cpu->stack[1];
  cpu->stack[1] = cpu->stack[2];
  cpu->stack[2] = cpu->stack[3];
  cpu->ts++;
  }

void _PD0(CPU *cpu) {                            /* LDM $0 */
  cpu->a = 0x0;
  cpu->ts++;
  }

void _PD1(CPU *cpu) {                            /* LDM $1 */
  cpu->a = 0x1;
  cpu->ts++;
  }

void _PD2(CPU *cpu) {                            /* LDM $2 */
  cpu->a = 0x2;
  cpu->ts++;
  }

void _PD3(CPU *cpu) {                            /* LDM $3 */
  cpu->a = 0x3;
  cpu->ts++;
  }

void _PD4(CPU *cpu) {                            /* LDM $4 */
  cpu->a = 0x4;
  cpu->ts++;
  }

void _PD5(CPU *cpu) {                            /* LDM $5 */
  cpu->a = 0x5;
  cpu->ts++;
  }

void _PD6(CPU *cpu) {                            /* LDM $6 */
  cpu->a = 0x6;
  cpu->ts++;
  }

void _PD7(CPU *cpu) {                            /* LDM $7 */
  cpu->a = 0x7;
  cpu->ts++;
  }

void _PD8(CPU *cpu) {                            /* LDM $8 */
  cpu->a = 0x8;
  cpu->ts++;
  }

void _PD9(CPU *cpu) {                            /* LDM $9 */
  cpu->a = 0x9;
  cpu->ts++;
  }

void _PDA(CPU *cpu) {                            /* LDM $A */
  cpu->a = 0xa;
  cpu->ts++;
  }

void _PDB(CPU *cpu) {                            /* LDM $B */
  cpu->a = 0xb;
  cpu->ts++;
  }

void _PDC(CPU *cpu) {                            /* LDM $C */
  cpu->a = 0xc;
  cpu->ts++;
  }

void _PDD(CPU *cpu) {                            /* LDM $D */
  cpu->a = 0xd;
  cpu->ts++;
  }

void _PDE(CPU *cpu) {                            /* LDM $E */
  cpu->a = 0xe;
  cpu->ts++;
  }

void _PDF(CPU *cpu) {                            /* LDM $F */
  cpu->a = 0xf;
  cpu->ts++;
  }

void _PE0(CPU *cpu) {                            /* WRM */
  word a;
  a = (cpu->x2 << 4) | cpu->x3;
  a += (cpu->cm * 256);
  ram[a] = cpu->a;
  cpu->ts += 2;
  }

void _PE1(CPU *cpu) {                            /* WMP */
  byte a;
  a = (cpu->x2 >> 2) + (cpu->cm * 4);
  ramPort[a] = cpu->a;
  cpu->ts += 1;
  }

void _PE2(CPU *cpu) {                            /* WRR */
  cpu->ts += 1;
  }

void _PE3(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _PE4(CPU *cpu) {                            /* WR0 */
  word a;
  a = ((cpu->x2 >> 2) * 16) + ((cpu->x2 & 0x3) * 4);
  a += (cpu->cm * 64);
  status[a+0] = cpu->a;
  cpu->ts += 2;
  }

void _PE5(CPU *cpu) {                            /* WR1 */
  word a;
  a = ((cpu->x2 >> 2) * 16) + ((cpu->x2 & 0x3) * 4);
  a += (cpu->cm * 64);
  status[a+1] = cpu->a;
  cpu->ts += 2;
  }

void _PE6(CPU *cpu) {                            /* WR2 */
  word a;
  a = ((cpu->x2 >> 2) * 16) + ((cpu->x2 & 0x3) * 4);
  a += (cpu->cm * 64);
  status[a+2] = cpu->a;
  cpu->ts += 2;
  }

void _PE7(CPU *cpu) {                            /* WR3 */
  word a;
  a = ((cpu->x2 >> 2) * 16) + ((cpu->x2 & 0x3) * 4);
  a += (cpu->cm * 64);
  status[a+3] = cpu->a;
  cpu->ts += 2;
  }

void _PE8(CPU *cpu) {                            /* SBM */
  word a;
  a = (cpu->x2 << 4) | cpu->x3;
  a += (cpu->cm * 256);
  cpu->a = cpu->a + (ram[a] ^ 0xf) + cpu->cy;
  cpu->cy = (cpu->a > 0x0f) ? 1 : 0;
  cpu->a &= 0x0f;
  cpu->ts += 2;
  }

void _PE9(CPU *cpu) {                            /* RDM */
  word a;
  a = (cpu->x2 << 4) | cpu->x3;
  a += (cpu->cm * 256);
  cpu->a = ram[a];
  cpu->ts += 2;
  }

void _PEA(CPU *cpu) {                            /* RDR */
  byte a;
  a = cpu->x2;
  cpu->a = romPort[a];
  cpu->ts += 1;
 }

void _PEB(CPU *cpu) {                            /* ADM */
  word a;
  a = (cpu->x2 << 4) | cpu->x3;
  a += (cpu->cm * 256);
  cpu->a = cpu->a + ram[a] + cpu->cy;
  cpu->cy = (cpu->a > 0x0f) ? 1 : 0;
  cpu->a &= 0x0f;
  cpu->ts += 2;
  }

void _PEC(CPU *cpu) {                            /* RD0 */
  word a;
  a = ((cpu->x2 >> 2) * 16) + ((cpu->x2 & 0x3) * 4);
  a += (cpu->cm * 64);
  cpu->a = status[a+0];
  cpu->ts += 2;
  }

void _PED(CPU *cpu) {                            /* RD1 */
  word a;
  a = ((cpu->x2 >> 2) * 16) + ((cpu->x2 & 0x3) * 4);
  a += (cpu->cm * 64);
  cpu->a = status[a+1];
  cpu->ts += 2;
  }

void _PEE(CPU *cpu) {                            /* RD2 */
  word a;
  a = ((cpu->x2 >> 2) * 16) + ((cpu->x2 & 0x3) * 4);
  a += (cpu->cm * 64);
  cpu->a = status[a+2];
  cpu->ts += 2;
  }

void _PEF(CPU *cpu) {                            /* RD3 */
  word a;
  a = ((cpu->x2 >> 2) * 16) + ((cpu->x2 & 0x3) * 4);
  a += (cpu->cm * 64);
  cpu->a = status[a+3];
  cpu->ts += 2;
  }

void _PF0(CPU *cpu) {                            /* CLB */
  cpu->a = 0;
  cpu->cy = 0;
  cpu->ts++;
  }

void _PF1(CPU *cpu) {                            /* CLC */
  cpu->cy = 0;
  cpu->ts++;
  }

void _PF2(CPU *cpu) {                            /* IAC */
  if (cpu->a == 0x0f) cpu->cy = 1;
    else cpu->cy = 0;
  cpu->a = (cpu->a + 1) & 0x0f;
  cpu->ts++;
  }

void _PF3(CPU *cpu) {                            /* CMC */
  cpu->cy = (cpu->cy != 0) ? 0 : 1;
  cpu->ts++;
  }

void _PF4(CPU *cpu) {                            /* CMA */
  cpu->a = cpu->a ^ 0xf;
  cpu->ts++;
  }

void _PF5(CPU *cpu) {                            /* RAL */
  cpu->a = (cpu->a << 1) | (cpu->cy & 0x01);
  cpu->cy = (cpu->a > 0x0f) ? 1 : 0;
  cpu->a = cpu->a & 0x0f;
  cpu->ts++;
  }

void _PF6(CPU *cpu) {                            /* RAR */
  if (cpu->cy != 0) cpu->a |= 0x10;
  cpu->cy = (cpu->a & 0x01);
  cpu->a >>= 1;
  cpu->ts++;
  }

void _PF7(CPU *cpu) {                            /* TCC */
  cpu->a = (cpu->cy & 0x01);
  cpu->cy = 0;
  cpu->ts++;
  }

void _PF8(CPU *cpu) {                            /* DAC */
  if (cpu->a == 0x00) cpu->cy = 0;
    else cpu->cy = 1;
  cpu->a = (cpu->a - 1) & 0x0f;
  cpu->ts++;
  }

void _PF9(CPU *cpu) {                            /* TCS */
  cpu->a = (cpu->cy == 1) ? 0x0a: 0x09;
  cpu->cy = 0;
  }

void _PFA(CPU *cpu) {                            /* STC */
  cpu->cy = 1;
  cpu->ts++;
  }

void _PFB(CPU *cpu) {                            /* DAA */
  if (cpu->a > 0x09 || cpu->cy == 0x01) cpu->a += 6;
  if (cpu->a > 0x0f) cpu->cy = 1;
  cpu->a = (cpu->a & 0x0f);
  cpu->ts++;
  }

void _PFC(CPU *cpu) {                            /* KBP */
  switch (cpu->a) {
    case 0x00: cpu->a = 0x00; break;
    case 0x01: cpu->a = 0x01; break;
    case 0x02: cpu->a = 0x02; break;
    case 0x04: cpu->a = 0x03; break;
    case 0x08: cpu->a = 0x04; break;
    default  : cpu->a = 0x0f; break;
    }
  cpu->ts++;
  }

void _PFD(CPU *cpu) {                            /* DCL */
  switch (cpu->a & 0x07) {
    case 0: cpu->cm = 0; break;
    case 1: cpu->cm = 1; break;
    case 2: cpu->cm = 2; break;
    case 3: cpu->cm = 4; break;
    case 4: cpu->cm = 3; break;
    case 5: cpu->cm = 5; break;
    case 6: cpu->cm = 6; break;
    case 7: cpu->cm = 7; break;
    }
  cpu->ts++;
  }

void _PFE(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _PFF(CPU *cpu) {
  cpu->halt = 0xff;
  }

void cpu_prepare(CPU *cpu) {
  cpu->Inst[0x00]=_P0; cpu->Inst[0x01]=_P1; cpu->Inst[0x02]=_P2; cpu->Inst[0x03]=_P3;
  cpu->Inst[0x04]=_P4; cpu->Inst[0x05]=_P5; cpu->Inst[0x06]=_P6; cpu->Inst[0x07]=_P7;
  cpu->Inst[0x08]=_P8; cpu->Inst[0x09]=_P9; cpu->Inst[0x0a]=_PA; cpu->Inst[0x0b]=_PB;
  cpu->Inst[0x0c]=_PC; cpu->Inst[0x0d]=_PD; cpu->Inst[0x0e]=_PE; cpu->Inst[0x0f]=_PF;

  cpu->Inst[0x10]=_P10; cpu->Inst[0x11]=_P10; cpu->Inst[0x12]=_P10; cpu->Inst[0x13]=_P10;
  cpu->Inst[0x14]=_P10; cpu->Inst[0x15]=_P10; cpu->Inst[0x16]=_P10; cpu->Inst[0x17]=_P10;
  cpu->Inst[0x18]=_P10; cpu->Inst[0x19]=_P10; cpu->Inst[0x1a]=_P10; cpu->Inst[0x1b]=_P10;
  cpu->Inst[0x1c]=_P10; cpu->Inst[0x1d]=_P10; cpu->Inst[0x1e]=_P10; cpu->Inst[0x1f]=_P10;

  cpu->Inst[0x20]=_P20; cpu->Inst[0x21]=_P21; cpu->Inst[0x22]=_P20; cpu->Inst[0x23]=_P21;
  cpu->Inst[0x24]=_P20; cpu->Inst[0x25]=_P21; cpu->Inst[0x26]=_P20; cpu->Inst[0x27]=_P21;
  cpu->Inst[0x28]=_P20; cpu->Inst[0x29]=_P21; cpu->Inst[0x2a]=_P20; cpu->Inst[0x2b]=_P21;
  cpu->Inst[0x2c]=_P20; cpu->Inst[0x2d]=_P21; cpu->Inst[0x2e]=_P20; cpu->Inst[0x2f]=_P21;

  cpu->Inst[0x30]=_P30; cpu->Inst[0x31]=_P31; cpu->Inst[0x32]=_P30; cpu->Inst[0x33]=_P31;
  cpu->Inst[0x34]=_P30; cpu->Inst[0x35]=_P31; cpu->Inst[0x36]=_P30; cpu->Inst[0x37]=_P31;
  cpu->Inst[0x38]=_P30; cpu->Inst[0x39]=_P31; cpu->Inst[0x3a]=_P30; cpu->Inst[0x3b]=_P31;
  cpu->Inst[0x3c]=_P30; cpu->Inst[0x3d]=_P31; cpu->Inst[0x3e]=_P30; cpu->Inst[0x3f]=_P31;

  cpu->Inst[0x40]=_P40; cpu->Inst[0x41]=_P40; cpu->Inst[0x42]=_P40; cpu->Inst[0x43]=_P40;
  cpu->Inst[0x44]=_P40; cpu->Inst[0x45]=_P40; cpu->Inst[0x46]=_P40; cpu->Inst[0x47]=_P40;
  cpu->Inst[0x48]=_P40; cpu->Inst[0x49]=_P40; cpu->Inst[0x4a]=_P40; cpu->Inst[0x4b]=_P40;
  cpu->Inst[0x4c]=_P40; cpu->Inst[0x4d]=_P40; cpu->Inst[0x4e]=_P40; cpu->Inst[0x4f]=_P40;

  cpu->Inst[0x50]=_P50; cpu->Inst[0x51]=_P50; cpu->Inst[0x52]=_P50; cpu->Inst[0x53]=_P50;
  cpu->Inst[0x54]=_P50; cpu->Inst[0x55]=_P50; cpu->Inst[0x56]=_P50; cpu->Inst[0x57]=_P50;
  cpu->Inst[0x58]=_P50; cpu->Inst[0x59]=_P50; cpu->Inst[0x5a]=_P50; cpu->Inst[0x5b]=_P50;
  cpu->Inst[0x5c]=_P50; cpu->Inst[0x5d]=_P50; cpu->Inst[0x5e]=_P50; cpu->Inst[0x5f]=_P50;

  cpu->Inst[0x60]=_P60; cpu->Inst[0x61]=_P60; cpu->Inst[0x62]=_P60; cpu->Inst[0x63]=_P60;
  cpu->Inst[0x64]=_P60; cpu->Inst[0x65]=_P60; cpu->Inst[0x66]=_P60; cpu->Inst[0x67]=_P60;
  cpu->Inst[0x68]=_P60; cpu->Inst[0x69]=_P60; cpu->Inst[0x6a]=_P60; cpu->Inst[0x6b]=_P60;
  cpu->Inst[0x6c]=_P60; cpu->Inst[0x6d]=_P60; cpu->Inst[0x6e]=_P60; cpu->Inst[0x6f]=_P60;

  cpu->Inst[0x70]=_P70; cpu->Inst[0x71]=_P70; cpu->Inst[0x72]=_P70; cpu->Inst[0x73]=_P70;
  cpu->Inst[0x74]=_P70; cpu->Inst[0x75]=_P70; cpu->Inst[0x76]=_P70; cpu->Inst[0x77]=_P70;
  cpu->Inst[0x78]=_P70; cpu->Inst[0x79]=_P70; cpu->Inst[0x7a]=_P70; cpu->Inst[0x7b]=_P70;
  cpu->Inst[0x7c]=_P70; cpu->Inst[0x7d]=_P70; cpu->Inst[0x7e]=_P70; cpu->Inst[0x7f]=_P70;

  cpu->Inst[0x80]=_P80; cpu->Inst[0x81]=_P80; cpu->Inst[0x82]=_P80; cpu->Inst[0x83]=_P80;
  cpu->Inst[0x84]=_P80; cpu->Inst[0x85]=_P80; cpu->Inst[0x86]=_P80; cpu->Inst[0x87]=_P80;
  cpu->Inst[0x88]=_P80; cpu->Inst[0x89]=_P80; cpu->Inst[0x8a]=_P80; cpu->Inst[0x8b]=_P80;
  cpu->Inst[0x8c]=_P80; cpu->Inst[0x8d]=_P80; cpu->Inst[0x8e]=_P80; cpu->Inst[0x8f]=_P80;

  cpu->Inst[0x90]=_P90; cpu->Inst[0x91]=_P90; cpu->Inst[0x92]=_P90; cpu->Inst[0x93]=_P90;
  cpu->Inst[0x94]=_P90; cpu->Inst[0x95]=_P90; cpu->Inst[0x96]=_P90; cpu->Inst[0x97]=_P90;
  cpu->Inst[0x98]=_P90; cpu->Inst[0x99]=_P90; cpu->Inst[0x9a]=_P90; cpu->Inst[0x9b]=_P90;
  cpu->Inst[0x9c]=_P90; cpu->Inst[0x9d]=_P90; cpu->Inst[0x9e]=_P90; cpu->Inst[0x9f]=_P90;

  cpu->Inst[0xa0]=_PA0; cpu->Inst[0xa1]=_PA0; cpu->Inst[0xa2]=_PA0; cpu->Inst[0xa3]=_PA0;
  cpu->Inst[0xa4]=_PA0; cpu->Inst[0xa5]=_PA0; cpu->Inst[0xa6]=_PA0; cpu->Inst[0xa7]=_PA0;
  cpu->Inst[0xa8]=_PA0; cpu->Inst[0xa9]=_PA0; cpu->Inst[0xaa]=_PA0; cpu->Inst[0xab]=_PA0;
  cpu->Inst[0xac]=_PA0; cpu->Inst[0xad]=_PA0; cpu->Inst[0xae]=_PA0; cpu->Inst[0xaf]=_PA0;

  cpu->Inst[0xb0]=_PB0; cpu->Inst[0xb1]=_PB0; cpu->Inst[0xb2]=_PB0; cpu->Inst[0xb3]=_PB0;
  cpu->Inst[0xb4]=_PB0; cpu->Inst[0xb5]=_PB0; cpu->Inst[0xb6]=_PB0; cpu->Inst[0xb7]=_PB0;
  cpu->Inst[0xb8]=_PB0; cpu->Inst[0xb9]=_PB0; cpu->Inst[0xba]=_PB0; cpu->Inst[0xbb]=_PB0;
  cpu->Inst[0xbc]=_PB0; cpu->Inst[0xbd]=_PB0; cpu->Inst[0xbe]=_PB0; cpu->Inst[0xbf]=_PB0;

  cpu->Inst[0xc0]=_PC0; cpu->Inst[0xc1]=_PC0; cpu->Inst[0xc2]=_PC0; cpu->Inst[0xc3]=_PC0;
  cpu->Inst[0xc4]=_PC0; cpu->Inst[0xc5]=_PC0; cpu->Inst[0xc6]=_PC0; cpu->Inst[0xc7]=_PC0;
  cpu->Inst[0xc8]=_PC0; cpu->Inst[0xc9]=_PC0; cpu->Inst[0xca]=_PC0; cpu->Inst[0xcb]=_PC0;
  cpu->Inst[0xcc]=_PC0; cpu->Inst[0xcd]=_PC0; cpu->Inst[0xce]=_PC0; cpu->Inst[0xcf]=_PC0;

  cpu->Inst[0xd0]=_PD0; cpu->Inst[0xd1]=_PD1; cpu->Inst[0xd2]=_PD2; cpu->Inst[0xd3]=_PD3;
  cpu->Inst[0xd4]=_PD4; cpu->Inst[0xd5]=_PD5; cpu->Inst[0xd6]=_PD6; cpu->Inst[0xd7]=_PD7;
  cpu->Inst[0xd8]=_PD8; cpu->Inst[0xd9]=_PD9; cpu->Inst[0xda]=_PDA; cpu->Inst[0xdb]=_PDB;
  cpu->Inst[0xdc]=_PDC; cpu->Inst[0xdd]=_PDD; cpu->Inst[0xde]=_PDE; cpu->Inst[0xdf]=_PDF;

  cpu->Inst[0xe0]=_PE0; cpu->Inst[0xe1]=_PE1; cpu->Inst[0xe2]=_PE2; cpu->Inst[0xe3]=_PE3;
  cpu->Inst[0xe4]=_PE4; cpu->Inst[0xe5]=_PE5; cpu->Inst[0xe6]=_PE6; cpu->Inst[0xe7]=_PE7;
  cpu->Inst[0xe8]=_PE8; cpu->Inst[0xe9]=_PE9; cpu->Inst[0xea]=_PEA; cpu->Inst[0xeb]=_PEB;
  cpu->Inst[0xec]=_PEC; cpu->Inst[0xed]=_PED; cpu->Inst[0xee]=_PEE; cpu->Inst[0xef]=_PEF;

  cpu->Inst[0xf0]=_PF0; cpu->Inst[0xf1]=_PF1; cpu->Inst[0xf2]=_PF2; cpu->Inst[0xf3]=_PF3;
  cpu->Inst[0xf4]=_PF4; cpu->Inst[0xf5]=_PF5; cpu->Inst[0xf6]=_PF6; cpu->Inst[0xf7]=_PF7;
  cpu->Inst[0xf8]=_PF8; cpu->Inst[0xf9]=_PF9; cpu->Inst[0xfa]=_PFA; cpu->Inst[0xfb]=_PFB;
  cpu->Inst[0xfc]=_PFC; cpu->Inst[0xfd]=_PFD; cpu->Inst[0xfe]=_PFE; cpu->Inst[0xff]=_PFF;
  }

void cpu_reset(CPU* cpu) {
  cpu->halt = 0;
  cpu->stack[0] = 0;
  cpu->sp = 0;
  cpu->cm = 0;
  cpu->x2 = 0;
  cpu->x3 = 0;
  }

void cpu_cycle(CPU* cpu) {
  byte cmd;
  cpu->ts = 0;
  cmd = readRom(rom, cpu->stack[0]++);
  cpu->opr = (cmd >> 4);
  cpu->opa = (cmd & 0x0f);
  cpu->Inst[cmd](cpu);
  }

