import sys

def main():
    lines = [l for l in sys.stdin if 'Execution' not in l]
    vars = {}
    for line in lines:
        P = line.split('(')
        var = P[0]
        if var not in vars:
            vars[var] = []
        P = P[1].split(')=')
        idx = P[0].split(',')
        idx = tuple([int(i) for i in idx])
        val = int(P[1])
        vars[var].append((idx,val))

    objs = {}
    for var in vars:
        max = [0,0]
        maxVal = 0
        for idx, val in vars[var]:
            for k,i in enumerate(idx):
                if i > max[k]:
                    max[k] = i
            if val > maxVal:
                maxVal = val
        obj = list()
        for i in range(max[0]+1):
            obj.append(list())
            for j in range(max[1]+1):
                obj[i].append(0)

        values = set()
        for idx, val in vars[var]:
            i, j = idx
            values.add('{}-{}'.format(i,j))
            obj[i][j] = val
        print('')
        print(var)
        for i in range(len(obj)):
            for j in range(len(obj[0])):
                if '{}-{}'.format(i,j) in values:
                    print('{:{}} '.format(obj[i][j], len(str(maxVal))), end='')
            print()


if __name__ == '__main__':
    main()
