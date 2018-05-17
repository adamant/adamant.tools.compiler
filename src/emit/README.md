# `adamant.tools.compiler.emit.cpp`

Emit C++ code for the semantic tree.

## Name Mangling

For some time, the name mangling scheme was rather complex. It was intended to produce names that could never conflict and never be spoofed by names in the source code. At the same time, it was trying to keep the mangled names as short as possible and maintain as much readability as possible. Eventually, it was decided this approach wasn't the best.

Reviewing the LLVM identifier rules, any character can be used in an identifier by simply enclosing the identifier in quotes. So when the compiler is transitioned from emitting C to LLVM, it will be able to simply use the source syntax like dots, parentheses and angle brackets in the identifiers. Thus any name mangling scheme used now will be discarded. Since naming conflicts are unlikely and fairly easily avoided, it seems to make sense to have a scheme that is easier to read and closer to a direct translation of the names.

The name mangling occurs in two phases. In the first phase, the name of the individual element (i.e. class, struct, method or function) is mangled. In the second phase, it is combined with the names of connected elements like namespaces and arguments to produce a full name. In this process, parts are separated by a double underscore and keywords and special type names are used as basic identifiers.

### Phase 1

This phase ensures that there can be no conflicts with standard C identifiers and escapes the double underscore so it can be used as a separator.

1. For any run of more than one underscore, add another underscore on the end. (This ensures no double underscores occur in the identifier)
2. For types, append double underscore and the number of type parameters, even if zero.
3. For functions, append double underscore and the number of parameters, even if zero.
4. For fields and variables, append a double underscore. For redeclarations of a variable, append a unique sequence number.

### Phase 2

This phase is specified in a short hand notation of concatenating strings.

1. `containing_namespace + "__" + namespace`
2. `namespace + "__" + class_name`
3. `namespace + "__" + struct_name`
4. `type_name + "__new__" + constructor_name`
5. `type_name + "__new__" + number_of_parameters`
6. `type_name + "__get__" + property_name`
7. `type_name + "__set__" + property_name`

### Special Names

* Tuples: `tuple_` + number_of_type_parameters + type_parameters_separated_by_underscores
* `int`: `i32`
* `uint`: `u32`