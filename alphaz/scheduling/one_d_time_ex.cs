prog = ReadAlphabets("./one_d_time_ex.ab");
system = "ONED";
outDir = "./out/";


generateWriteC(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);