def primo(num):
        if num < 2:
            return False
        for i in range(2, int (num**0.5) + 1):
            if num % i == 0:
                return False
            return True
        

i = 1 
while i <= 100:
    if primo(i):
        print(i, "es primo")
    else:
        print(i, "no es primo")
    i += 1