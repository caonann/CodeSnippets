fn main() {
    println!("Hello, world!");
    //loop test
    let mut counter:i64 = 0;
    let ret:i64 = loop {
        counter += 1;
        if counter == 10 {
            break counter * 2
        }
    };
    println!("counter is {}", ret);
}
