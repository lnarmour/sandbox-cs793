prog = ReadAlphabets("bpmax_streamlined.ab");
system = "bpmax";

#NormalizeReduction(prog, system, "FTable");
AShow(prog, system);
CheckProgram(prog);
ASave(prog, "bpmax_asave.ab");
Normalize(prog);  # This doesn't work. Need to ask Dr. Rajopadhye why ???

#ASave(prog, "bpmax_asave.ab");


outDir = "./out";
CheckProgram(prog);
generateWriteC(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);
generateVerificationCode(prog, system, outDir);

#outDir = "./../../src/progs/bpmax/base_schedule/autogen";
#setSpaceTimeMap(prog, system, "S1", "(i,j -> 0,j-i,i,0,0)");
#setSpaceTimeMap(prog, system, "S2", "(i,j -> 0,j-i,i,0,0)");
#setSpaceTimeMap(prog, system, "FTable", "(i1,j1,i2,j2-> 1, j1-i1,j2-i2,i1,i2)");
#setStatementOrdering(prog, system, "S1", "FTable");
#setStatementOrdering(prog, system, "S2", "FTable");
#setParallel(prog, system, "", "3");
#generateScheduledCode(prog, system, outDir);
#generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
#generateVerificationCode(prog, system, outDir);

outDir = "./out2";
setSpaceTimeMap(prog, system, "S1", "(i,j -> 0, M-i,j,0,0)");
setSpaceTimeMap(prog, system, "S2", "(i,j -> 0, N-i,j,0,0)");
setSpaceTimeMap(prog, system, "FTable", "(i1,j1,i2,j2 - > 1, M-i1,j1,j2-i2,i2)");
setParallel(prog, system, "", "4");
setStatementOrdering(prog, system, "S1", "FTable");
setStatementOrdering(prog, system, "S2", "FTable");
generateScheduledCode(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);
generateVerificationCode(prog, system, outDir);





