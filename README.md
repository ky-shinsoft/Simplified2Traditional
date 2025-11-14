# zhconvert

A command-line tool for converting Simplified Chinese to Traditional Chinese in files. Supports single files or recursive processing of entire directories.

## Features

- 🔄 Simplified to Traditional Chinese conversion (using OpenCC)
- 📁 Support for single files or recursive directory processing
- 🎨 Colored output showing conversion differences (red for original, green for converted)
- ⚡ Efficient file processing
- 🔒 Safe file operations (using temporary files)

## Requirements

- C++17 compiler (clang++ or g++)
- OpenCC library
- C++17 standard library (filesystem)

### macOS Installation

```bash
brew install opencc
```

### Linux Installation

```bash
# Ubuntu/Debian
sudo apt-get install libopencc-dev

# Fedora
sudo dnf install opencc-devel
```

## Building

```bash
make
```

This will generate the executable `zhconvert`.

## Usage

### Convert a Single File

```bash
./zhconvert file.txt
```

### Convert All Files in a Directory

```bash
./zhconvert /path/to/directory
```

The program will recursively scan all files in the directory and convert them.

### Install to System

```bash
make install
```

After installation, you can use the `zhconvert` command from anywhere.

### Uninstall

```bash
make uninstall
```

## Output

The program displays conversion results for each file:

- **File path**: Shows the file being processed
- **Conversion differences**: Only shows lines that have changed
  - Red (`-`): Original text
  - Green (`+`): Converted text

Example output:

```
/path/to/file.txt
=====
Line 5:
-这是简体中文
+這是繁體中文
```

## Notes

1. **Files are modified in place**: The program directly overwrites the original files. It is recommended to backup important files first.
2. **Configuration file**: The program uses `s2t.json` (Simplified to Traditional) configuration file. Make sure this file is in the program's working directory or in OpenCC's configuration directory.
3. **Encoding**: Files must be UTF-8 encoded.
4. **Error handling**: If an error occurs while converting a line, that line will remain unchanged.

## Build Options

If you need to modify build options (e.g., OpenCC installation path), edit the `Makefile`:

```makefile
CXXFLAGS = -std=c++17 -I/path/to/opencc/include -L/path/to/opencc/lib -lopencc -Wall -Wextra -O2
```

## Clean

```bash
make clean
```

## License

This project is licensed under the MIT License.

## Contributing

Issues and Pull Requests are welcome!
