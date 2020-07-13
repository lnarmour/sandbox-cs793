prog = ReadAlphabets("bpmax_double.ab");
system = "bpmax";

NormalizeReduction(prog, system, "FTable");
AShow(prog, system);
CheckProgram(prog);
#ASave(prog, "bpmax_asave.ab");
Normalize(prog);  # This doesn't work. Need to ask Dr. Rajopadhye why ???

## Base schedule. However, specify 6D schedule
#outDir = "./../../src/progs/bpmax/schedule_6d/base/autogen";
#setStatementOrdering(prog, system, "S1", "FTable");
#setStatementOrdering(prog, system, "S2", "FTable");
#setStatementOrdering(prog, system, "S1", "NR_FTable");
#setStatementOrdering(prog, system, "S2", "NR_FTable");
#setStatementOrdering(prog, system, "S1", "NR_FTable_1");
#setStatementOrdering(prog, system, "S2", "NR_FTable_1");
#setStatementOrdering(prog, system, "S1", "NR_FTable_2");
#setStatementOrdering(prog, system, "S2", "NR_FTable_2");
#setStatementOrdering(prog, system, "S1", "NR_FTable_3");
#setStatementOrdering(prog, system, "S2", "NR_FTable_3");
#setStatementOrdering(prog, system, "S1", "NR_FTable_4");
#setStatementOrdering(prog, system, "S2", "NR_FTable_4");
#setStatementOrdering(prog, system, "NR_FTable",   "FTable");
#setStatementOrdering(prog, system, "NR_FTable_1", "FTable");
#setStatementOrdering(prog, system, "NR_FTable_2", "FTable");
#setStatementOrdering(prog, system, "NR_FTable_3", "FTable");
#setStatementOrdering(prog, system, "NR_FTable_4", "FTable");
#setStatementOrdering(prog, system, "NR_FTable", "NR_FTable_1");
#setStatementOrdering(prog, system, "NR_FTable", "NR_FTable_2");
#setStatementOrdering(prog, system, "NR_FTable", "NR_FTable_3");
#setStatementOrdering(prog, system, "NR_FTable", "NR_FTable_4");
#setSpaceTimeMap(prog, system, "S1", "(i,j -> -100, 0,0,0, j-i,i)");
#setSpaceTimeMap(prog, system, "S2", "(i,j -> -100, 0,0,0, j-i,i)");
#setSpaceTimeMap(prog, system, "FTable",    "(i1,j1,i2,j2       -> j1-i1,  j2-i2, i1, i2, j1,   j2)");
#setSpaceTimeMap(prog, system, "NR_FTable", "(i1,j1,i2,j2,k1,k2 -> j1-i1,  j2-i2, i1, i2, k1,   k2)", 
#                                           "(i1,j1,i2,j2       -> j1-i1,  j2-i2, i1, i2, i1-1, i2-1)");
#setSpaceTimeMap(prog, system, "NR_FTable_1", "(i1,j1,i2,j2       -> j1-i1,  j2-i2, i1, i2, j1,   j2)");
#setSpaceTimeMap(prog, system, "NR_FTable_2", "(i1,j1,i2,j2       -> j1-i1,  j2-i2, i1, i2, j1,   j2)");
#setSpaceTimeMap(prog, system, "NR_FTable_3", "(i1,j1,i2,j2       -> j1-i1,  j2-i2, i1, i2, j1,   j2)");
#setSpaceTimeMap(prog, system, "NR_FTable_4", "(i1,j1,i2,j2       -> j1-i1,  j2-i2, i1, i2, j1,   j2)");
#setParallel(prog, system, "", "2");
#generateScheduledCode(prog, system, outDir);


## 6D schedule with k1, k2 loop outside, bottom up 
outDir = "out";
setMemoryMap(prog, system, "NR_FTable",   "NR_FTable0",   "(i1,j1,i2,j2->i1, i2, j2)");
setMemoryMap(prog, system, "NR_FTable_1", "NR_FTable1",   "(i1,j1,i2,j2->i1, i2, j2)");
setMemoryMap(prog, system, "NR_FTable_2", "NR_FTable2",   "(i1,j1,i2,j2->i1, i2, j2)");
setMemoryMap(prog, system, "NR_FTable_3", "NR_FTable3",   "(i1,j1,i2,j2->i1, i2, j2)");
setMemoryMap(prog, system, "NR_FTable_4", "NR_FTable4",   "(i1,j1,i2,j2->i1, i2, j2)");
setSpaceTimeMap(prog, system, "S1",          "(i,j               ->  0, j-i,     i,   0,     0,        0,     0)");
setSpaceTimeMap(prog, system, "S2",          "(i,j               ->  0, j-i,     i,   0,     0,        0,     0)");
setSpaceTimeMap(prog, system, "FTable",      "(i1,j1,i2,j2       ->  1, j1-i1,   i1,  j1,    j2-i2,    i2,    j2)");
setSpaceTimeMap(prog, system, "NR_FTable",   "(i1,j1,i2,j2,k1,k2 ->  1, j1-i1,   i1,  k1,    i2,       k2,    j2)", 
                                             "(i1,j1,i2,j2       ->  1, j1-i1,   i1,  i1-1,  i2,       i2-1,  j2)");
