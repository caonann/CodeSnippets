fn main() {
    println!("Hello, world!");
    let y:i32 = plus_one(3);
    println!("y is {}",y);
    let (s,len) = get_two_value(String::from("abc"));
    println!("s {},len {}",s,len);
}

fn plus_one(x:i32)->i32{
    x+1
}

fn get_two_value(s:String)->(String,usize){
    let slen = s.len();
    (s,slen)
}