use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut total = 0;

    for line in stdin.lock().lines() {
        match line {
            Ok(l) => {
                let (l, w, h) = parse_line(l);
                total += box_surface_area_with_slack(l, w, h);
            },
            Err(error) => panic!("Could not parse line: {error:?}"),
        }
    }

    println!("{total}");
}

fn parse_line(line: String) -> (i64, i64, i64) {
    let dims: Vec<i64> = line
        .split('x')
        .map(|s| s.trim().parse::<i64>().unwrap_or(0))
        .collect();
    (dims[0], dims[1], dims[2])
}

fn box_surface_area_with_slack(l: i64, w: i64, h: i64) -> i64 {
    box_surface_area(l, w, h) + slack_area(l, w, h)
}


fn box_surface_area(l: i64, w: i64, h: i64) -> i64 {
    2*l*w + 2*w*h + 2*h*l
}

fn slack_area(l: i64, w: i64, h: i64) -> i64 {
    [l*w, w*h, h*l].into_iter().min().unwrap()
}
