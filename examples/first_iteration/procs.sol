procedure foo(x: int, y: int): int {
	return x + y * y - x / 2;
}

procedure pow2(x: int) {
	return x * x;
}

procedure main() {
	return pow2(10) / foo(2, 2);
}
