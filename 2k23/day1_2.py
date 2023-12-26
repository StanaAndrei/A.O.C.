import re


def convert_to_number(number):
    # Dictionary to pair strings to numbers
    word_dict = {'one': '1', 'two': '2', 'three': '3', 'four': '4', 'five': '5', 'six': '6', 'seven': '7', 'eight': '8',
                 'nine': '9'}
    if number in word_dict.keys():
        real_number = word_dict.get(number)
        return real_number
    else:
        return str(number)


def getNr(line: str):
    numbers = re.findall(r'\d|one|two|three|four|five|six|seven|eight|nine', line)
    front = convert_to_number(numbers[0])
    back = convert_to_number(numbers[-1])
    return int(front + back)


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
