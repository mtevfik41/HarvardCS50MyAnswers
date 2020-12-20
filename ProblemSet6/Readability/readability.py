import cs50

text = cs50.get_string("Enter your text: ") # taking input from user
lettercount = 0 # count for letters
wordcount = 1 # counter for words
sentencecount= 0 # counter for sentences
textLength = len(text) # calculating length of text

for i in range(textLength): # for loop for input array
    if ((text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z')): # letter condition
        lettercount +=1
    if (text[i] == ' '): # word condition
        wordcount +=1
    if (text[i] == '!' or text[i] == '.' or text[i] == '?'): # sentence condition
        sentencecount +=1

# COLEMAN-LIAU INDEX
L = lettercount / wordcount * 100 # INDEX L FORMULA
S = sentencecount / wordcount * 100 # INDEX S FORMULA

index = (0.0588 * L) - (0.296 * S) - 15.8 # INDEX FORMULA
grade = round(index) # ROUNDING INDEX FOR THE NEAREST INT

print(f"Grade {grade}.")

if (grade < 1):
    print("Before Grade 1") # IF INDEX NUMBER IS LESS THAN 1 DISPLAY BEFORE GRADE 1
if (grade > 16):
    print("Grade 16+") # IF INDEX NUMBER IS GREATER THAN 16 DISPLAY GRADE 16+

