prog = ReadAlphabets("./bpmax.ab");
system = "bpmax";

outDir = "out";

setSpaceTimeMap(prog, system, "FMIN", "(i,j -> 0,i,j)");
setSpaceTimeMap(prog, system, "FMAX", "(i,j -> 0,i,j)");
setSpaceTimeMap(prog, system, "DMIN", "(i,j -> 0,i,j)");
setSpaceTimeMap(prog, system, "DMAX", "(i,j -> 0,i,j)");

AShow(prog);

#generateScheduledCode(prog, system, outDir);
generateWriteC(prog, system, outDir);