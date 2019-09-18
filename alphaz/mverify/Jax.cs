prog = ReadAlphabets("./Jax.ab");
system = "Jax";
outDir = "./out/";
 
#generateWriteC(prog, system, outDir);
generateScheduledCode(prog, system, outDir);
generateVerificationCode(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);