fn main() {
    println!("Hello, world!");
    let student = User {
        name: String::from("hulk"),
        age: 28,
        id: 1234,
    };

    //println!("student info {:?}", student);
    println!("student info {:#?}", student);
    let mut user1 = build_user(String::from("name1"), 11, 456);
    user1.age = 12;
    println!("user1 is {:?}", user1);
    let user2 = User {
        name: String::from("name2"),
        ..user1 //使用结构体更新语法从其他实例创建实例 ..
    };
    println!("user2 is {:?}", user2);

    #[derive(Debug)]
    struct Position(u32, u32, u32);
    let p1 = Position(1, 2, 3);
    println!("p1 is {:?}", p1);
    let mut p2 = Position(2, 3, 5);
    p2.1 = 100;
    println!("p2 is {:?}", p2);
    println!("user1 get age{}", user1.get_age());
    user1.set_age(18);
    println!("user1 get age{}", user1.get_age());
    let id3 = user1.move_ownership();
    println!("user1 move_ownership{}", id3);
    //println!("user1 get age{}", user1.get_age()); 这里将会编译不通过

    let o_rectangle = Rectangle {
        weight: 100,
        height: 200,
    };
    let o_square = Rectangle::square(50);
    if o_rectangle.can_hold(&o_square) {
        println!(
            "o_rectangle area:{} can hold o_square! area:{} ",
            o_rectangle.area(),
            o_square.area()
        );
    }
}

#[derive(Debug)]
struct User {
    name: String,
    age: u32,
    id: u64,
}

impl User {
    fn get_age(&self) -> u32 {
        //方法所有权借用，尽量不让方法所有权转让
        self.age
    }
    fn set_age(&mut self, age: u32) -> u32 {
        self.age = age;
        self.age
    }
    fn move_ownership(self) -> u64 {
        self.id
    }
}
fn build_user(name: String, age: u32, id: u64) -> User {
    User {
        name, //变量与字段同名，可以直接简化
        age: age,
        id: id,
    }
}

struct Rectangle {
    weight: u64,
    height: u64,
}

impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.weight > other.weight && self.height > other.height
    }

    fn square(length: u64) -> Rectangle {
        Rectangle {
            weight: length,
            height: length,
        }
    }

    fn area(&self) -> u64 {
        self.weight * self.height
    }
}
