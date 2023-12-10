def getNr(line: str):
    d1 = None
    d2 = None
    for char in line:
        if char.isdigit():
            d1 = int(char)
            break
    revLine = reversed(line)
    for char in revLine:
        if char.isdigit():
            d2 = int(char)
            break
    return d1 * 10 + d2


def main():
    s = 0
    with open('data.txt') as f:
        lines = f.readlines()
        for line in lines:
            x = getNr(line)
            s += x
    print(s)


if __name__ == "__main__":
    main()
