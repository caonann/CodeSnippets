fn main() {
    println!("Hello, world!");
    let ipv4 = IpAddrV1::V4;
    println!("ipv4v1 {:?}", ipv4);
    let ipv6_v2 = IpAddrV2::V6(String::from("::1"));
    let ipv4_v2 = IpAddrV2::V4(127, 0, 0, 1);
    println!("ipv4v2 {:?},ipv6v2 {:?}", ipv4_v2, ipv6_v2);

    // if ipv4 == IpAddrV1::V4 没法作比较
}

#[derive(Debug)]
enum IpAddrV1 {
    V4,
    V6,
}

#[derive(Debug)]
enum IpAddrV2 {
    V4(u8, u8, u8, u8),
    V6(String),
}

impl IpAddrV2 {
    fn conver_ipv4_to_string(&self) -> String {
        String::from("")
    }
}

struct IpAddrV3 {
    iptype: IpAddrV1,
    saddr: String,
}

enum Cards {
    Spades,
    Diamonds,
    Clubs,
    Hearts,
}

fn select_coin(card: Cards) -> Cards {
    match card {
        Cards::Spades => Cards::Spades,
        Cards::Diamonds => Cards::Diamonds,
        _ => Cards::Hearts,
    }
}
