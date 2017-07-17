#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "decode.h"
// #include "disasm.cc"
#include "disasm.h"
// using namespace std;

int main()
{

	int xlen=32;
	insn_bits_t instruction;
	disassembler_t disassembler(xlen);
	// disassembler_t * disassembler = new disassembler_t(xlen);
    scanf("%lux",&instruction);

    instruction = ((instruction>>24)&0xff) | // move byte 3 to byte 0
                    ((instruction<<8)&0xff0000) | // move byte 1 to byte 2
                    ((instruction>>8)&0xff00) | // move byte 2 to byte 1
                    ((instruction<<24)&0xff000000); // byte 0 to byte 3

	insn_t insn(instruction);

	// std::string str = disassembler.disassemble(insn);

    fprintf(stderr, "%s\n", disassembler.disassemble(insn).c_str());
    // fprintf(stderr, "%s\n", str.c_str());

    // delete(disassembler);
    return 0;
}