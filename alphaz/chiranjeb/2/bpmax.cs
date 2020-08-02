prog = ReadAlphabets("./bpmax.ab");
system = "bpmax";

outDir = "out";

setSpaceTimeMap(prog, system, "FMIN", "(i,j,k -> 0,i,k,j)", "(i,j -> 0,i,0,j)");
setSpaceTimeMap(prog, system, "FMAX", "(i,j,k -> 0,i,k,j)", "(i,j -> 0,i,0,j)");
setSpaceTimeMap(prog, system, "DMIN", "(i,j,k -> 0,i,k,j)", "(i,j -> 0,i,0,j)");
setSpaceTimeMap(prog, system, "DMAX", "(i,j,k -> 0,i,k,j)", "(i,j -> 0,i,0,j)");

AShow(prog);

generateScheduledCode(prog, system, outDir);