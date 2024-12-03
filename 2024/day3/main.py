import re

input_path = 'input.txt'
total = 0
with open(input_path, 'r') as file:
    for line in file:
        matches = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', line)

        for match in matches:
            total = total + int(match[0]) * int(match[1])

print(total)
