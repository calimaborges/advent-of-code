input_path = 'input.txt'

left_location_ids = []
right_location_ids = []

with open(input_path, 'r') as file:
    for line in file:
        left, right = map(int, line.split())
        left_location_ids.append(left)
        right_location_ids.append(right)

left_location_ids.sort()
right_location_ids.sort()

total_distance = 0
for i, rli in enumerate(right_location_ids):
    total_distance = total_distance + abs(rli - left_location_ids[i])

print(total_distance)

