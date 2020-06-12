prog = ReadAlphabets("norm.ab");
system = "normbug";

Normalize(prog);

AShow(prog);
CheckProgram(prog);

generateWriteC(prog, system, "out");

