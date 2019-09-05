# read program and store the internal representation in variable prog
prog = ReadAlphabets("./OSP.ab");
 
# store string (corresponding to system name) to variable system
system = "OSP";
 
# store output directory name to variable outDir
outDir = "./test-out/"+system;
 
# print out the program using Show syntax
Show(prog);
 
# print out the program using AShow syntax
AShow(prog);
 
# prints out the AST of the program (commented out)
#PrintAST(prog);
 
# generate codes (this is demand-driven, memoized code)
generateWriteC(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);