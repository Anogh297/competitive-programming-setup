# Competitive Programming Setup

This repository contains the setup I use for competitive programming in Visual Studio Code.

## Prerequisites

- [MinGW for Windows C++](https://winlibs.com/)
- [Pypy for Python execution](https://pypy.org/download.html)
- [clang-format for formatting](https://www.npmjs.com/package/clang-format)

## Available Snippets

- **cpp**: General C++ template
- **python**: General Python template
- **etime**: Log execution time to standard error stream
- **mp_hash**: Add a custom hash function to use in `unordered_map` for O(n) complexity

## Extra: Sublime text build system

```json
{
  "shell_cmd": "g++ -Wl,-stack=268435456 -std=c++20 -Wall -Wextra -O2 \"${file}\" -o \"${file_base_name}\" && \"${file_base_name}\" < \"input.txt\" > \"output.txt\" && del \"${file_base_name}.exe\"",
  "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
  "working_dir": "${file_path}",
  "selector": "source.c++"
}
```
