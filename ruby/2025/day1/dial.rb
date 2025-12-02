class Dial
  attr_reader :position

  def initialize(position, max)
    @position = position
    @max = max
  end

  def rotate(instruction)
    direction = instruction[0]
    rotation = instruction[1..].to_i
    case direction
    when 'L'
      operation = :-
    when 'R'
      operation = :+
    else
      raise ArgumentError, "Instruction should be either R or L"
    end

    clicks = 0
    rotation.times do
      @position = @position.public_send(operation, 1) % @max
      clicks += 1 if @position == 0
    end

    clicks
  end
end
