#libraries
import cs50
import math

# variables
quarter = 25 
quartercounter = 0 
dime = 10
dimecounter = 0
nickel = 5
nickelcounter = 0
penny = 1
pennycounter = 0
total = 0

#taking input from user
giris = cs50.get_float("Change owed: ")
# checking input is valid
while not(giris > 0):
    giris = cs50.get_float("Change owed: ")

#cents to coins
cents = round(giris * 100)
#calculations
quartercounter = math.floor(cents / quarter)
cents = cents % quarter

dimecounter = math.floor(cents / dime)
cents = cents % dime

nickelcounter = math.floor(cents / nickel)
cents = cents % nickel

pennycounter = cents

#calculating total of counters
total = quartercounter + dimecounter + nickelcounter + pennycounter
#printing total
print(total)