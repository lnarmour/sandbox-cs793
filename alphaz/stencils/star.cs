prog = ReadAlphabets("./star.ab");
system = "star";

outDir = "out";

setMemoryMap(prog, system, "X", "X", "(t,i,j -> t,i,j)", "2,,");
setMemorySpace(prog, system, "X_temp", "X");

generateScheduledCode(prog, system, outDir);
generateVerificationCode(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);