#include "RuntimeLibrary.h"

// Type Declarations
class Line_Info_;
class Source_Text_;
class Text_Line_;
class Text_Position_;
class Text_Span_;
class Source_File_Builder_;
class Binding_Scope_;
class Name_Binder_;
class Package_;
class Primitive_Types_;
class Semantic_Analyzer_;
class Semantic_Node_;
class Symbol_;
class Symbol_Builder_;
class Compilation_Unit_Parser_;
class Lexer_;
class Parser_;
class Syntax_Node_;
class Token_Stream_;
class Token_Type_;
class Diagnostic_;
class Emitter_;

// Function Declarations
auto compile_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) -> ::Package_ const *_Nonnull;
auto write_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> void;
auto has_errors_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> p_bool;
auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> p_int;
auto read_source_(p_string const path_) -> ::Source_Text_ const *_Nonnull;
auto TextLineFromTo_(::Source_Text_ const *_Nonnull const source_, p_int const start_, p_int const end_) -> ::Text_Line_ const *_Nonnull;
auto format_error_(p_string const message_) -> p_string;
auto new_syntax_node_missing_(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_) -> ::Syntax_Node_ const *_Nonnull;
auto new_Syntax_Node_Skipped_(::Syntax_Node_ const *_Nonnull const skipped_) -> ::Syntax_Node_ const *_Nonnull;
auto new_Syntax_Node_Skipped_(::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const skipped_) -> ::Syntax_Node_ const *_Nonnull;

// Class Declarations

class Line_Info_
{
public:
	p_bool op_Equal(Line_Info_ const * other) const { return this == other; }
	p_bool op_NotEqual(Line_Info_ const * other) const { return this != other; }
	::Source_Text_ const *_Nonnull source_;
	::System_::Collections_::List_<p_int> const *_Nonnull lineStarts_;
	Line_Info_(::Source_Text_ const *_Nonnull const source_, ::System_::Collections_::List_<p_int> const *_Nonnull const lineStarts_);
	auto Count_() const -> p_int;
	auto Get_(p_int const lineNumber_) const -> ::Text_Line_ const *_Nonnull;
	auto LineNumber_(p_int const offset_) const -> p_int;
};

class Source_Text_
{
public:
	p_bool op_Equal(Source_Text_ const * other) const { return this == other; }
	p_bool op_NotEqual(Source_Text_ const * other) const { return this != other; }
	p_string Package_;
	p_string Path_;
	p_string Name_;
	p_string Text_;
	::Line_Info_ const *_Nonnull Lines_;
	Source_Text_(p_string const package_, p_string const path_, p_string const text_);
	auto LineStarts_() const -> ::System_::Collections_::List_<p_int> const *_Nonnull;
	auto ByteLength_() const -> p_int;
	auto PositionOfStart_(::Text_Span_ const *_Nonnull const span_) const -> ::Text_Position_ const *_Nonnull;
};

class Text_Line_
{
public:
	p_bool op_Equal(Text_Line_ const * other) const { return this == other; }
	p_bool op_NotEqual(Text_Line_ const * other) const { return this != other; }
	::Source_Text_ const *_Nonnull Source_;
	p_int Start_;
	p_int Length_;
	Text_Line_(::Source_Text_ const *_Nonnull const source_, p_int const start_, p_int const length_);
	auto End_() const -> p_int;
};

class Text_Position_
{
public:
	p_bool op_Equal(Text_Position_ const * other) const { return this == other; }
	p_bool op_NotEqual(Text_Position_ const * other) const { return this != other; }
	p_int Offset_;
	p_int Line_;
	p_int Column_;
	Text_Position_(p_int const offset_, p_int const line_, p_int const column_);
};

class Text_Span_
{
public:
	p_bool op_Equal(Text_Span_ const * other) const { return this == other; }
	p_bool op_NotEqual(Text_Span_ const * other) const { return this != other; }
	p_int Start_;
	p_int Length_;
	Text_Span_(p_int const start_, p_int const length_);
	auto End_() const -> p_int;
};

class Source_File_Builder_
{
public:
	p_bool op_Equal(Source_File_Builder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Source_File_Builder_ const * other) const { return this != other; }
	::System_::Text_::String_Builder_ *_Nonnull code_;
	::System_::Text_::String_Builder_ *_Nonnull indent_;
	p_bool firstElement_;
	p_bool afterBlock_;
	Source_File_Builder_();
	auto Error_(p_string const message_) -> void;
	auto BeginLine_(p_string const value_) -> void;
	auto Write_(p_string const value_) -> void;
	auto EndLine_(p_string const value_) -> void;
	auto WriteLine_(p_string const value_) -> void;
	auto BlankLine_() -> void;
	auto ElementSeparatorLine_() -> void;
	auto StatementSeparatorLine_() -> void;
	auto BeginBlock_() -> void;
	auto EndBlock_() -> void;
	auto EndBlockWithSemicolon_() -> void;
	auto ToString_() const -> p_string;
};

class Binding_Scope_
{
public:
	p_bool op_Equal(Binding_Scope_ const * other) const { return this == other; }
	p_bool op_NotEqual(Binding_Scope_ const * other) const { return this != other; }
	::Binding_Scope_ const *_Nullable containing_scope_;
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull symbols_;
	::Primitive_Types_ const *_Nonnull primitives_;
	Binding_Scope_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_, ::Primitive_Types_ const *_Nonnull const primitives_);
	Binding_Scope_(::Binding_Scope_ const *_Nonnull const containing_scope_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_);
	auto GetPrimitive_(p_string const name_) const -> ::Symbol_ const *_Nullable;
	auto Lookup_(p_string const name_) const -> ::Symbol_ const *_Nullable;
	auto Lookup_(p_string const name_, p_int const type_) const -> ::Symbol_ const *_Nullable;
};

class Name_Binder_
{
public:
	p_bool op_Equal(Name_Binder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Name_Binder_ const * other) const { return this != other; }
	auto bind_(::Package_ const *_Nonnull const package_) const -> void;
	auto bind_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void;
	auto bind_type_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void;
	static auto add_resolution_error_(::Semantic_Node_ const *_Nonnull const node_) -> void;
};

class Package_
{
public:
	p_bool op_Equal(Package_ const * other) const { return this == other; }
	p_bool op_NotEqual(Package_ const * other) const { return this != other; }
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull CompilationUnits_;
	::Symbol_ const *_Nonnull symbol_;
	::Primitive_Types_ const *_Nonnull PrimitiveTypes_;
	Package_(::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilationUnits_, ::Primitive_Types_ const *_Nonnull const primitiveTypes_, ::Symbol_ const *_Nonnull const symbol_);
	auto AllDiagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull;
};

class Primitive_Types_
{
public:
	p_bool op_Equal(Primitive_Types_ const * other) const { return this == other; }
	p_bool op_NotEqual(Primitive_Types_ const * other) const { return this != other; }
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull Symbols_;
	Primitive_Types_();
	static auto AddFixedPointTypes_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_, p_int const bitLength_) -> void;
	auto Get_(p_string const name_) const -> ::Symbol_ const *_Nullable;
};

class Semantic_Analyzer_
{
public:
	p_bool op_Equal(Semantic_Analyzer_ const * other) const { return this == other; }
	p_bool op_NotEqual(Semantic_Analyzer_ const * other) const { return this != other; }
	static auto Analyze_(::Syntax_Node_ const *_Nonnull const package_syntax_) -> ::Package_ const *_Nonnull;
};

class Semantic_Node_
{
public:
	p_bool op_Equal(Semantic_Node_ const * other) const { return this == other; }
	p_bool op_NotEqual(Semantic_Node_ const * other) const { return this != other; }
	::Syntax_Node_ const *_Nonnull Syntax_;
	p_int Type_;
	p_bool IsMissing_;
	::Source_Text_ const *_Nonnull Source_;
	p_uint Start_;
	p_uint Length_;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull Children_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull Diagnostics_;
	::Symbol_ const *_Nullable symbol_;
	Semantic_Node_(::Syntax_Node_ const *_Nonnull const syntax_);
	auto get_text_span_() const -> ::Text_Span_ const *_Nonnull;
	auto GetText_() const -> p_string;
	auto BindSymbol_(::Symbol_ const *_Nonnull const symbol_) -> void;
	auto FirstChildOfType_(p_int const type_) const -> ::Semantic_Node_ *_Nullable;
	auto ChildrenOfType_(p_int const type_) const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull;
	auto Members_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull;
	auto Statements_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull;
	auto Parameters_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull;
	auto HasChildOfType_(p_int const type_) const -> p_bool;
	auto Add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void;
	auto AllDiagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull;
	auto CollectDiagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
};

class Symbol_
{
public:
	p_bool op_Equal(Symbol_ const * other) const { return this == other; }
	p_bool op_NotEqual(Symbol_ const * other) const { return this != other; }
	::Symbol_ const *_Nullable Parent_;
	p_string Name_;
	p_int Type_;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull Declarations_;
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull Children_;
	p_bool IsPrimitive_;
	Symbol_(::Symbol_ const *_Nullable const parent_, p_string const name_);
	Symbol_(::Symbol_ const *_Nullable const parent_, p_string const name_, p_int const type_);
	Symbol_(p_string const name_);
	auto Get_(p_string const name_, p_int const type_) const -> ::Symbol_ const *_Nullable;
	auto is_value_type_() const -> p_bool;
};

class Symbol_Builder_
{
public:
	p_bool op_Equal(Symbol_Builder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Symbol_Builder_ const * other) const { return this != other; }
	auto build_symbols_(::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilation_units_) const -> ::Symbol_ const *_Nonnull;
	auto build_symbols_(::Symbol_ const *_Nonnull const parent_, ::Semantic_Node_ *_Nonnull const node_) const -> void;
	auto build_function_symbols_(::Symbol_ const *_Nonnull const parent_, ::Semantic_Node_ *_Nonnull const node_, ::Symbol_ const *_Nonnull const symbol_) const -> void;
	auto build_runtime_library_symbols_(::Symbol_ const *_Nonnull const package_) const -> void;
};

class Compilation_Unit_Parser_
{
public:
	p_bool op_Equal(Compilation_Unit_Parser_ const * other) const { return this == other; }
	p_bool op_NotEqual(Compilation_Unit_Parser_ const * other) const { return this != other; }
	::Token_Stream_ *_Nonnull tokenStream_;
	::Syntax_Node_ const *_Nullable token_;
	::Syntax_Node_ const *_Nullable compilationUnit_;
	Compilation_Unit_Parser_(::Token_Stream_ *_Nonnull const tokenStream_);
	auto Parse_() -> ::Syntax_Node_ const *_Nonnull;
	auto AcceptToken_() -> ::Syntax_Node_ const *_Nullable;
	auto ExpectToken_(p_int const tokenType_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseTypeName_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseNonOptionalType_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseType_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseAtom_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseCallArguments_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseExpression_(p_int const minPrecedence_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseExpression_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseStatement_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseIfStatement_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseVariableDeclaration_(p_bool const allowInitializer_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseBlock_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseParameterList_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseMemberDeclaration_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseDeclaration_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseCompilationUnit_() -> ::Syntax_Node_ const *_Nonnull;
};

class Lexer_
{
public:
	p_bool op_Equal(Lexer_ const * other) const { return this == other; }
	p_bool op_NotEqual(Lexer_ const * other) const { return this != other; }
	auto Analyze_(::Source_Text_ const *_Nonnull const source_) const -> ::Token_Stream_ *_Nonnull;
};

class Parser_
{
public:
	p_bool op_Equal(Parser_ const * other) const { return this == other; }
	p_bool op_NotEqual(Parser_ const * other) const { return this != other; }
	Parser_();
	auto ParsePackage_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) const -> ::Syntax_Node_ const *_Nonnull;
};

class Syntax_Node_
{
public:
	p_bool op_Equal(Syntax_Node_ const * other) const { return this == other; }
	p_bool op_NotEqual(Syntax_Node_ const * other) const { return this != other; }
	p_int Type_;
	p_bool IsMissing_;
	::Source_Text_ const *_Nonnull Source_;
	p_uint Start_;
	p_uint Length_;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull Children_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull Diagnostics_;
	Syntax_Node_(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_, p_uint const length_);
	Syntax_Node_(p_int const type_, p_bool const isMissing_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_, p_uint const length_);
	Syntax_Node_(p_int const type_, ::Syntax_Node_ const *_Nonnull const child_);
	Syntax_Node_(p_int const type_, ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const children_);
	auto GetText_() const -> p_string;
	auto FirstChildOfType_(p_int const type_) const -> ::Syntax_Node_ const *_Nullable;
	auto HasChildOfType_(p_int const type_) const -> p_bool;
	auto Add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void;
	auto AllDiagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull;
	auto CollectDiagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
};

class Token_Stream_
{
public:
	p_bool op_Equal(Token_Stream_ const * other) const { return this == other; }
	p_bool op_NotEqual(Token_Stream_ const * other) const { return this != other; }
	::Source_Text_ const *_Nonnull Source_;
	p_uint position_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_;
	p_bool endOfFile_;
	Token_Stream_(::Source_Text_ const *_Nonnull const source_);
	auto GetNextToken_() -> ::Syntax_Node_ const *_Nullable;
	auto EndOfFile_() -> ::Syntax_Node_ const *_Nullable;
	auto NewIdentifierOrKeyword_(p_uint const end_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewOperator_(p_int const type_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewOperator_(p_int const type_, p_uint const length_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewToken_(p_int const type_, p_uint const end_) -> ::Syntax_Node_ const *_Nonnull;
	static auto IsIdentifierChar_(p_code_point const c_) -> p_bool;
	static auto IsNumberChar_(p_code_point const c_) -> p_bool;
};

class Token_Type_
{
public:
	p_bool op_Equal(Token_Type_ const * other) const { return this == other; }
	p_bool op_NotEqual(Token_Type_ const * other) const { return this != other; }
};

class Diagnostic_
{
public:
	p_bool op_Equal(Diagnostic_ const * other) const { return this == other; }
	p_bool op_NotEqual(Diagnostic_ const * other) const { return this != other; }
	p_int Level_;
	p_int Phase_;
	::Source_Text_ const *_Nonnull Source_;
	::Text_Span_ const *_Nonnull Span_;
	::Text_Position_ const *_Nonnull Position_;
	p_string Message_;
	Diagnostic_(p_int const level_, p_int const phase_, ::Source_Text_ const *_Nonnull const source_, ::Text_Span_ const *_Nonnull const span_, p_string const message_);
};

class Emitter_
{
public:
	p_bool op_Equal(Emitter_ const * other) const { return this == other; }
	p_bool op_NotEqual(Emitter_ const * other) const { return this != other; }
	::Package_ const *_Nonnull package_;
	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull resources_;
	::Source_File_Builder_ *_Nonnull TypeDeclarations_;
	::Source_File_Builder_ *_Nonnull FunctionDeclarations_;
	::Source_File_Builder_ *_Nonnull ClassDeclarations_;
	::Source_File_Builder_ *_Nonnull GlobalDefinitions_;
	::Source_File_Builder_ *_Nonnull Definitions_;
	p_string MainFunctionReturnType_;
	p_bool MainFunctionAcceptsConsole_;
	p_bool MainFunctionAcceptsArgs_;
	Emitter_(::Package_ const *_Nonnull const package_, ::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const resources_);
	auto Emit_() -> p_string;
	static auto is_value_type_(::Semantic_Node_ const *_Nonnull const type_) -> p_bool;
	static auto convert_type_name_(::Semantic_Node_ const *_Nonnull const type_) -> p_string;
	static auto convert_reference_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull type_, p_bool const nullable_, p_bool const mutable_value_) -> p_string;
	static auto convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull type_, p_bool const optional_) -> p_string;
	static auto convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull const type_) -> p_string;
	auto ConvertParameterList_(::Semantic_Node_ const *_Nonnull const parameterList_, p_bool const isMainFunction_) -> p_string;
	auto ConvertParameterList_(::Semantic_Node_ const *_Nonnull const parameterList_) -> p_string;
	static auto ConvertExpression_(::Semantic_Node_ const *_Nonnull const syntax_, ::Source_File_Builder_ *_Nonnull const builder_) -> void;
	auto EmitStatement_(::Semantic_Node_ const *_Nonnull const statement_) -> void;
	auto EmitMemberDeclaration_(::Semantic_Node_ const *_Nonnull const member_, p_string const className_) -> void;
	auto EmitDeclaration_(::Semantic_Node_ const *_Nonnull const declaration_) -> void;
	auto EmitCompilationUnit_(::Semantic_Node_ const *_Nonnull const unit_) -> void;
	auto EmitPreamble_() -> void;
	auto EmitEntryPointAdapter_() -> void;
};

// Global Definitions
p_int const Success_ = p_int(0);
p_int const UsageError_ = p_int(64);
p_int const DataError_ = p_int(65);
p_int const IdentifierSymbol_ = p_int(0);
p_int const PrimitiveSymbol_ = p_int(1);
p_int const ConstructorSymbol_ = p_int(2);
p_int const OperatorSymbol_ = p_int(3);
p_int const PackageSymbol_ = p_int(4);
p_int const SkippedTokens_ = p_int(1)->op_Negate();
p_int const EndOfFileToken_ = p_int(0);
p_int const LeftBrace_ = p_int(1);
p_int const RightBrace_ = p_int(2);
p_int const LeftParen_ = p_int(3);
p_int const RightParen_ = p_int(4);
p_int const Semicolon_ = p_int(5);
p_int const Comma_ = p_int(6);
p_int const Dot_ = p_int(7);
p_int const Colon_ = p_int(8);
p_int const LeftBracket_ = p_int(9);
p_int const RightBracket_ = p_int(10);
p_int const Question_ = p_int(11);
p_int const EqualsEquals_ = p_int(12);
p_int const Equals_ = p_int(13);
p_int const PlusEquals_ = p_int(14);
p_int const Plus_ = p_int(15);
p_int const Arrow_ = p_int(16);
p_int const MinusEquals_ = p_int(17);
p_int const Minus_ = p_int(18);
p_int const Slash_ = p_int(19);
p_int const EqualsSlashEquals_ = p_int(20);
p_int const LessThanEquals_ = p_int(21);
p_int const LessThan_ = p_int(22);
p_int const GreaterThanEquals_ = p_int(23);
p_int const GreaterThan_ = p_int(24);
p_int const StringLiteral_ = p_int(25);
p_int const CodePointLiteral_ = p_int(26);
p_int const Identifier_ = p_int(27);
p_int const Number_ = p_int(28);
p_int const NewKeyword_ = p_int(29);
p_int const NotOperator_ = p_int(30);
p_int const NullReservedWord_ = p_int(31);
p_int const SelfKeyword_ = p_int(32);
p_int const TrueKeyword_ = p_int(33);
p_int const FalseKeyword_ = p_int(34);
p_int const IdentifierName_ = p_int(35);
p_int const GenericName_ = p_int(36);
p_int const QualifiedName_ = p_int(37);
p_int const PackageQualifiedName_ = p_int(38);
p_int const MutableKeyword_ = p_int(39);
p_int const OptionalType_ = p_int(40);
p_int const PredefinedType_ = p_int(41);
p_int const CodePoint_ = p_int(42);
p_int const String_ = p_int(43);
p_int const Int_ = p_int(44);
p_int const Bool_ = p_int(45);
p_int const Void_ = p_int(46);
p_int const UnsignedInt_ = p_int(47);
p_int const ParameterList_ = p_int(48);
p_int const Parameter_ = p_int(49);
p_int const SelfParameter_ = p_int(50);
p_int const VarKeyword_ = p_int(51);
p_int const MutableType_ = p_int(52);
p_int const NewExpression_ = p_int(53);
p_int const ArgumentList_ = p_int(54);
p_int const NotExpression_ = p_int(55);
p_int const ParenthesizedExpression_ = p_int(56);
p_int const NoneLiteralExpression_ = p_int(57);
p_int const SelfExpression_ = p_int(58);
p_int const TrueLiteralExpression_ = p_int(59);
p_int const FalseLiteralExpression_ = p_int(60);
p_int const StringLiteralExpression_ = p_int(61);
p_int const CodePointLiteralExpression_ = p_int(62);
p_int const NumericLiteralExpression_ = p_int(63);
p_int const AssignmentExpression_ = p_int(64);
p_int const OrExpression_ = p_int(65);
p_int const AndExpression_ = p_int(66);
p_int const EqualExpression_ = p_int(67);
p_int const NotEqualExpression_ = p_int(68);
p_int const AndKeyword_ = p_int(69);
p_int const OrKeyword_ = p_int(70);
p_int const ComparisonExpression_ = p_int(71);
p_int const AddExpression_ = p_int(72);
p_int const SubtractExpression_ = p_int(73);
p_int const InvocationExpression_ = p_int(74);
p_int const MemberAccessExpression_ = p_int(75);
p_int const ElementAccessExpression_ = p_int(76);
p_int const NegateExpression_ = p_int(77);
p_int const ReturnKeyword_ = p_int(78);
p_int const ReturnStatement_ = p_int(79);
p_int const LoopKeyword_ = p_int(80);
p_int const LoopStatement_ = p_int(81);
p_int const Block_ = p_int(82);
p_int const WhileKeyword_ = p_int(83);
p_int const WhileStatement_ = p_int(84);
p_int const ForKeyword_ = p_int(85);
p_int const ForStatement_ = p_int(86);
p_int const LetKeyword_ = p_int(87);
p_int const VariableDeclaration_ = p_int(88);
p_int const LocalDeclarationStatement_ = p_int(89);
p_int const InKeyword_ = p_int(90);
p_int const DoKeyword_ = p_int(91);
p_int const DoWhileStatement_ = p_int(92);
p_int const IfKeyword_ = p_int(93);
p_int const ElseKeyword_ = p_int(94);
p_int const IfStatement_ = p_int(95);
p_int const ElseClause_ = p_int(96);
p_int const BreakKeyword_ = p_int(97);
p_int const BreakStatement_ = p_int(98);
p_int const ContinueKeyword_ = p_int(99);
p_int const ContinueStatement_ = p_int(100);
p_int const ExpressionStatement_ = p_int(101);
p_int const PublicKeyword_ = p_int(102);
p_int const ProtectedKeyword_ = p_int(103);
p_int const InternalKeyword_ = p_int(104);
p_int const PrivateKeyword_ = p_int(105);
p_int const ConstructorDeclaration_ = p_int(106);
p_int const FieldDeclaration_ = p_int(107);
p_int const MethodDeclaration_ = p_int(108);
p_int const GlobalDeclaration_ = p_int(109);
p_int const ClassKeyword_ = p_int(110);
p_int const ClassDeclaration_ = p_int(111);
p_int const EnumKeyword_ = p_int(112);
p_int const StructKeyword_ = p_int(113);
p_int const EnumDeclaration_ = p_int(114);
p_int const EnumMemberDeclaration_ = p_int(115);
p_int const FunctionDeclaration_ = p_int(116);
p_int const CompilationUnit_ = p_int(117);
p_int const PackageNode_ = p_int(118);
p_int const Percent_ = p_int(119);
p_int const RemainderExpression_ = p_int(120);
p_int const Pipe_ = p_int(121);
p_int const MagnitudeExpression_ = p_int(122);
p_int const Asterisk_ = p_int(123);
p_int const MultiplyExpression_ = p_int(124);
p_int const DivideExpression_ = p_int(125);
p_int const NoneKeyword_ = p_int(126);
p_int const StructDeclaration_ = p_int(127);
p_int const ImmutableType_ = p_int(128);
p_int const Lexing_ = p_int(1);
p_int const Parsing_ = p_int(2);
p_int const Analysis_ = p_int(3);
p_int const Info_ = p_int(1);
p_int const Warning_ = p_int(2);
p_int const RuntimeError_ = p_int(3);
p_int const CompilationError_ = p_int(4);
p_int const FatalCompilationError_ = p_int(5);

// Definitions

auto compile_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) -> ::Package_ const *_Nonnull
{
	::Parser_ const *_Nonnull const parser_ = (new ::Parser_());
	::Syntax_Node_ const *_Nonnull const packageSyntax_ = parser_->ParsePackage_(sources_);
	::Semantic_Analyzer_ const *_Nonnull const semanticAnalyzer_ = (new ::Semantic_Analyzer_());
	::Package_ const *_Nonnull const package_ = semanticAnalyzer_->Analyze_(packageSyntax_);
	return package_;
}

auto write_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> void
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		::Text_Position_ const *_Nonnull const position_ = diagnostic_->Position_;
		p_string severity_;
		if (diagnostic_->Level_->op_Equal(Info_).Value)
		{
			severity_ = p_string("Informational");
		}
		else if (diagnostic_->Level_->op_Equal(Warning_).Value)
		{
			severity_ = p_string("Warning");
		}
		else
		{
			severity_ = p_string("Error");
		}

