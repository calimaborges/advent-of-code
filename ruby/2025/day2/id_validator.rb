class IdValidator
  
  def invalid_ids(start, finish)
    invalid_ids = []
    (start..finish).each do |id|
      invalid_ids << id unless valid_id?(id.to_s)
    end
    invalid_ids
  end
  
  def split_id(id, parts_amount)
    return nil if id.length % parts_amount != 0
    size = id.length / parts_amount
    parts = []
    rest = id
    loop do
      left, rest = rest.slice(0, size), rest.slice(size..-1)
      parts << left
      if rest.length <= size
        parts << rest
        break
      end
    end
    parts
  end

  def parts_equal?(parts)
    equal = true
    prev = nil
    for part in parts
      if prev != nil
        if prev != part
          return false
        end
      end
      prev = part
    end
    return true
  end

  def valid_id?(id, parts_amount = 2)
    parts = split_id(id, parts_amount)
    if parts != nil and parts_equal?(parts)
      return false
    else
      next_parts_amount = parts_amount + 1
      if (id.length / next_parts_amount) >= 1
        valid_id?(id, next_parts_amount)
      else
        return true
      end
    end
  end
end
