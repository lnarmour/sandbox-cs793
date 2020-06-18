prog = ReadAlphabets("./bpmax.ab");
system = "bpmax";

outDir = "out";
setSpaceTimeMap(prog, system, "C", "(i,j -> 0,0,i,j)");
setSpaceTimeMap(prog, system, "D", "(i,j,k -> 1,i+j+k,k,j)", "(i,j -> 1,i,0,j)");

generateScheduledCode(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);