		console_->WriteLine_(diagnostic_->Source_->Path_->op_Add(p_string(":"))->op_Add(position_->Line_)->op_Add(p_string(":"))->op_Add(position_->Column_)->op_Add(p_string(" "))->op_Add(severity_)->op_Add(p_string(":")));
		console_->WriteLine_(p_string("  ")->op_Add(diagnostic_->Message_));
	}
}

auto has_errors_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> p_bool
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		if (diagnostic_->Level_->op_GreaterThanOrEqual(CompilationError_).Value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> p_int
{
	::System_::Collections_::List_<p_string> *_Nonnull const sourceFilePaths_ = (new ::System_::Collections_::List_<p_string>());
	::System_::Collections_::List_<p_string> *_Nonnull const resourceFilePaths_ = (new ::System_::Collections_::List_<p_string>());
	p_string outputFilePath_ = p_string("");
	p_bool verbose_ = p_bool(false);
	p_int argType_ = p_int(0);
	for (p_string const arg_ : *(args_))
	{
		if (argType_->op_Equal(p_int(0)).Value)
		{
			if (arg_->op_Equal(p_string("-r")).Value)
			{
				argType_ = p_int(1);
			}
			else if (arg_->op_Equal(p_string("-o")).Value)
			{
				argType_ = p_int(2);
			}
			else if (LogicalOr(arg_->op_Equal(p_string("-v")), [&] { return arg_->op_Equal(p_string("--verbose")); }).Value)
			{
				verbose_ = p_bool(true);
			}
			else
			{
				sourceFilePaths_->Add_(arg_);
			}
		}
		else if (argType_->op_Equal(p_int(1)).Value)
		{
			resourceFilePaths_->Add_(arg_);
			argType_ = p_int(0);
		}
		else if (argType_->op_Equal(p_int(2)).Value)
		{
			outputFilePath_ = arg_;
			argType_ = p_int(0);
		}
	}

	if (verbose_.Value)
	{
		console_->WriteLine_(p_string("Adamant Compiler v0.1.0"));
	}

	if (LogicalOr(sourceFilePaths_->op_Magnitude()->op_Equal(p_int(0)), [&] { return outputFilePath_->op_Equal(p_string("")); }).Value)
	{
		console_->WriteLine_(p_string("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return UsageError_;
	}

	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> *_Nonnull const resources_ = (new ::System_::Collections_::List_<::Source_Text_ const *_Nonnull>());
	if (resourceFilePaths_->op_Magnitude()->op_GreaterThan(p_int(0)).Value)
	{
		if (verbose_.Value)
		{
			console_->WriteLine_(p_string("Reading Resources:"));
		}

		for (p_string const resourceFilePath_ : *(resourceFilePaths_))
		{
			if (verbose_.Value)
			{
				console_->WriteLine_(p_string("  ")->op_Add(resourceFilePath_));
			}

			resources_->Add_(read_source_(resourceFilePath_));
		}
	}

	if (verbose_.Value)
	{
		console_->WriteLine_(p_string("Compiling:"));
	}

	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> *_Nonnull const sources_ = (new ::System_::Collections_::List_<::Source_Text_ const *_Nonnull>());
	for (p_string const sourceFilePath_ : *(sourceFilePaths_))
	{
		if (verbose_.Value)
		{
			console_->WriteLine_(p_string("  ")->op_Add(sourceFilePath_));
		}

		sources_->Add_(read_source_(sourceFilePath_));
	}

	::Package_ const *_Nonnull const package_ = compile_(sources_);
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_ = package_->AllDiagnostics_();
	write_(console_, diagnostics_);
	if (has_errors_(diagnostics_).Value)
	{
		return DataError_;
	}

	::Emitter_ *_Nonnull emitter_ = (new ::Emitter_(package_, resources_));
	p_string const translated_ = emitter_->Emit_();
	if (verbose_.Value)
	{
		console_->Write_(p_string("Output: "));
		console_->WriteLine_(outputFilePath_);
	}

	::System_::IO_::File_Writer_ *_Nonnull const outputFile_ = (new ::System_::IO_::File_Writer_(outputFilePath_));
	outputFile_->Write_(translated_);
	outputFile_->Close_();
	p_string outputDirPath_ = outputFilePath_;
	p_int index_ = outputDirPath_->LastIndexOf_(p_code_point('/'));
	if (index_->op_NotEqual(p_int(1)->op_Negate()).Value)
	{
		outputDirPath_ = outputDirPath_->Substring_(p_int(0), index_->op_Add(p_int(1)));
	}

	index_ = outputDirPath_->LastIndexOf_(p_code_point('\\'));
	if (index_->op_NotEqual(p_int(1)->op_Negate()).Value)
	{
		outputDirPath_ = outputDirPath_->Substring_(p_int(0), index_->op_Add(p_int(1)));
	}

	if (verbose_.Value)
	{
		console_->Write_(p_string("Outputting RuntimeLibrary to: "));
		console_->WriteLine_(outputDirPath_);
	}

	::System_::IO_::File_Writer_ *_Nonnull resourceFile_ = (new ::System_::IO_::File_Writer_(outputDirPath_->op_Add(p_string("RuntimeLibrary.h"))));
	resourceFile_->Write_(resource_manager_->GetString_(p_string("RuntimeLibrary.h")));
	resourceFile_->Close_();
	resourceFile_ = (new ::System_::IO_::File_Writer_(outputDirPath_->op_Add(p_string("RuntimeLibrary.cpp"))));
	resourceFile_->Write_(resource_manager_->GetString_(p_string("RuntimeLibrary.cpp")));
	resourceFile_->Close_();
	return Success_;
}

auto read_source_(p_string const path_) -> ::Source_Text_ const *_Nonnull
{
	::System_::IO_::File_Reader_ *_Nonnull const file_ = (new ::System_::IO_::File_Reader_(path_));
	p_string const contents_ = file_->ReadToEndSync_();
	file_->Close_();
	return (new ::Source_Text_(p_string("<default>"), path_, contents_));
}

::Line_Info_::Line_Info_(::Source_Text_ const *_Nonnull const source_, ::System_::Collections_::List_<p_int> const *_Nonnull const lineStarts_)
{
	this->source_ = source_;
	this->lineStarts_ = lineStarts_;
}

auto ::Line_Info_::Count_() const -> p_int
{
	return lineStarts_->op_Magnitude();
}

auto ::Line_Info_::Get_(p_int const lineNumber_) const -> ::Text_Line_ const *_Nonnull
{
	p_int const index_ = lineNumber_->op_Subtract(p_int(1));
	p_int const start_ = lineStarts_->op_Element(index_);
	if (index_->op_Equal(lineStarts_->op_Magnitude()->op_Subtract(p_int(1))).Value)
	{
		return TextLineFromTo_(source_, start_, source_->ByteLength_());
	}

	p_int const end_ = lineStarts_->op_Element(index_->op_Add(p_int(1)));
	return TextLineFromTo_(source_, start_, end_);
}

auto ::Line_Info_::LineNumber_(p_int const offset_) const -> p_int
{
	p_int left_ = p_int(0);
	p_int right_ = lineStarts_->op_Magnitude()->op_Subtract(p_int(1));
	while (left_->op_LessThanOrEqual(right_).Value)
	{
		p_int const mid_ = left_->op_Add(right_->op_Subtract(left_)->op_Divide(p_int(2)));
		p_int const midLineStart_ = lineStarts_->op_Element(mid_);
		if (midLineStart_->op_LessThan(offset_).Value)
		{
			left_ = mid_->op_Add(p_int(1));
		}
		else if (midLineStart_->op_GreaterThan(offset_).Value)
		{
			right_ = mid_->op_Subtract(p_int(1));
		}
		else
		{
			return mid_->op_Add(p_int(1));
		}
	}

	return left_;
}

::Source_Text_::Source_Text_(p_string const package_, p_string const path_, p_string const text_)
{
	Package_ = package_;
	Path_ = path_;
	p_string name_ = path_;
	p_int index_ = name_->LastIndexOf_(p_code_point('/'));
	if (index_->op_NotEqual(p_int(1)->op_Negate()).Value)
	{
		name_ = name_->Substring_(index_->op_Add(p_int(1)));
	}

	index_ = name_->LastIndexOf_(p_code_point('\\'));
	if (index_->op_NotEqual(p_int(1)->op_Negate()).Value)
	{
		name_ = name_->Substring_(index_->op_Add(p_int(1)));
	}

	Name_ = name_;
	Text_ = text_;
	Lines_ = (new ::Line_Info_(this, LineStarts_()));
}

auto ::Source_Text_::LineStarts_() const -> ::System_::Collections_::List_<p_int> const *_Nonnull
{
	p_int const length_ = ByteLength_();
	::System_::Collections_::List_<p_int> *_Nonnull const lineStarts_ = (new ::System_::Collections_::List_<p_int>());
	lineStarts_->Add_(p_int(0));
	p_int position_ = p_int(0);
	while (position_->op_LessThan(length_).Value)
	{
		p_code_point const c_ = Text_->op_Element(position_);
		position_->op_AddAssign(p_int(1));
		if (LogicalAnd(c_->op_GreaterThan(p_code_point('\r')), [&] { return c_->op_LessThanOrEqual(p_code_point('\x7F')); }).Value)
		{
			continue;
		}

		if (c_->op_Equal(p_code_point('\r')).Value)
		{
			if (LogicalAnd(position_->op_LessThan(length_), [&] { return Text_->op_Element(position_)->op_Equal(p_code_point('\n')); }).Value)
			{
				position_->op_AddAssign(p_int(1));
			}
		}
		else if (LogicalOr(LogicalOr(LogicalOr(c_->op_Equal(p_code_point('\n')), [&] { return c_->op_Equal(p_code_point('\x0B')); }), [&] { return c_->op_Equal(p_code_point('\f')); }), [&] { return c_->op_Equal(p_code_point('\x85')); }).Value)
		{
		}
		else
		{
			continue;
		}

		lineStarts_->Add_(position_);
	}

	return lineStarts_;
}

auto ::Source_Text_::ByteLength_() const -> p_int
{
	return Text_->ByteLength_();
}

auto ::Source_Text_::PositionOfStart_(::Text_Span_ const *_Nonnull const span_) const -> ::Text_Position_ const *_Nonnull
{
	p_int const offset_ = span_->Start_;
	p_int const lineNumber_ = Lines_->LineNumber_(offset_);
	p_int const lineStart_ = Lines_->Get_(lineNumber_)->Start_;
	p_int column_ = offset_->op_Subtract(lineStart_)->op_Add(p_int(1));
	p_int i_ = lineStart_;
	while (i_->op_LessThan(offset_).Value)
	{
		if (Text_->op_Element(i_)->op_Equal(p_code_point('\t')).Value)
		{
			column_->op_AddAssign(p_int(3));
		}

		i_->op_AddAssign(p_int(1));
	}

	return (new ::Text_Position_(offset_, lineNumber_, column_));
}

::Text_Line_::Text_Line_(::Source_Text_ const *_Nonnull const source_, p_int const start_, p_int const length_)
{
	Source_ = source_;
	Start_ = start_;
	Length_ = length_;
}

auto ::Text_Line_::End_() const -> p_int
{
	return Start_->op_Add(Length_);
}

auto TextLineFromTo_(::Source_Text_ const *_Nonnull const source_, p_int const start_, p_int const end_) -> ::Text_Line_ const *_Nonnull
{
	return (new ::Text_Line_(source_, start_, end_->op_Subtract(start_)));
}

::Text_Position_::Text_Position_(p_int const offset_, p_int const line_, p_int const column_)
{
	Offset_ = offset_;
	Line_ = line_;
	Column_ = column_;
}

::Text_Span_::Text_Span_(p_int const start_, p_int const length_)
{
	Start_ = start_;
	Length_ = length_;
}

auto ::Text_Span_::End_() const -> p_int
{
	return Start_->op_Add(Length_);
}

auto format_error_(p_string const message_) -> p_string
{
	return p_string("<$ ")->op_Add(message_)->op_Add(p_string(" $>"));
}

::Source_File_Builder_::Source_File_Builder_()
{
	code_ = (new ::System_::Text_::String_Builder_());
	indent_ = (new ::System_::Text_::String_Builder_());
	firstElement_ = p_bool(true);
	afterBlock_ = p_bool(true);
}

auto ::Source_File_Builder_::Error_(p_string const message_) -> void
{
	code_->Append_(format_error_(message_));
}

auto ::Source_File_Builder_::BeginLine_(p_string const value_) -> void
{
	code_->Append_(indent_);
	code_->Append_(value_);
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::Write_(p_string const value_) -> void
{
	code_->Append_(value_);
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::EndLine_(p_string const value_) -> void
{
	code_->Append_(value_);
	code_->AppendLine_();
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::WriteLine_(p_string const value_) -> void
{
	code_->Append_(indent_);
	code_->Append_(value_);
	code_->AppendLine_();
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::BlankLine_() -> void
{
	code_->AppendLine_();
	firstElement_ = p_bool(true);
	afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::ElementSeparatorLine_() -> void
{
	if (firstElement_->op_Not().Value)
	{
		code_->AppendLine_();
		firstElement_ = p_bool(true);
		afterBlock_ = p_bool(false);
	}
}

auto ::Source_File_Builder_::StatementSeparatorLine_() -> void
{
	if (afterBlock_.Value)
	{
		code_->AppendLine_();
		firstElement_ = p_bool(true);
		afterBlock_ = p_bool(false);
	}
}

auto ::Source_File_Builder_::BeginBlock_() -> void
{
	WriteLine_(p_string("{"));
	indent_->Append_(p_string("\t"));
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::EndBlock_() -> void
{
	indent_->Remove_(p_int(0), p_int(1));
	WriteLine_(p_string("}"));
	afterBlock_ = p_bool(true);
}

auto ::Source_File_Builder_::EndBlockWithSemicolon_() -> void
{
	indent_->Remove_(p_int(0), p_int(1));
	WriteLine_(p_string("};"));
}

auto ::Source_File_Builder_::ToString_() const -> p_string
{
	return code_->ToString_();
}

::Binding_Scope_::Binding_Scope_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_, ::Primitive_Types_ const *_Nonnull const primitives_)
{
	this->containing_scope_ = ::None;
	this->symbols_ = symbols_;
	this->primitives_ = primitives_;
}

::Binding_Scope_::Binding_Scope_(::Binding_Scope_ const *_Nonnull const containing_scope_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_)
{
	this->containing_scope_ = containing_scope_;
	this->symbols_ = symbols_;
	this->primitives_ = containing_scope_->primitives_;
}

auto ::Binding_Scope_::GetPrimitive_(p_string const name_) const -> ::Symbol_ const *_Nullable
{
	return primitives_->Get_(name_);
}

auto ::Binding_Scope_::Lookup_(p_string const name_) const -> ::Symbol_ const *_Nullable
{
	return Lookup_(name_, IdentifierSymbol_);
}

auto ::Binding_Scope_::Lookup_(p_string const name_, p_int const type_) const -> ::Symbol_ const *_Nullable
{
	for (::Symbol_ const *_Nonnull const symbol_ : *(symbols_))
	{
		if (LogicalAnd(symbol_->Name_->op_Equal(name_), [&] { return symbol_->Type_->op_Equal(type_); }).Value)
		{
			return symbol_;
		}
	}

	if (containing_scope_->op_NotEqual(::None).Value)
	{
		return containing_scope_->Lookup_(name_, type_);
	}

	return ::None;
}

auto ::Name_Binder_::bind_(::Package_ const *_Nonnull const package_) const -> void
{
	::Binding_Scope_ const *_Nonnull const global_scope_ = (new ::Binding_Scope_(package_->symbol_->Children_, package_->PrimitiveTypes_));
	for (::Semantic_Node_ *_Nonnull const compilation_unit_ : *(package_->CompilationUnits_))
	{
		bind_(compilation_unit_, global_scope_);
	}
}

auto ::Name_Binder_::bind_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void
{
	if (node_->Type_->op_Equal(CompilationUnit_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const child_ : *(node_->Children_))
		{
			bind_(child_, scope_);
		}
	}
	else if (LogicalOr(node_->Type_->op_Equal(FunctionDeclaration_), [&] { return node_->Type_->op_Equal(MethodDeclaration_); }).Value)
	{
		::Semantic_Node_ *_Nonnull const parameters_ = node_->FirstChildOfType_(ParameterList_);
		bind_(parameters_, scope_);
		::Semantic_Node_ *_Nonnull const return_type_ = node_->Children_->op_Element(p_int(4));
		bind_type_(return_type_, scope_);
		::Binding_Scope_ const *_Nonnull const function_scope_ = (new ::Binding_Scope_(scope_, node_->symbol_->Children_));
		::Semantic_Node_ *_Nonnull const body_ = node_->FirstChildOfType_(Block_);
		bind_(body_, function_scope_);
	}
	else if (node_->Type_->op_Equal(ParameterList_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const parameter_ : *(node_->ChildrenOfType_(Parameter_)))
		{
			bind_(parameter_, scope_);
		}
	}
	else if (node_->Type_->op_Equal(Parameter_).Value)
	{
		::Semantic_Node_ *_Nonnull const type_ = node_->Children_->op_Element(node_->Children_->op_Magnitude()->op_Subtract(p_int(1)));
		bind_type_(type_, scope_);
	}
	else if (LogicalOr(node_->Type_->op_Equal(ClassDeclaration_), [&] { return node_->Type_->op_Equal(StructDeclaration_); }).Value)
	{
		::Binding_Scope_ const *_Nonnull const type_scope_ = (new ::Binding_Scope_(scope_, node_->symbol_->Children_));
		for (::Semantic_Node_ *_Nonnull const member_ : *(node_->Members_()))
		{
			bind_(member_, type_scope_);
		}
	}
	else if (LogicalOr(node_->Type_->op_Equal(FieldDeclaration_), [&] { return node_->Type_->op_Equal(GlobalDeclaration_); }).Value)
	{
		::Semantic_Node_ *_Nonnull const variable_declaration_ = node_->FirstChildOfType_(VariableDeclaration_);
		bind_(variable_declaration_, scope_);
	}
	else if (node_->Type_->op_Equal(ConstructorDeclaration_).Value)
	{
		::Semantic_Node_ *_Nonnull const parameters_ = node_->FirstChildOfType_(ParameterList_);
		bind_(parameters_, scope_);
		::Binding_Scope_ const *_Nonnull const constructor_scope_ = (new ::Binding_Scope_(scope_, node_->symbol_->Children_));
		::Semantic_Node_ *_Nonnull const body_ = node_->FirstChildOfType_(Block_);
		bind_(body_, constructor_scope_);
	}
	else if (node_->Type_->op_Equal(VariableDeclaration_).Value)
	{
		::Semantic_Node_ *_Nonnull const type_ = node_->Children_->op_Element(p_int(3));
		bind_type_(type_, scope_);
		if (node_->Children_->op_Magnitude()->op_Equal(p_int(6)).Value)
		{
			::Semantic_Node_ *_Nonnull const initalizer_ = node_->Children_->op_Element(p_int(5));
			bind_(initalizer_, scope_);
		}
	}
	else if (node_->Type_->op_Equal(EnumDeclaration_).Value)
	{
	}
	else if (node_->Type_->op_Equal(Block_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const statement_ : *(node_->Statements_()))
		{
			bind_(statement_, scope_);
		}
	}
	else if (node_->Type_->op_Equal(LoopStatement_).Value)
	{
		bind_(node_->FirstChildOfType_(Block_), scope_);
	}
	else if (node_->Type_->op_Equal(WhileStatement_).Value)
	{
		bind_(node_->Children_->op_Element(p_int(1)), scope_);
		bind_(node_->FirstChildOfType_(Block_), scope_);
	}
	else if (node_->Type_->op_Equal(DoWhileStatement_).Value)
	{
		bind_(node_->FirstChildOfType_(Block_), scope_);
		bind_(node_->Children_->op_Element(p_int(3)), scope_);
	}
	else if (node_->Type_->op_Equal(ForStatement_).Value)
	{
		bind_(node_->FirstChildOfType_(VariableDeclaration_), scope_);
		bind_(node_->FirstChildOfType_(Block_), scope_);
	}
	else if (node_->Type_->op_Equal(LocalDeclarationStatement_).Value)
	{
		bind_(node_->FirstChildOfType_(VariableDeclaration_), scope_);
	}
	else if (node_->Type_->op_Equal(IfStatement_).Value)
	{
		bind_(node_->Children_->op_Element(p_int(1)), scope_);
		bind_(node_->FirstChildOfType_(Block_), scope_);
		::Semantic_Node_ *_Nullable const elseClause_ = node_->FirstChildOfType_(ElseClause_);
		if (elseClause_->op_NotEqual(::None).Value)
		{
			bind_(elseClause_, scope_);
		}
	}
	else if (node_->Type_->op_Equal(ElseClause_).Value)
	{
		::Semantic_Node_ *_Nullable const block_ = node_->FirstChildOfType_(Block_);
		if (block_->op_NotEqual(::None).Value)
		{
			bind_(block_, scope_);
		}
		else
		{
			bind_(node_->FirstChildOfType_(IfStatement_), scope_);
		}
	}
	else if (node_->Type_->op_Equal(ExpressionStatement_).Value)
	{
		bind_(node_->Children_->op_Element(p_int(0)), scope_);
	}
	else if (node_->Type_->op_Equal(ReturnStatement_).Value)
	{
		::Semantic_Node_ *_Nonnull const child_ = node_->Children_->op_Element(p_int(1));
		if (child_->Type_->op_NotEqual(Semicolon_).Value)
		{
			bind_(child_, scope_);
		}
	}
	else if (node_->Type_->op_Equal(NewExpression_).Value)
	{
		bind_type_(node_->Children_->op_Element(p_int(1)), scope_);
		bind_(node_->Children_->op_Element(p_int(2)), scope_);
	}
	else if (LogicalOr(LogicalOr(LogicalOr(node_->Type_->op_Equal(NotExpression_), [&] { return node_->Type_->op_Equal(ParenthesizedExpression_); }), [&] { return node_->Type_->op_Equal(MagnitudeExpression_); }), [&] { return node_->Type_->op_Equal(NegateExpression_); }).Value)
	{
		bind_(node_->Children_->op_Element(p_int(1)), scope_);
	}
	else if (LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(node_->Type_->op_Equal(AssignmentExpression_), [&] { return node_->Type_->op_Equal(AndExpression_); }), [&] { return node_->Type_->op_Equal(OrExpression_); }), [&] { return node_->Type_->op_Equal(EqualExpression_); }), [&] { return node_->Type_->op_Equal(NotEqualExpression_); }), [&] { return node_->Type_->op_Equal(ComparisonExpression_); }), [&] { return node_->Type_->op_Equal(AddExpression_); }), [&] { return node_->Type_->op_Equal(SubtractExpression_); }), [&] { return node_->Type_->op_Equal(ElementAccessExpression_); }), [&] { return node_->Type_->op_Equal(RemainderExpression_); }), [&] { return node_->Type_->op_Equal(MultiplyExpression_); }), [&] { return node_->Type_->op_Equal(DivideExpression_); }).Value)
	{
		bind_(node_->Children_->op_Element(p_int(0)), scope_);
		bind_(node_->Children_->op_Element(p_int(2)), scope_);
	}
	else if (node_->Type_->op_Equal(MemberAccessExpression_).Value)
	{
		bind_(node_->Children_->op_Element(p_int(0)), scope_);
	}
	else if (node_->Type_->op_Equal(InvocationExpression_).Value)
	{
		bind_(node_->Children_->op_Element(p_int(0)), scope_);
		bind_(node_->Children_->op_Element(p_int(1)), scope_);
	}
	else if (node_->Type_->op_Equal(ArgumentList_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const child_ : *(node_->Children_))
		{
			if (LogicalAnd(LogicalAnd(child_->Type_->op_NotEqual(LeftParen_), [&] { return child_->Type_->op_NotEqual(Comma_); }), [&] { return child_->Type_->op_NotEqual(RightParen_); }).Value)
			{
				bind_(child_, scope_);
			}
		}
	}
	else if (node_->Type_->op_Equal(IdentifierName_).Value)
	{
		if (node_->IsMissing_.Value)
		{
			return;
		}

		p_string const name_ = node_->GetText_();
		::Symbol_ const *_Nonnull const symbol_ = scope_->Lookup_(name_);
		if (symbol_->op_Equal(::None).Value)
		{
			add_resolution_error_(node_);
		}
		else
		{
			node_->BindSymbol_(symbol_);
		}
	}
	else if (LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(node_->Type_->op_Equal(NumericLiteralExpression_), [&] { return node_->Type_->op_Equal(BreakStatement_); }), [&] { return node_->Type_->op_Equal(ContinueStatement_); }), [&] { return node_->Type_->op_Equal(NoneLiteralExpression_); }), [&] { return node_->Type_->op_Equal(SelfExpression_); }), [&] { return node_->Type_->op_Equal(TrueLiteralExpression_); }), [&] { return node_->Type_->op_Equal(FalseLiteralExpression_); }), [&] { return node_->Type_->op_Equal(StringLiteralExpression_); }), [&] { return node_->Type_->op_Equal(CodePointLiteralExpression_); }), [&] { return node_->Type_->op_Equal(EndOfFileToken_); }).Value)
	{
	}
	else
	{
		THROW_EXCEPTION_(p_string("`Name_Binder.bind()` unimplemented node type ")->op_Add(node_->Type_));
	}
}

