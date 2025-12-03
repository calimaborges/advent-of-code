require_relative './id_validator.rb'

FILEPATH = "input.txt"
# FILEPATH = "example.txt"
# FILEPATH = "test.txt"

validator = IdValidator.new
sum = 0
ranges = File.read(FILEPATH).split(",")
ranges.each do |range_str|
  start, finish = range_str.split("-").map { |n| n.to_i }
  invalid_ids = validator.invalid_ids(start, finish)
  sum += invalid_ids.reduce(0) { |sum,num| sum + num }
end

puts sum
