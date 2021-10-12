fn main() {
    println!("Hello, world!");
    let x = 5;
    println!("x is {}", x);
    let mut x = 6;
    println!("x is {}", x);
    x = 7;
    println!("x is {}", x);
    x = x + 1;
    println!("x is {}", x);
    const PI: f32 = 3.141592553;
    println!("PI is {}", PI);

    let guess: u32 = "123".parse().expect("Not a number!");
    println!("guess is {}", guess);
    let float_num = 7.54321_989;
    println!("float_num is {}", float_num);
    let float_num_32: f32 = 5.4321;
    println!("float_num_32 is {}", float_num_32);
    let operation_1: u64 = 1 + 3;
    println!("operation_1 is {}", operation_1);
    // 减法
    let _difference = 95.5 - 4.3;
    // 乘法
    let _product = 4 * 30;
    // 除法
    let _quotient = 56.7 / 32.2;
    // 取余
    let _remainder = 43 % 5;
    let quotient_1 = 4.8 / 9.0;
    println!("quotient_1 is {}", quotient_1);

    //元组类型
    let tup: (u32, f32, i64, char) = (123, 3.14, -3, 'b');
    println!("tup is {}", tup.3);
    let (x, y, z, k) = tup;
    println!("x,y,z,k is {} {} {} {}", x, y, z, k);
    //数组类型
    let _test_arr = [1, 2, 3, 4, 5];
    let _test_arr_1: [i32; 5] = [1, 2, 3, 4, 5];
    let xx = plus_one(4);
    println!("xx is {}", xx);
    let condion: bool = true;
    //let mut yy:i64 = 0;
    let ifret: i64 = if condion {  2 } else {  3 };
    println!("ifret is {}", ifret);
}

fn plus_one(x: i32) -> i32 {
    x + 1
}