auto ::Name_Binder_::bind_type_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void
{
	if (node_->Type_->op_Equal(PredefinedType_).Value)
	{
		p_string const name_ = node_->Children_->op_Element(p_int(0))->GetText_();
		::Symbol_ const *_Nonnull const symbol_ = scope_->GetPrimitive_(name_);
		if (symbol_->op_Equal(::None).Value)
		{
			THROW_EXCEPTION_(p_string("`Name_Binder.bind_type()` no symbol for primitive type ")->op_Add(name_));
		}

		node_->BindSymbol_(symbol_);
	}
	else if (node_->Type_->op_Equal(MutableType_).Value)
	{
		::Semantic_Node_ *_Nonnull const innerType_ = node_->Children_->op_Element(p_int(1));
		bind_type_(innerType_, scope_);
	}
	else if (LogicalOr(node_->Type_->op_Equal(ImmutableType_), [&] { return node_->Type_->op_Equal(OptionalType_); }).Value)
	{
		::Semantic_Node_ *_Nonnull const innerType_ = node_->Children_->op_Element(p_int(0));
		bind_type_(innerType_, scope_);
	}
	else if (node_->Type_->op_Equal(QualifiedName_).Value)
	{
		::Semantic_Node_ *_Nonnull const qualifier_ = node_->Children_->op_Element(p_int(0));
		bind_type_(qualifier_, scope_);
		if (qualifier_->symbol_->op_Equal(::None).Value)
		{
			THROW_EXCEPTION_(p_string("`Name_Binder.bind_type()` no symbol for qualifier ")->op_Add(qualifier_->GetText_()));
		}

		::Semantic_Node_ *_Nonnull const name_ = node_->Children_->op_Element(p_int(2));
		if (name_->Type_->op_Equal(IdentifierName_).Value)
		{
			::Symbol_ const *_Nonnull const symbol_ = qualifier_->symbol_->Get_(name_->GetText_(), IdentifierSymbol_);
			name_->BindSymbol_(symbol_);
			node_->BindSymbol_(symbol_);
		}
		else if (name_->Type_->op_Equal(GenericName_).Value)
		{
			::Semantic_Node_ *_Nonnull const identiferName_ = name_->FirstChildOfType_(IdentifierName_);
			::Symbol_ const *_Nonnull const symbol_ = qualifier_->symbol_->Get_(identiferName_->GetText_(), IdentifierSymbol_);
			identiferName_->BindSymbol_(symbol_);
			node_->BindSymbol_(symbol_);
			p_bool typeArg_ = p_bool(false);
			for (::Semantic_Node_ *_Nonnull const typeArgument_ : *(name_->Children_))
			{
				if (typeArg_.Value)
				{
					if (typeArgument_->Type_->op_NotEqual(GreaterThan_).Value)
					{
						bind_type_(typeArgument_, scope_);
					}
				}
				else if (typeArgument_->Type_->op_Equal(LessThan_).Value)
				{
					typeArg_ = p_bool(true);
				}
			}
		}
		else
		{
			THROW_EXCEPTION_(p_string("Unreachable: `Name_Binder.bind(..)` name.Type = ")->op_Add(name_->Type_));
		}
	}
	else if (node_->Type_->op_Equal(IdentifierName_).Value)
	{
		if (node_->IsMissing_.Value)
		{
			return;
		}

		p_string const name_ = node_->GetText_();
		::Symbol_ const *_Nonnull const symbol_ = scope_->Lookup_(name_);
		if (symbol_->op_Equal(::None).Value)
		{
			add_resolution_error_(node_);
		}
		else
		{
			node_->BindSymbol_(symbol_);
		}
	}
	else
	{
		THROW_EXCEPTION_(p_string("`Name_Binder.bind_type()` unimplemented node type ")->op_Add(node_->Type_));
	}
}

auto ::Name_Binder_::add_resolution_error_(::Semantic_Node_ const *_Nonnull const node_) -> void
{
	node_->Add_((new ::Diagnostic_(FatalCompilationError_, Analysis_, node_->Source_, node_->get_text_span_(), p_string("Could not resolve name `")->op_Add(node_->GetText_())->op_Add(p_string("`")))));
}

::Package_::Package_(::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilationUnits_, ::Primitive_Types_ const *_Nonnull const primitiveTypes_, ::Symbol_ const *_Nonnull const symbol_)
{
	CompilationUnits_ = compilationUnits_;
	this->symbol_ = symbol_;
	PrimitiveTypes_ = primitiveTypes_;
}

auto ::Package_::AllDiagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull
{
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
	for (::Semantic_Node_ const *_Nonnull const compilationUnit_ : *(CompilationUnits_))
	{
		for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(compilationUnit_->AllDiagnostics_()))
		{
			diagnostics_->Add_(diagnostic_);
		}
	}

	return diagnostics_;
}

::Primitive_Types_::Primitive_Types_()
{
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>());
	symbols_->Add_((new ::Symbol_(p_string("void"))));
	symbols_->Add_((new ::Symbol_(p_string("never"))));
	symbols_->Add_((new ::Symbol_(p_string("bool"))));
	symbols_->Add_((new ::Symbol_(p_string("code_point"))));
	symbols_->Add_((new ::Symbol_(p_string("string"))));
	symbols_->Add_((new ::Symbol_(p_string("int8"))));
	symbols_->Add_((new ::Symbol_(p_string("int16"))));
	symbols_->Add_((new ::Symbol_(p_string("int"))));
	symbols_->Add_((new ::Symbol_(p_string("int64"))));
	symbols_->Add_((new ::Symbol_(p_string("int128"))));
	symbols_->Add_((new ::Symbol_(p_string("byte"))));
	symbols_->Add_((new ::Symbol_(p_string("uint16"))));
	symbols_->Add_((new ::Symbol_(p_string("uint"))));
	symbols_->Add_((new ::Symbol_(p_string("uint64"))));
	symbols_->Add_((new ::Symbol_(p_string("uint128"))));
	symbols_->Add_((new ::Symbol_(p_string("float32"))));
	symbols_->Add_((new ::Symbol_(p_string("float"))));
	symbols_->Add_((new ::Symbol_(p_string("float128"))));
	AddFixedPointTypes_(symbols_, p_int(8));
	AddFixedPointTypes_(symbols_, p_int(16));
	AddFixedPointTypes_(symbols_, p_int(32));
	AddFixedPointTypes_(symbols_, p_int(64));
	symbols_->Add_((new ::Symbol_(p_string("decimal32"))));
	symbols_->Add_((new ::Symbol_(p_string("decimal"))));
	symbols_->Add_((new ::Symbol_(p_string("decimal128"))));
	symbols_->Add_((new ::Symbol_(p_string("size"))));
	symbols_->Add_((new ::Symbol_(p_string("offset"))));
	Symbols_ = symbols_;
}

auto ::Primitive_Types_::AddFixedPointTypes_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_, p_int const bitLength_) -> void
{
}

auto ::Primitive_Types_::Get_(p_string const name_) const -> ::Symbol_ const *_Nullable
{
	for (::Symbol_ const *_Nonnull const symbol_ : *(Symbols_))
	{
		if (symbol_->Name_->op_Equal(name_).Value)
		{
			return symbol_;
		}
	}

	return ::None;
}

auto ::Semantic_Analyzer_::Analyze_(::Syntax_Node_ const *_Nonnull const package_syntax_) -> ::Package_ const *_Nonnull
{
	if (package_syntax_->Type_->op_NotEqual(PackageNode_).Value)
	{
		THROW_EXCEPTION_(p_string("`Semantic_Analyzer.Analyze(...)` called with node of type ")->op_Add(package_syntax_->Type_));
	}

	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilation_units_ = (new ::Semantic_Node_(package_syntax_))->Children_;
	::Primitive_Types_ const *_Nonnull const primitive_types_ = (new ::Primitive_Types_());
	::Symbol_Builder_ const *_Nonnull const symbol_builder_ = (new ::Symbol_Builder_());
	::Symbol_ const *_Nonnull const package_symbol_ = symbol_builder_->build_symbols_(compilation_units_);
	::Package_ *_Nonnull const package_ = (new ::Package_(compilation_units_, primitive_types_, package_symbol_));
	::Name_Binder_ const *_Nonnull const name_binder_ = (new ::Name_Binder_());
	name_binder_->bind_(package_);
	return package_;
}

::Semantic_Node_::Semantic_Node_(::Syntax_Node_ const *_Nonnull const syntax_)
{
	Syntax_ = syntax_;
	Type_ = syntax_->Type_;
	IsMissing_ = syntax_->IsMissing_;
	Source_ = syntax_->Source_;
	Start_ = syntax_->Start_;
	Length_ = syntax_->Length_;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>());
	for (::Syntax_Node_ const *_Nonnull const childSyntax_ : *(syntax_->Children_))
	{
		children_->Add_((new ::Semantic_Node_(childSyntax_)));
	}

	Children_ = children_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(syntax_->Diagnostics_))
	{
		diagnostics_->Add_(diagnostic_);
	}

	Diagnostics_ = diagnostics_;
	symbol_ = ::None;
}

auto ::Semantic_Node_::get_text_span_() const -> ::Text_Span_ const *_Nonnull
{
	return (new ::Text_Span_(Start_, Length_));
}

auto ::Semantic_Node_::GetText_() const -> p_string
{
	return Source_->Text_->Substring_(Start_, Length_);
}

auto ::Semantic_Node_::BindSymbol_(::Symbol_ const *_Nonnull const symbol_) -> void
{
	if (this->symbol_->op_NotEqual(::None).Value)
	{
		THROW_EXCEPTION_(p_string("`Semantic_Node.BindSymbol(..)` called on node that already has a symbol on `")->op_Add(GetText_())->op_Add(p_string("`")));
	}

	if (symbol_->op_Equal(::None).Value)
	{
		THROW_EXCEPTION_(p_string("`Semantic_Node.BindSymbol(..)` called without a symbol on `")->op_Add(GetText_())->op_Add(p_string("`")));
	}

	this->symbol_ = symbol_;
}

auto ::Semantic_Node_::FirstChildOfType_(p_int const type_) const -> ::Semantic_Node_ *_Nullable
{
	for (::Semantic_Node_ *_Nonnull const child_ : *(Children_))
	{
		if (child_->Type_->op_Equal(type_).Value)
		{
			return child_;
		}
	}

	return ::None;
}

auto ::Semantic_Node_::ChildrenOfType_(p_int const type_) const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull
{
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const members_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>());
	for (::Semantic_Node_ *_Nonnull const child_ : *(Children_))
	{
		if (child_->Type_->op_Equal(type_).Value)
		{
			members_->Add_(child_);
		}
	}

	return members_;
}

auto ::Semantic_Node_::Members_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull
{
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const members_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>());
	for (::Semantic_Node_ *_Nonnull const child_ : *(Children_))
	{
		if (LogicalOr(LogicalOr(child_->Type_->op_Equal(ConstructorDeclaration_), [&] { return child_->Type_->op_Equal(FieldDeclaration_); }), [&] { return child_->Type_->op_Equal(MethodDeclaration_); }).Value)
		{
			members_->Add_(child_);
		}
	}

	return members_;
}

auto ::Semantic_Node_::Statements_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull
{
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const statements_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>());
	for (::Semantic_Node_ *_Nonnull const child_ : *(Children_))
	{
		if (LogicalAnd(child_->Type_->op_NotEqual(LeftBrace_), [&] { return child_->Type_->op_NotEqual(RightBrace_); }).Value)
		{
			statements_->Add_(child_);
		}
	}

	return statements_;
}

auto ::Semantic_Node_::Parameters_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull
{
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const parameters_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>());
	for (::Semantic_Node_ *_Nonnull const child_ : *(Children_))
	{
		if (LogicalOr(child_->Type_->op_Equal(Parameter_), [&] { return child_->Type_->op_Equal(SelfParameter_); }).Value)
		{
			parameters_->Add_(child_);
		}
	}

	return parameters_;
}

