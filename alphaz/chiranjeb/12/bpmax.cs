prog = ReadAlphabets("bpmax.ab");
system = "bpmax";

NormalizeReduction(prog, system, "FTable");
AShow(prog, system);
CheckProgram(prog);

Normalize(prog);


outDir = "out";
setSpaceTimeMap(prog, system, "S1", "(i,j -> 0, j-i,i,0,0,0,0)");
setSpaceTimeMap(prog, system, "S2", "(i,j -> 0, j-i,i,0,0,0,0)");

## Base schedule. However, specify 6D schedule
setSpaceTimeMap(prog, system, "FTable",    "(i1,j1,i2,j2       -> 1, j1-i1,  j2-i2, i1, i2, j1,   j2)");
setSpaceTimeMap(prog, system, "NR_FTable", "(i1,j1,i2,j2,k1,k2 -> 1, j1-i1,  j2-i2, i1, i2, k1,   k2)",
                                           "(i1,j1,i2,j2       -> 1, j1-i1,  j2-i2, i1, i2, i1-1, i2-1)");
generateScheduledCode(prog, system, outDir);
