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
	// disassembler_t disassembler(xlen);
	
    disassembler_t * disassembler = new disassembler_t(xlen);
    
    while(scanf("%lx",&instruction))
    {
        // switch((char)instruction)
        // {
        //     case 'q':
        //         delete(disassembler);
        //         return 0;
        //         break;
        //     case 'h':
        //         fprintf(stdout, "Command Help\n\n");
        //         fprintf(stdout, "h\t:: Display this Command Help.\n");
        //         fprintf(stdout, "q\t:: Quit.\n");
        //         break;
        // }

    	insn_t insn(instruction);

    	std::string str = disassembler->disassemble(insn);

        // fprintf(stderr, "%s\n", disassembler.disassemble(insn).c_str());
        fprintf(stdout, "%lx\t:: %s\n", instruction,str.c_str());
        // fprintf(stderr, "%lx\t:: %s\n", instruction,str.c_str());
    }
    delete(disassembler);
    return 0;
}