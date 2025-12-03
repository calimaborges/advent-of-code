require 'minitest/autorun'
require_relative './id_validator.rb'

describe IdValidator do
  before do
    @validator = IdValidator.new
  end

  it "verify range validation" do
    invalid_numbers = @validator.invalid_ids(11, 22)
    assert_equal [11,22], invalid_numbers
  end
 
  it "verify valid id" do
    assert_equal true, @validator.valid_id?(12.to_s)
  end

  it "verify single number repetition" do
    assert_equal false, @validator.valid_id?(11.to_s)
  end
  
  it "verify double number repetition" do
    assert_equal false, @validator.valid_id?(1212.to_s)
  end

  it "verify triple number repetition" do
    assert_equal false, @validator.valid_id?(123123.to_s)
  end

  it "verify partial repetition is valid" do
    assert_equal true, @validator.valid_id?(112312.to_s)
  end

  it "verify repetition in odd number" do
    assert_equal true, @validator.valid_id?(1121112.to_s)
  end

  it "verify sequence of digits" do
    assert_equal false, @validator.valid_id?(121212.to_s)
  end

  it "splits id in informed amount of parts" do
    assert_equal ["12", "12", "13"], @validator.split_id(121213.to_s, 3)
  end

  it "splits id in informed amount of parts" do
    assert_nil @validator.split_id(1211213.to_s, 3)
  end

  it "compares equal parts array" do
    assert_equal true, @validator.parts_equal?(["12", "12", "12"])
  end

  it "compares different parts array" do
    assert_equal false, @validator.parts_equal?(["12", "23", "12"])
  end
end
