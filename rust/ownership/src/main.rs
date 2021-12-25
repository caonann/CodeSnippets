fn main() {
    let s1 = String::from("hello");
    //let s2=s1;所有权转义
    println!("Hello, world! {}", s1);
    //print_string(s1);
    //let s2=s1; 所有权已被函数转义，不允许
    let num = 0;
    print_int(num);
    let num2 = num;

    let _slen = get_string_len(&s1);
    let _s2 = s1;

    let mut s4 = String::from("test mut string");
    let s5 = &s4;
    let s6 = &s4;
    println!("s5 {} s6 {}", s5, s6); //s5,s6最后使用的地方，在这里之后超出作用域，可以声明s7
    let s7 = &mut s4;
    s7.push_str("abc");
    println!("s7 {}", s7);
    //println!("s5 {} s6 {} s7 {}",s7,s5,s6); //会报错

    //slice
    let mut first_world = String::from("abc def");
    let world = first_world_version2(&first_world);
    println!("first world index is {}", world);
    first_world.clear();
    //println!("first world index is {}",world); 报错
    let strslice = "my slice";//这种形式的字符串本身就是不可变引用类型，所以不可改变
    let world = first_world_version2(strslice);
    println!("first world index is {}", world);
}

fn print_string(s: String) {
    println!("print this string {}", s);
}

fn print_int(i: i32) {
    println!("print this interger {}", i);
}

fn get_string_len(s: &String) -> usize {
    s.len()
}

fn first_world_version1(s: &String) -> usize {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}

fn first_world_version2(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[..i];
        }
    }
    return &s[..];
}
