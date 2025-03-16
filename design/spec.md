# Programming Language

## Open problems

- Memory management on compound structures (arrays, structures, classes)
- Error handling
- Polimorphism
- Little boilerplate
- Standard library, IO design
    - Library import system
- System calls
- Calling functions from the Linux API and C libraries
- Which to choose:
    - Function overloading
    - Named parameters with default values
- String interpolation
- Variable scoping

## Specification

Features:

- Variables
- Builtin datatypes:
    - integers (byte, word, integer, qword aka. i8, i16, i32, i64)
        - int32, integer32, integer8, int8
    - floats (only doubles)
    - strings (C style)
    - booleans
    - arrays
- Polymorphic datatypes
- Control structures:
    - conditionals
    - while
    - for (C style)
    - match?
- Functions
- Data structures
- Abstract Datatypes (but with no inheritance)
- Interfaces
- Double pass compilation

Language name: Sol. Extension: `.sol`.

Example program:

```
/*
 *  Mając do dyspozycji semafory binarne, należy zaimplementować semafor ogólny
 *  który zmniejszamy i zwiększamy o 1 lub o 3 (operacje P1, P3, V1, V3) –
 *  oczywiście nigdy nie może być ujemny
 */

type GeneralSemaphore {

	let n: integer;
	let no_waiting: integer;
	let mutex(1): BinarySemaphore;
	let semP(0): BinarySemaphore;

	Semaphore(n: integer) {
		this.n = n;
		this.no_waiting = 0;
	}

	// [n > 0]
	procedure P1() {
		mutex.p();
		if (n == 0) {
			no_waiting += 1;
			mutex.v();
			semP.p();
			no_waiting -= 1;
		}
		n--;
		mutex.v();
	}

	procedure V1() {
		mutex.p();
		n++;
		if (no_waiting > 0) {
			semP.v();
		} else {
			mutex.v();
		}
	}
}
```

C style comments:

```
// Line comment
/*
    Block comment
*/
```

Variables:

```
// Usage

let x: byte = 21;
let y: float = 31.24;
let message: string = "Hello there";
let is_valid: bool = true;
let nums: array[byte] = [2, 3, 4, 5];

// With type inference:

let x = 21;
let y = 31.24;
let message = "Hello there";
let is_valid = true;

// Assignment

x = 3;
y = 41;
message = "Hello Mark";
is_valid = false;

// Errors on type mismatch

x = "foo";  // Error on line 4: conflicting types: [x] is of type [byte], ["foo"] is of type [string].
```

Functions:

```
procedure foo() {
    // ...
}

// Parameter datatypes are necessary
// No varargs.

procedure bar(x: byte, s: string) {
    // ...
}

// Return values

procedure id(x: byte): int {
    return x;
}
```

Control structures:

```
if (x == 21) {
    // ...
} else {
    // ...
}

while (x > 37) {
    // ...
}

for (x: byte; x < 21; x += 1) {
    // ...
}
```

Structures:

```
// Definition

type Person {
    let name: string = "[Empty]";  // Optional default value
    let age: byte;  // If no default value is defined, the value has to be
                    // defined when defining an object of this structure
}

type Error {
    let error_name: string = "Default Error";
    let error_code: integer = 0;
}

// Usage

procedure main(args: array[string]) {
    let mark: Person = {
        name = "Mark";
        age = 21;
    };

    // With the default value defined
    let empty: Person = {
        age = 21;
    }

    // When all fields have default values
    let default_error: Error;

    // Field access
    print(mark.name);
    print(mark.age);
}
```

Abstract datatypes:

```
// Definition

type Stack {
    let elements: array[byte];
    let i: integer = 0;

    Stack(size: byte) {
        // How do I initialize an array?
        // How do I use the heap?
        // How to solve memory management?
        // Maybe don't implement arrays for now, and assume all variables are
        // automatic.
    }

    procedure size(): integer {
        return length(elements);
    }

    procedure push(x: byte) {
        // The constructor takes a [size] argument
        array[i] = x;
        i += 1;
    }

    procedure pop(): byte {
        if (i > 0) {
            let retval: byte = array[i];
            i -= 1;
            return retval;
        } else {
            // How to solve error handling?
        }
    }
}

// Usage

procedure main(args: array[string]) {
    let stack: Stack(10);
    stack.push(10);
    let top: byte = stack.pop();
    print(stack.size());
}

// Interfaces

interface Stream {
    procedure write(b: byte);
    procedure read(): byte;
    procedure close();
}

type Terminal : Stream {
    procedure write(b: byte) {
        // ...
    }

    procedure read(): byte {
        // ...
    }

    procedure close() {
        // ...
    }
}

// Usage

import IO;  // How to solve library inclusion?

procedure write_hello(s: Stream) {
    s.write("Hello there\n");
}

procedure main(args: array[string]) {
    let term: Stream = IO.Terminal;  // Reference assignment, not object copy
    term.write("hello");  // Call via a reference
    Terminal.write();  // Direct call
    let command: string = term.read(20);
}
```

