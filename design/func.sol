import IO;

procedure main() {
    let x: int32 = func(x + y);
    print("Result:")
    print(x);
    return 0;
}

procedure func(x: int32, y: int32) {
    let r: int32 = x + y;
    return r;
}
