prog = ReadAlphabets("./main.ab");
system = "main";

outDir = "out";

options = createCGOptionForScheduledC();
setCGOptionFlattenArrays(options, 1);

generateScheduledCode(prog, system, options, outDir);