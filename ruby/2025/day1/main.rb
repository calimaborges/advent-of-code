require_relative './dial'

DIAL_MAX = 100
STARTING_POINT = 50
FILEPATH = "input.txt"
# FILEPATH = "example.txt"
# FILEPATH = "test.txt"

dial = Dial.new(STARTING_POINT, DIAL_MAX)
password = 0
File.foreach(FILEPATH) do |line|
  instruction = line.chomp
  clicks = dial.rotate(instruction)
  # puts "#{instruction}\t#{dial.position}"
  password += clicks
end

puts password
