lin-entrop
===================

Linearize images in row major order and z order (Morton Curves), then gets
their $$k$$ grade entropy.

This script automatize that process for sets of images.

Also, and essay was made using this program (with some modifications though), with the intention of find a relation between better locality in
linearized images and better entropies (smaller values).

## Dependency
- [entrop](http://pizzachili.dcc.uchile.cl/experiments.html), computes the empirical entropy of order <k> of <filename>.

## External Libraries

- [CImg C++ library](http://cimg.eu/index.html).

## Installation
General installation process is only available for GNU/Linux operating system.

- **Download this program:** Execute command

```sh
git clone https://github.com/vlermandac/lin-entrop
```
- **Install :** Just run the program and all the needed stuff will be compiled.

```sh
chmod +x lin-entrop
./lin-entrop
```

## Usage
Use -h or --help to display the help message.
```sh
$lin-entrop -h
Usage: lin-entrop [OPTION] <entropy order> <files>
Options:
-h, --help     display the help message.
-r, --row-major <files>    linearize in row major order.
-z, --z-order   <files>    linearize in z order (Morton Curve).
```

## Future work

- Add more curves, such as Hilbert curves.


