#include "header.h"

word Disassem(word addr, char* dest) {
  char tmp[80];
  char tmp2[16];
  sprintf(dest,"%04x: %02x ", addr, rom[addr]);
//         sprintf(tmp,"%02x           NEG    <$%02x",rom[addr+1],rom[addr+1]);
  switch (rom[addr]) {
    case 0x00:
         sprintf(tmp,"             NOP");
         addr += 1;
         break;
    case 0x10:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x11:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x12:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x13:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x14:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x15:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x16:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x17:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x18:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x19:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x1a:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x1b:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x1c:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x1d:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x1e:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x1f:
         sprintf(tmp,"%02x           JCN    ",rom[addr+1]);
         if (rom[addr] & 0x8) strcat(tmp,"N");
         if (rom[addr] & 0x4) strcat(tmp,"Z");
         if (rom[addr] & 0x2) strcat(tmp,"C");
         if (rom[addr] & 0x1) strcat(tmp,"T");
         sprintf(tmp2,",%02x",rom[addr+1]);
         strcat(tmp,tmp2);
         addr += 2;
         break;
    case 0x20:
         sprintf(tmp,"%02x           FIM    $0,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x21:
         sprintf(tmp,"             SRC    $0");
         addr += 1;
         break;
    case 0x22:
         sprintf(tmp,"%02x           FIM    $1,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x23:
         sprintf(tmp,"             SRC    $1");
         addr += 1;
         break;
    case 0x24:
         sprintf(tmp,"%02x           FIM    $2,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x25:
         sprintf(tmp,"             SRC    $2");
         addr += 1;
         break;
    case 0x26:
         sprintf(tmp,"%02x           FIM    $3,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x27:
         sprintf(tmp,"             SRC    $3");
         addr += 1;
         break;
    case 0x28:
         sprintf(tmp,"%02x           FIM    $4,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x29:
         sprintf(tmp,"             SRC    $4");
         addr += 1;
         break;
    case 0x2a:
         sprintf(tmp,"%02x           FIM    $5,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x2b:
         sprintf(tmp,"             SRC    $5");
         addr += 1;
         break;
    case 0x2c:
         sprintf(tmp,"%02x           FIM    $6,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x2d:
         sprintf(tmp,"             SRC    $6");
         addr += 1;
         break;
    case 0x2e:
         sprintf(tmp,"%02x           FIM    $7,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x2f:
         sprintf(tmp,"             SRC    $7");
         addr += 1;
         break;
    case 0x30:
         sprintf(tmp,"             FIN    $0");
         addr += 1;
         break;
    case 0x31:
         sprintf(tmp,"             JIN    $0");
         addr += 1;
         break;
    case 0x32:
         sprintf(tmp,"             FIN    $1");
         addr += 1;
         break;
    case 0x33:
         sprintf(tmp,"             JIN    $1");
         addr += 1;
         break;
    case 0x34:
         sprintf(tmp,"             FIN    $2");
         addr += 1;
         break;
    case 0x35:
         sprintf(tmp,"             JIN    $2");
         addr += 1;
         break;
    case 0x36:
         sprintf(tmp,"             FIN    $3");
         addr += 1;
         break;
    case 0x37:
         sprintf(tmp,"             JIN    $3");
         addr += 1;
         break;
    case 0x38:
         sprintf(tmp,"             FIN    $4");
         addr += 1;
         break;
    case 0x39:
         sprintf(tmp,"             JIN    $4");
         addr += 1;
         break;
    case 0x3a:
         sprintf(tmp,"             FIN    $5");
         addr += 1;
         break;
    case 0x3b:
         sprintf(tmp,"             JIN    $5");
         addr += 1;
         break;
    case 0x3c:
         sprintf(tmp,"             FIN    $6");
         addr += 1;
         break;
    case 0x3d:
         sprintf(tmp,"             JIN    $6");
         addr += 1;
         break;
    case 0x3e:
         sprintf(tmp,"             FIN    $7");
         addr += 1;
         break;
    case 0x3f:
         sprintf(tmp,"             JIN    $7");
         addr += 1;
         break;
    case 0x40:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x41:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x42:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x43:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x44:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x45:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x46:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x47:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x48:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x49:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x4a:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x4b:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x4c:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x4d:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x4e:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x4f:
         sprintf(tmp,"%02x           JUN    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x50:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x51:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x52:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x53:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x54:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x55:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x56:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x57:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x58:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x59:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x5a:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x5b:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x5c:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x5d:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x5e:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x5f:
         sprintf(tmp,"%02x           JMS    $%02x%02x",rom[addr+1], rom[addr] & 0xf, rom[addr+1]);
         addr += 2;
         break;
    case 0x60:
         sprintf(tmp,"             INC    $0");
         addr += 1;
         break;
    case 0x61:
         sprintf(tmp,"             INC    $1");
         addr += 1;
         break;
    case 0x62:
         sprintf(tmp,"             INC    $2");
         addr += 1;
         break;
    case 0x63:
         sprintf(tmp,"             INC    $3");
         addr += 1;
         break;
    case 0x64:
         sprintf(tmp,"             INC    $4");
         addr += 1;
         break;
    case 0x65:
         sprintf(tmp,"             INC    $5");
         addr += 1;
         break;
    case 0x66:
         sprintf(tmp,"             INC    $6");
         addr += 1;
         break;
    case 0x67:
         sprintf(tmp,"             INC    $7");
         addr += 1;
         break;
    case 0x68:
         sprintf(tmp,"             INC    $8");
         addr += 1;
         break;
    case 0x69:
         sprintf(tmp,"             INC    $9");
         addr += 1;
         break;
    case 0x6a:
         sprintf(tmp,"             INC    $A");
         addr += 1;
         break;
    case 0x6b:
         sprintf(tmp,"             INC    $B");
         addr += 1;
         break;
    case 0x6c:
         sprintf(tmp,"             INC    $C");
         addr += 1;
         break;
    case 0x6d:
         sprintf(tmp,"             INC    $D");
         addr += 1;
         break;
    case 0x6e:
         sprintf(tmp,"             INC    $E");
         addr += 1;
         break;
    case 0x6f:
         sprintf(tmp,"             INC    $F");
         addr += 1;
         break;
    case 0x70:
         sprintf(tmp,"%02x           ISZ    $0,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x71:
         sprintf(tmp,"%02x           ISZ    $1,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x72:
         sprintf(tmp,"%02x           ISZ    $2,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x73:
         sprintf(tmp,"%02x           ISZ    $3,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x74:
         sprintf(tmp,"%02x           ISZ    $4,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x75:
         sprintf(tmp,"%02x           ISZ    $5,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x76:
         sprintf(tmp,"%02x           ISZ    $6,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x77:
         sprintf(tmp,"%02x           ISZ    $7,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x78:
         sprintf(tmp,"%02x           ISZ    $8,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x79:
         sprintf(tmp,"%02x           ISZ    $9,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x7a:
         sprintf(tmp,"%02x           ISZ    $A,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x7b:
         sprintf(tmp,"%02x           ISZ    $B,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x7c:
         sprintf(tmp,"%02x           ISZ    $C,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x7d:
         sprintf(tmp,"%02x           ISZ    $D,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x7e:
         sprintf(tmp,"%02x           ISZ    $E,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x7f:
         sprintf(tmp,"%02x           ISZ    $F,%02x",rom[addr+1],rom[addr+1]);
         addr += 2;
         break;
    case 0x80:
         sprintf(tmp,"             ADD    $0");
         addr += 1;
         break;
    case 0x81:
         sprintf(tmp,"             ADD    $1");
         addr += 1;
         break;
    case 0x82:
         sprintf(tmp,"             ADD    $2");
         addr += 1;
         break;
    case 0x83:
         sprintf(tmp,"             ADD    $3");
         addr += 1;
         break;
    case 0x84:
         sprintf(tmp,"             ADD    $4");
         addr += 1;
         break;
    case 0x85:
         sprintf(tmp,"             ADD    $5");
         addr += 1;
         break;
    case 0x86:
         sprintf(tmp,"             ADD    $6");
         addr += 1;
         break;
    case 0x87:
         sprintf(tmp,"             ADD    $7");
         addr += 1;
         break;
    case 0x88:
         sprintf(tmp,"             ADD    $8");
         addr += 1;
         break;
    case 0x89:
         sprintf(tmp,"             ADD    $9");
         addr += 1;
         break;
    case 0x8a:
         sprintf(tmp,"             ADD    $A");
         addr += 1;
         break;
    case 0x8b:
         sprintf(tmp,"             ADD    $B");
         addr += 1;
         break;
    case 0x8c:
         sprintf(tmp,"             ADD    $C");
         addr += 1;
         break;
    case 0x8d:
         sprintf(tmp,"             ADD    $D");
         addr += 1;
         break;
    case 0x8e:
         sprintf(tmp,"             ADD    $E");
         addr += 1;
         break;
    case 0x8f:
         sprintf(tmp,"             ADD    $F");
         addr += 1;
         break;
    case 0x90:
         sprintf(tmp,"             SUB    $0");
         addr += 1;
         break;
    case 0x91:
         sprintf(tmp,"             SUB    $1");
         addr += 1;
         break;
    case 0x92:
         sprintf(tmp,"             SUB    $2");
         addr += 1;
         break;
    case 0x93:
         sprintf(tmp,"             SUB    $3");
         addr += 1;
         break;
    case 0x94:
         sprintf(tmp,"             SUB    $4");
         addr += 1;
         break;
    case 0x95:
         sprintf(tmp,"             SUB    $5");
         addr += 1;
         break;
    case 0x96:
         sprintf(tmp,"             SUB    $6");
         addr += 1;
         break;
    case 0x97:
         sprintf(tmp,"             SUB    $7");
         addr += 1;
         break;
    case 0x98:
         sprintf(tmp,"             SUB    $8");
         addr += 1;
         break;
    case 0x99:
         sprintf(tmp,"             SUB    $9");
         addr += 1;
         break;
    case 0x9a:
         sprintf(tmp,"             SUB    $A");
         addr += 1;
         break;
    case 0x9b:
         sprintf(tmp,"             SUB    $B");
         addr += 1;
         break;
    case 0x9c:
         sprintf(tmp,"             SUB    $C");
         addr += 1;
         break;
    case 0x9d:
         sprintf(tmp,"             SUB    $D");
         addr += 1;
         break;
    case 0x9e:
         sprintf(tmp,"             SUB    $E");
         addr += 1;
         break;
    case 0x9f:
         sprintf(tmp,"             SUB    $F");
         addr += 1;
         break;
    case 0xa0:
         sprintf(tmp,"             LD     $0");
         addr += 1;
         break;
    case 0xa1:
         sprintf(tmp,"             LD     $1");
         addr += 1;
         break;
    case 0xa2:
         sprintf(tmp,"             LD     $2");
         addr += 1;
         break;
    case 0xa3:
         sprintf(tmp,"             LD     $3");
         addr += 1;
         break;
    case 0xa4:
         sprintf(tmp,"             LD     $4");
         addr += 1;
         break;
    case 0xa5:
         sprintf(tmp,"             LD     $5");
         addr += 1;
         break;
    case 0xa6:
         sprintf(tmp,"             LD     $6");
         addr += 1;
         break;
    case 0xa7:
         sprintf(tmp,"             LD     $7");
         addr += 1;
         break;
    case 0xa8:
         sprintf(tmp,"             LD     $8");
         addr += 1;
         break;
    case 0xa9:
         sprintf(tmp,"             LD     $9");
         addr += 1;
         break;
    case 0xaa:
         sprintf(tmp,"             LD     $A");
         addr += 1;
         break;
    case 0xab:
         sprintf(tmp,"             LD     $B");
         addr += 1;
         break;
    case 0xac:
         sprintf(tmp,"             LD     $C");
         addr += 1;
         break;
    case 0xad:
         sprintf(tmp,"             LD     $D");
         addr += 1;
         break;
    case 0xae:
         sprintf(tmp,"             LD     $E");
         addr += 1;
         break;
    case 0xaf:
         sprintf(tmp,"             LD     $F");
         addr += 1;
         break;
    case 0xb0:
         sprintf(tmp,"             XCH    $0");
         addr += 1;
         break;
    case 0xb1:
         sprintf(tmp,"             XCH    $1");
         addr += 1;
         break;
    case 0xb2:
         sprintf(tmp,"             XCH    $2");
         addr += 1;
         break;
    case 0xb3:
         sprintf(tmp,"             XCH    $3");
         addr += 1;
         break;
    case 0xb4:
         sprintf(tmp,"             XCH    $4");
         addr += 1;
         break;
    case 0xb5:
         sprintf(tmp,"             XCH    $5");
         addr += 1;
         break;
    case 0xb6:
         sprintf(tmp,"             XCH    $6");
         addr += 1;
         break;
    case 0xb7:
         sprintf(tmp,"             XCH    $7");
         addr += 1;
         break;
    case 0xb8:
         sprintf(tmp,"             XCH    $8");
         addr += 1;
         break;
    case 0xb9:
         sprintf(tmp,"             XCH    $9");
         addr += 1;
         break;
    case 0xba:
         sprintf(tmp,"             XCH    $A");
         addr += 1;
         break;
    case 0xbb:
         sprintf(tmp,"             XCH    $B");
         addr += 1;
         break;
    case 0xbc:
         sprintf(tmp,"             XCH    $C");
         addr += 1;
         break;
    case 0xbd:
         sprintf(tmp,"             XCH    $D");
         addr += 1;
         break;
    case 0xbe:
         sprintf(tmp,"             XCH    $E");
         addr += 1;
         break;
    case 0xbf:
         sprintf(tmp,"             XCH    $F");
         addr += 1;
         break;
    case 0xc0:
         sprintf(tmp,"             BBL    $0");
         addr += 1;
         break;
    case 0xc1:
         sprintf(tmp,"             BBL    $1");
         addr += 1;
         break;
    case 0xc2:
         sprintf(tmp,"             BBL    $2");
         addr += 1;
         break;
    case 0xc3:
         sprintf(tmp,"             BBL    $3");
         addr += 1;
         break;
    case 0xc4:
         sprintf(tmp,"             BBL    $4");
         addr += 1;
         break;
    case 0xc5:
         sprintf(tmp,"             BBL    $5");
         addr += 1;
         break;
    case 0xc6:
         sprintf(tmp,"             BBL    $6");
         addr += 1;
         break;
    case 0xc7:
         sprintf(tmp,"             BBL    $7");
         addr += 1;
         break;
    case 0xc8:
         sprintf(tmp,"             BBL    $8");
         addr += 1;
         break;
    case 0xc9:
         sprintf(tmp,"             BBL    $9");
         addr += 1;
         break;
    case 0xca:
         sprintf(tmp,"             BBL    $A");
         addr += 1;
         break;
    case 0xcb:
         sprintf(tmp,"             BBL    $B");
         addr += 1;
         break;
    case 0xcc:
         sprintf(tmp,"             BBL    $C");
         addr += 1;
         break;
    case 0xcd:
         sprintf(tmp,"             BBL    $D");
         addr += 1;
         break;
    case 0xce:
         sprintf(tmp,"             BBL    $E");
         addr += 1;
         break;
    case 0xcf:
         sprintf(tmp,"             BBL    $F");
         addr += 1;
         break;
    case 0xd0:
         sprintf(tmp,"             LDM    $0");
         addr += 1;
         break;
    case 0xd1:
         sprintf(tmp,"             LDM    $1");
         addr += 1;
         break;
    case 0xd2:
         sprintf(tmp,"             LDM    $2");
         addr += 1;
         break;
    case 0xd3:
         sprintf(tmp,"             LDM    $3");
         addr += 1;
         break;
    case 0xd4:
         sprintf(tmp,"             LDM    $4");
         addr += 1;
         break;
    case 0xd5:
         sprintf(tmp,"             LDM    $5");
         addr += 1;
         break;
    case 0xd6:
         sprintf(tmp,"             LDM    $6");
         addr += 1;
         break;
    case 0xd7:
         sprintf(tmp,"             LDM    $7");
         addr += 1;
         break;
    case 0xd8:
         sprintf(tmp,"             LDM    $8");
         addr += 1;
         break;
    case 0xd9:
         sprintf(tmp,"             LDM    $9");
         addr += 1;
         break;
    case 0xda:
         sprintf(tmp,"             LDM    $A");
         addr += 1;
         break;
    case 0xdb:
         sprintf(tmp,"             LDM    $B");
         addr += 1;
         break;
    case 0xdc:
         sprintf(tmp,"             LDM    $C");
         addr += 1;
         break;
    case 0xdd:
         sprintf(tmp,"             LDM    $D");
         addr += 1;
         break;
    case 0xde:
         sprintf(tmp,"             LDM    $E");
         addr += 1;
         break;
    case 0xdf:
         sprintf(tmp,"             LDM    $F");
         addr += 1;
         break;
    case 0xe0:
         sprintf(tmp,"             WRM");
         addr += 1;
         break;
    case 0xe1:
         sprintf(tmp,"             WMP");
         addr += 1;
         break;
    case 0xe2:
         sprintf(tmp,"             WRR");
         addr += 1;
         break;
    case 0xe3:
         break;
    case 0xe4:
         sprintf(tmp,"             WR0");
         addr += 1;
         break;
    case 0xe5:
         sprintf(tmp,"             WR1");
         addr += 1;
         break;
    case 0xe6:
         sprintf(tmp,"             WR2");
         addr += 1;
         break;
    case 0xe7:
         sprintf(tmp,"             WR3");
         addr += 1;
         break;
    case 0xe8:
         sprintf(tmp,"             SBM");
         addr += 1;
         break;
    case 0xe9:
         sprintf(tmp,"             RDM");
         addr += 1;
         break;
    case 0xea:
         sprintf(tmp,"             RDR");
         addr += 1;
         break;
    case 0xeb:
         sprintf(tmp,"             ADM");
         addr += 1;
         break;
    case 0xec:
         sprintf(tmp,"             RD0");
         addr += 1;
         break;
    case 0xed:
         sprintf(tmp,"             RD1");
         addr += 1;
         break;
    case 0xee:
         sprintf(tmp,"             RD2");
         addr += 1;
         break;
    case 0xef:
         sprintf(tmp,"             RD3");
         addr += 1;
         break;
    case 0xf0:
         sprintf(tmp,"             CLB");
         addr += 1;
         break;
    case 0xf1:
         sprintf(tmp,"             CLC");
         addr += 1;
         break;
    case 0xf2:
         sprintf(tmp,"             IAC");
         addr += 1;
         break;
    case 0xf3:
         sprintf(tmp,"             CMC");
         addr += 1;
         break;
    case 0xf4:
         sprintf(tmp,"             CMA");
         addr += 1;
         break;
    case 0xf5:
         sprintf(tmp,"             RAL");
         addr += 1;
         break;
    case 0xf6:
         sprintf(tmp,"             RAR");
         addr += 1;
         break;
    case 0xf7:
         sprintf(tmp,"             TCC");
         addr += 1;
         break;
    case 0xf8:
         sprintf(tmp,"             DAC");
         addr += 1;
         break;
    case 0xf9:
         sprintf(tmp,"             TCS");
         addr += 1;
         break;
    case 0xfa:
         sprintf(tmp,"             STC");
         addr += 1;
         break;
    case 0xfb:
         sprintf(tmp,"             DAA");
         addr += 1;
         break;
    case 0xfc:
         sprintf(tmp,"             KBP");
         addr += 1;
         break;
    case 0xfd:
         sprintf(tmp,"             DCL");
         addr += 1;
         break;
    default: 
         sprintf(tmp,"             DB   %02x",rom[addr]); addr++; break;
    }
  strcat(dest, tmp);
  return addr;
  }