auto ::Semantic_Node_::HasChildOfType_(p_int const type_) const -> p_bool
{
	for (::Semantic_Node_ const *_Nonnull const child_ : *(Children_))
	{
		if (child_->Type_->op_Equal(type_).Value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

auto ::Semantic_Node_::Add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void
{
	Diagnostics_->Add_(diagnostic_);
}

auto ::Semantic_Node_::AllDiagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull
{
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
	CollectDiagnostics_(diagnostics_);
	return diagnostics_;
}

auto ::Semantic_Node_::CollectDiagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(Diagnostics_))
	{
		diagnostics_->Add_(diagnostic_);
	}

	for (::Semantic_Node_ const *_Nonnull const child_ : *(Children_))
	{
		child_->CollectDiagnostics_(diagnostics_);
	}
}

::Symbol_::Symbol_(::Symbol_ const *_Nullable const parent_, p_string const name_)
{
	Parent_ = parent_;
	Name_ = name_;
	Type_ = IdentifierSymbol_;
	Declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>());
	Children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>());
	IsPrimitive_ = p_bool(false);
}

::Symbol_::Symbol_(::Symbol_ const *_Nullable const parent_, p_string const name_, p_int const type_)
{
	Parent_ = parent_;
	Name_ = name_;
	Type_ = type_;
	Declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>());
	Children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>());
	IsPrimitive_ = p_bool(false);
}

::Symbol_::Symbol_(p_string const name_)
{
	Parent_ = ::None;
	Name_ = name_;
	Type_ = PrimitiveSymbol_;
	Declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>());
	Children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>());
	IsPrimitive_ = p_bool(true);
}

auto ::Symbol_::Get_(p_string const name_, p_int const type_) const -> ::Symbol_ const *_Nullable
{
	for (::Symbol_ const *_Nonnull const child_ : *(Children_))
	{
		if (LogicalAnd(child_->Name_->op_Equal(name_), [&] { return child_->Type_->op_Equal(type_); }).Value)
		{
			return child_;
		}
	}

	return ::None;
}

auto ::Symbol_::is_value_type_() const -> p_bool
{
	if (Declarations_->op_Magnitude()->op_Equal(p_int(0)).Value)
	{
		THROW_EXCEPTION_(p_string("Could not determine if `")->op_Add(Name_)->op_Add(p_string("` was a value type. No declarations.")));
	}

	::Semantic_Node_ const *_Nonnull const declaration_ = Declarations_->op_Element(p_int(0));
	if (declaration_->Type_->op_Equal(ClassDeclaration_).Value)
	{
		return p_bool(false);
	}
	else if (declaration_->Type_->op_Equal(StructDeclaration_).Value)
	{
		return p_bool(true);
	}
	else
	{
		THROW_EXCEPTION_(p_string("Could not determine if `")->op_Add(Name_)->op_Add(p_string("` was a value type. Declaration of type "))->op_Add(declaration_->Type_));
	}
}

auto ::Symbol_Builder_::build_symbols_(::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilation_units_) const -> ::Symbol_ const *_Nonnull
{
	::Symbol_ *_Nonnull const package_symbol_ = (new ::Symbol_(::None, p_string(""), PackageSymbol_));
	for (::Semantic_Node_ *_Nonnull const compilation_unit_ : *(compilation_units_))
	{
		if (compilation_unit_->Type_->op_NotEqual(CompilationUnit_).Value)
		{
			THROW_EXCEPTION_(p_string("`Symbol_Builder.build_symbols(...)` called with node of type ")->op_Add(compilation_unit_->Type_));
		}

		build_symbols_(package_symbol_, compilation_unit_);
	}

	build_runtime_library_symbols_(package_symbol_);
	return package_symbol_;
}

auto ::Symbol_Builder_::build_symbols_(::Symbol_ const *_Nonnull const parent_, ::Semantic_Node_ *_Nonnull const node_) const -> void
{
	if (node_->Type_->op_Equal(CompilationUnit_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const declaration_ : *(node_->Children_))
		{
			build_symbols_(parent_, declaration_);
		}
	}
	else if (LogicalOr(node_->Type_->op_Equal(FunctionDeclaration_), [&] { return node_->Type_->op_Equal(MethodDeclaration_); }).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(Identifier_)->GetText_();
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_(parent_, name_));
		build_function_symbols_(parent_, node_, symbol_);
	}
	else if (LogicalOr(node_->Type_->op_Equal(ClassDeclaration_), [&] { return node_->Type_->op_Equal(StructDeclaration_); }).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(Identifier_)->GetText_();
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_(parent_, name_));
		symbol_->Declarations_->Add_(node_);
		for (::Semantic_Node_ *_Nonnull const member_ : *(node_->Members_()))
		{
			build_symbols_(symbol_, member_);
		}

		parent_->Children_->Add_(symbol_);
		node_->BindSymbol_(symbol_);
	}
	else if (node_->Type_->op_Equal(ConstructorDeclaration_).Value)
	{
		::Symbol_ const *_Nonnull const constructor_symbol_ = (new ::Symbol_(::None, p_string(""), ConstructorSymbol_));
		constructor_symbol_->Declarations_->Add_(node_);
		build_function_symbols_(parent_, node_, constructor_symbol_);
	}
	else if (node_->Type_->op_Equal(FieldDeclaration_).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(VariableDeclaration_)->FirstChildOfType_(Identifier_)->GetText_();
		::Symbol_ const *_Nonnull const field_symbol_ = (new ::Symbol_(::None, name_));
		field_symbol_->Declarations_->Add_(node_);
		parent_->Children_->Add_(field_symbol_);
		node_->BindSymbol_(field_symbol_);
	}
	else if (node_->Type_->op_Equal(EnumDeclaration_).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(Identifier_)->GetText_();
		::Symbol_ const *_Nonnull const enum_symbol_ = (new ::Symbol_(parent_, name_));
		enum_symbol_->Declarations_->Add_(node_);
		parent_->Children_->Add_(enum_symbol_);
		node_->BindSymbol_(enum_symbol_);
	}
	else if (node_->Type_->op_Equal(GlobalDeclaration_).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(VariableDeclaration_)->FirstChildOfType_(Identifier_)->GetText_();
		::Symbol_ const *_Nonnull const globalDeclarationSymbol_ = (new ::Symbol_(::None, name_));
		globalDeclarationSymbol_->Declarations_->Add_(node_);
		parent_->Children_->Add_(globalDeclarationSymbol_);
		node_->BindSymbol_(globalDeclarationSymbol_);
	}
	else if (node_->Type_->op_Equal(Block_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const statement_ : *(node_->Statements_()))
		{
			build_symbols_(parent_, statement_);
		}
	}
	else if (LogicalOr(LogicalOr(node_->Type_->op_Equal(LoopStatement_), [&] { return node_->Type_->op_Equal(WhileStatement_); }), [&] { return node_->Type_->op_Equal(DoWhileStatement_); }).Value)
	{
		build_symbols_(parent_, node_->FirstChildOfType_(Block_));
	}
	else if (node_->Type_->op_Equal(ForStatement_).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(VariableDeclaration_)->FirstChildOfType_(Identifier_)->GetText_();
		::Symbol_ const *_Nonnull const for_symbol_ = (new ::Symbol_(::None, name_));
		for_symbol_->Declarations_->Add_(node_);
		parent_->Children_->Add_(for_symbol_);
		node_->BindSymbol_(for_symbol_);
		build_symbols_(parent_, node_->FirstChildOfType_(Block_));
	}
	else if (node_->Type_->op_Equal(LocalDeclarationStatement_).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(VariableDeclaration_)->FirstChildOfType_(Identifier_)->GetText_();
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_(::None, name_));
		symbol_->Declarations_->Add_(node_);
		parent_->Children_->Add_(symbol_);
	}
	else if (node_->Type_->op_Equal(IfStatement_).Value)
	{
		build_symbols_(parent_, node_->FirstChildOfType_(Block_));
		::Semantic_Node_ *_Nullable const elseClause_ = node_->FirstChildOfType_(ElseClause_);
		if (elseClause_->op_NotEqual(::None).Value)
		{
			build_symbols_(parent_, elseClause_);
		}
	}
	else if (node_->Type_->op_Equal(ElseClause_).Value)
	{
		::Semantic_Node_ *_Nullable const block_ = node_->FirstChildOfType_(Block_);
		if (block_->op_NotEqual(::None).Value)
		{
			build_symbols_(parent_, block_);
		}
		else
		{
			build_symbols_(parent_, node_->FirstChildOfType_(IfStatement_));
		}
	}
	else if (node_->Type_->op_Equal(Parameter_).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(Identifier_)->GetText_();
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_(::None, name_));
		symbol_->Declarations_->Add_(node_);
		parent_->Children_->Add_(symbol_);
	}
	else if (node_->Type_->op_Equal(SelfParameter_).Value)
	{
		p_string const name_ = node_->FirstChildOfType_(SelfKeyword_)->GetText_();
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_(::None, name_, PrimitiveSymbol_));
		symbol_->Declarations_->Add_(node_);
		parent_->Children_->Add_(symbol_);
	}
	else if (LogicalOr(LogicalOr(LogicalOr(LogicalOr(node_->Type_->op_Equal(ExpressionStatement_), [&] { return node_->Type_->op_Equal(ReturnStatement_); }), [&] { return node_->Type_->op_Equal(BreakStatement_); }), [&] { return node_->Type_->op_Equal(ContinueStatement_); }), [&] { return node_->Type_->op_Equal(EndOfFileToken_); }).Value)
	{
	}
	else
	{
		THROW_EXCEPTION_(p_string("`Symbol_Builder.Build()` unimplemented node type ")->op_Add(node_->Type_));
	}
}

auto ::Symbol_Builder_::build_function_symbols_(::Symbol_ const *_Nonnull const parent_, ::Semantic_Node_ *_Nonnull const node_, ::Symbol_ const *_Nonnull const symbol_) const -> void
{
	symbol_->Declarations_->Add_(node_);
	::Semantic_Node_ *_Nonnull const parameters_ = node_->FirstChildOfType_(ParameterList_);
	for (::Semantic_Node_ *_Nonnull const parameter_ : *(parameters_->Parameters_()))
	{
		build_symbols_(symbol_, parameter_);
	}

	::Semantic_Node_ *_Nonnull const body_ = node_->FirstChildOfType_(Block_);
	build_symbols_(symbol_, body_);
	parent_->Children_->Add_(symbol_);
	node_->BindSymbol_(symbol_);
}

auto ::Symbol_Builder_::build_runtime_library_symbols_(::Symbol_ const *_Nonnull const package_) const -> void
{
	::Semantic_Node_ const *_Nonnull const fake_declaration_ = (new ::Semantic_Node_((new ::Syntax_Node_(ClassDeclaration_, p_bool(true), ::None, p_int(0), p_int(0)))));
	package_->Children_->Add_((new ::Symbol_(package_, p_string("resource_manager"))));
	package_->Children_->Add_((new ::Symbol_(package_, p_string("THROW_EXCEPTION"))));
	package_->Children_->Add_((new ::Symbol_(package_, p_string("assert"))));
	::Symbol_ const *_Nonnull const system_ = (new ::Symbol_(package_, p_string("System")));
	package_->Children_->Add_(system_);
	::Symbol_ const *_Nonnull const collections_ = (new ::Symbol_(system_, p_string("Collections")));
	system_->Children_->Add_(collections_);
	::Symbol_ *_Nonnull const list_ = (new ::Symbol_(system_, p_string("List")));
	list_->Declarations_->Add_(fake_declaration_);
	collections_->Children_->Add_(list_);
	::Symbol_ const *_Nonnull const console_ = (new ::Symbol_(system_, p_string("Console")));
	system_->Children_->Add_(console_);
	::Symbol_ *_Nonnull const console_class_ = (new ::Symbol_(system_, p_string("Console")));
	console_class_->Declarations_->Add_(fake_declaration_);
	console_->Children_->Add_(console_class_);
	::Symbol_ *_Nonnull const arguments_ = (new ::Symbol_(system_, p_string("Arguments")));
	arguments_->Declarations_->Add_(fake_declaration_);
	console_->Children_->Add_(arguments_);
	::Symbol_ const *_Nonnull const io_ = (new ::Symbol_(system_, p_string("IO")));
	system_->Children_->Add_(io_);
	::Symbol_ *_Nonnull const file_reader_ = (new ::Symbol_(system_, p_string("File_Reader")));
	file_reader_->Declarations_->Add_(fake_declaration_);
	io_->Children_->Add_(file_reader_);
	::Symbol_ *_Nonnull const file_writer_ = (new ::Symbol_(system_, p_string("File_Writer")));
	file_writer_->Declarations_->Add_(fake_declaration_);
	io_->Children_->Add_(file_writer_);
	::Symbol_ const *_Nonnull const text_ = (new ::Symbol_(system_, p_string("Text")));
	system_->Children_->Add_(text_);
	::Symbol_ *_Nonnull const string_builder_ = (new ::Symbol_(text_, p_string("String_Builder")));
	string_builder_->Declarations_->Add_(fake_declaration_);
	text_->Children_->Add_(string_builder_);
}

::Compilation_Unit_Parser_::Compilation_Unit_Parser_(::Token_Stream_ *_Nonnull const tokenStream_)
{
	this->tokenStream_ = tokenStream_;
	this->compilationUnit_ = ::None;
}

auto ::Compilation_Unit_Parser_::Parse_() -> ::Syntax_Node_ const *_Nonnull
{
	if (compilationUnit_->op_Equal(::None).Value)
	{
		token_ = tokenStream_->GetNextToken_();
		compilationUnit_ = ParseCompilationUnit_();
	}

	return compilationUnit_;
}

auto ::Compilation_Unit_Parser_::AcceptToken_() -> ::Syntax_Node_ const *_Nullable
{
	::Syntax_Node_ const *_Nullable const node_ = token_;
	token_ = tokenStream_->GetNextToken_();
	return node_;
}

auto ::Compilation_Unit_Parser_::ExpectToken_(p_int const tokenType_) -> ::Syntax_Node_ const *_Nonnull
{
	if (token_->op_Equal(::None).Value)
	{
		return new_syntax_node_missing_(tokenType_, tokenStream_->Source_, tokenStream_->Source_->ByteLength_());
	}

	if (LogicalOr(token_->op_Equal(::None), [&] { return token_->Type_->op_NotEqual(tokenType_); }).Value)
	{
		return new_syntax_node_missing_(tokenType_, tokenStream_->Source_, token_->Start_);
	}

	::Syntax_Node_ const *_Nullable const node_ = token_;
	token_ = tokenStream_->GetNextToken_();
	return node_;
}

auto ::Compilation_Unit_Parser_::ParseTypeName_() -> ::Syntax_Node_ const *_Nonnull
{
	if (LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(token_->Type_->op_Equal(CodePoint_), [&] { return token_->Type_->op_Equal(String_); }), [&] { return token_->Type_->op_Equal(Int_); }), [&] { return token_->Type_->op_Equal(Bool_); }), [&] { return token_->Type_->op_Equal(Void_); }), [&] { return token_->Type_->op_Equal(UnsignedInt_); }).Value)
	{
		return (new ::Syntax_Node_(PredefinedType_, AcceptToken_()));
	}
	else
	{
		::Syntax_Node_ const *_Nonnull type_ = (new ::Syntax_Node_(IdentifierName_, ExpectToken_(Identifier_)));
		while (token_->Type_->op_Equal(Dot_).Value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
			children_->Add_(type_);
			children_->Add_(ExpectToken_(Dot_));
			::Syntax_Node_ const *_Nonnull const identifier_ = ExpectToken_(Identifier_);
			if (token_->Type_->op_Equal(LessThan_).Value)
			{
				::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const genericNameChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
				genericNameChildren_->Add_((new ::Syntax_Node_(IdentifierName_, identifier_)));
				genericNameChildren_->Add_(ExpectToken_(LessThan_));
				genericNameChildren_->Add_(ParseType_());
				genericNameChildren_->Add_(ExpectToken_(GreaterThan_));
				children_->Add_((new ::Syntax_Node_(GenericName_, genericNameChildren_)));
			}
			else
			{
				children_->Add_((new ::Syntax_Node_(IdentifierName_, identifier_)));
			}

			type_ = (new ::Syntax_Node_(QualifiedName_, children_));
		}

		return type_;
	}
}

auto ::Compilation_Unit_Parser_::ParseNonOptionalType_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	if (token_->Type_->op_Equal(MutableKeyword_).Value)
	{
		children_->Add_(ExpectToken_(MutableKeyword_));
		children_->Add_(ParseTypeName_());
		return (new ::Syntax_Node_(MutableType_, children_));
	}
	else
	{
		children_->Add_(ParseTypeName_());
		return (new ::Syntax_Node_(ImmutableType_, children_));
	}
}

auto ::Compilation_Unit_Parser_::ParseType_() -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ const *_Nonnull type_ = ParseNonOptionalType_();
	while (token_->Type_->op_Equal(Question_).Value)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
		children_->Add_(type_);
		children_->Add_(ExpectToken_(Question_));
		type_ = (new ::Syntax_Node_(ImmutableType_, (new ::Syntax_Node_(OptionalType_, children_))));
	}

	return type_;
}

auto ::Compilation_Unit_Parser_::ParseAtom_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	if (token_->Type_->op_Equal(NewKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseTypeName_());
		children_->Add_(ParseCallArguments_());
		return (new ::Syntax_Node_(NewExpression_, children_));
	}

	if (token_->Type_->op_Equal(NotOperator_).Value)
	{
		children_->Add_(ExpectToken_(NotOperator_));
		children_->Add_(ParseExpression_(p_int(8)));
		return (new ::Syntax_Node_(NotExpression_, children_));
	}

	if (token_->Type_->op_Equal(LeftParen_).Value)
	{
		children_->Add_(ExpectToken_(LeftParen_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(RightParen_));
		return (new ::Syntax_Node_(ParenthesizedExpression_, children_));
	}

	if (token_->Type_->op_Equal(Pipe_).Value)
	{
		children_->Add_(ExpectToken_(Pipe_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Pipe_));
		return (new ::Syntax_Node_(MagnitudeExpression_, children_));
	}

	if (token_->Type_->op_Equal(Minus_).Value)
	{
		children_->Add_(ExpectToken_(Minus_));
		children_->Add_(ParseExpression_(p_int(8)));
		return (new ::Syntax_Node_(NegateExpression_, children_));
	}

	if (token_->Type_->op_Equal(NoneKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NoneKeyword_));
		return (new ::Syntax_Node_(NoneLiteralExpression_, children_));
	}

	if (token_->Type_->op_Equal(SelfKeyword_).Value)
	{
		children_->Add_(ExpectToken_(SelfKeyword_));
		return (new ::Syntax_Node_(SelfExpression_, children_));
	}

	if (token_->Type_->op_Equal(TrueKeyword_).Value)
	{
		children_->Add_(ExpectToken_(TrueKeyword_));
		return (new ::Syntax_Node_(TrueLiteralExpression_, children_));
	}

	if (token_->Type_->op_Equal(FalseKeyword_).Value)
	{
		children_->Add_(ExpectToken_(FalseKeyword_));
		return (new ::Syntax_Node_(FalseLiteralExpression_, children_));
	}

	if (token_->Type_->op_Equal(Number_).Value)
	{
		children_->Add_(ExpectToken_(Number_));
		return (new ::Syntax_Node_(NumericLiteralExpression_, children_));
	}

	if (token_->Type_->op_Equal(Identifier_).Value)
	{
		children_->Add_(ExpectToken_(Identifier_));
		return (new ::Syntax_Node_(IdentifierName_, children_));
	}

	if (token_->Type_->op_Equal(StringLiteral_).Value)
	{
		children_->Add_(ExpectToken_(StringLiteral_));
		return (new ::Syntax_Node_(StringLiteralExpression_, children_));
	}

	if (token_->Type_->op_Equal(CodePointLiteral_).Value)
	{
		children_->Add_(ExpectToken_(CodePointLiteral_));
		return (new ::Syntax_Node_(CodePointLiteralExpression_, children_));
	}

	return (new ::Syntax_Node_(IdentifierName_, ExpectToken_(Identifier_)));
}

auto ::Compilation_Unit_Parser_::ParseCallArguments_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	children_->Add_(ExpectToken_(LeftParen_));
	if (token_->Type_->op_NotEqual(RightParen_).Value)
	{
		for (;;)
		{
			children_->Add_(ParseExpression_());
			if (token_->Type_->op_Equal(Comma_).Value)
			{
				children_->Add_(ExpectToken_(Comma_));
			}
			else
			{
				break;
			}
		}
	}

	children_->Add_(ExpectToken_(RightParen_));
	return (new ::Syntax_Node_(ArgumentList_, children_));
}