setSpaceTimeMap(prog, system, "NR_FTable_1", "(i1,j1,i2,j2,k1    ->  1, j1-i1,   i1,  k1,    N+1,      i2,    j2)", 
                                             "(i1,j1,i2,j2       ->  1, j1-i1,   i1,  i1-1,  N+1,      i2,    j2)");
setSpaceTimeMap(prog, system, "NR_FTable_2", "(i1,j1,i2,j2,k1    ->  1, j1-i1,   i1,  k1,    N+1,      i2,    j2)", 
                                             "(i1,j1,i2,j2       ->  1, j1-i1,   i1,  i1-1,  N+1,      i2,    j2)");                                             
setSpaceTimeMap(prog, system, "NR_FTable_3", "(i1,j1,i2,j2,k2    ->  1, j1-i1,   i1,  j1,    j2-i2,    i2,    k2)", 
                                             "(i1,j1,i2,j2       ->  1, j1-i1,   i1,  j1,    j2-i2,    i2,    i2-1)");                                                                           
setSpaceTimeMap(prog, system, "NR_FTable_4", "(i1,j1,i2,j2,k2    ->  1, j1-i1,   i1,  j1,    j2-i2,    i2,    k2)", 
                                             "(i1,j1,i2,j2       ->  1, j1-i1,   i1,  j1,    j2-i2,    i2,    i2-1)");
setParallel(prog, system, "", "2");
AShow(prog, system);
generateScheduledCode(prog, system, outDir);


#outDir = "./../../src/progs/bpmax/schedule_6d/bottom_up_fine_grain_double/autogen";
#setSpaceTimeMap(prog, system, "S1",           "(i,j               ->  0,     0,    0,   0,     0,       0,   j-i,   0, i)");
#setSpaceTimeMap(prog, system, "S2",           "(i,j               ->  0,     0,    0,   0,     0,       0,   j-i,   0, i)");
#setSpaceTimeMap(prog, system, "FTable",       "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   j1,    N-i2,    1,   i2,    1, j2)");
#setSpaceTimeMap(prog, system, "NR_FTable",    "(i1,j1,i2,j2,k1,k2 ->  1,  M-i1,   j1,   k1,    N-i2,    0,   k2,    0, j2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   i1-1,  N-i2,    0,   i2-1,  0, j2)");
#setSpaceTimeMap(prog, system, "NR_FTable_1",  "(i1,j1,i2,j2,k1    ->  1,  M-i1,   j1,   k1,    -1,      0,   i2,    0, j2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   i1-1,  -1,      0,   i2,    0, j2)");
#setSpaceTimeMap(prog, system, "NR_FTable_2",  "(i1,j1,i2,j2,k1    ->  1,  M-i1,   j1,   k1,    -1,      0,   i2,    0, j2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   i1-1,  -1,      0,   i2,    0, j2)");                                             
#setSpaceTimeMap(prog, system, "NR_FTable_3",  "(i1,j1,i2,j2,k2    ->  1,  M-i1,   j1,   j1,    N-i2,    1,   k2,    0, j2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   j1,    N-i2,    1,   i2-1,  0, j2)");                                                                           
#setSpaceTimeMap(prog, system, "NR_FTable_4",  "(i1,j1,i2,j2,k2    ->  1,  M-i1,   j1,   j1,    N-i2,    1,   k2,    0, j2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   j1,    N-i2,    1,   i2-1,  0, j2)");
#setParallel(prog, system, "", "8");
#AShow(prog, system);
#generateScheduledCode(prog, system, outDir);



#outDir = "./../../src/progs/bpmax/schedule_6d/bottom_up_coarse_grain/autogen";
#setSpaceTimeMap(prog, system, "S1",           "(i,j               ->  0,     0,    0,   0,     0,       j-i,   i)");
#setSpaceTimeMap(prog, system, "S2",           "(i,j               ->  0,     0,    0,   0,     0,       j-i,   i)");
#setSpaceTimeMap(prog, system, "FTable",       "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   j1,    N-i2,    i2,    j2)");
#setSpaceTimeMap(prog, system, "NR_FTable",    "(i1,j1,i2,j2,k1,k2 ->  1,  M-i1,   k1,   j1,    N-i2,    j2,    k2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   i1-1, j1,    N-i2,    j2,    i2-1)");
#setSpaceTimeMap(prog, system, "NR_FTable_1",  "(i1,j1,i2,j2,k1    ->  1,  M-i1,   k1,   j1,    -1,      i2,    j2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   i1-1, j1,    -1,      i2,    j2)");
#setSpaceTimeMap(prog, system, "NR_FTable_2",  "(i1,j1,i2,j2,k1    ->  1,  M-i1,   k1,   j1,    -1,      i2,    j2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   i1-1, j1,    -1,      i2,    j2)");                                             
#setSpaceTimeMap(prog, system, "NR_FTable_3",  "(i1,j1,i2,j2,k2    ->  1,  M-i1,   j1,   j1,    N-i2,    j2,    k2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   j1,    N-i2,    j2,    i2-1)");                                                                           
#setSpaceTimeMap(prog, system, "NR_FTable_4",  "(i1,j1,i2,j2,k2    ->  1,  M-i1,   j1,   j1,    N-i2,    j2,    k2)", 
#                                              "(i1,j1,i2,j2       ->  1,  M-i1,   j1,   j1,    N-i2,    j2,    i2-1)");
#setParallel(prog, system, "", "3");
#AShow(prog, system);
#generateScheduledCode(prog, system, outDir);




