# Automated Testing Program - User Guide

- `directory` indicates the directory containing test configuration files.
- `result.csv` specifies a file where test results will be appended.

If no arguments are provided, the script will process the current directory.

### Configuration Files:

- `run`: A text file indicating the command line to execute (mandatory).
- `std.in`: A text file indicating simulated keyboard input (optional).
- `std.out`: A text file indicating the expected output (optional/validation*).
- `stderr.out`: A text file indicating the expected error output (optional/validation*).
- `description`: A text file providing a description of the test (optional).
- `returncode`: A text file containing the expected integer return code (optional/validation*).
- `*.outfile`: One or more files to be produced by the program (optional/validation*).
  If the file is named `example.txt.outfile`, it will be compared to `example.txt`.

*Validation indicates that the script will test compliance. If not satisfied, it will indicate non-compliance.


### mktest.sh

Customizable file. As it stands, it seeks to validate all tests in directories whose names begin with "Test".