auto ::Compilation_Unit_Parser_::ParseExpression_(p_int const minPrecedence_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ const *_Nonnull expression_ = ParseAtom_();
	for (;;)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
		children_->Add_(expression_);
		p_int precedence_;
		p_bool leftAssociative_;
		p_bool suffixOperator_ = p_bool(false);
		p_int expressionType_;
		if (LogicalAnd(LogicalOr(LogicalOr(token_->Type_->op_Equal(Equals_), [&] { return token_->Type_->op_Equal(PlusEquals_); }), [&] { return token_->Type_->op_Equal(MinusEquals_); }), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(1)); }).Value)
		{
			precedence_ = p_int(1);
			leftAssociative_ = p_bool(false);
			children_->Add_(AcceptToken_());
			expressionType_ = AssignmentExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(OrKeyword_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(2)); }).Value)
		{
			precedence_ = p_int(2);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(OrKeyword_));
			expressionType_ = OrExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(AndKeyword_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(3)); }).Value)
		{
			precedence_ = p_int(3);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(AndKeyword_));
			expressionType_ = AndExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(EqualsEquals_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(4)); }).Value)
		{
			precedence_ = p_int(4);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(EqualsEquals_));
			expressionType_ = EqualExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(EqualsSlashEquals_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(4)); }).Value)
		{
			precedence_ = p_int(4);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(EqualsSlashEquals_));
			expressionType_ = NotEqualExpression_;
		}
		else if (LogicalAnd(LogicalOr(LogicalOr(LogicalOr(token_->Type_->op_Equal(LessThan_), [&] { return token_->Type_->op_Equal(LessThanEquals_); }), [&] { return token_->Type_->op_Equal(GreaterThan_); }), [&] { return token_->Type_->op_Equal(GreaterThanEquals_); }), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(5)); }).Value)
		{
			precedence_ = p_int(5);
			leftAssociative_ = p_bool(true);
			children_->Add_(AcceptToken_());
			expressionType_ = ComparisonExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(Plus_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(6)); }).Value)
		{
			precedence_ = p_int(6);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Plus_));
			expressionType_ = AddExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(Minus_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(6)); }).Value)
		{
			precedence_ = p_int(6);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Minus_));
			expressionType_ = SubtractExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(Asterisk_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(7)); }).Value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Asterisk_));
			expressionType_ = MultiplyExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(Slash_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(7)); }).Value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Slash_));
			expressionType_ = DivideExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(Percent_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(7)); }).Value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Percent_));
			expressionType_ = RemainderExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(LeftParen_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(9)); }).Value)
		{
			precedence_ = p_int(9);
			leftAssociative_ = p_bool(true);
			suffixOperator_ = p_bool(true);
			children_->Add_(ParseCallArguments_());
			expressionType_ = InvocationExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(Dot_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(9)); }).Value)
		{
			precedence_ = p_int(9);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Dot_));
			expressionType_ = MemberAccessExpression_;
		}
		else if (LogicalAnd(token_->Type_->op_Equal(LeftBracket_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(9)); }).Value)
		{
			precedence_ = p_int(9);
			leftAssociative_ = p_bool(true);
			suffixOperator_ = p_bool(true);
			children_->Add_(ExpectToken_(LeftBracket_));
			children_->Add_(ParseExpression_());
			children_->Add_(ExpectToken_(RightBracket_));
			expressionType_ = ElementAccessExpression_;
		}
		else
		{
			return expression_;
		}

		if (suffixOperator_->op_Not().Value)
		{
			if (leftAssociative_.Value)
			{
				precedence_->op_AddAssign(p_int(1));
			}

			children_->Add_(ParseExpression_(precedence_));
			expression_ = (new ::Syntax_Node_(expressionType_, children_));
		}
		else
		{
			expression_ = (new ::Syntax_Node_(expressionType_, children_));
		}
	}
}

auto ::Compilation_Unit_Parser_::ParseExpression_() -> ::Syntax_Node_ const *_Nonnull
{
	return ParseExpression_(p_int(1));
}

auto ::Compilation_Unit_Parser_::ParseStatement_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	if (token_->Type_->op_Equal(ReturnKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ReturnKeyword_));
		if (token_->Type_->op_NotEqual(Semicolon_).Value)
		{
			children_->Add_(ParseExpression_());
		}

		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_(ReturnStatement_, children_));
	}

	if (token_->Type_->op_Equal(LoopKeyword_).Value)
	{
		children_->Add_(ExpectToken_(LoopKeyword_));
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_(LoopStatement_, children_));
	}

	if (token_->Type_->op_Equal(WhileKeyword_).Value)
	{
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_(WhileStatement_, children_));
	}

	if (token_->Type_->op_Equal(ForKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ForKeyword_));
		children_->Add_(ParseVariableDeclaration_(p_bool(false)));
		children_->Add_(ExpectToken_(InKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_(ForStatement_, children_));
	}

	if (token_->Type_->op_Equal(DoKeyword_).Value)
	{
		children_->Add_(ExpectToken_(DoKeyword_));
		children_->Add_(ParseBlock_());
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_(DoWhileStatement_, children_));
	}

	if (token_->Type_->op_Equal(IfKeyword_).Value)
	{
		return ParseIfStatement_();
	}

	if (token_->Type_->op_Equal(BreakKeyword_).Value)
	{
		children_->Add_(ExpectToken_(BreakKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_(BreakStatement_, children_));
	}

	if (token_->Type_->op_Equal(ContinueKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ContinueKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_(ContinueStatement_, children_));
	}

	if (LogicalOr(token_->Type_->op_Equal(VarKeyword_), [&] { return token_->Type_->op_Equal(LetKeyword_); }).Value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(true)));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_(LocalDeclarationStatement_, children_));
	}

	if (token_->Type_->op_Equal(LeftBrace_).Value)
	{
		return ParseBlock_();
	}

	children_->Add_(ParseExpression_());
	children_->Add_(ExpectToken_(Semicolon_));
	return (new ::Syntax_Node_(ExpressionStatement_, children_));
}

auto ::Compilation_Unit_Parser_::ParseIfStatement_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	children_->Add_(ExpectToken_(IfKeyword_));
	children_->Add_(ParseExpression_());
	children_->Add_(ParseBlock_());
	if (token_->Type_->op_Equal(ElseKeyword_).Value)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const elseChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
		elseChildren_->Add_(ExpectToken_(ElseKeyword_));
		if (token_->Type_->op_Equal(IfKeyword_).Value)
		{
			elseChildren_->Add_(ParseIfStatement_());
		}
		else
		{
			elseChildren_->Add_(ParseBlock_());
		}

		children_->Add_((new ::Syntax_Node_(ElseClause_, elseChildren_)));
	}

	return (new ::Syntax_Node_(IfStatement_, children_));
}

auto ::Compilation_Unit_Parser_::ParseVariableDeclaration_(p_bool const allowInitializer_) -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	if (LogicalAnd(token_->Type_->op_Equal(LetKeyword_), [&] { return token_->Type_->op_NotEqual(VarKeyword_); }).Value)
	{
		children_->Add_(ExpectToken_(LetKeyword_));
	}
	else
	{
		children_->Add_(ExpectToken_(VarKeyword_));
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ExpectToken_(Colon_));
	children_->Add_(ParseType_());
	if (LogicalAnd(allowInitializer_, [&] { return token_->Type_->op_Equal(Equals_); }).Value)
	{
		children_->Add_(ExpectToken_(Equals_));
		children_->Add_(ParseExpression_());
	}

	return (new ::Syntax_Node_(VariableDeclaration_, children_));
}

auto ::Compilation_Unit_Parser_::ParseBlock_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	children_->Add_(ExpectToken_(LeftBrace_));
	while (LogicalAnd(token_->Type_->op_NotEqual(RightBrace_), [&] { return token_->Type_->op_NotEqual(EndOfFileToken_); }).Value)
	{
		::Syntax_Node_ const *_Nonnull const startToken_ = token_;
		children_->Add_(ParseStatement_());
		if (token_->op_Equal(startToken_).Value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const skipped_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
			while (LogicalAnd(LogicalAnd(token_->Type_->op_NotEqual(LeftBrace_), [&] { return token_->Type_->op_NotEqual(RightBrace_); }), [&] { return token_->Type_->op_NotEqual(EndOfFileToken_); }).Value)
			{
				p_int const currentTokenType_ = token_->Type_;
				skipped_->Add_(AcceptToken_());
				if (currentTokenType_->op_Equal(Semicolon_).Value)
				{
					break;
				}
			}

			children_->Add_(new_Syntax_Node_Skipped_(skipped_));
		}
	}

	children_->Add_(ExpectToken_(RightBrace_));
	return (new ::Syntax_Node_(Block_, children_));
}

auto ::Compilation_Unit_Parser_::ParseParameterList_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	children_->Add_(ExpectToken_(LeftParen_));
	if (token_->Type_->op_NotEqual(RightParen_).Value)
	{
		for (;;)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const parameterChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
			if (LogicalOr(token_->Type_->op_Equal(MutableKeyword_), [&] { return token_->Type_->op_Equal(SelfKeyword_); }).Value)
			{
				if (token_->Type_->op_Equal(MutableKeyword_).Value)
				{
					parameterChildren_->Add_(ExpectToken_(MutableKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(SelfKeyword_));
				children_->Add_((new ::Syntax_Node_(SelfParameter_, parameterChildren_)));
			}
			else
			{
				p_bool const mutableBinding_ = token_->Type_->op_Equal(VarKeyword_);
				if (token_->Type_->op_Equal(VarKeyword_).Value)
				{
					parameterChildren_->Add_(ExpectToken_(VarKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(Identifier_));
				parameterChildren_->Add_(ExpectToken_(Colon_));
				::Syntax_Node_ const *_Nonnull const type_ = ParseType_();
				parameterChildren_->Add_(type_);
				children_->Add_((new ::Syntax_Node_(Parameter_, parameterChildren_)));
			}

			if (token_->Type_->op_Equal(Comma_).Value)
			{
				children_->Add_(ExpectToken_(Comma_));
			}
			else
			{
				break;
			}
		}
	}

	children_->Add_(ExpectToken_(RightParen_));
	return (new ::Syntax_Node_(ParameterList_, children_));
}

auto ::Compilation_Unit_Parser_::ParseMemberDeclaration_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	if (LogicalOr(LogicalOr(LogicalOr(token_->Type_->op_Equal(PublicKeyword_), [&] { return token_->Type_->op_Equal(ProtectedKeyword_); }), [&] { return token_->Type_->op_Equal(InternalKeyword_); }), [&] { return token_->Type_->op_Equal(PrivateKeyword_); }).Value)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		children_->Add_(ExpectToken_(PublicKeyword_));
	}

	if (token_->Type_->op_Equal(NewKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseParameterList_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_(ConstructorDeclaration_, children_));
	}

	if (LogicalOr(token_->Type_->op_Equal(VarKeyword_), [&] { return token_->Type_->op_Equal(LetKeyword_); }).Value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(false)));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_(FieldDeclaration_, children_));
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ParseParameterList_());
	children_->Add_(ExpectToken_(Arrow_));
	children_->Add_(ParseType_());
	children_->Add_(ParseBlock_());
	return (new ::Syntax_Node_(MethodDeclaration_, children_));
}

auto ::Compilation_Unit_Parser_::ParseDeclaration_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	if (LogicalOr(LogicalOr(LogicalOr(token_->Type_->op_Equal(PublicKeyword_), [&] { return token_->Type_->op_Equal(ProtectedKeyword_); }), [&] { return token_->Type_->op_Equal(InternalKeyword_); }), [&] { return token_->Type_->op_Equal(PrivateKeyword_); }).Value)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		children_->Add_(ExpectToken_(PublicKeyword_));
	}

	if (LogicalOr(token_->Type_->op_Equal(VarKeyword_), [&] { return token_->Type_->op_Equal(LetKeyword_); }).Value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(true)));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_(GlobalDeclaration_, children_));
	}

	if (token_->Type_->op_Equal(ClassKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ClassKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (LogicalAnd(token_->Type_->op_NotEqual(RightBrace_), [&] { return token_->Type_->op_NotEqual(EndOfFileToken_); }).Value)
		{
			::Syntax_Node_ const *_Nonnull const startToken_ = token_;
			children_->Add_(ParseMemberDeclaration_());
			if (token_->op_Equal(startToken_).Value)
			{
				children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
			}
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_(ClassDeclaration_, children_));
	}

	if (token_->Type_->op_Equal(StructKeyword_).Value)
	{
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (LogicalAnd(token_->Type_->op_NotEqual(RightBrace_), [&] { return token_->Type_->op_NotEqual(EndOfFileToken_); }).Value)
		{
			::Syntax_Node_ const *_Nonnull const startToken_ = token_;
			children_->Add_(ParseMemberDeclaration_());
			if (token_->op_Equal(startToken_).Value)
			{
				children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
			}
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_(StructDeclaration_, children_));
	}

	if (token_->Type_->op_Equal(EnumKeyword_).Value)
	{
		children_->Add_(ExpectToken_(EnumKeyword_));
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (LogicalAnd(token_->Type_->op_NotEqual(RightBrace_), [&] { return token_->Type_->op_NotEqual(EndOfFileToken_); }).Value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const memberChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
			memberChildren_->Add_(ExpectToken_(Identifier_));
			if (token_->Type_->op_Equal(Equals_).Value)
			{
				memberChildren_->Add_(ExpectToken_(Equals_));
				memberChildren_->Add_(ExpectToken_(Number_));
			}

			if (token_->Type_->op_NotEqual(RightBrace_).Value)
			{
				memberChildren_->Add_(ExpectToken_(Comma_));
			}

			children_->Add_((new ::Syntax_Node_(EnumMemberDeclaration_, memberChildren_)));
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_(EnumDeclaration_, children_));
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ParseParameterList_());
	children_->Add_(ExpectToken_(Arrow_));
	children_->Add_(ParseType_());
	children_->Add_(ParseBlock_());
	return (new ::Syntax_Node_(FunctionDeclaration_, children_));
}

auto ::Compilation_Unit_Parser_::ParseCompilationUnit_() -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	while (LogicalAnd(token_->op_NotEqual(::None), [&] { return token_->Type_->op_NotEqual(EndOfFileToken_); }).Value)
	{
		::Syntax_Node_ const *_Nonnull const startToken_ = token_;
		children_->Add_(ParseDeclaration_());
		if (token_->op_Equal(startToken_).Value)
		{
			children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
		}
	}

	children_->Add_(ExpectToken_(EndOfFileToken_));
	return (new ::Syntax_Node_(CompilationUnit_, children_));
}

auto ::Lexer_::Analyze_(::Source_Text_ const *_Nonnull const source_) const -> ::Token_Stream_ *_Nonnull
{
	return (new ::Token_Stream_(source_));
}

::Parser_::Parser_()
{
}

auto ::Parser_::ParsePackage_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) const -> ::Syntax_Node_ const *_Nonnull
{
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	::Lexer_ const *_Nonnull const lexer_ = (new ::Lexer_());
	for (::Source_Text_ const *_Nonnull const source_ : *(sources_))
	{
		::Token_Stream_ *_Nonnull const tokenStream_ = lexer_->Analyze_(source_);
		::Compilation_Unit_Parser_ *_Nonnull const compilationUnitParser_ = (new ::Compilation_Unit_Parser_(tokenStream_));
		children_->Add_(compilationUnitParser_->Parse_());
	}

	return (new ::Syntax_Node_(PackageNode_, children_));
}

::Syntax_Node_::Syntax_Node_(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_, p_uint const length_)
{
	Type_ = type_;
	IsMissing_ = p_bool(false);
	Source_ = source_;
	Start_ = start_;
	Length_ = length_;
	Children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	Diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
}

::Syntax_Node_::Syntax_Node_(p_int const type_, p_bool const isMissing_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_, p_uint const length_)
{
	Type_ = type_;
	IsMissing_ = isMissing_;
	Source_ = source_;
	Start_ = start_;
	Length_ = length_;
	Children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	Diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
}

::Syntax_Node_::Syntax_Node_(p_int const type_, ::Syntax_Node_ const *_Nonnull const child_)
{
	Type_ = type_;
	IsMissing_ = child_->IsMissing_;
	Source_ = child_->Source_;
	Start_ = child_->Start_;
	Length_ = child_->Length_;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>());
	children_->Add_(child_);
	Children_ = children_;
	Diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
}

::Syntax_Node_::Syntax_Node_(p_int const type_, ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const children_)
{
	Type_ = type_;
	IsMissing_ = p_bool(false);
	Source_ = children_->op_Element(p_int(0))->Source_;
	Start_ = children_->op_Element(p_int(0))->Start_;
	::Syntax_Node_ const *_Nonnull const lastChild_ = children_->op_Element(children_->op_Magnitude()->op_Subtract(p_int(1)));
	Length_ = lastChild_->Start_->op_Subtract(Start_)->op_Add(lastChild_->Length_);
	Children_ = children_;
	Diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
}

auto ::Syntax_Node_::GetText_() const -> p_string
{
	return Source_->Text_->Substring_(Start_, Length_);
}

auto ::Syntax_Node_::FirstChildOfType_(p_int const type_) const -> ::Syntax_Node_ const *_Nullable
{
	for (::Syntax_Node_ const *_Nonnull const child_ : *(Children_))
	{
		if (child_->Type_->op_Equal(type_).Value)
		{
			return child_;
		}
	}

	return ::None;
}

auto ::Syntax_Node_::HasChildOfType_(p_int const type_) const -> p_bool
{
	for (::Syntax_Node_ const *_Nonnull const child_ : *(Children_))
	{
		if (child_->Type_->op_Equal(type_).Value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

auto ::Syntax_Node_::Add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void
{
	Diagnostics_->Add_(diagnostic_);
}

auto ::Syntax_Node_::AllDiagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull
{
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
	CollectDiagnostics_(diagnostics_);
	return diagnostics_;
}

auto ::Syntax_Node_::CollectDiagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(Diagnostics_))
	{
		diagnostics_->Add_(diagnostic_);
	}

	for (::Syntax_Node_ const *_Nonnull const child_ : *(Children_))
	{
		child_->CollectDiagnostics_(diagnostics_);
	}
}

auto new_syntax_node_missing_(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_(type_, p_bool(true), source_, start_, p_int(0)));
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_(start_, p_int(0)));
	node_->Add_((new ::Diagnostic_(CompilationError_, Parsing_, source_, span_, p_string("Missing token of type ")->op_Add(type_))));
	return node_;
}

auto new_Syntax_Node_Skipped_(::Syntax_Node_ const *_Nonnull const skipped_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_(SkippedTokens_, skipped_));
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_(skipped_->Start_, skipped_->Length_));
	node_->Add_((new ::Diagnostic_(CompilationError_, Parsing_, skipped_->Source_, span_, p_string("Skipped unexpected token of type ")->op_Add(skipped_->Type_))));
	return node_;
}

auto new_Syntax_Node_Skipped_(::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const skipped_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_(SkippedTokens_, skipped_));
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_(node_->Start_, node_->Length_));
	node_->Add_((new ::Diagnostic_(CompilationError_, Parsing_, node_->Source_, span_, p_string("Skipped ")->op_Add(skipped_->op_Magnitude())->op_Add(p_string(" unexpected token(s)")))));
	return node_;
}

::Token_Stream_::Token_Stream_(::Source_Text_ const *_Nonnull const source_)
{
	Source_ = source_;
	position_ = p_int(0);
	diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>());
	endOfFile_ = p_bool(false);
}

