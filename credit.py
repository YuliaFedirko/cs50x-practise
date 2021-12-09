import cs50

def main():
    card = cs50.get_string("Number: ")
    if(valid(card) == False or len(card) < 13):
         print("INVALID")
    else:
        print(company(card))
    
def valid(card):
    suma1 = 0
    suma2 = 0
    k = 0
    if (len(card) % 2 == 0):
        for i in range(0, len(card) -1 , 2): 
            k = (int(card[i]) * 2)
            if k>9:
                suma1 = suma1 + int(k/10) + int(k%10)
            else:
                suma1 += k
            
          
        for i in range(1, len(card) , 2):
            suma2 += int(card[i])
    else:
        for i in range(1, len(card)-1 , 2): 
            k = (int(card[i]) * 2)
           
            if k>9:
                suma1 = suma1 + int(k/10) + int(k%10)
            else:
                suma1 += k
            
          
        for i in range(0, len(card) , 2):
            suma2 += int(card[i])
            
    suma = suma1 + suma2
    
    return (suma % 10 == 0)

def company(card):
    temp = []
    temp.append(int(card[0]))
    temp.append(int(card[1]))
    
        
    if (temp[0] == 5 and temp[1] in range(1,6)):
        return "MASTERCARD"
    if (temp[0] == 3 and temp[1] in [4, 7]):
        return "AMEX"
    if (temp[0] == 4):
        return "VISA"
        
main()
    