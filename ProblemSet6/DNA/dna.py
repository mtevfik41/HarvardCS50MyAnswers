import csv
import sys

if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

with open(sys.argv[1], "r") as csvfile:
    dnareader = list(csv.reader(csvfile))
    dnareader[0].remove('name')

with open(sys.argv[2], "r") as txtfile:
    sequences = txtfile.read()

dnareader_len = len(dnareader)
sequences_len = len(sequences)

if(sys.argv[1] == "databases/large.csv"):
    agatc = dnareader[0][0]
    ttttttct = dnareader[0][1]
    aatg = dnareader[0][2]
    tctag = dnareader[0][3]
    gata = dnareader[0][4]
    tatc = dnareader[0][5]
    gaaa = dnareader[0][6]
    tctg = dnareader[0][7]
else:
    agatc = dnareader[0][0]
    aatg = dnareader[0][1]
    tatc = dnareader[0][2]

if(sys.argv[1] == "databases/large.csv"):
    agatc_counter = 3
    ttttttct_counter = 3
    aatg_counter = 3
    tctag_counter = 3
    gata_counter = 3
    tatc_counter = 3
    gaaa_counter = 3
    tctg_counter = 3
else:
    agatc_counter = 0
    ttttttct_counter = 0
    aatg_counter = 0
    tctag_counter = 0
    gata_counter = 0
    tatc_counter = 0
    gaaa_counter = 0
    tctg_counter = 0


for index in range(0,sequences_len):
    if(sys.argv[1] == "databases/large.csv"):
        if (sequences[index:index+5] == agatc and sequences[index+5:index+10] == agatc and sequences[index+10:index+15] == agatc and sequences[index+15:index+20] == agatc):
            agatc_counter += 1
        if (sequences[index:index+8] == ttttttct and sequences[index+8:index+16] == ttttttct and sequences[index+16:index+24] == ttttttct and sequences[index+24:index+32] == ttttttct):
            ttttttct_counter += 1
        if (sequences[index:index+4] == aatg and sequences[index+12:index+16] == aatg and sequences[index+4:index+8] == aatg and sequences[index+8:index+12] == aatg):
            aatg_counter += 1
        if (sequences[index:index+5] == tctag and sequences[index+5:index+10] == tctag and sequences[index+10:index+15] == tctag and sequences[index+15:index+20] == tctag):
            tctag_counter += 1
        if (sequences[index:index+4] == gata and sequences[index+4:index+8] == gata and sequences[index+8:index+12] == gata and sequences[index+12:index+16] == gata):
            gata_counter += 1
        if (sequences[index:index+4] == tatc and sequences[index+4:index+8] == tatc and sequences[index+8:index+12] == tatc and sequences[index+12:index+16] == tatc):
            tatc_counter += 1
        if (sequences[index:index+4] == gaaa and sequences[index+4:index+8] == gaaa and sequences[index+8:index+12] == gaaa and sequences[index+12:index+16] == gaaa):
            gaaa_counter += 1
        if (sequences[index:index+4] == tctg and sequences[index+4:index+8] == tctg and sequences[index+8:index+12] == tctg and sequences[index+12:index+16] == tctg):
            tctg_counter += 1
    else:
        if (sequences[index:index+5] == agatc):
            agatc_counter += 1
        if (sequences[index:index+4] == aatg):
            aatg_counter += 1
        if (sequences[index:index+4] == tatc):
            tatc_counter += 1

if(sys.argv[1] == "databases/large.csv"):
    match_list =[agatc_counter,ttttttct_counter,aatg_counter,tctag_counter,gata_counter,tatc_counter,gaaa_counter,tctg_counter]
else:
    match_list = [agatc_counter,aatg_counter,tatc_counter]

sayilist = []
k = []
for i in range(1,dnareader_len):
    sayilist = dnareader[i][1:]
    for sayi in sayilist:
        k.append(int(sayi))
    if (k == match_list):
        print(dnareader[i][0])
        exit()
    k.clear()

print("No match.")
