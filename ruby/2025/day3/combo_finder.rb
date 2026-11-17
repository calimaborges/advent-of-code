class ComboFinder
  NumberProperties = Data.define(:number, :index)
  def parse_line(line)
    line.split("").map { |n| n.to_i }
  end

  def find_max(numbers, combo_size = 2)
    crop_size = -combo_size
    parts = []
    parts_index = 0
    loop do
      if parts_index == 0
        start_index = 0
      else
        start_index = parts.last.index + 1
      end
      cropped_numbers = numbers[start_index..crop_size]
      parts[parts_index] = find_largest_number(cropped_numbers)
      parts_index += 1
      crop_size -= 1
      break if parts_index == combo_size
    end
    return parts.map { |n| n.number.to_i }.join.to_i
  end

  def find_largest_number(numbers)
    max = nil
    (0...numbers.length).each do |index|
      number = numbers[index]
      if max == nil or number > max.number
        max = NumberProperties.new(number: number, index: index)
      end
    end
    return max
  end
end
