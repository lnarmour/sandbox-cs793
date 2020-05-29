prog1 = ReadAlphabets("./MM1.ab");
#prog2 = ReadAlphabets("./MM2.ab");
sys1 = "MM1";
sys2 = "MM2";
out1 = "./out1/";
out2 = "./out2/";

# program 1
setSpaceTimeMap(prog1, sys1, "C", "(i,j,k -> 0,i,j,k)");   # throws exception
#setSpaceTimeMap(prog1, sys1, "D", "(i,j,k -> 1,i,j,k)");   # throws exception
generateScheduledCode(prog1, sys1, out1);

# program 2
#setMemoryMap(prog2, sys2, "C", "C", "(i,j,k -> i,j)");
#setMemoryMap(prog2, sys2, "D", "D", "(i,j,k -> i,j)");
#setSpaceTimeMap(prog2, sys2, "C", "(i,j,k -> 0,i,j,k)");
#setSpaceTimeMap(prog2, sys2, "D", "(i,j,k -> 1,i,j,k)");
#generateScheduledCode(prog2, sys2, out2);
