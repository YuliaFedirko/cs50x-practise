import cs50

def main():
    text = cs50.get_string("Text: ")
    
    grade = formula(text)
    
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")
    
def formula(text):
    w = count_w(text)
    l = count_L(text)/w *100
    s = count_S(text)/w * 100
    
    
    grade = 0.0588 * l - 0.296 * s - 15.8
    
    return round(grade)
    
def count_L(text):
    L = 0
    for i in range(len(text)):
        if ((text[i]).isalpha() == True):
            L += 1

    return L
    
def count_S(text):
    S = 0
    for i in range(len(text)):
        if(text[i] == "!" or text[i] == "?" or text[i] == "."):
            S += 1
 
    return S
    
def count_w(text):
    w = 1
    for i in range(len(text)):
        if(text[i] == " "):
            w += 1

    return w
    
    
main()