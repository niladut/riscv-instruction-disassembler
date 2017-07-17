disassembler: disassembler.cc disasm.cc regnames.cc
	g++ -std=c++11 -o disasm disassembler.cc disasm.cc regnames.cc -I .
