prog = ReadAlphabets("./bpmax.ab");
system = "bpmax";

outDir = "out";

setSpaceTimeMap(prog, system, "C", "(i,j,k,l,r1,r2 -> i,j,r1,r2,k,l)", "(i,j,k,l -> i,j,0,0,k,l)");

setParallel(prog, system, "", "4");

generateScheduledCode(prog, system, outDir);