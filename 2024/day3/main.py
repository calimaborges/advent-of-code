import re

input_path = 'input.txt'
total = 0
with open(input_path, 'r') as file:
    matches = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', file.read())
    for match in matches:
        total = total + int(match[0]) * int(match[1])

print(total)

def remove_disabled_interval(text):
    disable_handle_index = text.find("don't()")
    if disable_handle_index == -1:
        return None
    enable_handle_index = text.find("do()")
    if enable_handle_index == -1:
        enable_handle_index = len(text)
    else:
        enable_handle_index = enable_handle_index + len("do()")
    return text[:disable_handle_index] + text[enable_handle_index:]


def remove_all_disabled_intervals(text):
    new_text = remove_disabled_interval(text)
    if new_text is None:
        return text
    return remove_disabled_interval(new_text)


# TEST
text = "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))don't()blablablablablabla"
text = remove_all_disabled_intervals(text)
print(remove_all_disabled_intervals(text))
matches = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', text)
total_test = 0
for match in matches:
    total_test = total_test + int(match[0]) * int(match[1])
print(total_test)
# text = remove_disabled_interval(text)
# print(text)
# text = remove_disabled_interval(text)
# print(text)
# text = remove_disabled_interval(text)
# print(text)

total_disabled_interval = 0
with open(input_path, 'r') as file:
    text = remove_all_disabled_intervals(file.read())
    matches = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', text)
    for match in matches:
        total_disabled_interval = total_disabled_interval + int(match[0]) * int(match[1])

print(total_disabled_interval)
