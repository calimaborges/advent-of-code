from enum import Enum

class IntervalType(Enum):
    Unsafe     = 0
    Increasing = 1
    Decreasing = 2

input_path = 'input.txt'

def is_interval_safe(level1, level2, previous_interval_type):
    interval_type = None
    diff = level1 - level2
    if abs(diff) > 3 or abs(diff) < 1:
        return IntervalType.Unsafe
    if diff > 0:
        interval_type = IntervalType.Decreasing
    elif diff < 0:
        interval_type = IntervalType.Increasing
    if previous_interval_type is not None:
        if interval_type != previous_interval_type:
            return IntervalType.Unsafe
    return interval_type

def is_levels_safe(levels):
    interval_type = None
    for current, next in list(zip(levels, levels[1:])):
        interval_type = is_interval_safe(current, next, interval_type)
        if interval_type == IntervalType.Unsafe:
            return False
    return True

def is_levels_with_bad_level_safe(levels):
    for i in range(0, len(levels)):
        partial_levels = levels.copy()
        del partial_levels[i]
        if is_levels_safe(partial_levels):
            return True
    return False

# Tests
# print(is_levels_safe([7,6,4,2,1]))
# print(is_levels_safe([1,2,7,8,9]))
# print(is_levels_safe([1,3,2,4,5]))
# print(is_levels_safe([8,6,4,4,1]))
# print(is_levels_safe([1,3,6,7,9]))


# Tests
# print(is_levels_with_bad_level_safe([7,6,4,2,1]))
# print(is_levels_with_bad_level_safe([1,2,7,8,9]))
# print(is_levels_with_bad_level_safe([9,7,6,2,1]))
# print(is_levels_with_bad_level_safe([1,3,2,4,5]))
# print(is_levels_with_bad_level_safe([8,6,4,4,1]))
# print(is_levels_with_bad_level_safe([1,3,6,7,9]))

total_safe_levels = 0
total_safe_levels_bad_level = 0
with open(input_path, 'r') as file:
    for line in file:
        levels = list(map(int, line.split()))

        if is_levels_safe(levels):
            total_safe_levels = total_safe_levels + 1

        if is_levels_with_bad_level_safe(levels):
            total_safe_levels_bad_level = total_safe_levels_bad_level + 1


print(total_safe_levels)
print(total_safe_levels_bad_level)
