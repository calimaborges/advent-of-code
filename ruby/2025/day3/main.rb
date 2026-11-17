require_relative './combo_finder.rb'

# FILEPATH = "input.txt"
# FILEPATH = "example.txt"
FILEPATH = "test.txt"

finder = ComboFinder.new
sum = 0
File.foreach(FILEPATH) do |line|
  numbers = finder.parse_line(line.chomp)
  max = finder.find_max(numbers, 12)
  p "#{line} #{max}"
  sum += max
end

puts sum