auto ::Token_Stream_::GetNextToken_() -> ::Syntax_Node_ const *_Nullable
{
	if (position_->op_GreaterThanOrEqual(Source_->ByteLength_()).Value)
	{
		return EndOfFile_();
	}

	p_uint end_ = p_int(1)->op_Negate();
	while (position_->op_LessThan(Source_->ByteLength_()).Value)
	{
		p_code_point const curChar_ = Source_->Text_->op_Element(position_);
		if (LogicalOr(LogicalOr(LogicalOr(curChar_->op_Equal(p_code_point(' ')), [&] { return curChar_->op_Equal(p_code_point('\t')); }), [&] { return curChar_->op_Equal(p_code_point('\n')); }), [&] { return curChar_->op_Equal(p_code_point('\r')); }).Value)
		{
			position_->op_AddAssign(p_int(1));
			continue;
		}
		else if (curChar_->op_Equal(p_code_point('{')).Value)
		{
			return NewOperator_(LeftBrace_);
		}
		else if (curChar_->op_Equal(p_code_point('}')).Value)
		{
			return NewOperator_(RightBrace_);
		}
		else if (curChar_->op_Equal(p_code_point('(')).Value)
		{
			return NewOperator_(LeftParen_);
		}
		else if (curChar_->op_Equal(p_code_point(')')).Value)
		{
			return NewOperator_(RightParen_);
		}
		else if (curChar_->op_Equal(p_code_point(';')).Value)
		{
			return NewOperator_(Semicolon_);
		}
		else if (curChar_->op_Equal(p_code_point(',')).Value)
		{
			return NewOperator_(Comma_);
		}
		else if (curChar_->op_Equal(p_code_point('.')).Value)
		{
			return NewOperator_(Dot_);
		}
		else if (curChar_->op_Equal(p_code_point(':')).Value)
		{
			return NewOperator_(Colon_);
		}
		else if (curChar_->op_Equal(p_code_point('[')).Value)
		{
			return NewOperator_(LeftBracket_);
		}
		else if (curChar_->op_Equal(p_code_point(']')).Value)
		{
			return NewOperator_(RightBracket_);
		}
		else if (curChar_->op_Equal(p_code_point('?')).Value)
		{
			return NewOperator_(Question_);
		}
		else if (curChar_->op_Equal(p_code_point('|')).Value)
		{
			return NewOperator_(Pipe_);
		}
		else if (curChar_->op_Equal(p_code_point('*')).Value)
		{
			return NewOperator_(Asterisk_);
		}
		else if (curChar_->op_Equal(p_code_point('=')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(EqualsEquals_, p_int(2));
			}

			if (LogicalAnd(LogicalAnd(position_->op_Add(p_int(2))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('/')); }), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(2)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(EqualsSlashEquals_, p_int(3));
			}

			return NewOperator_(Equals_);
		}
		else if (curChar_->op_Equal(p_code_point('+')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(PlusEquals_, p_int(2));
			}

			return NewOperator_(Plus_);
		}
		else if (curChar_->op_Equal(p_code_point('-')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('>')); }).Value)
			{
				return NewOperator_(Arrow_, p_int(2));
			}

			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(MinusEquals_, p_int(2));
			}

			return NewOperator_(Minus_);
		}
		else if (curChar_->op_Equal(p_code_point('/')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('/')); }).Value)
			{
				while (LogicalAnd(LogicalAnd(position_->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_)->op_NotEqual(p_code_point('\r')); }), [&] { return Source_->Text_->op_Element(position_)->op_NotEqual(p_code_point('\n')); }).Value)
				{
					position_->op_AddAssign(p_int(1));
				}

				continue;
			}

			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('*')); }).Value)
			{
				position_->op_AddAssign(p_int(2));
				p_bool lastCharStar_ = p_bool(false);
				while (LogicalAnd(position_->op_LessThan(Source_->ByteLength_()), [&] { return LogicalAnd(lastCharStar_, [&] { return Source_->Text_->op_Element(position_)->op_Equal(p_code_point('/')); })->op_Not(); }).Value)
				{
					lastCharStar_ = Source_->Text_->op_Element(position_)->op_Equal(p_code_point('*'));
					position_->op_AddAssign(p_int(1));
				}

				position_->op_AddAssign(p_int(1));
				continue;
			}

			return NewOperator_(Slash_);
		}
		else if (curChar_->op_Equal(p_code_point('%')).Value)
		{
			return NewOperator_(Percent_);
		}
		else if (curChar_->op_Equal(p_code_point('<')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(LessThanEquals_, p_int(2));
			}

			return NewOperator_(LessThan_);
		}
		else if (curChar_->op_Equal(p_code_point('>')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(Source_->ByteLength_()), [&] { return Source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(GreaterThanEquals_, p_int(2));
			}

			return NewOperator_(GreaterThan_);
		}
		else if (curChar_->op_Equal(p_code_point('"')).Value)
		{
			end_ = position_->op_Add(p_int(1));
			p_bool escaped_ = p_bool(false);
			while (LogicalAnd(end_->op_LessThan(Source_->ByteLength_()), [&] { return LogicalOr(Source_->Text_->op_Element(end_)->op_NotEqual(p_code_point('"')), [&] { return escaped_; }); }).Value)
			{
				escaped_ = LogicalAnd(Source_->Text_->op_Element(end_)->op_Equal(p_code_point('\\')), [&] { return escaped_->op_Not(); });
				end_->op_AddAssign(p_int(1));
			}

			end_->op_AddAssign(p_int(1));
			return NewToken_(StringLiteral_, end_);
		}
		else if (curChar_->op_Equal(p_code_point('\'')).Value)
		{
			end_ = position_->op_Add(p_int(1));
			p_bool escaped_ = p_bool(false);
			while (LogicalAnd(end_->op_LessThan(Source_->ByteLength_()), [&] { return LogicalOr(Source_->Text_->op_Element(end_)->op_NotEqual(p_code_point('\'')), [&] { return escaped_; }); }).Value)
			{
				escaped_ = LogicalAnd(Source_->Text_->op_Element(end_)->op_Equal(p_code_point('\\')), [&] { return escaped_->op_Not(); });
				end_->op_AddAssign(p_int(1));
			}

			end_->op_AddAssign(p_int(1));
			return NewToken_(CodePointLiteral_, end_);
		}
		else
		{
			if (IsIdentifierChar_(curChar_).Value)
			{
				end_ = position_->op_Add(p_int(1));
				while (IsIdentifierChar_(Source_->Text_->op_Element(end_)).Value)
				{
					end_->op_AddAssign(p_int(1));
				}

				return NewIdentifierOrKeyword_(end_);
			}

			if (IsNumberChar_(curChar_).Value)
			{
				end_ = position_->op_Add(p_int(1));
				while (IsNumberChar_(Source_->Text_->op_Element(end_)).Value)
				{
					end_->op_AddAssign(p_int(1));
				}

				return NewToken_(Number_, end_);
			}

			::Text_Span_ const *_Nonnull diagnosticSpan_ = (new ::Text_Span_(position_, p_int(1)));
			diagnostics_->Add_((new ::Diagnostic_(CompilationError_, Lexing_, Source_, diagnosticSpan_, p_string("Invalid character `")->op_Add(curChar_)->op_Add(p_string("`")))));
			position_ = end_;
		}
	}

	return EndOfFile_();
}

auto ::Token_Stream_::EndOfFile_() -> ::Syntax_Node_ const *_Nullable
{
	if (endOfFile_.Value)
	{
		return ::None;
	}

	endOfFile_ = p_bool(true);
	return NewToken_(EndOfFileToken_, position_);
}

auto ::Token_Stream_::NewIdentifierOrKeyword_(p_uint const end_) -> ::Syntax_Node_ const *_Nonnull
{
	p_uint const length_ = end_->op_Subtract(position_);
	p_string const value_ = Source_->Text_->Substring_(position_, length_);
	p_int type_;
	if (value_->op_Equal(p_string("new")).Value)
	{
		type_ = NewKeyword_;
	}
	else if (value_->op_Equal(p_string("not")).Value)
	{
		type_ = NotOperator_;
	}
	else if (value_->op_Equal(p_string("null")).Value)
	{
		type_ = NullReservedWord_;
	}
	else if (value_->op_Equal(p_string("self")).Value)
	{
		type_ = SelfKeyword_;
	}
	else if (value_->op_Equal(p_string("true")).Value)
	{
		type_ = TrueKeyword_;
	}
	else if (value_->op_Equal(p_string("false")).Value)
	{
		type_ = FalseKeyword_;
	}
	else if (value_->op_Equal(p_string("mut")).Value)
	{
		type_ = MutableKeyword_;
	}
	else if (value_->op_Equal(p_string("code_point")).Value)
	{
		type_ = CodePoint_;
	}
	else if (value_->op_Equal(p_string("string")).Value)
	{
		type_ = String_;
	}
	else if (value_->op_Equal(p_string("int")).Value)
	{
		type_ = Int_;
	}
	else if (value_->op_Equal(p_string("bool")).Value)
	{
		type_ = Bool_;
	}
	else if (value_->op_Equal(p_string("void")).Value)
	{
		type_ = Void_;
	}
	else if (value_->op_Equal(p_string("uint")).Value)
	{
		type_ = UnsignedInt_;
	}
	else if (value_->op_Equal(p_string("var")).Value)
	{
		type_ = VarKeyword_;
	}
	else if (value_->op_Equal(p_string("and")).Value)
	{
		type_ = AndKeyword_;
	}
	else if (value_->op_Equal(p_string("or")).Value)
	{
		type_ = OrKeyword_;
	}
	else if (value_->op_Equal(p_string("return")).Value)
	{
		type_ = ReturnKeyword_;
	}
	else if (value_->op_Equal(p_string("loop")).Value)
	{
		type_ = LoopKeyword_;
	}
	else if (value_->op_Equal(p_string("while")).Value)
	{
		type_ = WhileKeyword_;
	}
	else if (value_->op_Equal(p_string("for")).Value)
	{
		type_ = ForKeyword_;
	}
	else if (value_->op_Equal(p_string("let")).Value)
	{
		type_ = LetKeyword_;
	}
	else if (value_->op_Equal(p_string("in")).Value)
	{
		type_ = InKeyword_;
	}
	else if (value_->op_Equal(p_string("do")).Value)
	{
		type_ = DoKeyword_;
	}
	else if (value_->op_Equal(p_string("if")).Value)
	{
		type_ = IfKeyword_;
	}
	else if (value_->op_Equal(p_string("else")).Value)
	{
		type_ = ElseKeyword_;
	}
	else if (value_->op_Equal(p_string("break")).Value)
	{
		type_ = BreakKeyword_;
	}
	else if (value_->op_Equal(p_string("continue")).Value)
	{
		type_ = ContinueKeyword_;
	}
	else if (value_->op_Equal(p_string("private")).Value)
	{
		type_ = PrivateKeyword_;
	}
	else if (value_->op_Equal(p_string("protected")).Value)
	{
		type_ = ProtectedKeyword_;
	}
	else if (value_->op_Equal(p_string("public")).Value)
	{
		type_ = PublicKeyword_;
	}
	else if (value_->op_Equal(p_string("internal")).Value)
	{
		type_ = InternalKeyword_;
	}
	else if (value_->op_Equal(p_string("class")).Value)
	{
		type_ = ClassKeyword_;
	}
	else if (value_->op_Equal(p_string("enum")).Value)
	{
		type_ = EnumKeyword_;
	}
	else if (value_->op_Equal(p_string("struct")).Value)
	{
		type_ = StructKeyword_;
	}
	else if (value_->op_Equal(p_string("none")).Value)
	{
		type_ = NoneKeyword_;
	}
	else
	{
		type_ = Identifier_;
	}

	return NewToken_(type_, end_);
}

auto ::Token_Stream_::NewOperator_(p_int const type_) -> ::Syntax_Node_ const *_Nonnull
{
	return NewToken_(type_, position_->op_Add(p_int(1)));
}

auto ::Token_Stream_::NewOperator_(p_int const type_, p_uint const length_) -> ::Syntax_Node_ const *_Nonnull
{
	return NewToken_(type_, position_->op_Add(length_));
}

auto ::Token_Stream_::NewToken_(p_int const type_, p_uint const end_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const token_ = (new ::Syntax_Node_(type_, Source_, position_, end_->op_Subtract(position_)));
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		token_->Add_(diagnostic_);
	}

	diagnostics_->Clear_();
	position_ = end_;
	return token_;
}

auto ::Token_Stream_::IsIdentifierChar_(p_code_point const c_) -> p_bool
{
	return LogicalOr(LogicalOr(LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('a')), [&] { return c_->op_LessThanOrEqual(p_code_point('z')); }), [&] { return LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('A')), [&] { return c_->op_LessThanOrEqual(p_code_point('Z')); }); }), [&] { return c_->op_Equal(p_code_point('_')); });
}

auto ::Token_Stream_::IsNumberChar_(p_code_point const c_) -> p_bool
{
	return LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('0')), [&] { return c_->op_LessThanOrEqual(p_code_point('9')); });
}

::Diagnostic_::Diagnostic_(p_int const level_, p_int const phase_, ::Source_Text_ const *_Nonnull const source_, ::Text_Span_ const *_Nonnull const span_, p_string const message_)
{
	Level_ = level_;
	Phase_ = phase_;
	Source_ = source_;
	Span_ = span_;
	Position_ = Source_->PositionOfStart_(span_);
	Message_ = message_;
}

::Emitter_::Emitter_(::Package_ const *_Nonnull const package_, ::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const resources_)
{
	this->package_ = package_;
	this->resources_ = resources_;
}

auto ::Emitter_::Emit_() -> p_string
{
	TypeDeclarations_ = (new ::Source_File_Builder_());
	FunctionDeclarations_ = (new ::Source_File_Builder_());
	ClassDeclarations_ = (new ::Source_File_Builder_());
	GlobalDefinitions_ = (new ::Source_File_Builder_());
	Definitions_ = (new ::Source_File_Builder_());
	MainFunctionReturnType_ = p_string("");
	MainFunctionAcceptsConsole_ = p_bool(false);
	MainFunctionAcceptsArgs_ = p_bool(false);
	EmitPreamble_();
	for (::Semantic_Node_ const *_Nonnull const compilationUnit_ : *(package_->CompilationUnits_))
	{
		EmitCompilationUnit_(compilationUnit_);
	}

	EmitEntryPointAdapter_();
	return TypeDeclarations_->ToString_()->op_Add(FunctionDeclarations_->ToString_())->op_Add(ClassDeclarations_->ToString_())->op_Add(GlobalDefinitions_->ToString_())->op_Add(Definitions_->ToString_());
}

auto ::Emitter_::is_value_type_(::Semantic_Node_ const *_Nonnull const type_) -> p_bool
{
	if (LogicalOr(type_->Type_->op_Equal(PredefinedType_), [&] { return type_->Type_->op_Equal(OptionalType_); }).Value)
	{
		return p_bool(true);
	}

	if (type_->Type_->op_Equal(QualifiedName_).Value)
	{
		return is_value_type_(type_->Children_->op_Element(p_int(2)));
	}

	if (type_->Type_->op_Equal(GenericName_).Value)
	{
		return is_value_type_(type_->FirstChildOfType_(IdentifierName_));
	}

	if (type_->Type_->op_Equal(IdentifierName_).Value)
	{
		if (type_->symbol_->op_Equal(::None).Value)
		{
			THROW_EXCEPTION_(p_string("No symbol on identifier name `")->op_Add(type_->GetText_())->op_Add(p_string("`")));
		}

		return type_->symbol_->is_value_type_();
	}

	if (type_->Type_->op_Equal(MutableType_).Value)
	{
		return is_value_type_(type_->Children_->op_Element(p_int(1)));
	}

	if (type_->Type_->op_Equal(ImmutableType_).Value)
	{
		return is_value_type_(type_->Children_->op_Element(p_int(0)));
	}

	THROW_EXCEPTION_(p_string("is_value_type() unable to determine if value type. Syntax node type ")->op_Add(type_->Type_));
	return p_bool(true);
}

auto ::Emitter_::convert_type_name_(::Semantic_Node_ const *_Nonnull const type_) -> p_string
{
	if (type_->Type_->op_Equal(PredefinedType_).Value)
	{
		::Semantic_Node_ const *_Nonnull const keyword_ = type_->Children_->op_Element(p_int(0));
		if (keyword_->Type_->op_Equal(Void_).Value)
		{
			return keyword_->GetText_();
		}

		return p_string("p_")->op_Add(keyword_->GetText_());
	}

	if (type_->Type_->op_Equal(IdentifierName_).Value)
	{
		return p_string("::")->op_Add(type_->GetText_())->op_Add(p_string("_"));
	}

	if (type_->Type_->op_Equal(QualifiedName_).Value)
	{
		return convert_type_name_(type_->Children_->op_Element(p_int(0)))->op_Add(convert_type_name_(type_->Children_->op_Element(p_int(2))));
	}

	if (type_->Type_->op_Equal(GenericName_).Value)
	{
		return convert_type_name_(type_->Children_->op_Element(p_int(0)))->op_Add(p_string("<"))->op_Add(convert_type_(p_bool(true), type_->Children_->op_Element(p_int(2))))->op_Add(p_string(">"));
	}

	return format_error_(p_string("Unexpected Token of type ")->op_Add(type_->Type_)->op_Add(p_string(" found in convert_type_name(), `"))->op_Add(type_->GetText_())->op_Add(p_string("`")));
}

auto ::Emitter_::convert_reference_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull type_, p_bool const nullable_, p_bool const mutable_value_) -> p_string
{
	p_string cpp_type_ = convert_type_name_(type_);
	if (mutable_value_->op_Not().Value)
	{
		cpp_type_ = cpp_type_->op_Add(p_string(" const"));
	}

	cpp_type_ = cpp_type_->op_Add(p_string(" *"));
	if (nullable_.Value)
	{
		cpp_type_ = cpp_type_->op_Add(p_string("_Nullable"));
	}
	else
	{
		cpp_type_ = cpp_type_->op_Add(p_string("_Nonnull"));
	}

	if (mutable_binding_->op_Not().Value)
	{
		cpp_type_ = cpp_type_->op_Add(p_string(" const"));
	}

	return cpp_type_;
}

auto ::Emitter_::convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull type_, p_bool const optional_) -> p_string
{
	p_bool const mutable_value_ = type_->Type_->op_Equal(MutableType_);
	if (mutable_value_.Value)
	{
		type_ = type_->Children_->op_Element(p_int(1));
	}
	else if (type_->Type_->op_Equal(ImmutableType_).Value)
	{
		type_ = type_->Children_->op_Element(p_int(0));
	}
	else
	{
		return format_error_(p_string("Expected mutable or immutable type in convert_type(). Found token `")->op_Add(type_->GetText_())->op_Add(p_string("` of type "))->op_Add(type_->Type_));
	}

	if (type_->Type_->op_Equal(OptionalType_).Value)
	{
		::Semantic_Node_ const *_Nonnull const optional_type_ = type_->Children_->op_Element(p_int(0));
		assert_(LogicalOr(optional_type_->Type_->op_Equal(MutableType_), [&] { return optional_type_->Type_->op_Equal(ImmutableType_); }));
		if (is_value_type_(optional_type_).Value)
		{
			return p_string("p_optional<")->op_Add(convert_type_(p_bool(true), optional_type_, p_bool(true)))->op_Add(p_string("> const"));
		}
		else
		{
			return convert_type_(mutable_binding_, optional_type_, p_bool(true));
		}
	}
	else
	{
		if (is_value_type_(type_).Value)
		{
			p_string cpp_type_ = convert_type_name_(type_);
			if (LogicalAnd(mutable_binding_->op_Not(), [&] { return mutable_value_->op_Not(); }).Value)
			{
				cpp_type_ = cpp_type_->op_Add(p_string(" const"));
			}

			return cpp_type_;
		}
		else
		{
			return convert_reference_type_(mutable_binding_, type_, optional_, mutable_value_);
		}
	}
}

auto ::Emitter_::convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull const type_) -> p_string
{
	return convert_type_(mutable_binding_, type_, p_bool(false));
}

auto ::Emitter_::ConvertParameterList_(::Semantic_Node_ const *_Nonnull const parameterList_, p_bool const isMainFunction_) -> p_string
{
	::System_::Text_::String_Builder_ *_Nonnull const builder_ = (new ::System_::Text_::String_Builder_());
	builder_->Append_(p_string("("));
	p_bool firstParameter_ = p_bool(true);
	for (::Semantic_Node_ const *_Nonnull const parameter_ : *(parameterList_->ChildrenOfType_(Parameter_)))
	{
		if (firstParameter_->op_Not().Value)
		{
			builder_->Append_(p_string(", "));
		}
		else
		{
			firstParameter_ = p_bool(false);
		}

		p_bool const mutable_binding_ = parameter_->HasChildOfType_(VarKeyword_);
		::Semantic_Node_ const *_Nonnull const type_ = parameter_->Children_->op_Element(parameter_->Children_->op_Magnitude()->op_Subtract(p_int(1)));
		builder_->Append_(convert_type_(mutable_binding_, type_));
		builder_->Append_(p_string(" "));
		builder_->Append_(parameter_->FirstChildOfType_(Identifier_)->GetText_());
		builder_->Append_(p_string("_"));
		if (isMainFunction_.Value)
		{
			p_string typeString_;
			if (type_->Type_->op_Equal(MutableType_).Value)
			{
				typeString_ = type_->Children_->op_Element(p_int(1))->GetText_();
			}
			else
			{
				typeString_ = type_->GetText_();
			}

			if (typeString_->op_Equal(p_string("System.Console.Console")).Value)
			{
				MainFunctionAcceptsConsole_ = p_bool(true);
			}

			if (typeString_->op_Equal(p_string("System.Console.Arguments")).Value)
			{
				MainFunctionAcceptsArgs_ = p_bool(true);
			}
		}
	}

	builder_->Append_(p_string(")"));
	return builder_->ToString_();
}

auto ::Emitter_::ConvertParameterList_(::Semantic_Node_ const *_Nonnull const parameterList_) -> p_string
{
	return ConvertParameterList_(parameterList_, p_bool(false));
}

