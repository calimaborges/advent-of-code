require 'minitest/autorun'
require_relative './dial.rb'

MAX = 4
START = MAX / 2

describe Dial do
  before do
    @dial = Dial.new(START, MAX)
  end
  
  it "rotates based on R instruction" do
    @dial.rotate('R1')
    _(@dial.position).must_equal 3
  end

  it "rotates based on L instruction" do
    @dial.rotate('L1')
    _(@dial.position).must_equal 1
  end

  it "considers values larger than max" do
    @dial.rotate('R2')
    _(@dial.position).must_equal 0
  end

  it "considers negative values" do
    @dial.rotate('L2')
    _(@dial.position).must_equal 0
  end

  describe "clicks on zero counter" do
    it "calculates for R instructions with no clicks" do
      clicks = @dial.rotate('R1')
      _(clicks).must_equal 0
    end

    it "calculates for L instructions with no clicks" do
      clicks = @dial.rotate('L1')
      _(clicks).must_equal 0
    end

    it "calculates for R instructions with 1 click" do
      clicks = @dial.rotate('R2')
      _(clicks).must_equal 1
    end

    it "calculates for L instructions with 1 click" do
      clicks = @dial.rotate('L2')
      _(clicks).must_equal 1
    end

    it "calculates for R instructions with multiple clicks" do
      clicks = @dial.rotate('R8')
      _(clicks).must_equal 2
    end

    it "calculates for L instructions with multiple clicks" do
      clicks = @dial.rotate('L8')
      _(clicks).must_equal 2
    end
    
    it "calculates for R instructions with multiple clicks ending with 0" do
      clicks = @dial.rotate('R10')
      _(clicks).must_equal 3
    end

    it "calculates for L instructions with multiple clicks ending with 0" do
      clicks = @dial.rotate('L10')
      _(clicks).must_equal 3
    end

    it "calculates for multiple instructions" do
      @dial = Dial.new(50, 100)
      clicks = @dial.rotate('L68')
      _(clicks).must_equal 1
      _(@dial.position).must_equal 82
      clicks = @dial.rotate('L30')
      _(clicks).must_equal 0
      _(@dial.position).must_equal 52
      clicks = @dial.rotate('R48')
      _(clicks).must_equal 1
      _(@dial.position).must_equal 0
      clicks = @dial.rotate('L5')
      _(clicks).must_equal 0
      _(@dial.position).must_equal 95
      clicks = @dial.rotate('R60')
      _(clicks).must_equal 1
      _(@dial.position).must_equal 55
      clicks = @dial.rotate('L55')
      _(clicks).must_equal 1
      _(@dial.position).must_equal 0
      clicks = @dial.rotate('L1')
      _(clicks).must_equal 0
      _(@dial.position).must_equal 99
      clicks = @dial.rotate('L99')
      _(clicks).must_equal 1
      _(@dial.position).must_equal 0
      clicks = @dial.rotate('R14')
      _(clicks).must_equal 0
      _(@dial.position).must_equal 14
      clicks = @dial.rotate('L82')
      _(clicks).must_equal 1
      _(@dial.position).must_equal 32
    end
  end
  
end
    
