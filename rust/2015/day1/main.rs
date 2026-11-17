use std::io::{self, BufReader, Read};

fn main() -> io::Result<()> {
    let reader = BufReader::new(io::stdin().lock());
    let mut floor = 0;
    for (i, byte) in reader.bytes().enumerate() {
        let ch = byte? as char;
        match ch {
            '(' => floor += 1,
            ')' => floor -= 1,
            _ => {},
        }
        if floor == -1 {
            println!("basement reached in character {}", i + 1);
            break;
        }
    }
    println!("{floor} floor");
    Ok(())
}
