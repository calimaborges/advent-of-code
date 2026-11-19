use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut total_wrap = 0;
    let mut total_ribbon = 0;
    for line in stdin.lock().lines() {
        match line {
            Ok(l) => {
                let (l, w, h) = parse_line(l);
                total_wrap += box_surface_area_with_slack(l, w, h);
                total_ribbon += ribbon_with_bow(l, w, h);
            },
            Err(error) => panic!("Could not parse line: {error:?}"),
        }
    }
    println!("wrap: {total_wrap}; ribbon: {total_ribbon}");
}

fn parse_line(line: String) -> (i64, i64, i64) {
    let dims: Vec<i64> = line
        .split('x')
        .map(|s| s.trim().parse::<i64>().unwrap_or(0))
        .collect();
    (dims[0], dims[1], dims[2])
}

fn ribbon_with_bow(l: i64, w: i64, h: i64) -> i64 {
    let [s1, s2, _] = sorted_sides(l, w, h);
    let bow = l*w*h;
    2 * (s1 + s2) + bow
}

fn box_surface_area_with_slack(l: i64, w: i64, h: i64) -> i64 {
    box_surface_area(l, w, h) + shortest_surface_area(l, w, h)
}


fn box_surface_area(l: i64, w: i64, h: i64) -> i64 {
    2*l*w + 2*w*h + 2*h*l
}

fn shortest_surface_area(l: i64, w: i64, h: i64) -> i64 {
    sorted_surface_areas(l, w, h)[0]
}

fn sorted_surface_areas(l: i64, w: i64, h: i64) -> [i64; 3] {
    let mut surfaces = [l*w, w*h, h*l];
    surfaces.sort_unstable();
    surfaces
}

fn sorted_sides(l: i64, w: i64, h: i64) -> [i64; 3] {
    let mut sides = [l, w, h];
    sides.sort_unstable();
    sides
}
