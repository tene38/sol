import IO;

// Requires:
// - arrays
// - for loop
// - assignments
// - print

procedure main(argv: array[string]) {
    for (let i: int = 0; i < length(argv); i += 1) {
        print(argv[i]);
    }
}
