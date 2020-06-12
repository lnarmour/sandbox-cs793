prog = ReadAlphabets("./bpmax.ab");
system = "bpmax";
outDir = "out";

NormalizeReduction(prog, system, "FTable");
setSpaceTimeMap(prog, system, "NR_FTable", "(i1,j1,i2,j2,k1,k2 -> i1,j1,i2,j2,k1,k2)",
                                           "(i1,j1,i2,j2       -> i1,j1,i2,j2)");
SerializeReduction(prog, system, "NR_FTable", "(i1,j1,i2,j2,k1,k2 -> i1,j1,i2,j2,k1,k2)");
AShow(prog);
ASaveSystem(prog, system, "bpmax_intermediate.ab");
# if the file is empty for whatever reason, then just copy/paste from the previous AShow output
# You also need to manually add the external function declarations (e_intra_score & e_inter_score) back in
# since ASave doesn't save those. After this is done, just comment out the ASave call.



prog = ReadAlphabets("bpmax_intermediate.ab");
AShow(prog);

setSpaceTimeMap(prog, system, "S1", "(i,j -> 0, j-i,i,0,0,0,0)");
setSpaceTimeMap(prog, system, "S2", "(i,j -> 0, j-i,i,0,0,0,0)");

setMemoryMap(prog, system, "NR_FTable_Alpha_Init", "NR_FTable", "(i1,j1,i2,j2       -> i1,j1,i2,j2)");
setMemoryMap(prog, system, "_serNR_FTable",        "NR_FTable", "(i1,j1,i2,j2,k1,k2 -> i1,j1,i2,j2)");

setSpaceTimeMap(prog, system, "FTable",                "(i1,j1,i2,j2       -> 1, j1-i1,  j2-i2, i1, i2, j1,   j2)");
setSpaceTimeMap(prog, system, "NR_FTable",             "(i1,j1,i2,j2       -> 1, j1-i1,  j2-i2, i1, i2, M,    N)");
setSpaceTimeMap(prog, system, "_serNR_FTable",         "(i1,j1,i2,j2,k1,k2 -> 1, j1-i1,  j2-i2, i1, i2, k1,   k2)");
setSpaceTimeMap(prog, system, "NR_FTable_Alpha_Init",  "(i1,j1,i2,j2       -> 1, j1-i1,  j2-i2, i1, i2, i1-1, i2-1)");

generateScheduledCode(prog, system, outDir);
