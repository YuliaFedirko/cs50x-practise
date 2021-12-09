import csv
import sys

def main():
    if(len(sys.argv) != 3 or sys.argv[1].endswith(".csv") == False or sys.argv[2].endswith(".txt") == False):
        print("Usage: python dna.py data.csv sequence.txt")
        return
    
    database = []  
    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)
    
        
    
    dna = []
    with open(sys.argv[2], 'r') as file:
       dna = file.read()
    
    
    str_counts = {}
    str_counts["AGATC"] = count(dna, "AGATC")
    str_counts["AATG"] = count(dna, "AATG")
    str_counts["TATC"] = count(dna, "TATC")
    str_counts["TCTAG"] = count(dna, "TCTAG")
    str_counts["GATA"] = count(dna, "GATA")
    str_counts["GAAA"] = count(dna, "GAAA")
    str_counts["TCTG"] = count(dna, "TCTG")
    str_counts["TTTTTTCT"] = count(dna, "TTTTTTCT")
  
    
    notfound = True
    for i in range(len(database)):
        if(len(database[0]) > 4):
            if(str_counts["AGATC"] == int(database[i]["AGATC"]) and str_counts["TTTTTTCT"] == int(database[i]["TTTTTTCT"]) and str_counts["AATG"] == int(database[i]["AATG"]) and str_counts["TCTAG"] == int(database[i]["TCTAG"]) and str_counts["GATA"] == int(database[i]["GATA"]) and str_counts["TATC"] == int(database[i]["TATC"]) and str_counts["GAAA"] == int(database[i]["GAAA"]) and str_counts["TCTG"] == int(database[i]["TCTG"])):
                notfound = False
                print(database[i]["name"])
        else:
            if(str_counts["AGATC"] == int(database[i]["AGATC"]) and str_counts["AATG"] == int(database[i]["AATG"]) and str_counts["TATC"] == int(database[i]["TATC"])):
                notfound = False
                print(database[i]["name"])
    
    if(notfound == True):
        print("No match")
    
    

def count(file, STR):
    count = []
    dubli = 0
    count.append(dubli)
    for k in range(len(file)-len(STR)):
        i=k
        while(i < len(file)-len(STR)-1): 
            j=i+len(STR)
            if(file[i:j] == STR):
                dubli += 1
                i = j
            else:
                if dubli > 0:
                    if dubli > max(count):
                        count.append(dubli)
                    dubli = 0
                i = j
                break
    
    return max(count)


main()
    
        