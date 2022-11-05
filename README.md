Parse command line arguments for C++ programs. Boost [has a more robust library](https://www.boost.org/doc/libs/1_80_0/doc/html/program_options/overview.html) for parsing command line options, but this lighter-weight argparse can be used without using the boost library.

## Usage
See main.cpp for an example of how to use argparse. In short:
* First create argument specifications using the `Argument` class.
* Then add those argument specifications to an `ArgumentParser` object.
* Parse the command line arguments with `ArgumentParser::parse`.
* Finally, retrieve argument values with `ArgumentParser::get<t>`.

## Argument Specification
The `Argument` class specifies how a command line argument is to be interpreted. Its member variables include:
* `name`. Determines whether the argument is an option, beginning with "--" or "-", or a positional argument. Options must appear before positional arguments: `programName [optional arguments] [positional arguments]`.
* `shortName`. A shorter name for an option to appear on the command line. Must begin with '-'. Ignored for positional arguments.
* `nargs`. The number of sub-arguments expected for this argument. (Defaults to 1.) Set this to 0 to make this a boolean flag (i.e., if this argument is present, then its value is true, and if not, then its value is false). Special constant values `NARGS_AT_LEAST_ZERO` and `NARGS_AT_LEAST_ONE` specify that the parser is to consume as many arguments as possible.
* `required`. Must this argument be provided on the command line? (Defaults to false for options and true for positionals.)
* `defaultValue`. The default value for if this argument doesn't appear. This can be a single string (for nargs=1) or a vector of strings (for nargs>1). If `nargs` is 0, then `defaultValue` becomes `"false"`.
* `help`. The help description printed if the user specifies the `--help` or `-h` option.
* `metavar`. The name that represents this argument's sub-arguments in the help message. (Defaults to `name` for positionals and all-caps `name` for options.)

## Roadmap
As my leisure time permits, I intend to make the following changes:
* Improve error messages.
* Implement mutually exclusive options.
* Improve documentation, comments, and code organization.
* Write comprehensive tests.
