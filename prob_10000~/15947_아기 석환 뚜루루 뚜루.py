def main():
    s = ['baby', 'sukhwan', 'tururu', 'turu', 'very', 'cute', 'tururu', 'turu', 'in', 'bed', 'tururu', 'turu', 'baby', 'sukhwan']
    n = int(input())
    n -= 1
    q = n//14
    r = n%14

    if s[r] != 'tururu' and s[r] != 'turu':
        print(s[r])
        return
    s[r] += 'ru'*q
    if len(s[r]) > 10:
        s[r] = 'tu+ru*' + str((len(s[r])-2)//2)
    print(s[r])

main()