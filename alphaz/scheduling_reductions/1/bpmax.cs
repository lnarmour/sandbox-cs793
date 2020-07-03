prog = ReadAlphabets("./bpmax.ab");
system = "bpmax";

setSpaceTimeMap(prog, system, "C", "(aa,bb,cc -> 0,0,aa,bb,cc)", "(xx,yy -> xx,0,0,10-yy-xx,0)");

generateScheduledCode(prog, system, "out");