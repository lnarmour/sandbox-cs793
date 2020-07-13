prog = ReadAlphabets("./bpmax.ab");
system = "bpmax";

outDir = "out";

setMemoryMap(prog, system, "C",   "D",   "(i,j -> i+7,j+17)");

#setSpaceTimeMap(prog, system, "C", "(i,j,k -> i,k,j)", "(i,j -> i,0,j)");
setSpaceTimeMap(prog, system, "C", "(i,j -> N+1,i,j)");
setSpaceTimeMap(prog, system, "D", "(i,j -> N+1,i,j)");

generateScheduledCode(prog, system, outDir);