auto ::Emitter_::ConvertExpression_(::Semantic_Node_ const *_Nonnull const syntax_, ::Source_File_Builder_ *_Nonnull const builder_) -> void
{
	if (syntax_->Type_->op_Equal(NewExpression_).Value)
	{
		::Semantic_Node_ const *_Nonnull const type_ = syntax_->Children_->op_Element(p_int(1));
		p_bool const isValueType_ = is_value_type_(type_);
		if (isValueType_->op_Not().Value)
		{
			builder_->Write_(p_string("(new "));
		}

		builder_->Write_(convert_type_name_(type_));
		::Semantic_Node_ const *_Nonnull const argumentList_ = syntax_->Children_->op_Element(p_int(2));
		ConvertExpression_(argumentList_, builder_);
		if (isValueType_->op_Not().Value)
		{
			builder_->Write_(p_string(")"));
		}
	}
	else if (syntax_->Type_->op_Equal(ArgumentList_).Value)
	{
		builder_->Write_(p_string("("));
		p_bool firstExpression_ = p_bool(true);
		for (::Semantic_Node_ const *_Nonnull const arg_ : *(syntax_->Children_))
		{
			if (LogicalAnd(LogicalAnd(arg_->Type_->op_NotEqual(LeftParen_), [&] { return arg_->Type_->op_NotEqual(RightParen_); }), [&] { return arg_->Type_->op_NotEqual(Comma_); }).Value)
			{
				if (firstExpression_.Value)
				{
					firstExpression_ = p_bool(false);
				}
				else
				{
					builder_->Write_(p_string(", "));
				}

				ConvertExpression_(arg_, builder_);
			}
		}

		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(NotExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("->op_Not()"));
	}
	else if (syntax_->Type_->op_Equal(MagnitudeExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("->op_Magnitude()"));
	}
	else if (syntax_->Type_->op_Equal(ParenthesizedExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(1)), builder_);
	}
	else if (syntax_->Type_->op_Equal(NegateExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("->op_Negate()"));
	}
	else if (syntax_->Type_->op_Equal(NoneLiteralExpression_).Value)
	{
		builder_->Write_(p_string("::None"));
	}
	else if (syntax_->Type_->op_Equal(SelfExpression_).Value)
	{
		builder_->Write_(p_string("this"));
	}
	else if (syntax_->Type_->op_Equal(NumericLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_int(")->op_Add(syntax_->GetText_())->op_Add(p_string(")")));
	}
	else if (LogicalOr(syntax_->Type_->op_Equal(TrueLiteralExpression_), [&] { return syntax_->Type_->op_Equal(FalseLiteralExpression_); }).Value)
	{
		builder_->Write_(p_string("p_bool(")->op_Add(syntax_->GetText_())->op_Add(p_string(")")));
	}
	else if (syntax_->Type_->op_Equal(CodePointLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_code_point(")->op_Add(syntax_->GetText_())->op_Add(p_string(")")));
	}
	else if (syntax_->Type_->op_Equal(IdentifierName_).Value)
	{
		builder_->Write_(syntax_->GetText_()->op_Add(p_string("_")));
	}
	else if (syntax_->Type_->op_Equal(StringLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_string(")->op_Add(syntax_->GetText_())->op_Add(p_string(")")));
	}
	else if (syntax_->Type_->op_Equal(AssignmentExpression_).Value)
	{
		p_int const operator_ = syntax_->Children_->op_Element(p_int(1))->Type_;
		if (operator_->op_Equal(Equals_).Value)
		{
			ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
			builder_->Write_(p_string(" "));
			builder_->Write_(syntax_->Children_->op_Element(p_int(1))->GetText_());
			builder_->Write_(p_string(" "));
			ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		}
		else
		{
			ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
			builder_->Write_(p_string("->op_"));
			if (operator_->op_Equal(PlusEquals_).Value)
			{
				builder_->Write_(p_string("AddAssign"));
			}
			else if (operator_->op_Equal(MinusEquals_).Value)
			{
				builder_->Write_(p_string("SubtractAssign"));
			}
			else
			{
				builder_->Error_(p_string("Unsupported assignment operator ")->op_Add(operator_));
			}

			builder_->Write_(p_string("("));
			ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
			builder_->Write_(p_string(")"));
		}
	}
	else if (syntax_->Type_->op_Equal(EqualExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Equal("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(NotEqualExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_NotEqual("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(ComparisonExpression_).Value)
	{
		p_int const operator_ = syntax_->Children_->op_Element(p_int(1))->Type_;
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_"));
		if (operator_->op_Equal(LessThan_).Value)
		{
			builder_->Write_(p_string("LessThan"));
		}
		else if (operator_->op_Equal(LessThanEquals_).Value)
		{
			builder_->Write_(p_string("LessThanOrEqual"));
		}
		else if (operator_->op_Equal(GreaterThan_).Value)
		{
			builder_->Write_(p_string("GreaterThan"));
		}
		else if (operator_->op_Equal(GreaterThanEquals_).Value)
		{
			builder_->Write_(p_string("GreaterThanOrEqual"));
		}
		else
		{
			builder_->Error_(p_string("Unsupported comparison operator ")->op_Add(operator_));
		}

		builder_->Write_(p_string("("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(AddExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Add("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(SubtractExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Subtract("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(MultiplyExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Multiply("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(DivideExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Divide("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(RemainderExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Remainder("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(OrExpression_).Value)
	{
		builder_->Write_(p_string("LogicalOr("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string(", [&] { return "));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string("; })"));
	}
	else if (syntax_->Type_->op_Equal(AndExpression_).Value)
	{
		builder_->Write_(p_string("LogicalAnd("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string(", [&] { return "));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string("; })"));
	}
	else if (syntax_->Type_->op_Equal(InvocationExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		ConvertExpression_(syntax_->Children_->op_Element(p_int(1)), builder_);
	}
	else if (syntax_->Type_->op_Equal(MemberAccessExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->"));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
	}
	else if (syntax_->Type_->op_Equal(ElementAccessExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Element("));
		ConvertExpression_(syntax_->Children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else
	{
		builder_->Error_(p_string("Could not convert expression of type ")->op_Add(syntax_->Type_));
	}
}

auto ::Emitter_::EmitStatement_(::Semantic_Node_ const *_Nonnull const statement_) -> void
{
	Definitions_->StatementSeparatorLine_();
	if (statement_->Type_->op_Equal(ReturnStatement_).Value)
	{
		if (statement_->Children_->op_Magnitude()->op_Equal(p_int(2)).Value)
		{
			Definitions_->WriteLine_(p_string("return;"));
		}
		else
		{
			Definitions_->BeginLine_(p_string("return "));
			ConvertExpression_(statement_->Children_->op_Element(p_int(1)), Definitions_);
			Definitions_->EndLine_(p_string(";"));
		}
	}
	else if (statement_->Type_->op_Equal(LoopStatement_).Value)
	{
		Definitions_->WriteLine_(p_string("for (;;)"));
		EmitStatement_(statement_->Children_->op_Element(p_int(1)));
	}
	else if (statement_->Type_->op_Equal(Block_).Value)
	{
		Definitions_->BeginBlock_();
		for (::Semantic_Node_ const *_Nonnull const blockStatement_ : *(statement_->Statements_()))
		{
			EmitStatement_(blockStatement_);
		}

		Definitions_->EndBlock_();
	}
	else if (statement_->Type_->op_Equal(WhileStatement_).Value)
	{
		Definitions_->BeginLine_(p_string("while ("));
		ConvertExpression_(statement_->Children_->op_Element(p_int(1)), Definitions_);
		Definitions_->EndLine_(p_string(".Value)"));
		EmitStatement_(statement_->Children_->op_Element(p_int(2)));
	}
	else if (statement_->Type_->op_Equal(ForStatement_).Value)
	{
		Definitions_->BeginLine_(p_string("for ("));
		::Semantic_Node_ const *_Nonnull const variableDeclaration_ = statement_->Children_->op_Element(p_int(1));
		p_bool const mutable_binding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		p_string const name_ = variableDeclaration_->FirstChildOfType_(Identifier_)->GetText_();
		::Semantic_Node_ const *_Nonnull const type_ = variableDeclaration_->Children_->op_Element(p_int(3));
		Definitions_->Write_(convert_type_(mutable_binding_, type_)->op_Add(p_string(" "))->op_Add(name_)->op_Add(p_string("_")));
		Definitions_->Write_(p_string(" : *("));
		ConvertExpression_(statement_->Children_->op_Element(p_int(3)), Definitions_);
		Definitions_->EndLine_(p_string("))"));
		EmitStatement_(statement_->Children_->op_Element(p_int(4)));
	}
	else if (statement_->Type_->op_Equal(DoWhileStatement_).Value)
	{
		Definitions_->WriteLine_(p_string("do"));
		EmitStatement_(statement_->Children_->op_Element(p_int(1)));
		Definitions_->BeginLine_(p_string("while ("));
		ConvertExpression_(statement_->Children_->op_Element(p_int(3)), Definitions_);
		Definitions_->EndLine_(p_string(".Value);"));
	}
	else if (statement_->Type_->op_Equal(IfStatement_).Value)
	{
		::Semantic_Node_ const *_Nullable ifStatement_ = statement_;
		Definitions_->BeginLine_(p_string(""));
		for (;;)
		{
			Definitions_->Write_(p_string("if ("));
			ConvertExpression_(ifStatement_->Children_->op_Element(p_int(1)), Definitions_);
			Definitions_->EndLine_(p_string(".Value)"));
			EmitStatement_(ifStatement_->Children_->op_Element(p_int(2)));
			::Semantic_Node_ const *_Nullable const elseClause_ = ifStatement_->FirstChildOfType_(ElseClause_);
			if (elseClause_->op_NotEqual(::None).Value)
			{
				ifStatement_ = elseClause_->FirstChildOfType_(IfStatement_);
				if (ifStatement_->op_NotEqual(::None).Value)
				{
					Definitions_->BeginLine_(p_string("else "));
				}
				else
				{
					Definitions_->WriteLine_(p_string("else"));
					EmitStatement_(elseClause_->Children_->op_Element(p_int(1)));
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (statement_->Type_->op_Equal(BreakStatement_).Value)
	{
		Definitions_->WriteLine_(p_string("break;"));
	}
	else if (statement_->Type_->op_Equal(ContinueStatement_).Value)
	{
		Definitions_->WriteLine_(p_string("continue;"));
	}
	else if (statement_->Type_->op_Equal(LocalDeclarationStatement_).Value)
	{
		::Semantic_Node_ const *_Nonnull const variableDeclaration_ = statement_->Children_->op_Element(p_int(0));
		p_string const variableName_ = variableDeclaration_->FirstChildOfType_(Identifier_)->GetText_();
		::Semantic_Node_ const *_Nonnull const variableType_ = variableDeclaration_->Children_->op_Element(p_int(3));
		p_bool const mutable_binding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		Definitions_->BeginLine_(convert_type_(mutable_binding_, variableType_));
		Definitions_->Write_(p_string(" ")->op_Add(variableName_)->op_Add(p_string("_")));
		if (variableDeclaration_->HasChildOfType_(Equals_).Value)
		{
			Definitions_->Write_(p_string(" = "));
			ConvertExpression_(variableDeclaration_->Children_->op_Element(p_int(5)), Definitions_);
		}

		Definitions_->EndLine_(p_string(";"));
	}
	else if (statement_->Type_->op_Equal(ExpressionStatement_).Value)
	{
		Definitions_->BeginLine_(p_string(""));
		ConvertExpression_(statement_->Children_->op_Element(p_int(0)), Definitions_);
		Definitions_->EndLine_(p_string(";"));
	}
	else
	{
		Definitions_->Error_(p_string("Could not emit statement of type ")->op_Add(statement_->Type_));
	}
}

auto ::Emitter_::EmitMemberDeclaration_(::Semantic_Node_ const *_Nonnull const member_, p_string const className_) -> void
{
	if (member_->Type_->op_Equal(ConstructorDeclaration_).Value)
	{
		p_string const parameters_ = ConvertParameterList_(member_->Children_->op_Element(p_int(2)));
		ClassDeclarations_->WriteLine_(className_->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(";")));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(p_string("::")->op_Add(className_)->op_Add(p_string("_::"))->op_Add(className_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string("")));
		EmitStatement_(member_->Children_->op_Element(p_int(3)));
	}
	else if (member_->Type_->op_Equal(FieldDeclaration_).Value)
	{
		::Semantic_Node_ const *_Nonnull const variableDeclaration_ = member_->FirstChildOfType_(VariableDeclaration_);
		p_string const fieldName_ = variableDeclaration_->Children_->op_Element(p_int(1))->GetText_();
		::Semantic_Node_ const *_Nonnull const fieldType_ = variableDeclaration_->Children_->op_Element(p_int(3));
		p_string const cppType_ = convert_type_(p_bool(true), fieldType_);
		ClassDeclarations_->WriteLine_(cppType_->op_Add(p_string(" "))->op_Add(fieldName_)->op_Add(p_string("_;")));
	}
	else if (member_->Type_->op_Equal(MethodDeclaration_).Value)
	{
		p_string const methodName_ = member_->Children_->op_Element(p_int(1))->GetText_();
		::Semantic_Node_ const *_Nonnull const parameterList_ = member_->Children_->op_Element(p_int(2));
		p_string const parameters_ = ConvertParameterList_(parameterList_);
		::Semantic_Node_ const *_Nullable const selfParameter_ = parameterList_->FirstChildOfType_(SelfParameter_);
		p_bool const isAssociatedFunction_ = selfParameter_->op_Equal(::None);
		p_bool const mutableSelf_ = LogicalAnd(isAssociatedFunction_->op_Not(), [&] { return selfParameter_->HasChildOfType_(MutableKeyword_); });
		::Semantic_Node_ const *_Nonnull const returnType_ = member_->Children_->op_Element(p_int(4));
		p_string const cppType_ = convert_type_(p_bool(true), returnType_);
		p_string staticModifier_ = p_string("");
		if (isAssociatedFunction_.Value)
		{
			staticModifier_ = p_string("static ");
		}

		p_string constModifier_ = p_string("");
		if (LogicalAnd(mutableSelf_->op_Not(), [&] { return isAssociatedFunction_->op_Not(); }).Value)
		{
			constModifier_ = p_string("const ");
		}

		ClassDeclarations_->WriteLine_(staticModifier_->op_Add(p_string("auto "))->op_Add(methodName_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(" "))->op_Add(constModifier_)->op_Add(p_string("-> "))->op_Add(cppType_)->op_Add(p_string(";")));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(p_string("auto ::")->op_Add(className_)->op_Add(p_string("_::"))->op_Add(methodName_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(" "))->op_Add(constModifier_)->op_Add(p_string("-> "))->op_Add(cppType_));
		::Semantic_Node_ const *_Nonnull const block_ = member_->Children_->op_Element(p_int(5));
		EmitStatement_(block_);
	}
	else
	{
		Definitions_->Error_(p_string("Could not emit member of type ")->op_Add(member_->Type_));
	}
}

auto ::Emitter_::EmitDeclaration_(::Semantic_Node_ const *_Nonnull const declaration_) -> void
{
	if (declaration_->Type_->op_Equal(GlobalDeclaration_).Value)
	{
		::Semantic_Node_ const *_Nonnull const variableDeclaration_ = declaration_->Children_->op_Element(p_int(1));
		p_string const variableName_ = variableDeclaration_->Children_->op_Element(p_int(1))->GetText_();
		::Semantic_Node_ const *_Nonnull const variableType_ = variableDeclaration_->Children_->op_Element(p_int(3));
		p_bool const mutable_binding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		p_string const cppType_ = convert_type_(mutable_binding_, variableType_);
		GlobalDefinitions_->BeginLine_(cppType_);
		GlobalDefinitions_->Write_(p_string(" ")->op_Add(variableName_)->op_Add(p_string("_ = ")));
		::Semantic_Node_ const *_Nonnull const expression_ = variableDeclaration_->Children_->op_Element(p_int(5));
		ConvertExpression_(expression_, GlobalDefinitions_);
		GlobalDefinitions_->EndLine_(p_string(";"));
	}
	else if (declaration_->Type_->op_Equal(ClassDeclaration_).Value)
	{
		p_string const className_ = declaration_->Children_->op_Element(p_int(2))->GetText_();
		TypeDeclarations_->WriteLine_(p_string("class ")->op_Add(className_)->op_Add(p_string("_;")));
		ClassDeclarations_->ElementSeparatorLine_();
		ClassDeclarations_->WriteLine_(p_string("class ")->op_Add(className_)->op_Add(p_string("_")));
		ClassDeclarations_->BeginBlock_();
		ClassDeclarations_->EndLine_(p_string("public:"));
		ClassDeclarations_->WriteLine_(p_string("p_bool op_Equal(")->op_Add(className_)->op_Add(p_string("_ const * other) const { return this == other; }")));
		ClassDeclarations_->WriteLine_(p_string("p_bool op_NotEqual(")->op_Add(className_)->op_Add(p_string("_ const * other) const { return this != other; }")));
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->Members_()))
		{
			EmitMemberDeclaration_(member_, className_);
		}

		ClassDeclarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->Type_->op_Equal(StructDeclaration_).Value)
	{
		p_string const structName_ = declaration_->Children_->op_Element(p_int(2))->GetText_();
		TypeDeclarations_->WriteLine_(p_string("struct ")->op_Add(structName_)->op_Add(p_string("_;")));
		ClassDeclarations_->ElementSeparatorLine_();
		ClassDeclarations_->WriteLine_(p_string("struct ")->op_Add(structName_)->op_Add(p_string("_")));
		ClassDeclarations_->BeginBlock_();
		ClassDeclarations_->EndLine_(p_string("public:"));
		ClassDeclarations_->WriteLine_(structName_->op_Add(p_string("_ * operator->() { return this; }")));
		ClassDeclarations_->WriteLine_(structName_->op_Add(p_string("_ const * operator->() const { return this; }")));
		ClassDeclarations_->WriteLine_(structName_->op_Add(p_string("_ & operator* () { return *this; }")));
		ClassDeclarations_->WriteLine_(structName_->op_Add(p_string("_ const & operator* () const { return *this; }")));
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->Members_()))
		{
			EmitMemberDeclaration_(member_, structName_);
		}

		ClassDeclarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->Type_->op_Equal(EnumDeclaration_).Value)
	{
		p_string const enumName_ = declaration_->Children_->op_Element(p_int(3))->GetText_();
		TypeDeclarations_->WriteLine_(p_string("enum class ")->op_Add(enumName_)->op_Add(p_string("_;")));
		ClassDeclarations_->ElementSeparatorLine_();
		ClassDeclarations_->WriteLine_(p_string("enum class ")->op_Add(enumName_)->op_Add(p_string("_")));
		ClassDeclarations_->BeginBlock_();
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->Children_))
		{
			if (member_->Type_->op_Equal(EnumMemberDeclaration_).Value)
			{
				p_string const memberName_ = member_->Children_->op_Element(p_int(0))->GetText_();
				ClassDeclarations_->BeginLine_(memberName_->op_Add(p_string("_")));
				::Semantic_Node_ const *_Nullable const memberValue_ = member_->FirstChildOfType_(Number_);
				if (memberValue_->op_NotEqual(::None).Value)
				{
					ClassDeclarations_->Write_(p_string(" = "));
					ClassDeclarations_->Write_(memberValue_->GetText_());
				}

				ClassDeclarations_->EndLine_(p_string(","));
			}
		}

		ClassDeclarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->Type_->op_Equal(FunctionDeclaration_).Value)
	{
		p_string const name_ = declaration_->Children_->op_Element(p_int(1))->GetText_();
		p_bool const isMain_ = name_->op_Equal(p_string("Main"));
		p_string const parameters_ = ConvertParameterList_(declaration_->Children_->op_Element(p_int(2)), isMain_);
		::Semantic_Node_ const *_Nonnull const returnType_ = declaration_->Children_->op_Element(p_int(4));
		p_string const cppType_ = convert_type_(p_bool(true), returnType_);
		FunctionDeclarations_->WriteLine_(p_string("auto ")->op_Add(name_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(" -> "))->op_Add(cppType_)->op_Add(p_string(";")));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(p_string("auto ")->op_Add(name_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(" -> "))->op_Add(cppType_));
		if (isMain_.Value)
		{
			if (MainFunctionReturnType_->op_NotEqual(p_string("")).Value)
			{
				Definitions_->Error_(p_string("Multiple declarations of main"));
			}

			MainFunctionReturnType_ = cppType_;
		}

		EmitStatement_(declaration_->Children_->op_Element(p_int(5)));
	}
	else if (declaration_->Type_->op_Equal(EndOfFileToken_).Value)
	{
	}
	else
	{
		Definitions_->Error_(p_string("Could not emit declaration of type ")->op_Add(declaration_->Type_));
	}
}

auto ::Emitter_::EmitCompilationUnit_(::Semantic_Node_ const *_Nonnull const unit_) -> void
{
	for (::Semantic_Node_ const *_Nonnull const declaration_ : *(unit_->Children_))
	{
		EmitDeclaration_(declaration_);
	}
}

auto ::Emitter_::EmitPreamble_() -> void
{
	TypeDeclarations_->WriteLine_(p_string("#include \"RuntimeLibrary.h\""));
	TypeDeclarations_->BlankLine_();
	TypeDeclarations_->WriteLine_(p_string("// Type Declarations"));
	FunctionDeclarations_->BlankLine_();
	FunctionDeclarations_->WriteLine_(p_string("// Function Declarations"));
	ClassDeclarations_->BlankLine_();
	ClassDeclarations_->WriteLine_(p_string("// Class Declarations"));
	GlobalDefinitions_->BlankLine_();
	GlobalDefinitions_->WriteLine_(p_string("// Global Definitions"));
	Definitions_->BlankLine_();
	Definitions_->WriteLine_(p_string("// Definitions"));
}

auto ::Emitter_::EmitEntryPointAdapter_() -> void
{
	Definitions_->ElementSeparatorLine_();
	Definitions_->WriteLine_(p_string("// Entry Point Adapter"));
	Definitions_->WriteLine_(p_string("std::int32_t main(int argc, char const *const * argv)"));
	Definitions_->BeginBlock_();
	Definitions_->WriteLine_(p_string("try"));
	Definitions_->BeginBlock_();
	for (::Source_Text_ const *_Nonnull const resource_ : *(resources_))
	{
		Definitions_->BeginLine_(p_string("resource_manager_->AddResource(p_string(\""));
		Definitions_->Write_(resource_->Name_);
		Definitions_->Write_(p_string("\"), p_string(\""));
		Definitions_->Write_(resource_->Text_->Replace_(p_string("\\"), p_string("\\\\"))->Replace_(p_string("\n"), p_string("\\n"))->Replace_(p_string("\r"), p_string("\\r"))->Replace_(p_string("\""), p_string("\\\"")));
		Definitions_->EndLine_(p_string("\"));"));
	}

	if (resources_->op_Magnitude()->op_GreaterThan(p_int(0)).Value)
	{
		Definitions_->EndLine_(p_string(""));
	}

	::System_::Text_::String_Builder_ *_Nonnull const args_ = (new ::System_::Text_::String_Builder_());
	if (MainFunctionAcceptsConsole_.Value)
	{
		args_->Append_(p_string("new ::System_::Console_::Console_()"));
	}

	if (MainFunctionAcceptsArgs_.Value)
	{
		if (MainFunctionAcceptsConsole_.Value)
		{
			args_->Append_(p_string(", "));
		}

		args_->Append_(p_string("new ::System_::Console_::Arguments_(argc, argv)"));
	}

	if (MainFunctionReturnType_->op_Equal(p_string("void")).Value)
	{
		Definitions_->WriteLine_(p_string("Main_(")->op_Add(args_->ToString_())->op_Add(p_string(");")));
		Definitions_->WriteLine_(p_string("return 0;"));
	}
	else
	{
		Definitions_->WriteLine_(p_string("return Main_(")->op_Add(args_->ToString_())->op_Add(p_string(").Value;")));
	}

	Definitions_->EndBlock_();
	Definitions_->WriteLine_(p_string("catch(std::exception &ex)"));
	Definitions_->BeginBlock_();
	Definitions_->WriteLine_(p_string("std::printf(\"Program exited due to error:\\n\");"));
	Definitions_->WriteLine_(p_string("std::printf(\"%s\", ex.what());"));
	Definitions_->WriteLine_(p_string("return 70;"));
	Definitions_->EndBlock_();
	Definitions_->EndBlock_();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager_->AddResource(p_string("RuntimeLibrary.cpp"), p_string("#include \"RuntimeLibrary.h\"\n#include <map>\n\np_uint p_int::AsUInt_() const\n{\n	if(this->Value < 0)\n		throw std::range_error(\"Can't convert negative number to unsigned\");\n\n	return this->Value;\n}\n\nchar p_code_point::CharValue() const\n{\n	if(this->Value > 0xFF)\n		throw std::range_error(\"Unicode char values not yet supported\");\n\n	return this->Value;\n}\n\np_string::p_string()\n	: Length(0), Buffer(0)\n{\n}\n\np_string::p_string(p_code_point c, p_int repeat)\n	: Length(repeat.Value)\n{\n	char* buffer = new char[repeat.Value];\n	for (int i = 0; i < repeat.Value; i++)\n		buffer[i] = c.CharValue();\n\n	Buffer = buffer;\n}\n\np_string::p_string(const char* s)\n	: Length(std::strlen(s)), Buffer(s)\n{\n}\n\np_string::p_string(int length, const char* s)\n	: Length(length), Buffer(s)\n{\n}\n\nchar const * p_string::cstr() const\n{\n	auto buffer = new char[Length + 1];\n	std::memcpy(buffer, Buffer, Length);\n	buffer[Length] = 0;\n	return buffer;\n}\n\np_string::p_string(p_int other)\n	: Length(0), Buffer(0)\n{\n	char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator\n	std::sprintf(buffer,\"%d\", other.Value);\n	Length = std::strlen(buffer);\n	Buffer = buffer;\n}\n\np_string::p_string(p_code_point other)\n	: Length(1), Buffer(new char[1] { other.CharValue() })\n{\n}\n\np_string p_string::Substring_(p_int start, p_int length) const\n{\n	return p_string(length.Value, Buffer + start.Value);\n}\n\np_string p_string::Replace_(p_string oldValue, p_string newValue) const\n{\n	p_string buffer = \"\";\n	int limit = Length - oldValue.Length + 1;\n	int lastIndex = 0;\n	for(int i=0; i < limit; i++)\n		if (Substring_(i, oldValue.Length).op_Equal(oldValue).Value)\n		{\n			buffer = buffer.op_Add(Substring_(lastIndex, i-lastIndex)).op_Add(newValue);\n			i += oldValue.Length; // skip over the value we just matched\n			lastIndex = i;\n			i--; // we need i-- to offset the i++ that is about to happen\n		}\n\n	buffer = buffer.op_Add(Substring_(lastIndex, Length - lastIndex));\n	return buffer;\n}\n\np_int p_string::LastIndexOf_(p_code_point c) const\n{\n	for(int i = Length - 1; i >= 0; i--)\n		if(Buffer[i] == c.CharValue())\n			return i;\n\n	return -1;\n}\n\np_string p_string::op_Add(p_string const & value) const\n{\n	int newLength = Length + value.Length;\n	char* chars = new char[newLength];\n	size_t offset = sizeof(char) * Length;\n	std::memcpy(chars, Buffer, offset);\n	std::memcpy(chars + offset, value.Buffer, value.Length);\n	return p_string(newLength, chars);\n}\n\np_bool p_string::op_Equal(p_string const & other) const\n{\n	if (Length != other.Length)\n		return false;\n\n	for (int i = 0; i < Length; i++)\n		if (Buffer[i] != other.Buffer[i])\n			return false;\n\n	return true;\n}\n\nbool operator < (p_string const & lhs, p_string const & rhs)\n{\n    return std::strcmp(lhs.cstr(), rhs.cstr()) < 0;\n}\n\nstd::map<p_string, p_string> resourceValues;\n\np_string const & ResourceManager::GetString_(p_string resourceName)\n{\n	return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(p_string name, p_string value)\n{\n	resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager_ = new ResourceManager();\n\nnamespace system_\n{\n	namespace Console_\n	{\n		void Console_::Write_(p_string value)\n		{\n			std::printf(\"%.*s\", value.Length, value.Buffer);\n		}\n\n		void Console_::WriteLine_(p_string value)\n		{\n			std::printf(\"%.*s\\n\", value.Length, value.Buffer);\n		}\n\n		void Console_::WriteLine_()\n		{\n			std::printf(\"\\n\");\n		}\n\n		Arguments_::Arguments_(int argc, char const *const * argv)\n			: Count(argc-1)\n		{\n			args = new p_string[Count];\n			for (int i = 0; i < Count; i++)\n				args[i] = p_string(argv[i+1]);\n		}\n	}\n\n	namespace IO_\n	{\n		File_Reader_::File_Reader_(const p_string& fileName)\n		{\n			std::FILE* foo;\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"rb\");\n			delete[] fname;\n		}\n\n		p_string File_Reader_::ReadToEndSync_()\n		{\n			std::fseek(file, 0, SEEK_END);\n			auto length = std::ftell(file);\n			std::fseek(file, 0, SEEK_SET);\n			auto buffer = new char[length];\n			length = std::fread(buffer, sizeof(char), length, file);\n			return p_string(length, buffer);\n		}\n\n		void File_Reader_::Close_()\n		{\n			std::fclose(file);\n		}\n\n		File_Writer_::File_Writer_(const p_string& fileName)\n		{\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"wb\"); // TODO check error\n			delete[] fname;\n		}\n\n		void File_Writer_::Write_(const p_string& value)\n		{\n			std::fwrite(value.Buffer, sizeof(char), value.Length, file);\n		}\n\n		void File_Writer_::Close_()\n		{\n			std::fclose(file);\n		}\n	}\n\n	namespace Text_\n	{\n		String_Builder_::String_Builder_(p_string const & value)\n			: buffer(value)\n		{\n		}\n\n		String_Builder_::String_Builder_()\n			: buffer(\"\")\n		{\n		}\n\n		void String_Builder_::Append_(p_string const & value)\n		{\n			buffer = buffer.op_Add(value);\n		}\n\n		void String_Builder_::Append_(String_Builder_ const * value)\n		{\n			buffer = buffer.op_Add(value->buffer);\n		}\n\n		void String_Builder_::AppendLine_(p_string const & value)\n		{\n			buffer = buffer.op_Add(value).op_Add(p_string(\"\\n\"));\n		}\n\n		void String_Builder_::AppendLine_()\n		{\n			buffer = buffer.op_Add(p_string(\"\\n\"));\n		}\n\n		void String_Builder_::Remove_(p_int start, p_int length)\n		{\n			buffer = buffer.Substring_(0, start).op_Add(buffer.Substring_(start.Value+length.Value));\n		}\n\n		void String_Builder_::Remove_(p_int start)\n		{\n			String_Builder_::Remove_(start, buffer.Length-start.Value);\n		}\n	}\n}\n"));
		resource_manager_->AddResource(p_string("RuntimeLibrary.h"), p_string("// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n#include <cstring>\n#include <cstdio>\n#include <cstdint>\n#include <stdexcept>\n\ntemplate<typename T, typename F>\nT LogicalAnd(T const & lhs, F rhs)\n{\n	return lhs.op_False().Value ? lhs : lhs.op_And(rhs());\n}\n\ntemplate<typename T, typename F>\nT LogicalOr(T const & lhs, F rhs)\n{\n	return lhs.op_True().Value ? lhs : lhs.op_Or(rhs());\n}\n\nstruct p_bool\n{\npublic:\n	// Runtime Use Members\n	bool Value;\n\n	p_bool(): Value(false) {}\n	p_bool(bool value): Value(value) {}\n	p_bool * operator->() { return this; }\n	p_bool const * operator->() const { return this; }\n	p_bool & operator* () { return *this; }\n	p_bool const & operator* () const { return *this; }\n\n	// Adamant Members\n	p_bool op_Not() const { return !this->Value; }\n	p_bool op_True() const { return this->Value; }\n	p_bool op_False() const { return !this->Value; }\n	p_bool op_And(p_bool other) const { return this->Value & other.Value; }\n	p_bool op_Or(p_bool other) const { return this->Value | other.Value; }\n};\n\nstruct p_uint;\n\nstruct p_int\n{\npublic:\n	// Runtime Use Members\n	std::int32_t Value;\n\n	p_int(std::int32_t value): Value(value) {}\n	p_int * operator->() { return this; }\n	p_int const * operator->() const { return this; }\n	p_int & operator* () { return *this; }\n	p_int const & operator* () const { return *this; }\n\n	// Hack to support conversion of uint to int for now\n	p_int(p_uint value);\n\n	// Adamant Members\n	p_int(): Value(0) {}\n	void op_AddAssign(p_int other) { this->Value += other.Value; }\n	void op_SubtractAssign(p_int other) { this->Value -= other.Value; }\n	p_bool op_Equal(p_int other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_int other) const { return this->Value != other.Value; }\n	p_bool op_LessThan(p_int other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_int other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_int other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_int other) const { return this->Value >= other.Value; }\n	p_int op_Add(p_int other) const { return this->Value + other.Value; }\n	p_int op_Subtract(p_int other) const { return this->Value - other.Value; }\n	p_int op_Negate() const { return -this->Value; }\n	p_int op_Multiply(p_int other) const { return this->Value * other.Value; }\n	p_int op_Divide(p_int other) const { return this->Value / other.Value; }\n	p_int op_Remainder(p_int other) const { return this->Value % other.Value; }\n	p_int op_Magnitude() const { if(this->Value==INT32_MIN) throw std::overflow_error(\"Can't take |int.Min|\"); return this->Value < 0 ? -this->Value : this->Value; }\n\n	// Hack because we don't support as correctly yet\n	p_uint AsUInt_() const;\n};\n\nstruct p_uint\n{\npublic:\n	// Runtime Use Members\n	std::uint32_t Value;\n\n	p_uint(std::uint32_t value): Value(value) {}\n	p_uint * operator->() { return this; }\n	p_uint const * operator->() const { return this; }\n	p_uint & operator* () { return *this; }\n	p_uint const & operator* () const { return *this; }\n\n	// Hack to support conversion of int to uint for now\n	p_uint(p_int value): Value(value.Value) {}\n\n	// Adamant Members\n	p_uint(): Value(0) {}\n	void op_AddAssign(p_uint other) { this->Value += other.Value; }\n	void op_SubtractAssign(p_uint other) { this->Value -= other.Value; }\n	p_bool op_Equal(p_uint other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_uint other) const { return this->Value != other.Value; }\n	p_bool op_LessThan(p_uint other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_uint other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_uint other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_uint other) const { return this->Value >= other.Value; }\n	p_uint op_Add(p_uint other) const { return this->Value + other.Value; }\n	p_uint op_Subtract(p_uint other) const { return this->Value - other.Value; }\n};\n\ninline p_int::p_int(p_uint value)\n	: Value(value.Value)\n{\n}\n\nstruct p_code_point\n{\nprivate:\n	std::uint32_t Value;\n\npublic:\n	// Runtime Use Members\n	p_code_point(): Value(0) {}\n	p_code_point(char value): Value(value) {}\n	p_code_point * operator->() { return this; }\n	p_code_point const * operator->() const { return this; }\n	p_code_point & operator* () { return *this; }\n	p_code_point const & operator* () const { return *this; }\n	char CharValue() const;\n\n	// Adamant Members\n	p_bool op_Equal(p_code_point const & other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_code_point const & other) const { return this->Value != other.Value; }\n	// TODO: Not sure code_point should support these operations\n	p_bool op_LessThan(p_code_point other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_code_point other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_code_point other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_code_point other) const { return this->Value >= other.Value; }\n\n};\n\nstruct p_string\n{\npublic:\n	// Runtime Use Members\n	char const * Buffer;\n	int Length;\n\n	p_string();\n	p_string(char const * s);\n	p_string(int length, char const * s);\n	char const * cstr() const;\n	p_string const * operator->() const { return this; }\n	p_string const & operator* () const { return *this; }\n\n	typedef char const * const_iterator;\n	const_iterator begin() const { return &Buffer[0]; }\n	const_iterator end() const { return &Buffer[Length]; }\n\n	// Hack to support conversion of int and code_point to strings for now\n	p_string(p_int other);\n	p_string(p_code_point other);\n\n	// Adamant Members\n	// TODO ByteLength should be a property\n	p_int ByteLength_() const { return this->Length; }\n\n	p_string(p_code_point c, p_int repeat);\n\n	p_string Substring_(p_int start, p_int length) const;\n	p_string Substring_(p_int start) const { return Substring_(start, Length-start.Value); }\n	p_string Replace_(p_string oldValue, p_string newValue) const;\n	p_int LastIndexOf_(p_code_point c) const;\n\n	p_code_point op_Element(p_int const index) const { return Buffer[index.Value]; }\n	p_string op_Add(p_string const & value) const;\n	p_bool op_Equal(p_string const & other) const;\n	p_bool op_NotEqual(p_string const & other) const { return !this->op_Equal(other).Value; }\n	p_bool op_LessThan(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) < 0; }\n	p_bool op_LessThanOrEqual(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) <= 0; }\n	p_bool op_GreaterThan(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) > 0; }\n	p_bool op_GreaterThanOrEqual(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) >= 0; }\n};\n\nclass ResourceManager\n{\npublic:\n	p_string const & GetString_(p_string resourceName);\n	void AddResource(p_string name, p_string value);\n};\n\nextern ResourceManager *const resource_manager_;\n\nclass NoneType\n{\npublic:\n	template<class T>\n	operator T*() const { return static_cast<T*>(0); }\n};\nstatic const NoneType None = NoneType();\n\ntemplate<typename T>\nstruct p_optional\n{\nprivate:\n	T data;\n	bool hasValue;\n\npublic:\n	p_optional(T const & value) : data(value), hasValue(true) {}\n	p_optional(::NoneType const & none) : hasValue(false) {}\n	T & operator->()\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T const & operator->() const\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T & operator* ()\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T const & operator* () const\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n};\n\n// A placeholder function until we get proper exceptions implemented\ninline void THROW_EXCEPTION_(const p_string& value)\n{\n	throw std::runtime_error(value.Buffer);\n}\n\ninline void assert(const p_bool condition, const p_string code, const p_string file, const std::int32_t line)\n{\n	if(!condition.Value)\n		throw std::runtime_error(\n			p_string(\"Assertion failed: \").op_Add(code)\n			.op_Add(p_string(\", file \")).op_Add(file).op_Add(p_string(\", line \")).op_Add(p_int(line)).Buffer);\n}\n\n#define assert_(condition) assert(condition, #condition, __FILE__, __LINE__)\n\n\nnamespace system_\n{\n	namespace Collections_\n	{\n		template<typename T>\n		class List_\n		{\n		private:\n			T* values;\n			int length;\n			int capacity;\n\n		public:\n			// Runtime Use Members\n			typedef T const * const_iterator;\n			const_iterator begin() const { return values; }\n			const_iterator end() const { return &values[length]; }\n\n			// Adamant Members\n			List_() : values(0), length(0), capacity(0) { }\n			void Add_(T value);\n			void Clear_() { length = 0; }\n			p_int op_Magnitude() const { return length; }\n			T const & op_Element(p_int const index) const;\n		};\n\n		template<typename T>\n		void List_<T>::Add_(T value)\n		{\n			if(length >= capacity)\n			{\n				int newCapacity = capacity == 0 ? 16 : capacity * 2;\n				T* newValues = new T[newCapacity];\n				std::memcpy(newValues, values, length * sizeof(T));\n				values = newValues;\n				capacity = newCapacity;\n			}\n			values[length] = value;\n			length++;\n		}\n\n		template<typename T>\n		T const & List_<T>::op_Element(p_int const index) const\n		{\n			if(index.Value < 0 || index.Value >= length)\n				throw std::out_of_range(\"List index out of bounds\");\n			return values[index.Value];\n		}\n	}\n\n	namespace Console_\n	{\n		class Console_\n		{\n		public:\n			void Write_(p_string value);\n			void WriteLine_(p_string value);\n			void WriteLine_();\n		};\n\n		class Arguments_\n		{\n		private:\n			p_string* args;\n		public:\n			// Runtime Use Members\n			typedef p_string const * const_iterator;\n\n			Arguments_(int argc, char const *const * argv);\n			const_iterator begin() const { return &args[0]; }\n			const_iterator end() const { return &args[Count]; }\n\n			const int Count;\n\n			// Adamant Members\n\n			p_int op_Magnitude() const { return Count; }\n			p_string const & Get_(int const index) const { return args[index]; }\n		};\n	}\n\n	namespace IO_\n	{\n		class File_Reader_\n		{\n		private:\n			std::FILE* file;\n\n		public:\n			File_Reader_(const p_string& fileName);\n			p_string ReadToEndSync_();\n			void Close_();\n		};\n\n		class File_Writer_\n		{\n		private:\n			std::FILE* file;\n\n		public:\n			File_Writer_(const p_string& fileName);\n			void Write_(const p_string& value);\n			void Close_();\n		};\n	}\n\n	namespace Text_\n	{\n		class String_Builder_\n		{\n		private:\n			p_string buffer;\n		public:\n			String_Builder_();\n			String_Builder_(p_string const & value);\n			void Append_(p_string const & value);\n			void Append_(String_Builder_ const * value);\n			void AppendLine_(p_string const& value);\n			void AppendLine_();\n			void Remove_(p_int start, p_int length);\n			void Remove_(p_int start);\n			p_string ToString_() const { return buffer; }\n		};\n	}\n}\n\nnamespace System_ = system_;\n"));

		return Main_(new ::System_::Console_::Console_(), new ::System_::Console_::Arguments_(argc, argv)).Value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
