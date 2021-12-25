fn main() {
    println!("Hello, world!");
    //loop test
    let mut counter: i64 = 0;
    let ret: i64 = loop {
        counter += 1;
        if counter == 10 {
            break counter * 2;
        }
    };
    println!("counter is {}", ret);

    while counter > 0 {
        counter -= 1;
        if counter % 2 == 0 {
            println!("counter is {}", counter);
        }
    }

    let arr = [1, 2, 3, 4, 5];
    for item in arr.iter() {
        println!("item {}", item);
    }

    for i in (0..4).rev() {
        println!("index {}", i);
    }
    let cels = fahrenheit_conv_celsius(200.0);
    println!("cels is {}", cels);
    let mut fib = fibonacci(40);
    println!("fibonacci is {}", fib);
    fib = fibonacci2(40);
    println!("fibonacci2 is {}", fib);
}

fn fahrenheit_conv_celsius(x: f64) -> f64 {
    5.0 * (x - 32.0) / 9.0
}

fn fibonacci(n: i32) -> i64 {
    if n == 1 {
        1
    } else if n == 0 {
        0
    } else {
        fibonacci(n - 1) + fibonacci(n - 2)
    }
}

fn fibonacci2(n: i64) -> i64 {
    if n < 0 {
        return -1;
    } else if n == 0 {
        return 0;
    } else if n == 1 {
        return 1;
    }

    let mut pre = 1;
    for i in 2..n - 1 {
        pre += i;
    }
    return pre;
}
