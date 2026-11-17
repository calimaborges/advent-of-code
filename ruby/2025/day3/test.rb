require 'minitest/autorun'
require_relative './combo_finder.rb'

describe ComboFinder do
  before do
    @finder = ComboFinder.new
  end

  it "parses line string" do
    numbers = @finder.parse_line("987654321111111")
    assert_equal [9,8,7,6,5,4,3,2,1,1,1,1,1,1,1], numbers
  end

  it "finds largest number index" do
    numbers = @finder.parse_line("987654321111111")
    max = @finder.find_largest_number(numbers)
    assert_equal 0, max.index
  end

  it "finds largest combo for two selected numbers" do
    numbers = @finder.parse_line("987654321111111")
    max_number = @finder.find_max(numbers)
    assert_equal 98, max_number
  end

  it "finds largest combo for two selected numbers, largest in the end" do
    numbers = @finder.parse_line("811111111111119")
    max_number = @finder.find_max(numbers)
    assert_equal 89, max_number
  end

  it "finds largest combo for two selected numbers, both in the end" do
    numbers = @finder.parse_line("234234234234278")
    max_number = @finder.find_max(numbers)
    assert_equal 78, max_number
  end

  it "finds largest combo for two selected numbers, both in the middle" do
    numbers = @finder.parse_line("818181911112111")
    max_number = @finder.find_max(numbers)
    assert_equal 92, max_number
  end

  it "finds largest combo for twelve selected numbers: case 1" do
    numbers = @finder.parse_line("987654321111111")
    max_number = @finder.find_max(numbers, 12)
    assert_equal 987654321111, max_number
  end

  it "finds largest combo for twelve selected numbers: case 2" do
    numbers = @finder.parse_line("811111111111119")
    max_number = @finder.find_max(numbers, 12)
    assert_equal 811111111119, max_number
  end

  it "finds largest combo for twelve selected numbers: case 3" do
    numbers = @finder.parse_line("234234234234278")
    max_number = @finder.find_max(numbers, 12)
    assert_equal 434234234278, max_number
  end

  it "finds largest combo for twelve selected numbers: case 4" do
    numbers = @finder.parse_line("818181911112111")
    max_number = @finder.find_max(numbers, 12)
    assert_equal 888911112111, max_number
  end
end
