import cs50
import math

# input from user
number = cs50.get_int("Number: ")

# finding length of cc num
# calculate total digits
count = math.floor(math.log(math.fabs(number),10)) + 1

# finding first number of cc number
first_num = 0
if (count == 15):
    first_num = number // 10000000000000
elif (count == 16):
    first_num = number // 1000000000000000
    if (first_num == 5):
        first_num = number // 100000000000000
elif (count == 13):
    first_num = number // 1000000000000

# LUHN's ALGORITHM
length = 0
if (count == 16):
    (length) = count // 2
else:
    halfLength = count // 2
    length = round(math.ceil(halfLength)) + 1

# get even digits starting with last in card number

evenDigits = []
evenNum = number
for i in range(length):
    evenDigits.append(evenNum % 10)
    evenNum = evenNum // 100

# get odd digits starting with second-to-last in card number

oddDigits = []
number = number // 10
for i in range(length):
    oddDigits.append((number % 10) * 2) # multiply by number by two and push to array
    number = number // 100

oddTOP = 0
for x in range(length):
    if oddDigits[x] > 9:
        oddTOP = oddTOP + oddDigits[x] % 10
        temp = oddDigits[x] // 10
        oddTOP = oddTOP + temp % 10
    else:
        oddTOP = oddTOP + oddDigits[x]

evenTOP = 0
for y in range(length):
    evenTOP = evenDigits[y] + evenTOP

totalTOP = evenTOP + oddTOP

test = totalTOP % 10

if(test == 0):
    # test card number
    # AMEX len:15 start:34 37
    if (count == 15 and (first_num == 34 or first_num == 37)):
        print("AMEX")
    # MASTERCARD len:16 start 51,52,53,54,55
    elif ((first_num == 51 or first_num == 52 or first_num == 53 or first_num == 54 or first_num == 5) and count == 16):
        print("MASTERCARD")
    # VISA len:13 16 start:4
    elif ((first_num == 4) and (count == 13 or count == 16)):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")

