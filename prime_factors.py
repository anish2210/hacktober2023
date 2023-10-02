def prime_factors(n):
    factors = []
    divisor = 2

    while divisor <= n:
        if n % divisor == 0:
            factors.append(divisor)
            n = n // divisor
        else:
            divisor += 1

    return factors


# Input: A composite number
num = int(input("Enter number to find prime factors: "))
result = prime_factors(num)

print(f"Prime factors of {num} are: {result}")
