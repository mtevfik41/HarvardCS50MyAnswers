import cs50

# make sure user enters valid input
height = cs50.get_int("Height: ")
while not (height >= 1 and height <= 8):
    height = cs50.get_int("Height: ")

for i in range(height):
    # add spaces. decrementing so subract 1
    for j in range(height - i - 1):
        print(" ", end = "")

    # print hashtags
    for k in range(i + 1):
        print("#", end = "")
    #print mid spaces

    print("")