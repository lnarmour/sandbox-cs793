prog = ReadAlphabets("OSP.ab");
system = "OSP";
outDir = "minus_d_kj";

CheckProgram(prog);
AShow(prog, system);
PrintAST(prog);

setSpaceTimeMap(prog, system, "C", "(i,j,k->i,k,j)", "(i,j->i,j,0)");

CheckProgram(prog);
AShow(prog, system);
PrintAST(prog);

print("------------------");
generateScheduledCode(prog, system, outDir);
