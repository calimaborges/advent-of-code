import re

input_path = 'input.txt'
total = 0
with open(input_path, 'r') as file:
    matches = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', file.read())
    for match in matches:
        total = total + int(match[0]) * int(match[1])
print(total)

def remove_disabled_interval(text):
    enabler_text = "do()"
    disabler_text = "don't()"
    enabler_len = len(enabler_text)
    disable_handle_index = text.find(disabler_text)
    if disable_handle_index == -1:
        return None
    enable_handle_index = text.find(enabler_text)
    if enable_handle_index == -1:
        enable_handle_index = len(text)
    else:
        enable_handle_index = enable_handle_index + enabler_len

    if enable_handle_index < disable_handle_index:
        return text[:enable_handle_index - enabler_len] + text[enable_handle_index:]
    return text[:disable_handle_index] + text[enable_handle_index:]

def remove_all_disabled_intervals(text, count = 0):
    new_text = remove_disabled_interval(text)
    if new_text is None:
        return text
    return remove_all_disabled_intervals(new_text, count + 1)


# TEST
# text = "00000000000000000don't()11111111111111do()00000000000000000000don't()11111111111111111do()0000000000000do()0000000000000000don't()1111111111111111"
# text = remove_all_disabled_intervals(text)
# print(text)
# matches = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', text)
# total_test = 0
# for match in matches:
#     total_test = total_test + int(match[0]) * int(match[1])
# print(total_test)

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
