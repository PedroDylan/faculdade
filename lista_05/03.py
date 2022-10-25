def is_prime(x) -> bool:
    for i in range(2,x):
        if x%i ==0:
            prime = False
            break
        else:
            prime = True

    return prime

def list_prime(list) -> list:
    dummy = []
    
    for x in list:
        if is_prime(x):
            dummy.append(x)
    
    return dummy


numer_inputs = 5
inputs = []
for i in range(numer_inputs):
    n = int(input("number: "))
    inputs.append(n)

print(list_prime(inputs))
print(len(list_prime(inputs)))
