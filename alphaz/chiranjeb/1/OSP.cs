prog = ReadAlphabets("OSP.ab");
system = "OSP";
outDir = "minus_d_kj";

CheckProgram(prog);
AShow(prog, system);
NormalizeReduction(prog, system, "C");
RenameVariable(prog, system, "NR_C", "Main");
Normalize(prog);
CheckProgram(prog);

# -i,k,j
# Main = reduction variable, C = full answer memory space
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,k,j)", "(i,j->N-i,i-1,j)");
#setSpaceTimeMap(prog, system, "C", "(i,j->N-i,j,j)");
#setParallel(prog, system, "", "2");
#setStatementOrdering(prog, system, "Main", "C");
#setMemorySpace(prog, system, "C", "C, Main");
#setMemoryMap(prog, system, "Main", system, "(i,j->N-i,i-1,j)");
#setMemoryMap(prog, system, "C", system, "(i,j->N-i,j,j)");

# d,k,j
setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,k,j)", "(i,j->j-i,i-1,j)");
setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j)");
#setParallel(prog, system, "", "1");
generateScheduledCode(prog, system, outDir);
generateWrapper(prog, system, outDir);

# d,-k,j
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,k-i,j)", "(i,j->j-i,-1,j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,N-i,j)");
#setParallel(prog, system, "", "1");
#generateScheduledCode(prog, system, outDir);
#generateWrapper(prog, system, outDir);


#setMemorySpace(prog, system, "C", "C, Main");
#generateScheduledCode(prog, system, outDir+"/memSpace"); # Default maping, (i,j -> i,j), does NOT work.

#AShow(prog, system);

#generateVerificationCode(prog, system, outDir);
#generateWriteC(prog, system, outDir);
#generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
#generateScheduledCode(prog, system, outDir);