import sys

file = open(sys.argv[1], "r")
lines = file.readlines()

for line in lines:
    if not 'Demande' in line and not 'toujours' in line and not 'aussi' in line and not 'Toujours' in line:
        print line
