
use std::fs::File;
use std::io::prelude::*;

fn main () {
    let input_file = String::from("input.txt");
    let mut f = File::open(input_file).expect("file not found");
    
    let mut input = String::new();
    f.read_to_string(&mut input)
        .expect("something went wrong reading the file");
	
	let mut arr = Vec::<i32>::with_capacity(input.len());
	arr.resize(input.len(), 0);
	
	const RADIX: u32 = 10;
	for (i, c) in input.chars().enumerate() {
		arr[i] = c.to_digit(RADIX).unwrap() as i32;
		//println!("{}", arr[i]);
	}
	
	let res = parse_file(arr);
	println!("{}", res);
}

fn parse_file (arr: Vec<i32>) -> i32 {
	let mut before: i32 = 0;
	let mut sum: i32 = 0;
	for i in 0..arr.len() {
        if (arr[i] == before) {
            sum += arr[i];
        }
        if (i == arr.len() - 1 && arr[i] == arr[0]) {
            sum += arr[i];
        }
        before = arr[i];
	}
	return sum;
}