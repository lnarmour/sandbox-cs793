prog = ReadAlphabets("./star.ab");
system = "star";

outDir = "out";

setMemoryMap(prog, system, "X", "X", "(t,i,j -> t,i,j)", "2,,");

generateScheduledCode(prog, system, outDir);
generateVerificationCode(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);