prog = ReadAlphabets("./sched0.ab");
system = "Sched0";
outDir = "./out/";


generateWriteC(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);