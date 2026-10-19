# techno-car-form

Implementation of the mathmatical form:

`f(x) = -0.5 * (|x| ± x) + 100`

for an project.

# Building

Use an C compiler of your liking to compile `nob.c` into `nob` (or `nob.exe` on Windows).

Example:
```console
clang -o nob.exe nob.c
```

Then run `./nob` or `./nob.exe`. This will build the `./main.c` file. To run the binary directly in one command you can do `./nob run <file>`. The file (e.g. `output.txt`) will be filled with the output numbers of the form.

Example:
```console
./nob.exe run output.txt
```
`output.txt` will contain a bunch of lines looking something like this: `direction = ...; speed = ... => ...`

# Credits & Info

[**nob.h**](https://github.com/tsoding/nob.h) by [tsoding](https://github.com/tsoding)
