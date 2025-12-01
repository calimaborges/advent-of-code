DIAL_MAX = 100
STARTING_POINT = 50
FILEPATH = "input.txt"
# FILEPATH = "example.txt"

def calculate_next(current, instruction)
  direction = instruction[0]
  amount = instruction[1..].to_i

  case direction
  when 'L'
    raw_location = (current - amount) % DIAL_MAX
  when 'R'
    raw_location = (current + amount) % DIAL_MAX
  end
end

current_point = STARTING_POINT
password = 0
File.foreach(FILEPATH) do |line|
  instruction = line.chomp
  current_point = calculate_next(current_point, instruction)
  # puts "#{instruction}\t#{current_point}"
  password += 1 if current_point == 0
end
puts password