## First subset

First subset of the language should include:

- Functions
- Integers

The syntax of functions shall be constrained to:

```
procedure add(x: int, y: int): int {
    return x + y;
}

procedure compute(x: int, y: int): int {
    return add(x, y) * add(y, x);
}
```

The grammar of the language is:

```
program = procedure*

procedure = 'procedure' ident args [':' ident] '{' return_statement '}'
args = '(' [arg (, arg)*] ')'
arg = ident ':' 'int'
retrun_statement = 'return' expression

ident = [A-Za-z_][A-Za-z_0-9]*
integer = [0-9]+

expression = integer
           | ident
           | func_call
           | expression arith_binop expression

arith_binop = '+' (precedence 20)
            | '-' (precedence 30)
            | '/' (precedence 35)
            | '*' (precedence 40)
func_call = ident '(' [expression (, expression)*] ')'
```

The AST for the program above would be:

```
(program (
    (procedure add ((x int) (y int)) int (
        (binop + x y)))
    (procedure compute ((x int) (y int)) int (
        (binop * (func_call add (x y)) 
                 (func_call add (y x)))))))

; Isn't lisp beautiful?
```

## Work plan

- [x] Write a rudimentary design spec
- [x] Choose a subset of features for the first iteration
- [x] Write down the language syntax in BNF
- [x] Generate a parser in ANTLR
- [x] Read about LLVM IR
- [x] Implement an AST
- [x] Implement a visitor, which maps the parse tree to the AST
- [x] Implement a visitor, which maps the AST to LLVM IR
- [ ] Use the LLVM API to output a compiled file
- [ ] Define invariants of all classes explicitly. Write unit tests to verify
      them.
- [ ] Push the code into a repo, setup CI/CD with automatic testing
- [ ] Make the project run with Conan packages
- [ ] Add running optimization passes on the IR
- [ ] Extend the language by:
    - [ ] variables
    - [ ] conditional expressions
    - [ ] builtin datatypes
    - [ ] all operators in expressions
    - [ ] external functions
- [ ] Make AstPrinter print S-expressions
- [ ] Pick sensible naming conventions
- [ ] Read the ISO C++ core guidelines
- [ ] Think how to implement a compiler frontend in Coq (using a representation
      for the parse tree, AST and LLVM IR, IR from Vellvm)

- Think about a domain specific language and write one.
- Read about dependent type systems. Can one be implemented in a language with
    operational semantics?
- What really are static and dynamic types?

## Language Grammar

```
#
# Top level
#

program = top_level_statement*
top_level_statement = import | assignment | procedure | struct
import = 'import' ident ';'

#
# Statements
#

assignment = 'let' ident [':' ident] '=' expression ';' 
           | 'let' ident ':' ident '=' '{' [struct_assignment (, struct_assignment)*] '}'
struct_assignment = ident '=' expression ';'
declaration = 'let' ident ':' ident ';'

statement = expression_statement | assignment | conditional | loop | block
expression_statement = expression ';'
block = '{' statement* '}'

procedure = 'procedure' ident args [':' ident] '{' statement* '}'
args = '(' [arg (, arg)*] ')'
arg = ident ':' ident

struct = 'type' ident '{' (declaration | assignment)* '}'

for_loop = 'for' '(' assignment ';' expression ';' expression ')' '{' statement* '}'
while_loop = 'while' '(' expression ')' '{' statement* '}'
loop = for_loop | while_loop

# Note: `block` was defined as a `statement` so that we can do nested ifs. I'm
# not sure if I like it.
conditional = 'if' '(' expression ')' statement [else statement]

conditional_alt = 'if' '(' expression ')' '{' statement* '} [
                    else ('{' statement* '}' | conditional)

#
# Atomic values
# 

ident = [A-Za-z_][A-Za-z_0-9]*
integer = [0-9]+
float = [0-9]+ '.' [0.9]+
string = '\'' .* '\''  # TODO: add escape sequences
boolean = 'true' | 'false'
value = integer | float | string
LF = '\r'? '\n'

#
# Expressions
#

# TODO: Should I include binary operators (& | ^)?
# TODO: Operator precedence has to be somehow included in the BNF

expression = value
           | ident
           | func_call
           | expression binary_operator expression
           | unary_operator expression

arith_bin_op = '+' | '-' | '/' | '%' | '*'
logic_bin_op = '&&' | '||' | '>' | '<' | '>=' | '<=' | '==' | '!='
binary_operator = arith_bin_op | logic_bin_op
unary_operator = '-' | '+' | '!'
func_call = ident '(' [expression (, expression)*] ')'

#
# Comments (not technically processed by the grammar)
#

BLOCK_COMMENT = '/*' .* '*/'
LINE_COMMENT = '//' .* LF
COMMENT = BLOCK_COMMENT | LINE_COMMENT
```
