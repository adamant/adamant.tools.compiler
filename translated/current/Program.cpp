#include "RuntimeLibrary.h"

// Type Declarations
class Source_Text_;
class Source_File_Builder_;
class Lexer_;
class Parser_;
class Syntax_Node_;
class Token_Stream_;
class Token_Type_;
class Emitter_;

// Function Declarations
auto Compile_(::System_::Collections_::List_<::Source_Text_ const *> const *const sources_, ::System_::Collections_::List_<::Source_Text_ const *> const *const resources_) -> p_string;
auto Main_(::System_::Console_::Console_ *const console_, ::System_::Console_::Arguments_ const *const args_) -> void;
auto ReadSource_(p_string const path_) -> ::Source_Text_ const *;
auto FormatError_(p_string const message_) -> p_string;
auto AcceptToken_() -> ::Syntax_Node_ const *;
auto ExpectToken_(p_int const tokenType_) -> ::Syntax_Node_ const *;
auto Accept_(p_string const expected_) -> p_bool;
auto Expect_(p_string const expected_) -> void;
auto ParseType_() -> ::Syntax_Node_ const *;
auto ParseAtom_() -> ::Syntax_Node_ const *;
auto ParseCallArguments_() -> ::Syntax_Node_ const *;
auto ParseExpression_(p_int const minPrecedence_) -> ::Syntax_Node_ const *;
auto ParseExpression_() -> ::Syntax_Node_ const *;
auto ParseStatement_() -> ::Syntax_Node_ const *;
auto ParseIfStatement_() -> ::Syntax_Node_ const *;
auto ParseVariableDeclaration_(p_bool const allowInitializer_) -> ::Syntax_Node_ const *;
auto ParseBlock_() -> ::Syntax_Node_ const *;
auto ParseParameterList_() -> ::Syntax_Node_ const *;
auto ParseClassMember_() -> ::Syntax_Node_ const *;
auto ParseDeclaration_() -> ::Syntax_Node_ const *;
auto ParseCompilationUnit_() -> ::Syntax_Node_ const *;
auto ParsePackage_(::System_::Collections_::List_<::Source_Text_ const *> const *const sources_) -> ::Syntax_Node_ const *;
auto IsValueType_(::Syntax_Node_ const *const type_) -> p_bool;
auto ConvertType_(::Syntax_Node_ const *const type_) -> p_string;
auto ConvertType_(p_bool const mutableBinding_, ::Syntax_Node_ const * type_) -> p_string;
auto ConvertParameterList_(::Syntax_Node_ const *const parameterList_, p_bool const isMainFunction_) -> p_string;
auto ConvertParameterList_(::Syntax_Node_ const *const parameterList_) -> p_string;
auto ConvertExpression_(::Syntax_Node_ const *const syntax_, ::Source_File_Builder_ *const builder_) -> void;
auto EmitStatement_(::Syntax_Node_ const *const statement_) -> void;
auto EmitClassMember_(::Syntax_Node_ const *const member_, p_string const className_) -> void;
auto EmitDeclaration_(::Syntax_Node_ const *const declaration_) -> void;
auto EmitCompilationUnit_(::Syntax_Node_ const *const unit_) -> void;
auto EmitPackage_(::Syntax_Node_ const *const package_) -> void;
auto EmitPreamble_() -> void;
auto EmitEntryPointAdapter_(::System_::Collections_::List_<::Source_Text_ const *> const *const resources_) -> void;

// Class Declarations

class Source_Text_
{
public:
	p_bool op_Equal(Source_Text_ const * other) const { return this == other; }
	p_bool op_NotEqual(Source_Text_ const * other) const { return this != other; }
	p_string Package_;
	p_string Name_;
	p_string Text_;
	Source_Text_(p_string const package_, p_string const name_, p_string const text_);
};

class Source_File_Builder_
{
public:
	p_bool op_Equal(Source_File_Builder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Source_File_Builder_ const * other) const { return this != other; }
	::System_::Text_::String_Builder_ * code_;
	::System_::Text_::String_Builder_ * indent_;
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

class Lexer_
{
public:
	p_bool op_Equal(Lexer_ const * other) const { return this == other; }
	p_bool op_NotEqual(Lexer_ const * other) const { return this != other; }
	auto Analyze_(::Source_Text_ const *const source_) const -> ::Token_Stream_ *;
};

class Parser_
{
public:
	p_bool op_Equal(Parser_ const * other) const { return this == other; }
	p_bool op_NotEqual(Parser_ const * other) const { return this != other; }
	Parser_();
	auto Parse_(::Token_Stream_ const *const tokenStream_) const -> ::Syntax_Node_ const *;
};

class Syntax_Node_
{
public:
	p_bool op_Equal(Syntax_Node_ const * other) const { return this == other; }
	p_bool op_NotEqual(Syntax_Node_ const * other) const { return this != other; }
	p_int Type_;
	::Source_Text_ const * Source_;
	p_uint Start_;
	p_uint Length_;
	::System_::Collections_::List_<::Syntax_Node_ const *> const * Children_;
	Syntax_Node_(p_int const type_, ::Source_Text_ const *const source_, p_uint const start_, p_uint const length_);
	Syntax_Node_(p_int const type_, ::Syntax_Node_ const *const child_);
	Syntax_Node_(p_int const type_, ::System_::Collections_::List_<::Syntax_Node_ const *> const *const children_);
	auto GetText_() const -> p_string;
	auto FirstChildOfType_(p_int const type_) const -> ::Syntax_Node_ const *;
	auto HasChildOfType_(p_int const type_) const -> p_bool;
};

class Token_Stream_
{
public:
	p_bool op_Equal(Token_Stream_ const * other) const { return this == other; }
	p_bool op_NotEqual(Token_Stream_ const * other) const { return this != other; }
	::Source_Text_ const * Source_;
	p_uint position_;
	Token_Stream_(::Source_Text_ const *const source_);
	auto GetNextToken_() -> ::Syntax_Node_ const *;
	auto NewIdentifierOrKeyword_(p_uint const end_) -> ::Syntax_Node_ const *;
	auto NewOperator_(p_int const type_) -> ::Syntax_Node_ const *;
	auto NewOperator_(p_int const type_, p_uint const length_) -> ::Syntax_Node_ const *;
	auto NewToken_(p_int const type_, p_uint const end_) -> ::Syntax_Node_ const *;
	static auto IsIdentifierChar_(p_code_point const c_) -> p_bool;
	static auto IsNumberChar_(p_code_point const c_) -> p_bool;
};

class Token_Type_
{
public:
	p_bool op_Equal(Token_Type_ const * other) const { return this == other; }
	p_bool op_NotEqual(Token_Type_ const * other) const { return this != other; }
};

class Emitter_
{
public:
	p_bool op_Equal(Emitter_ const * other) const { return this == other; }
	p_bool op_NotEqual(Emitter_ const * other) const { return this != other; }
};

// Global Definitions
::Token_Stream_ * tokenStream_ = ::None;
::Syntax_Node_ const * Token_ = ::None;
p_int const Error_ = p_int(1)->op_UnaryMinus();
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
p_int const Equal_ = p_int(12);
p_int const Assign_ = p_int(13);
p_int const AddAssign_ = p_int(14);
p_int const Add_ = p_int(15);
p_int const Arrow_ = p_int(16);
p_int const SubAssign_ = p_int(17);
p_int const Sub_ = p_int(18);
p_int const Slash_ = p_int(19);
p_int const NotEqual_ = p_int(20);
p_int const LessThanOrEqual_ = p_int(21);
p_int const LessThan_ = p_int(22);
p_int const GreaterThanOrEqual_ = p_int(23);
p_int const GreaterThan_ = p_int(24);
p_int const StringLiteral_ = p_int(25);
p_int const CodePointLiteral_ = p_int(26);
p_int const Identifier_ = p_int(27);
p_int const Number_ = p_int(28);
p_int const NewKeyword_ = p_int(29);
p_int const NotOperator_ = p_int(30);
p_int const NullKeyword_ = p_int(31);
p_int const SelfKeyword_ = p_int(32);
p_int const TrueKeyword_ = p_int(33);
p_int const FalseKeyword_ = p_int(34);
p_int const IdentifierName_ = p_int(35);
p_int const GenericName_ = p_int(36);
p_int const QualifiedName_ = p_int(37);
p_int const PackageQualifiedName_ = p_int(38);
p_int const MutableKeyword_ = p_int(39);
p_int const NullableType_ = p_int(40);
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
p_int const NullLiteralExpression_ = p_int(57);
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
p_int const ComparisionExpression_ = p_int(71);
p_int const AddExpression_ = p_int(72);
p_int const SubtractExpression_ = p_int(73);
p_int const InvocationExpression_ = p_int(74);
p_int const MemberAccessExpression_ = p_int(75);
p_int const ElementAccessExpression_ = p_int(76);
p_int const UnaryMinusExpression_ = p_int(77);
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
p_int const Package_ = p_int(118);
::Source_File_Builder_ *const TypeDeclarations_ = new ::Source_File_Builder_();
::Source_File_Builder_ *const FunctionDeclarations_ = new ::Source_File_Builder_();
::Source_File_Builder_ *const ClassDeclarations_ = new ::Source_File_Builder_();
::Source_File_Builder_ *const GlobalDefinitions_ = new ::Source_File_Builder_();
::Source_File_Builder_ *const Definitions_ = new ::Source_File_Builder_();
p_string MainFunctionReturnType_ = p_string("");
p_bool MainFunctionAcceptsConsole_ = p_bool(false);
p_bool MainFunctionAcceptsArgs_ = p_bool(false);

// Definitions

auto Compile_(::System_::Collections_::List_<::Source_Text_ const *> const *const sources_, ::System_::Collections_::List_<::Source_Text_ const *> const *const resources_) -> p_string
{
	::Syntax_Node_ const * package_ = ParsePackage_(sources_);
	EmitPreamble_();
	EmitPackage_(package_);
	EmitEntryPointAdapter_(resources_);
	return TypeDeclarations_->ToString_()->op_Plus(FunctionDeclarations_->ToString_())->op_Plus(ClassDeclarations_->ToString_())->op_Plus(GlobalDefinitions_->ToString_())->op_Plus(Definitions_->ToString_());
}

auto Main_(::System_::Console_::Console_ *const console_, ::System_::Console_::Arguments_ const *const args_) -> void
{
	::System_::Collections_::List_<p_string> *const sourceFilePaths_ = new ::System_::Collections_::List_<p_string>();
	::System_::Collections_::List_<p_string> *const resourceFilePaths_ = new ::System_::Collections_::List_<p_string>();
	p_string outputFilePath_ = p_string("");
	p_bool verbose_ = p_bool(false);
	p_int argType_ = p_int(0);
	for (p_string const arg_ : *(args_))
	{
		if (argType_->op_Equal(p_int(1)).Value)
		{
			resourceFilePaths_->Add_(arg_);
			argType_ = p_int(0);
		}
		else if (argType_->op_Equal(p_int(2)).Value)
		{
			outputFilePath_ = arg_;
			argType_ = p_int(0);
		}
		else
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
	}

	if ((verbose_).Value)
	{
		console_->WriteLine_(p_string("Adamant Compiler v0.1.0"));
	}

	if (LogicalOr(sourceFilePaths_->Length_()->op_Equal(p_int(0)), [&] { return outputFilePath_->op_Equal(p_string("")); }).Value)
	{
		console_->WriteLine_(p_string("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return;
	}

	::System_::Collections_::List_<::Source_Text_ const *> *const resources_ = new ::System_::Collections_::List_<::Source_Text_ const *>();
	if (resourceFilePaths_->Length_()->op_GreaterThan(p_int(0)).Value)
	{
		if ((verbose_).Value)
		{
			console_->WriteLine_(p_string("Reading Resources:"));
		}

		for (p_string const resourceFilePath_ : *(resourceFilePaths_))
		{
			if ((verbose_).Value)
			{
				console_->WriteLine_(p_string("  ")->op_Plus(resourceFilePath_));
			}

			resources_->Add_(ReadSource_(resourceFilePath_));
		}
	}

	if ((verbose_).Value)
	{
		console_->WriteLine_(p_string("Compiling:"));
	}

	::System_::Collections_::List_<::Source_Text_ const *> *const sources_ = new ::System_::Collections_::List_<::Source_Text_ const *>();
	for (p_string const sourceFilePath_ : *(sourceFilePaths_))
	{
		if ((verbose_).Value)
		{
			console_->WriteLine_(p_string("  ")->op_Plus(sourceFilePath_));
		}

		sources_->Add_(ReadSource_(sourceFilePath_));
	}

	p_string const translated_ = Compile_(sources_, resources_);
	if ((verbose_).Value)
	{
		console_->Write_(p_string("Output: "));
		console_->WriteLine_(outputFilePath_);
	}

	::System_::IO_::File_Writer_ *const outputFile_ = new ::System_::IO_::File_Writer_(outputFilePath_);
	outputFile_->Write_(translated_);
	outputFile_->Close_();
	p_string outputDirPath_ = outputFilePath_;
	p_int index_ = outputDirPath_->LastIndexOf_(p_code_point('/'));
	if (index_->op_NotEqual(p_int(1)->op_UnaryMinus()).Value)
	{
		outputDirPath_ = outputDirPath_->Substring_(p_int(0), index_->op_Plus(p_int(1)));
	}

	index_ = outputDirPath_->LastIndexOf_(p_code_point('\\'));
	if (index_->op_NotEqual(p_int(1)->op_UnaryMinus()).Value)
	{
		outputDirPath_ = outputDirPath_->Substring_(p_int(0), index_->op_Plus(p_int(1)));
	}

	if ((verbose_).Value)
	{
		console_->Write_(p_string("Outputting RuntimeLibrary to: "));
		console_->WriteLine_(outputDirPath_);
	}

	::System_::IO_::File_Writer_ * resourceFile_ = new ::System_::IO_::File_Writer_(outputDirPath_->op_Plus(p_string("RuntimeLibrary.h")));
	resourceFile_->Write_(resource_manager_->GetString_(p_string("RuntimeLibrary.h")));
	resourceFile_->Close_();
	resourceFile_ = new ::System_::IO_::File_Writer_(outputDirPath_->op_Plus(p_string("RuntimeLibrary.cpp")));
	resourceFile_->Write_(resource_manager_->GetString_(p_string("RuntimeLibrary.cpp")));
	resourceFile_->Close_();
}

auto ReadSource_(p_string const path_) -> ::Source_Text_ const *
{
	::System_::IO_::File_Reader_ *const file_ = new ::System_::IO_::File_Reader_(path_);
	p_string const contents_ = file_->ReadToEndSync_();
	file_->Close_();
	p_string name_ = path_;
	p_int index_ = name_->LastIndexOf_(p_code_point('/'));
	if (index_->op_NotEqual(p_int(1)->op_UnaryMinus()).Value)
	{
		name_ = name_->Substring_(index_->op_Plus(p_int(1)));
	}

	index_ = name_->LastIndexOf_(p_code_point('\\'));
	if (index_->op_NotEqual(p_int(1)->op_UnaryMinus()).Value)
	{
		name_ = name_->Substring_(index_->op_Plus(p_int(1)));
	}

	return new ::Source_Text_(p_string("<default>"), name_, contents_);
}

::Source_Text_::Source_Text_(p_string const package_, p_string const name_, p_string const text_)
{
	Package_ = package_;
	Name_ = name_;
	Text_ = text_;
}

auto FormatError_(p_string const message_) -> p_string
{
	return p_string("<$ ")->op_Plus(message_)->op_Plus(p_string(" $>"));
}

::Source_File_Builder_::Source_File_Builder_()
{
	code_ = new ::System_::Text_::String_Builder_();
	indent_ = new ::System_::Text_::String_Builder_();
	firstElement_ = p_bool(true);
	afterBlock_ = p_bool(true);
}

auto ::Source_File_Builder_::Error_(p_string const message_) -> void
{
	code_->Append_(FormatError_(message_));
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

auto ::Lexer_::Analyze_(::Source_Text_ const *const source_) const -> ::Token_Stream_ *
{
	return new ::Token_Stream_(source_);
}

auto AcceptToken_() -> ::Syntax_Node_ const *
{
	::Syntax_Node_ const *const node_ = Token_;
	Token_ = tokenStream_->GetNextToken_();
	return node_;
}

auto ExpectToken_(p_int const tokenType_) -> ::Syntax_Node_ const *
{
	if (Token_->Type_->op_NotEqual(tokenType_).Value)
	{
		Definitions_->Error_(p_string("Expected token type ")->op_Plus(tokenType_)->op_Plus(p_string(", found `"))->op_Plus(Token_->GetText_())->op_Plus(p_string("` of type "))->op_Plus(Token_->Type_));
		Token_ = tokenStream_->GetNextToken_();
		return new ::Syntax_Node_(Error_, Token_->Source_, Token_->Start_, Token_->Length_);
	}

	::Syntax_Node_ const *const node_ = Token_;
	Token_ = tokenStream_->GetNextToken_();
	return node_;
}

auto Accept_(p_string const expected_) -> p_bool
{
	p_bool const accepted_ = Token_->GetText_()->op_Equal(expected_);
	if (accepted_.Value)
	{
		Token_ = tokenStream_->GetNextToken_();
	}

	return accepted_;
}

auto Expect_(p_string const expected_) -> void
{
	if (Token_->GetText_()->op_NotEqual(expected_).Value)
	{
		Definitions_->Error_(p_string("Expected `")->op_Plus(expected_)->op_Plus(p_string("` but found `"))->op_Plus(Token_->GetText_())->op_Plus(p_string("`")));
		Token_ = tokenStream_->GetNextToken_();
	}
	else
	{
		Token_ = tokenStream_->GetNextToken_();
	}
}

auto ParseType_() -> ::Syntax_Node_ const *
{
	if (Token_->Type_->op_Equal(MutableKeyword_).Value)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
		children_->Add_(ExpectToken_(MutableKeyword_));
		children_->Add_(ParseType_());
		return new ::Syntax_Node_(MutableType_, children_);
	}

	::Syntax_Node_ const * type_;
	if (LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(Token_->Type_->op_Equal(CodePoint_), [&] { return Token_->Type_->op_Equal(String_); }), [&] { return Token_->Type_->op_Equal(Int_); }), [&] { return Token_->Type_->op_Equal(Bool_); }), [&] { return Token_->Type_->op_Equal(Void_); }), [&] { return Token_->Type_->op_Equal(UnsignedInt_); }).Value)
	{
		type_ = new ::Syntax_Node_(PredefinedType_, AcceptToken_());
	}
	else
	{
		type_ = new ::Syntax_Node_(IdentifierName_, ExpectToken_(Identifier_));
		while (Token_->Type_->op_Equal(Dot_).Value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
			children_->Add_(type_);
			children_->Add_(ExpectToken_(Dot_));
			::Syntax_Node_ const *const identifier_ = ExpectToken_(Identifier_);
			if (Token_->Type_->op_Equal(LessThan_).Value)
			{
				::System_::Collections_::List_<::Syntax_Node_ const *> *const genericNameChildren_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
				genericNameChildren_->Add_(new ::Syntax_Node_(IdentifierName_, identifier_));
				genericNameChildren_->Add_(ExpectToken_(LessThan_));
				genericNameChildren_->Add_(ParseType_());
				genericNameChildren_->Add_(ExpectToken_(GreaterThan_));
				children_->Add_(new ::Syntax_Node_(GenericName_, genericNameChildren_));
			}
			else
			{
				children_->Add_(new ::Syntax_Node_(IdentifierName_, identifier_));
			}

			type_ = new ::Syntax_Node_(QualifiedName_, children_);
		}
	}

	if (Token_->Type_->op_Equal(Question_).Value)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
		children_->Add_(type_);
		children_->Add_(ExpectToken_(Question_));
		type_ = new ::Syntax_Node_(NullableType_, children_);
	}

	return type_;
}

auto ParseAtom_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (Token_->Type_->op_Equal(NewKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseType_());
		children_->Add_(ParseCallArguments_());
		return new ::Syntax_Node_(NewExpression_, children_);
	}

	if (Token_->Type_->op_Equal(NotOperator_).Value)
	{
		children_->Add_(ExpectToken_(NotOperator_));
		children_->Add_(ParseExpression_(p_int(7)));
		return new ::Syntax_Node_(NotExpression_, children_);
	}

	if (Token_->Type_->op_Equal(LeftParen_).Value)
	{
		children_->Add_(ExpectToken_(LeftParen_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(RightParen_));
		return new ::Syntax_Node_(ParenthesizedExpression_, children_);
	}

	if (Token_->Type_->op_Equal(Sub_).Value)
	{
		children_->Add_(ExpectToken_(Sub_));
		children_->Add_(ParseExpression_(p_int(7)));
		return new ::Syntax_Node_(UnaryMinusExpression_, children_);
	}

	if (Token_->Type_->op_Equal(NullKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NullKeyword_));
		return new ::Syntax_Node_(NullLiteralExpression_, children_);
	}

	if (Token_->Type_->op_Equal(SelfKeyword_).Value)
	{
		children_->Add_(ExpectToken_(SelfKeyword_));
		return new ::Syntax_Node_(SelfExpression_, children_);
	}

	if (Token_->Type_->op_Equal(TrueKeyword_).Value)
	{
		children_->Add_(ExpectToken_(TrueKeyword_));
		return new ::Syntax_Node_(TrueLiteralExpression_, children_);
	}

	if (Token_->Type_->op_Equal(FalseKeyword_).Value)
	{
		children_->Add_(ExpectToken_(FalseKeyword_));
		return new ::Syntax_Node_(FalseLiteralExpression_, children_);
	}

	if (Token_->Type_->op_Equal(Number_).Value)
	{
		children_->Add_(ExpectToken_(Number_));
		return new ::Syntax_Node_(NumericLiteralExpression_, children_);
	}

	if (Token_->Type_->op_Equal(Identifier_).Value)
	{
		children_->Add_(ExpectToken_(Identifier_));
		return new ::Syntax_Node_(IdentifierName_, children_);
	}

	if (Token_->Type_->op_Equal(StringLiteral_).Value)
	{
		children_->Add_(ExpectToken_(StringLiteral_));
		return new ::Syntax_Node_(StringLiteralExpression_, children_);
	}

	if (Token_->Type_->op_Equal(CodePointLiteral_).Value)
	{
		children_->Add_(ExpectToken_(CodePointLiteral_));
		return new ::Syntax_Node_(CodePointLiteralExpression_, children_);
	}

	return ::None;
}

auto ParseCallArguments_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(ExpectToken_(LeftParen_));
	if (Token_->Type_->op_NotEqual(RightParen_).Value)
	{
		for (;;)
		{
			children_->Add_(ParseExpression_());
			if (Token_->Type_->op_Equal(Comma_).Value)
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
	return new ::Syntax_Node_(ArgumentList_, children_);
}

auto ParseExpression_(p_int const minPrecedence_) -> ::Syntax_Node_ const *
{
	::Syntax_Node_ const * expression_ = ParseAtom_();
	if (expression_->op_Equal(::None).Value)
	{
		return ::None;
	}

	for (;;)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
		children_->Add_(expression_);
		p_int precedence_;
		p_bool leftAssociative_;
		p_bool suffixOperator_ = p_bool(false);
		p_int expressionType_;
		if (LogicalAnd((LogicalOr(LogicalOr(Token_->Type_->op_Equal(Assign_), [&] { return Token_->Type_->op_Equal(AddAssign_); }), [&] { return Token_->Type_->op_Equal(SubAssign_); })), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(1)); }).Value)
		{
			precedence_ = p_int(1);
			leftAssociative_ = p_bool(false);
			children_->Add_(AcceptToken_());
			expressionType_ = AssignmentExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(OrKeyword_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(2)); }).Value)
		{
			precedence_ = p_int(2);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(OrKeyword_));
			expressionType_ = OrExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(AndKeyword_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(3)); }).Value)
		{
			precedence_ = p_int(3);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(AndKeyword_));
			expressionType_ = AndExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(Equal_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(4)); }).Value)
		{
			precedence_ = p_int(4);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Equal_));
			expressionType_ = EqualExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(NotEqual_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(4)); }).Value)
		{
			precedence_ = p_int(4);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(NotEqual_));
			expressionType_ = NotEqualExpression_;
		}
		else if (LogicalAnd((LogicalOr(LogicalOr(LogicalOr(Token_->Type_->op_Equal(LessThan_), [&] { return Token_->Type_->op_Equal(LessThanOrEqual_); }), [&] { return Token_->Type_->op_Equal(GreaterThan_); }), [&] { return Token_->Type_->op_Equal(GreaterThanOrEqual_); })), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(5)); }).Value)
		{
			precedence_ = p_int(5);
			leftAssociative_ = p_bool(true);
			children_->Add_(AcceptToken_());
			expressionType_ = ComparisionExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(Add_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(6)); }).Value)
		{
			precedence_ = p_int(6);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Add_));
			expressionType_ = AddExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(Sub_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(6)); }).Value)
		{
			precedence_ = p_int(6);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Sub_));
			expressionType_ = SubtractExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(LeftParen_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(8)); }).Value)
		{
			precedence_ = p_int(8);
			leftAssociative_ = p_bool(true);
			suffixOperator_ = p_bool(true);
			children_->Add_(ParseCallArguments_());
			expressionType_ = InvocationExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(Dot_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(8)); }).Value)
		{
			precedence_ = p_int(8);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Dot_));
			expressionType_ = MemberAccessExpression_;
		}
		else if (LogicalAnd(Token_->Type_->op_Equal(LeftBracket_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(8)); }).Value)
		{
			precedence_ = p_int(8);
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
				precedence_->op_PlusAssign(p_int(1));
			}

			::Syntax_Node_ const *const rhs_ = ParseExpression_(precedence_);
			children_->Add_(rhs_);
			expression_ = new ::Syntax_Node_(expressionType_, children_);
		}
		else
		{
			expression_ = new ::Syntax_Node_(expressionType_, children_);
		}
	}
}

auto ParseExpression_() -> ::Syntax_Node_ const *
{
	return ParseExpression_(p_int(1));
}

auto ParseStatement_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (Token_->Type_->op_Equal(ReturnKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ReturnKeyword_));
		if (Token_->Type_->op_NotEqual(Semicolon_).Value)
		{
			children_->Add_(ParseExpression_());
		}

		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(ReturnStatement_, children_);
	}

	if (Token_->Type_->op_Equal(LoopKeyword_).Value)
	{
		children_->Add_(ExpectToken_(LoopKeyword_));
		children_->Add_(ParseBlock_());
		return new ::Syntax_Node_(LoopStatement_, children_);
	}

	if (Token_->Type_->op_Equal(WhileKeyword_).Value)
	{
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return new ::Syntax_Node_(WhileStatement_, children_);
	}

	if (Token_->Type_->op_Equal(ForKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ForKeyword_));
		children_->Add_(ParseVariableDeclaration_(p_bool(false)));
		children_->Add_(ExpectToken_(InKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return new ::Syntax_Node_(ForStatement_, children_);
	}

	if (Token_->Type_->op_Equal(DoKeyword_).Value)
	{
		children_->Add_(ExpectToken_(DoKeyword_));
		children_->Add_(ParseBlock_());
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(DoWhileStatement_, children_);
	}

	if (Token_->Type_->op_Equal(IfKeyword_).Value)
	{
		return ParseIfStatement_();
	}

	if (Token_->Type_->op_Equal(BreakKeyword_).Value)
	{
		children_->Add_(ExpectToken_(BreakKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(BreakStatement_, children_);
	}

	if (Token_->Type_->op_Equal(ContinueKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ContinueKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(ContinueStatement_, children_);
	}

	if (LogicalOr(Token_->Type_->op_Equal(VarKeyword_), [&] { return Token_->Type_->op_Equal(LetKeyword_); }).Value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(true)));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(LocalDeclarationStatement_, children_);
	}

	children_->Add_(ParseExpression_());
	children_->Add_(ExpectToken_(Semicolon_));
	return new ::Syntax_Node_(ExpressionStatement_, children_);
}

auto ParseIfStatement_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(ExpectToken_(IfKeyword_));
	children_->Add_(ParseExpression_());
	children_->Add_(ParseBlock_());
	if (Token_->Type_->op_Equal(ElseKeyword_).Value)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *> *const elseChildren_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
		elseChildren_->Add_(ExpectToken_(ElseKeyword_));
		if (Token_->Type_->op_Equal(IfKeyword_).Value)
		{
			elseChildren_->Add_(ParseIfStatement_());
		}
		else
		{
			elseChildren_->Add_(ParseBlock_());
		}

		children_->Add_(new ::Syntax_Node_(ElseClause_, elseChildren_));
	}

	return new ::Syntax_Node_(IfStatement_, children_);
}

auto ParseVariableDeclaration_(p_bool const allowInitializer_) -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (LogicalAnd(Token_->Type_->op_Equal(LetKeyword_), [&] { return Token_->Type_->op_NotEqual(VarKeyword_); }).Value)
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
	if (LogicalAnd(allowInitializer_, [&] { return Token_->Type_->op_Equal(Assign_); }).Value)
	{
		children_->Add_(ExpectToken_(Assign_));
		children_->Add_(ParseExpression_());
	}

	return new ::Syntax_Node_(VariableDeclaration_, children_);
}

auto ParseBlock_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(ExpectToken_(LeftBrace_));
	while (Token_->Type_->op_NotEqual(RightBrace_).Value)
	{
		children_->Add_(ParseStatement_());
	}

	children_->Add_(ExpectToken_(RightBrace_));
	return new ::Syntax_Node_(Block_, children_);
}

auto ParseParameterList_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(ExpectToken_(LeftParen_));
	if (Token_->Type_->op_NotEqual(RightParen_).Value)
	{
		for (;;)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *> *const parameterChildren_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
			if (LogicalOr(Token_->Type_->op_Equal(MutableKeyword_), [&] { return Token_->Type_->op_Equal(SelfKeyword_); }).Value)
			{
				if (Token_->Type_->op_Equal(MutableKeyword_).Value)
				{
					parameterChildren_->Add_(ExpectToken_(MutableKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(SelfKeyword_));
				children_->Add_(new ::Syntax_Node_(SelfParameter_, parameterChildren_));
			}
			else
			{
				p_bool const mutableBinding_ = Token_->Type_->op_Equal(VarKeyword_);
				if (Token_->Type_->op_Equal(VarKeyword_).Value)
				{
					parameterChildren_->Add_(ExpectToken_(VarKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(Identifier_));
				parameterChildren_->Add_(ExpectToken_(Colon_));
				::Syntax_Node_ const *const type_ = ParseType_();
				parameterChildren_->Add_(type_);
				children_->Add_(new ::Syntax_Node_(Parameter_, parameterChildren_));
			}

			if (Token_->Type_->op_Equal(Comma_).Value)
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
	return new ::Syntax_Node_(ParameterList_, children_);
}

auto ParseClassMember_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (LogicalOr(LogicalOr(LogicalOr(Token_->Type_->op_Equal(PublicKeyword_), [&] { return Token_->Type_->op_Equal(ProtectedKeyword_); }), [&] { return Token_->Type_->op_Equal(InternalKeyword_); }), [&] { return Token_->Type_->op_Equal(PrivateKeyword_); }).Value)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		ExpectToken_(PublicKeyword_);
	}

	if (Token_->Type_->op_Equal(NewKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseParameterList_());
		children_->Add_(ParseBlock_());
		return new ::Syntax_Node_(ConstructorDeclaration_, children_);
	}

	if (LogicalOr(Token_->Type_->op_Equal(VarKeyword_), [&] { return Token_->Type_->op_Equal(LetKeyword_); }).Value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(false)));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(FieldDeclaration_, children_);
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ParseParameterList_());
	children_->Add_(ExpectToken_(Arrow_));
	children_->Add_(ParseType_());
	children_->Add_(ParseBlock_());
	return new ::Syntax_Node_(MethodDeclaration_, children_);
}

auto ParseDeclaration_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (LogicalOr(LogicalOr(LogicalOr(Token_->Type_->op_Equal(PublicKeyword_), [&] { return Token_->Type_->op_Equal(ProtectedKeyword_); }), [&] { return Token_->Type_->op_Equal(InternalKeyword_); }), [&] { return Token_->Type_->op_Equal(PrivateKeyword_); }).Value)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		ExpectToken_(PublicKeyword_);
	}

	if (LogicalOr(Token_->Type_->op_Equal(VarKeyword_), [&] { return Token_->Type_->op_Equal(LetKeyword_); }).Value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(true)));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(GlobalDeclaration_, children_);
	}

	if (Token_->Type_->op_Equal(ClassKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ClassKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (Token_->Type_->op_NotEqual(RightBrace_).Value)
		{
			children_->Add_(ParseClassMember_());
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return new ::Syntax_Node_(ClassDeclaration_, children_);
	}

	if (Token_->Type_->op_Equal(EnumKeyword_).Value)
	{
		children_->Add_(ExpectToken_(EnumKeyword_));
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (Token_->Type_->op_NotEqual(RightBrace_).Value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *> *const memberChildren_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
			memberChildren_->Add_(ExpectToken_(Identifier_));
			if (Token_->Type_->op_Equal(Assign_).Value)
			{
				memberChildren_->Add_(ExpectToken_(Assign_));
				memberChildren_->Add_(ExpectToken_(Number_));
			}

			if (Token_->Type_->op_NotEqual(RightBrace_).Value)
			{
				memberChildren_->Add_(ExpectToken_(Comma_));
			}

			children_->Add_(new ::Syntax_Node_(EnumMemberDeclaration_, memberChildren_));
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return new ::Syntax_Node_(EnumDeclaration_, children_);
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ParseParameterList_());
	children_->Add_(ExpectToken_(Arrow_));
	children_->Add_(ParseType_());
	children_->Add_(ParseBlock_());
	return new ::Syntax_Node_(FunctionDeclaration_, children_);
}

auto ParseCompilationUnit_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	while (Token_->op_NotEqual(::None).Value)
	{
		children_->Add_(ParseDeclaration_());
	}

	return new ::Syntax_Node_(CompilationUnit_, children_);
}

auto ParsePackage_(::System_::Collections_::List_<::Source_Text_ const *> const *const sources_) -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	::Lexer_ const *const lexer_ = new ::Lexer_();
	for (::Source_Text_ const *const source_ : *(sources_))
	{
		tokenStream_ = lexer_->Analyze_(source_);
		Token_ = tokenStream_->GetNextToken_();
		children_->Add_(ParseCompilationUnit_());
	}

	return new ::Syntax_Node_(Package_, children_);
}

::Parser_::Parser_()
{
}

auto ::Parser_::Parse_(::Token_Stream_ const *const tokenStream_) const -> ::Syntax_Node_ const *
{
	return ::None;
}

::Syntax_Node_::Syntax_Node_(p_int const type_, ::Source_Text_ const *const source_, p_uint const start_, p_uint const length_)
{
	Type_ = type_;
	Source_ = source_;
	Start_ = start_;
	Length_ = length_;
	Children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
}

::Syntax_Node_::Syntax_Node_(p_int const type_, ::Syntax_Node_ const *const child_)
{
	Type_ = type_;
	Source_ = child_->Source_;
	Start_ = child_->Start_;
	Length_ = child_->Length_;
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(child_);
	Children_ = children_;
}

::Syntax_Node_::Syntax_Node_(p_int const type_, ::System_::Collections_::List_<::Syntax_Node_ const *> const *const children_)
{
	Type_ = type_;
	if (children_->Length_()->op_GreaterThan(p_int(0)).Value)
	{
		Source_ = children_->Get_(p_int(0))->Source_;
		Start_ = children_->Get_(p_int(0))->Start_;
		::Syntax_Node_ const *const lastChild_ = children_->Get_(children_->Length_()->op_Minus(p_int(1)));
		Length_ = lastChild_->Start_->op_Minus(Start_)->op_Plus(lastChild_->Length_);
	}
	else
	{
		Start_ = p_int(0);
		Length_ = p_int(0);
	}

	Children_ = children_;
}

auto ::Syntax_Node_::GetText_() const -> p_string
{
	return Source_->Text_->Substring_(Start_, Length_);
}

auto ::Syntax_Node_::FirstChildOfType_(p_int const type_) const -> ::Syntax_Node_ const *
{
	for (::Syntax_Node_ const *const child_ : *(Children_))
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
	for (::Syntax_Node_ const *const child_ : *(Children_))
	{
		if (child_->Type_->op_Equal(type_).Value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

::Token_Stream_::Token_Stream_(::Source_Text_ const *const source_)
{
	Source_ = source_;
	position_ = p_int(0);
}

auto ::Token_Stream_::GetNextToken_() -> ::Syntax_Node_ const *
{
	p_uint end_ = p_int(1)->op_UnaryMinus();
	while (position_->op_LessThan(Source_->Text_->Length_).Value)
	{
		p_code_point const curChar_ = Source_->Text_->op_Element(position_);
		if (LogicalOr(LogicalOr(LogicalOr(curChar_->op_Equal(p_code_point(' ')), [&] { return curChar_->op_Equal(p_code_point('\t')); }), [&] { return curChar_->op_Equal(p_code_point('\n')); }), [&] { return curChar_->op_Equal(p_code_point('\r')); }).Value)
		{
			position_->op_PlusAssign(p_int(1));
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
		else if (curChar_->op_Equal(p_code_point('=')).Value)
		{
			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(Equal_, p_int(2));
			}

			return NewOperator_(Assign_);
		}
		else if (curChar_->op_Equal(p_code_point('+')).Value)
		{
			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(AddAssign_, p_int(2));
			}

			return NewOperator_(Add_);
		}
		else if (curChar_->op_Equal(p_code_point('-')).Value)
		{
			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('>')); }).Value)
			{
				return NewOperator_(Arrow_, p_int(2));
			}

			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(SubAssign_, p_int(2));
			}

			return NewOperator_(Sub_);
		}
		else if (curChar_->op_Equal(p_code_point('/')).Value)
		{
			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('/')); }).Value)
			{
				while (LogicalAnd(LogicalAnd(position_->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_)->op_NotEqual(p_code_point('\r')); }), [&] { return Source_->Text_->op_Element(position_)->op_NotEqual(p_code_point('\n')); }).Value)
				{
					position_->op_PlusAssign(p_int(1));
				}

				continue;
			}

			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('*')); }).Value)
			{
				position_->op_PlusAssign(p_int(2));
				p_bool lastCharStar_ = p_bool(false);
				while (LogicalAnd(position_->op_LessThan(Source_->Text_->Length_), [&] { return (LogicalAnd(lastCharStar_, [&] { return Source_->Text_->op_Element(position_)->op_Equal(p_code_point('/')); }))->op_Not(); }).Value)
				{
					lastCharStar_ = Source_->Text_->op_Element(position_)->op_Equal(p_code_point('*'));
					position_->op_PlusAssign(p_int(1));
				}

				position_->op_PlusAssign(p_int(1));
				continue;
			}

			return NewOperator_(Slash_);
		}
		else if (curChar_->op_Equal(p_code_point('<')).Value)
		{
			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('>')); }).Value)
			{
				return NewOperator_(NotEqual_, p_int(2));
			}

			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(LessThanOrEqual_, p_int(2));
			}

			return NewOperator_(LessThan_);
		}
		else if (curChar_->op_Equal(p_code_point('>')).Value)
		{
			if (LogicalAnd(position_->op_Plus(p_int(1))->op_LessThan(Source_->Text_->Length_), [&] { return Source_->Text_->op_Element(position_->op_Plus(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(GreaterThanOrEqual_, p_int(2));
			}

			return NewOperator_(GreaterThan_);
		}
		else if (curChar_->op_Equal(p_code_point('"')).Value)
		{
			end_ = position_->op_Plus(p_int(1));
			p_bool escaped_ = p_bool(false);
			while (LogicalAnd(end_->op_LessThan(Source_->Text_->Length_), [&] { return (LogicalOr(Source_->Text_->op_Element(end_)->op_NotEqual(p_code_point('"')), [&] { return escaped_; })); }).Value)
			{
				escaped_ = LogicalAnd(Source_->Text_->op_Element(end_)->op_Equal(p_code_point('\\')), [&] { return escaped_->op_Not(); });
				end_->op_PlusAssign(p_int(1));
			}

			end_->op_PlusAssign(p_int(1));
			return NewToken_(StringLiteral_, end_);
		}
		else if (curChar_->op_Equal(p_code_point('\'')).Value)
		{
			end_ = position_->op_Plus(p_int(1));
			p_bool escaped_ = p_bool(false);
			while (LogicalAnd(end_->op_LessThan(Source_->Text_->Length_), [&] { return (LogicalOr(Source_->Text_->op_Element(end_)->op_NotEqual(p_code_point('\'')), [&] { return escaped_; })); }).Value)
			{
				escaped_ = LogicalAnd(Source_->Text_->op_Element(end_)->op_Equal(p_code_point('\\')), [&] { return escaped_->op_Not(); });
				end_->op_PlusAssign(p_int(1));
			}

			end_->op_PlusAssign(p_int(1));
			return NewToken_(CodePointLiteral_, end_);
		}
		else
		{
			if (IsIdentifierChar_(curChar_).Value)
			{
				end_ = position_->op_Plus(p_int(1));
				while (IsIdentifierChar_(Source_->Text_->op_Element(end_)).Value)
				{
					end_->op_PlusAssign(p_int(1));
				}

				return NewIdentifierOrKeyword_(end_);
			}

			if ((IsNumberChar_(curChar_)).Value)
			{
				end_ = position_->op_Plus(p_int(1));
				while (IsNumberChar_(Source_->Text_->op_Element(end_)).Value)
				{
					end_->op_PlusAssign(p_int(1));
				}

				return NewToken_(Number_, end_);
			}

			return NewToken_(Error_, position_->op_Plus(p_int(1)));
		}
	}

	return ::None;
}

auto ::Token_Stream_::NewIdentifierOrKeyword_(p_uint const end_) -> ::Syntax_Node_ const *
{
	p_uint const length_ = end_->op_Minus(position_);
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
		type_ = NullKeyword_;
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
	else
	{
		type_ = Identifier_;
	}

	return NewToken_(type_, end_);
}

auto ::Token_Stream_::NewOperator_(p_int const type_) -> ::Syntax_Node_ const *
{
	return NewToken_(type_, position_->op_Plus(p_int(1)));
}

auto ::Token_Stream_::NewOperator_(p_int const type_, p_uint const length_) -> ::Syntax_Node_ const *
{
	return NewToken_(type_, position_->op_Plus(length_));
}

auto ::Token_Stream_::NewToken_(p_int const type_, p_uint const end_) -> ::Syntax_Node_ const *
{
	::Syntax_Node_ const *const token_ = new ::Syntax_Node_(type_, Source_, position_, end_->op_Minus(position_));
	position_ = end_;
	return token_;
}

auto ::Token_Stream_::IsIdentifierChar_(p_code_point const c_) -> p_bool
{
	return LogicalOr(LogicalOr((LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('a')), [&] { return c_->op_LessThanOrEqual(p_code_point('z')); })), [&] { return (LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('A')), [&] { return c_->op_LessThanOrEqual(p_code_point('Z')); })); }), [&] { return c_->op_Equal(p_code_point('_')); });
}

auto ::Token_Stream_::IsNumberChar_(p_code_point const c_) -> p_bool
{
	return LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('0')), [&] { return c_->op_LessThanOrEqual(p_code_point('9')); });
}

auto IsValueType_(::Syntax_Node_ const *const type_) -> p_bool
{
	if (type_->Type_->op_Equal(PredefinedType_).Value)
	{
		return p_bool(true);
	}

	if (type_->Type_->op_Equal(NullableType_).Value)
	{
		return IsValueType_(type_->Children_->Get_(p_int(0)));
	}

	if (type_->Type_->op_Equal(QualifiedName_).Value)
	{
		return IsValueType_(type_->Children_->Get_(type_->Children_->Length_()->op_Minus(p_int(1))));
	}

	if (type_->Type_->op_Equal(GenericName_).Value)
	{
		p_code_point const firstChar_ = type_->FirstChildOfType_(IdentifierName_)->FirstChildOfType_(Identifier_)->GetText_()->op_Element(p_int(0));
		return LogicalAnd(firstChar_->op_GreaterThanOrEqual(p_code_point('a')), [&] { return firstChar_->op_LessThanOrEqual(p_code_point('z')); });
	}

	if (type_->Type_->op_Equal(IdentifierName_).Value)
	{
		p_code_point const firstChar_ = type_->FirstChildOfType_(Identifier_)->GetText_()->op_Element(p_int(0));
		return LogicalAnd(firstChar_->op_GreaterThanOrEqual(p_code_point('a')), [&] { return firstChar_->op_LessThanOrEqual(p_code_point('z')); });
	}

	if (type_->Type_->op_Equal(MutableType_).Value)
	{
		return IsValueType_(type_->Children_->Get_(p_int(1)));
	}

	return p_bool(true);
}

auto ConvertType_(::Syntax_Node_ const *const type_) -> p_string
{
	if (type_->Type_->op_Equal(PredefinedType_).Value)
	{
		::Syntax_Node_ const *const keyword_ = type_->Children_->Get_(p_int(0));
		if (keyword_->Type_->op_Equal(Void_).Value)
		{
			return keyword_->GetText_();
		}

		return p_string("p_")->op_Plus(keyword_->GetText_());
	}

	if (type_->Type_->op_Equal(IdentifierName_).Value)
	{
		return p_string("::")->op_Plus(type_->GetText_())->op_Plus(p_string("_"));
	}

	if (type_->Type_->op_Equal(QualifiedName_).Value)
	{
		return ConvertType_(type_->Children_->Get_(p_int(0)))->op_Plus(ConvertType_(type_->Children_->Get_(p_int(2))));
	}

	if (type_->Type_->op_Equal(GenericName_).Value)
	{
		return ConvertType_(type_->Children_->Get_(p_int(0)))->op_Plus(p_string("<"))->op_Plus(ConvertType_(p_bool(true), type_->Children_->Get_(p_int(2))))->op_Plus(p_string(">"));
	}

	return FormatError_(p_string("Unexpected Token of type ")->op_Plus(type_->Type_)->op_Plus(p_string(" found in CovertType(), `"))->op_Plus(type_->GetText_())->op_Plus(p_string("`")));
}

auto ConvertType_(p_bool const mutableBinding_, ::Syntax_Node_ const * type_) -> p_string
{
	p_bool const nullable_ = type_->Type_->op_Equal(NullableType_);
	if (nullable_.Value)
	{
		type_ = type_->Children_->Get_(p_int(0));
	}

	p_bool const mutableValue_ = type_->Type_->op_Equal(MutableType_);
	if (mutableValue_.Value)
	{
		type_ = type_->Children_->Get_(p_int(1));
	}

	p_bool const isValueType_ = IsValueType_(type_);
	p_string cppType_ = ConvertType_(type_);
	if (isValueType_.Value)
	{
		if (nullable_.Value)
		{
			cppType_ = p_string("::Maybe<")->op_Plus(cppType_)->op_Plus(p_string(">"));
		}

		if (LogicalAnd(mutableBinding_->op_Not(), [&] { return mutableValue_->op_Not(); }).Value)
		{
			cppType_ = cppType_->op_Plus(p_string(" const"));
		}
	}
	else
	{
		if (mutableValue_->op_Not().Value)
		{
			cppType_ = cppType_->op_Plus(p_string(" const"));
		}

		cppType_ = cppType_->op_Plus(p_string(" *"));
		if (mutableBinding_->op_Not().Value)
		{
			cppType_ = cppType_->op_Plus(p_string("const"));
		}
	}

	return cppType_;
}

auto ConvertParameterList_(::Syntax_Node_ const *const parameterList_, p_bool const isMainFunction_) -> p_string
{
	::System_::Text_::String_Builder_ *const builder_ = new ::System_::Text_::String_Builder_();
	builder_->Append_(p_string("("));
	p_bool firstParameter_ = p_bool(true);
	for (::Syntax_Node_ const *const parameter_ : *(parameterList_->Children_))
	{
		if (parameter_->Type_->op_Equal(Parameter_).Value)
		{
			if (firstParameter_->op_Not().Value)
			{
				builder_->Append_(p_string(", "));
			}
			else
			{
				firstParameter_ = p_bool(false);
			}

			p_bool const mutableBinding_ = parameter_->HasChildOfType_(VarKeyword_);
			::Syntax_Node_ const *const type_ = parameter_->Children_->Get_(parameter_->Children_->Length_()->op_Minus(p_int(1)));
			builder_->Append_(ConvertType_(mutableBinding_, type_));
			builder_->Append_(p_string(" "));
			builder_->Append_(parameter_->FirstChildOfType_(Identifier_)->GetText_());
			builder_->Append_(p_string("_"));
			if (isMainFunction_.Value)
			{
				p_string typeString_;
				if (type_->Type_->op_Equal(MutableType_).Value)
				{
					typeString_ = type_->Children_->Get_(p_int(1))->GetText_();
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
	}

	builder_->Append_(p_string(")"));
	return builder_->ToString_();
}

auto ConvertParameterList_(::Syntax_Node_ const *const parameterList_) -> p_string
{
	return ConvertParameterList_(parameterList_, p_bool(false));
}

auto ConvertExpression_(::Syntax_Node_ const *const syntax_, ::Source_File_Builder_ *const builder_) -> void
{
	if (syntax_->Type_->op_Equal(NewExpression_).Value)
	{
		::Syntax_Node_ const *const type_ = syntax_->Children_->Get_(p_int(1));
		if (IsValueType_(type_)->op_Not().Value)
		{
			builder_->Write_(p_string("new "));
		}

		builder_->Write_(ConvertType_(type_));
		::Syntax_Node_ const *const argumentList_ = syntax_->Children_->Get_(p_int(2));
		ConvertExpression_(argumentList_, builder_);
	}
	else if (syntax_->Type_->op_Equal(ArgumentList_).Value)
	{
		builder_->Write_(p_string("("));
		p_bool firstExpression_ = p_bool(true);
		for (::Syntax_Node_ const *const arg_ : *(syntax_->Children_))
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
		ConvertExpression_(syntax_->Children_->Get_(p_int(1)), builder_);
		builder_->Write_(p_string("->op_Not()"));
	}
	else if (syntax_->Type_->op_Equal(ParenthesizedExpression_).Value)
	{
		builder_->Write_(p_string("("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(1)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(UnaryMinusExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->Get_(p_int(1)), builder_);
		builder_->Write_(p_string("->op_UnaryMinus()"));
	}
	else if (syntax_->Type_->op_Equal(NullLiteralExpression_).Value)
	{
		builder_->Write_(p_string("::None"));
	}
	else if (syntax_->Type_->op_Equal(SelfExpression_).Value)
	{
		builder_->Write_(p_string("this"));
	}
	else if (syntax_->Type_->op_Equal(NumericLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_int(")->op_Plus(syntax_->GetText_())->op_Plus(p_string(")")));
	}
	else if (LogicalOr(syntax_->Type_->op_Equal(TrueLiteralExpression_), [&] { return syntax_->Type_->op_Equal(FalseLiteralExpression_); }).Value)
	{
		builder_->Write_(p_string("p_bool(")->op_Plus(syntax_->GetText_())->op_Plus(p_string(")")));
	}
	else if (syntax_->Type_->op_Equal(CodePointLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_code_point(")->op_Plus(syntax_->GetText_())->op_Plus(p_string(")")));
	}
	else if (syntax_->Type_->op_Equal(IdentifierName_).Value)
	{
		builder_->Write_(syntax_->GetText_()->op_Plus(p_string("_")));
	}
	else if (syntax_->Type_->op_Equal(StringLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_string(")->op_Plus(syntax_->GetText_())->op_Plus(p_string(")")));
	}
	else if (syntax_->Type_->op_Equal(AssignmentExpression_).Value)
	{
		p_int const operator_ = syntax_->Children_->Get_(p_int(1))->Type_;
		if (operator_->op_Equal(Assign_).Value)
		{
			ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
			builder_->Write_(p_string(" "));
			builder_->Write_(syntax_->Children_->Get_(p_int(1))->GetText_());
			builder_->Write_(p_string(" "));
			ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		}
		else
		{
			ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
			builder_->Write_(p_string("->op_"));
			if (operator_->op_Equal(AddAssign_).Value)
			{
				builder_->Write_(p_string("PlusAssign"));
			}
			else if (operator_->op_Equal(SubAssign_).Value)
			{
				builder_->Write_(p_string("MinusAssign"));
			}
			else
			{
				builder_->Error_(p_string("Unsupported assignment operator ")->op_Plus(operator_));
			}

			builder_->Write_(p_string("("));
			ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
			builder_->Write_(p_string(")"));
		}
	}
	else if (syntax_->Type_->op_Equal(EqualExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Equal("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(NotEqualExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string("->op_NotEqual("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(ComparisionExpression_).Value)
	{
		p_int const operator_ = syntax_->Children_->Get_(p_int(1))->Type_;
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string("->op_"));
		if (operator_->op_Equal(LessThan_).Value)
		{
			builder_->Write_(p_string("LessThan"));
		}
		else if (operator_->op_Equal(LessThanOrEqual_).Value)
		{
			builder_->Write_(p_string("LessThanOrEqual"));
		}
		else if (operator_->op_Equal(GreaterThan_).Value)
		{
			builder_->Write_(p_string("GreaterThan"));
		}
		else if (operator_->op_Equal(GreaterThanOrEqual_).Value)
		{
			builder_->Write_(p_string("GreaterThanOrEqual"));
		}
		else
		{
			builder_->Error_(p_string("Unsupported comparision operator ")->op_Plus(operator_));
		}

		builder_->Write_(p_string("("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(AddExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Plus("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(SubtractExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Minus("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->Type_->op_Equal(OrExpression_).Value)
	{
		builder_->Write_(p_string("LogicalOr("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string(", [&] { return "));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		builder_->Write_(p_string("; })"));
	}
	else if (syntax_->Type_->op_Equal(AndExpression_).Value)
	{
		builder_->Write_(p_string("LogicalAnd("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string(", [&] { return "));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		builder_->Write_(p_string("; })"));
	}
	else if (syntax_->Type_->op_Equal(InvocationExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		ConvertExpression_(syntax_->Children_->Get_(p_int(1)), builder_);
	}
	else if (syntax_->Type_->op_Equal(MemberAccessExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string("->"));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
	}
	else if (syntax_->Type_->op_Equal(ElementAccessExpression_).Value)
	{
		ConvertExpression_(syntax_->Children_->Get_(p_int(0)), builder_);
		builder_->Write_(p_string("->op_Element("));
		ConvertExpression_(syntax_->Children_->Get_(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else
	{
		builder_->Error_(p_string("Could not convert expression of type ")->op_Plus(syntax_->Type_));
	}
}

auto EmitStatement_(::Syntax_Node_ const *const statement_) -> void
{
	Definitions_->StatementSeparatorLine_();
	if (statement_->Type_->op_Equal(ReturnStatement_).Value)
	{
		if (statement_->Children_->Length_()->op_Equal(p_int(2)).Value)
		{
			Definitions_->WriteLine_(p_string("return;"));
		}
		else
		{
			Definitions_->BeginLine_(p_string("return "));
			ConvertExpression_(statement_->Children_->Get_(p_int(1)), Definitions_);
			Definitions_->EndLine_(p_string(";"));
		}
	}
	else if (statement_->Type_->op_Equal(LoopStatement_).Value)
	{
		Definitions_->WriteLine_(p_string("for (;;)"));
		EmitStatement_(statement_->Children_->Get_(p_int(1)));
	}
	else if (statement_->Type_->op_Equal(Block_).Value)
	{
		Definitions_->BeginBlock_();
		for (::Syntax_Node_ const *const blockStatement_ : *(statement_->Children_))
		{
			if (LogicalAnd(blockStatement_->Type_->op_NotEqual(LeftBrace_), [&] { return blockStatement_->Type_->op_NotEqual(RightBrace_); }).Value)
			{
				EmitStatement_(blockStatement_);
			}
		}

		Definitions_->EndBlock_();
	}
	else if (statement_->Type_->op_Equal(WhileStatement_).Value)
	{
		Definitions_->BeginLine_(p_string("while ("));
		ConvertExpression_(statement_->Children_->Get_(p_int(1)), Definitions_);
		Definitions_->EndLine_(p_string(".Value)"));
		EmitStatement_(statement_->Children_->Get_(p_int(2)));
	}
	else if (statement_->Type_->op_Equal(ForStatement_).Value)
	{
		Definitions_->BeginLine_(p_string("for ("));
		::Syntax_Node_ const *const variableDeclaration_ = statement_->Children_->Get_(p_int(1));
		p_bool const mutableBinding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		p_string const name_ = variableDeclaration_->FirstChildOfType_(Identifier_)->GetText_();
		::Syntax_Node_ const *const type_ = variableDeclaration_->Children_->Get_(p_int(3));
		Definitions_->Write_(ConvertType_(mutableBinding_, type_)->op_Plus(p_string(" "))->op_Plus(name_)->op_Plus(p_string("_")));
		Definitions_->Write_(p_string(" : *("));
		ConvertExpression_(statement_->Children_->Get_(p_int(3)), Definitions_);
		Definitions_->EndLine_(p_string("))"));
		EmitStatement_(statement_->Children_->Get_(p_int(4)));
	}
	else if (statement_->Type_->op_Equal(DoWhileStatement_).Value)
	{
		Definitions_->WriteLine_(p_string("do"));
		EmitStatement_(statement_->Children_->Get_(p_int(1)));
		Definitions_->BeginLine_(p_string("while ("));
		ConvertExpression_(statement_->Children_->Get_(p_int(3)), Definitions_);
		Definitions_->EndLine_(p_string(".Value);"));
	}
	else if (statement_->Type_->op_Equal(IfStatement_).Value)
	{
		::Syntax_Node_ const * ifStatement_ = statement_;
		Definitions_->BeginLine_(p_string(""));
		for (;;)
		{
			Definitions_->Write_(p_string("if ("));
			ConvertExpression_(ifStatement_->Children_->Get_(p_int(1)), Definitions_);
			Definitions_->EndLine_(p_string(".Value)"));
			EmitStatement_(ifStatement_->Children_->Get_(p_int(2)));
			::Syntax_Node_ const *const elseClause_ = ifStatement_->FirstChildOfType_(ElseClause_);
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
					EmitStatement_(elseClause_->Children_->Get_(p_int(1)));
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
		::Syntax_Node_ const *const variableDeclaration_ = statement_->Children_->Get_(p_int(0));
		p_string const variableName_ = variableDeclaration_->FirstChildOfType_(Identifier_)->GetText_();
		::Syntax_Node_ const *const variableType_ = variableDeclaration_->Children_->Get_(p_int(3));
		p_bool const mutableBinding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		Definitions_->BeginLine_(ConvertType_(mutableBinding_, variableType_));
		Definitions_->Write_(p_string(" ")->op_Plus(variableName_)->op_Plus(p_string("_")));
		if (variableDeclaration_->HasChildOfType_(Assign_).Value)
		{
			Definitions_->Write_(p_string(" = "));
			ConvertExpression_(variableDeclaration_->Children_->Get_(p_int(5)), Definitions_);
		}

		Definitions_->EndLine_(p_string(";"));
	}
	else if (statement_->Type_->op_Equal(ExpressionStatement_).Value)
	{
		Definitions_->BeginLine_(p_string(""));
		ConvertExpression_(statement_->Children_->Get_(p_int(0)), Definitions_);
		Definitions_->EndLine_(p_string(";"));
	}
	else
	{
		Definitions_->Error_(p_string("Could not emit statement of type ")->op_Plus(statement_->Type_));
	}
}

auto EmitClassMember_(::Syntax_Node_ const *const member_, p_string const className_) -> void
{
	if (member_->Type_->op_Equal(ConstructorDeclaration_).Value)
	{
		p_string const parameters_ = ConvertParameterList_(member_->Children_->Get_(p_int(2)));
		ClassDeclarations_->WriteLine_(className_->op_Plus(p_string("_"))->op_Plus(parameters_)->op_Plus(p_string(";")));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(p_string("::")->op_Plus(className_)->op_Plus(p_string("_::"))->op_Plus(className_)->op_Plus(p_string("_"))->op_Plus(parameters_)->op_Plus(p_string("")));
		EmitStatement_(member_->Children_->Get_(p_int(3)));
	}
	else if (member_->Type_->op_Equal(FieldDeclaration_).Value)
	{
		::Syntax_Node_ const *const variableDeclaration_ = member_->Children_->Get_(p_int(1));
		p_string const fieldName_ = variableDeclaration_->Children_->Get_(p_int(1))->GetText_();
		::Syntax_Node_ const *const fieldType_ = variableDeclaration_->Children_->Get_(p_int(3));
		p_string const cppType_ = ConvertType_(p_bool(true), fieldType_);
		ClassDeclarations_->WriteLine_(cppType_->op_Plus(p_string(" "))->op_Plus(fieldName_)->op_Plus(p_string("_;")));
	}
	else if (member_->Type_->op_Equal(MethodDeclaration_).Value)
	{
		p_string const methodName_ = member_->Children_->Get_(p_int(1))->GetText_();
		::Syntax_Node_ const *const parameterList_ = member_->Children_->Get_(p_int(2));
		p_string const parameters_ = ConvertParameterList_(parameterList_);
		::Syntax_Node_ const *const selfParameter_ = parameterList_->FirstChildOfType_(SelfParameter_);
		p_bool const isAssociatedFuntion_ = selfParameter_->op_Equal(::None);
		p_bool const mutableSelf_ = LogicalAnd(isAssociatedFuntion_->op_Not(), [&] { return selfParameter_->HasChildOfType_(MutableKeyword_); });
		::Syntax_Node_ const *const returnType_ = member_->Children_->Get_(p_int(4));
		p_string const cppType_ = ConvertType_(p_bool(true), returnType_);
		p_string staticModifier_ = p_string("");
		if (isAssociatedFuntion_.Value)
		{
			staticModifier_ = p_string("static ");
		}

		p_string constModifier_ = p_string("");
		if (LogicalAnd(mutableSelf_->op_Not(), [&] { return isAssociatedFuntion_->op_Not(); }).Value)
		{
			constModifier_ = p_string("const ");
		}

		ClassDeclarations_->WriteLine_(staticModifier_->op_Plus(p_string("auto "))->op_Plus(methodName_)->op_Plus(p_string("_"))->op_Plus(parameters_)->op_Plus(p_string(" "))->op_Plus(constModifier_)->op_Plus(p_string("-> "))->op_Plus(cppType_)->op_Plus(p_string(";")));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(p_string("auto ::")->op_Plus(className_)->op_Plus(p_string("_::"))->op_Plus(methodName_)->op_Plus(p_string("_"))->op_Plus(parameters_)->op_Plus(p_string(" "))->op_Plus(constModifier_)->op_Plus(p_string("-> "))->op_Plus(cppType_));
		::Syntax_Node_ const *const block_ = member_->Children_->Get_(p_int(5));
		EmitStatement_(block_);
	}
	else
	{
		Definitions_->Error_(p_string("Could not emit member of type ")->op_Plus(member_->Type_));
	}
}

auto EmitDeclaration_(::Syntax_Node_ const *const declaration_) -> void
{
	if (declaration_->Type_->op_Equal(GlobalDeclaration_).Value)
	{
		::Syntax_Node_ const *const variableDeclaration_ = declaration_->Children_->Get_(p_int(1));
		p_string const variableName_ = variableDeclaration_->Children_->Get_(p_int(1))->GetText_();
		::Syntax_Node_ const *const variableType_ = variableDeclaration_->Children_->Get_(p_int(3));
		p_bool const mutableBinding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		p_string const cppType_ = ConvertType_(mutableBinding_, variableType_);
		GlobalDefinitions_->BeginLine_(cppType_);
		GlobalDefinitions_->Write_(p_string(" ")->op_Plus(variableName_)->op_Plus(p_string("_ = ")));
		::Syntax_Node_ const *const expression_ = variableDeclaration_->Children_->Get_(p_int(5));
		ConvertExpression_(expression_, GlobalDefinitions_);
		GlobalDefinitions_->EndLine_(p_string(";"));
	}
	else if (declaration_->Type_->op_Equal(ClassDeclaration_).Value)
	{
		p_string const className_ = declaration_->Children_->Get_(p_int(2))->GetText_();
		TypeDeclarations_->WriteLine_(p_string("class ")->op_Plus(className_)->op_Plus(p_string("_;")));
		ClassDeclarations_->ElementSeparatorLine_();
		ClassDeclarations_->WriteLine_(p_string("class ")->op_Plus(className_)->op_Plus(p_string("_")));
		ClassDeclarations_->BeginBlock_();
		ClassDeclarations_->EndLine_(p_string("public:"));
		ClassDeclarations_->WriteLine_(p_string("p_bool op_Equal(")->op_Plus(className_)->op_Plus(p_string("_ const * other) const { return this == other; }")));
		ClassDeclarations_->WriteLine_(p_string("p_bool op_NotEqual(")->op_Plus(className_)->op_Plus(p_string("_ const * other) const { return this != other; }")));
		for (::Syntax_Node_ const *const member_ : *(declaration_->Children_))
		{
			if (LogicalOr(LogicalOr(member_->Type_->op_Equal(ConstructorDeclaration_), [&] { return member_->Type_->op_Equal(FieldDeclaration_); }), [&] { return member_->Type_->op_Equal(MethodDeclaration_); }).Value)
			{
				EmitClassMember_(member_, className_);
			}
		}

		ClassDeclarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->Type_->op_Equal(EnumDeclaration_).Value)
	{
		p_string const enumName_ = declaration_->Children_->Get_(p_int(3))->GetText_();
		TypeDeclarations_->WriteLine_(p_string("enum class ")->op_Plus(enumName_)->op_Plus(p_string("_;")));
		ClassDeclarations_->ElementSeparatorLine_();
		ClassDeclarations_->WriteLine_(p_string("enum class ")->op_Plus(enumName_)->op_Plus(p_string("_")));
		ClassDeclarations_->BeginBlock_();
		for (::Syntax_Node_ const *const member_ : *(declaration_->Children_))
		{
			if (member_->Type_->op_Equal(EnumMemberDeclaration_).Value)
			{
				p_string const memberName_ = member_->Children_->Get_(p_int(0))->GetText_();
				ClassDeclarations_->BeginLine_(memberName_->op_Plus(p_string("_")));
				::Syntax_Node_ const *const memberValue_ = member_->FirstChildOfType_(Number_);
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
		p_string const name_ = declaration_->Children_->Get_(p_int(1))->GetText_();
		p_bool const isMain_ = name_->op_Equal(p_string("Main"));
		p_string const parameters_ = ConvertParameterList_(declaration_->Children_->Get_(p_int(2)), isMain_);
		::Syntax_Node_ const *const returnType_ = declaration_->Children_->Get_(p_int(4));
		p_string const cppType_ = ConvertType_(p_bool(true), returnType_);
		FunctionDeclarations_->WriteLine_(p_string("auto ")->op_Plus(name_)->op_Plus(p_string("_"))->op_Plus(parameters_)->op_Plus(p_string(" -> "))->op_Plus(cppType_)->op_Plus(p_string(";")));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(p_string("auto ")->op_Plus(name_)->op_Plus(p_string("_"))->op_Plus(parameters_)->op_Plus(p_string(" -> "))->op_Plus(cppType_));
		if (isMain_.Value)
		{
			if (MainFunctionReturnType_->op_NotEqual(p_string("")).Value)
			{
				Definitions_->Error_(p_string("Multiple declarations of main"));
			}

			MainFunctionReturnType_ = cppType_;
		}

		EmitStatement_(declaration_->Children_->Get_(p_int(5)));
	}
	else
	{
		Definitions_->Error_(p_string("Could not emit declaration of type ")->op_Plus(declaration_->Type_));
	}
}

auto EmitCompilationUnit_(::Syntax_Node_ const *const unit_) -> void
{
	for (::Syntax_Node_ const *const declaration_ : *(unit_->Children_))
	{
		EmitDeclaration_(declaration_);
	}
}

auto EmitPackage_(::Syntax_Node_ const *const package_) -> void
{
	for (::Syntax_Node_ const *const compilationUnit_ : *(package_->Children_))
	{
		EmitCompilationUnit_(compilationUnit_);
	}
}

auto EmitPreamble_() -> void
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

auto EmitEntryPointAdapter_(::System_::Collections_::List_<::Source_Text_ const *> const *const resources_) -> void
{
	Definitions_->ElementSeparatorLine_();
	Definitions_->WriteLine_(p_string("// Entry Point Adapter"));
	Definitions_->WriteLine_(p_string("std::int32_t main(int argc, char const *const * argv)"));
	Definitions_->BeginBlock_();
	for (::Source_Text_ const *const resource_ : *(resources_))
	{
		Definitions_->BeginLine_(p_string("resource_manager_->AddResource(p_string(\""));
		Definitions_->Write_(resource_->Name_);
		Definitions_->Write_(p_string("\"), p_string(\""));
		Definitions_->Write_(resource_->Text_->Replace_(p_string("\\"), p_string("\\\\"))->Replace_(p_string("\n"), p_string("\\n"))->Replace_(p_string("\r"), p_string("\\r"))->Replace_(p_string("\""), p_string("\\\"")));
		Definitions_->EndLine_(p_string("\"));"));
	}

	if (resources_->Length_()->op_GreaterThan(p_int(0)).Value)
	{
		Definitions_->EndLine_(p_string(""));
	}

	::System_::Text_::String_Builder_ *const args_ = new ::System_::Text_::String_Builder_();
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
		Definitions_->WriteLine_(p_string("Main_(")->op_Plus(args_->ToString_())->op_Plus(p_string(");")));
		Definitions_->WriteLine_(p_string("return 0;"));
	}
	else
	{
		Definitions_->WriteLine_(p_string("return Main_(")->op_Plus(args_->ToString_())->op_Plus(p_string(").Value;")));
	}

	Definitions_->EndBlock_();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	resource_manager_->AddResource(p_string("RuntimeLibrary.cpp"), p_string("#include \"RuntimeLibrary.h\"\n#include <map>\n\np_uint p_int::AsUInt_() const\n{\n	if(this->Value < 0)\n		throw \"Can't convert negative number to unsigned\";\n\n	return this->Value;\n}\n\nchar p_code_point::CharValue() const\n{\n	if(this->Value > 0xFF)\n		throw \"Unicode char values not yet supported\";\n\n	return this->Value;\n}\n\np_string::p_string()\n	: Length_(0), Buffer(0)\n{\n}\n\np_string::p_string(p_code_point c, p_int repeat)\n	: Length_(repeat)\n{\n	char* buffer = new char[repeat.Value];\n	for (int i = 0; i < repeat.Value; i++)\n		buffer[i] = c.CharValue();\n\n	Buffer = buffer;\n}\n\np_string::p_string(const char* s)\n	: Length_(std::strlen(s)), Buffer(s)\n{\n}\n\np_string::p_string(int length, const char* s)\n	: Length_(length), Buffer(s)\n{\n}\n\nchar const * p_string::cstr() const\n{\n	auto buffer = new char[Length_.Value + 1];\n	std::memcpy(buffer, Buffer, Length_.Value);\n	buffer[Length_.Value] = 0;\n	return buffer;\n}\n\np_string::p_string(p_int other)\n	: Length_(0), Buffer(0)\n{\n	char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator\n	std::sprintf(buffer,\"%d\", other.Value);\n	Length_ = std::strlen(buffer);\n	Buffer = buffer;\n}\n\np_string p_string::Substring_(p_int start, p_int length) const\n{\n	return p_string(length.Value, Buffer + start.Value);\n}\n\np_string p_string::Replace_(p_string oldValue, p_string newValue) const\n{\n	p_string buffer = \"\";\n	int limit = Length_.Value - oldValue.Length_.Value + 1;\n	int lastIndex = 0;\n	for(int i=0; i < limit; i++)\n		if (Substring_(i, oldValue.Length_).op_Equal(oldValue).Value)\n		{\n			buffer = buffer.op_Plus(Substring_(lastIndex, i-lastIndex)).op_Plus(newValue);\n			i += oldValue.Length_.Value; // skip over the value we just matched\n			lastIndex = i;\n			i--; // we need i-- to offset the i++ that is about to happen\n		}\n\n	buffer = buffer.op_Plus(Substring_(lastIndex, Length_.Value - lastIndex));\n	return buffer;\n}\n\np_int p_string::LastIndexOf_(p_code_point c) const\n{\n	for(int i = Length_.Value - 1; i >= 0; i--)\n		if(Buffer[i] == c.CharValue())\n			return i;\n\n	return -1;\n}\n\np_string p_string::op_Plus(p_string const & value) const\n{\n	int newLength = Length_.Value + value.Length_.Value;\n	char* chars = new char[newLength];\n	size_t offset = sizeof(char) * Length_.Value;\n	std::memcpy(chars, Buffer, offset);\n	std::memcpy(chars + offset, value.Buffer, value.Length_.Value);\n	return p_string(newLength, chars);\n}\n\np_bool p_string::op_Equal(p_string const & other) const\n{\n	if (Length_.Value != other.Length_.Value)\n		return false;\n\n	for (int i = 0; i < Length_.Value; i++)\n		if (Buffer[i] != other.Buffer[i])\n			return false;\n\n	return true;\n}\n\nbool operator < (p_string const & lhs, p_string const & rhs)\n{\n    return std::strcmp(lhs.cstr(), rhs.cstr()) < 0;\n}\n\nstd::map<p_string, p_string> resourceValues;\n\np_string const & ResourceManager::GetString_(p_string resourceName)\n{\n	return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(p_string name, p_string value)\n{\n	resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager_ = new ResourceManager();\n\nnamespace System_\n{\n	namespace Console_\n	{\n		void Console_::Write_(p_string value)\n		{\n			std::printf(\"%.*s\", value.Length_.Value, value.Buffer);\n		}\n\n		void Console_::WriteLine_(p_string value)\n		{\n			std::printf(\"%.*s\\n\", value.Length_.Value, value.Buffer);\n		}\n\n		void Console_::WriteLine_()\n		{\n			std::printf(\"\\n\");\n		}\n\n		Arguments_::Arguments_(int argc, char const *const * argv)\n			: Count_(argc-1)\n		{\n			args = new p_string[Count_];\n			for (int i = 0; i < Count_; i++)\n				args[i] = p_string(argv[i+1]);\n		}\n	}\n\n	namespace IO_\n	{\n		File_Reader_::File_Reader_(const p_string& fileName)\n		{\n			std::FILE* foo;\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"rb\");\n			delete[] fname;\n		}\n\n		p_string File_Reader_::ReadToEndSync_()\n		{\n			std::fseek(file, 0, SEEK_END);\n			auto length = std::ftell(file);\n			std::fseek(file, 0, SEEK_SET);\n			auto buffer = new char[length];\n			length = std::fread(buffer, sizeof(char), length, file);\n			return p_string(length, buffer);\n		}\n\n		void File_Reader_::Close_()\n		{\n			std::fclose(file);\n		}\n\n		File_Writer_::File_Writer_(const p_string& fileName)\n		{\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"wb\"); // TODO check error\n			delete[] fname;\n		}\n\n		void File_Writer_::Write_(const p_string& value)\n		{\n			std::fwrite(value.Buffer, sizeof(char), value.Length_.Value, file);\n		}\n\n		void File_Writer_::Close_()\n		{\n			std::fclose(file);\n		}\n	}\n\n	namespace Text_\n	{\n		String_Builder_::String_Builder_(p_string const & value)\n			: buffer(value)\n		{\n		}\n\n		String_Builder_::String_Builder_()\n			: buffer(\"\")\n		{\n		}\n\n		void String_Builder_::Append_(p_string const & value)\n		{\n			buffer = buffer.op_Plus(value);\n		}\n\n		void String_Builder_::Append_(String_Builder_ const * value)\n		{\n			buffer = buffer.op_Plus(value->buffer);\n		}\n\n		void String_Builder_::AppendLine_(p_string const & value)\n		{\n			buffer = buffer.op_Plus(value).op_Plus(p_string(\"\\n\"));\n		}\n\n		void String_Builder_::AppendLine_()\n		{\n			buffer = buffer.op_Plus(p_string(\"\\n\"));\n		}\n\n		void String_Builder_::Remove_(p_int start, p_int length)\n		{\n			buffer = buffer.Substring_(0, start).op_Plus(buffer.Substring_(start.Value+length.Value));\n		}\n\n		void String_Builder_::Remove_(p_int start)\n		{\n			String_Builder_::Remove_(start, buffer.Length_.Value-start.Value);\n		}\n	}\n}\n"));
	resource_manager_->AddResource(p_string("RuntimeLibrary.h"), p_string("// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n#include <cstring>\n#include <cstdio>\n#include <cstdint>\n\ntemplate<typename T, typename F>\nT LogicalAnd(T const & lhs, F rhs)\n{\n	return lhs.op_False().Value ? lhs : lhs.op_And(rhs());\n}\n\ntemplate<typename T, typename F>\nT LogicalOr(T const & lhs, F rhs)\n{\n	return lhs.op_True().Value ? lhs : lhs.op_Or(rhs());\n}\n\n\nstruct p_bool\n{\npublic:\n	// Runtime Use Members\n	bool Value;\n\n	p_bool(): Value(false) {}\n	p_bool(bool value): Value(value) {}\n	p_bool * operator->() { return this; }\n	p_bool const * operator->() const { return this; }\n	p_bool & operator* () { return *this; }\n	p_bool const & operator* () const { return *this; }\n\n	// Adamant Members\n	p_bool op_Not() const { return !this->Value; }\n	p_bool op_True() const { return this->Value; }\n	p_bool op_False() const { return !this->Value; }\n	p_bool op_And(p_bool other) const { return this->Value & other.Value; }\n	p_bool op_Or(p_bool other) const { return this->Value | other.Value; }\n};\n\nstruct p_uint;\n\nstruct p_int\n{\npublic:\n	// Runtime Use Members\n	std::int32_t Value;\n\n	p_int(std::int32_t value): Value(value) {}\n	p_int * operator->() { return this; }\n	p_int const * operator->() const { return this; }\n	p_int & operator* () { return *this; }\n	p_int const & operator* () const { return *this; }\n\n	// Hack to support conversion of uint to int for now\n	p_int(p_uint value);\n\n	// Adamant Members\n	p_int(): Value(0) {}\n	void op_PlusAssign(p_int other) { this->Value += other.Value; }\n	void op_MinusAssign(p_int other) { this->Value -= other.Value; }\n	p_bool op_Equal(p_int other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_int other) const { return this->Value != other.Value; }\n	p_bool op_LessThan(p_int other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_int other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_int other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_int other) const { return this->Value >= other.Value; }\n	p_int op_Plus(p_int other) const { return this->Value + other.Value; }\n	p_int op_Minus(p_int other) const { return this->Value - other.Value; }\n	p_int op_UnaryMinus() const { return -this->Value; }\n\n	// Hack because we don't support as correctly yet\n	p_uint AsUInt_() const;\n};\n\nstruct p_uint\n{\npublic:\n	// Runtime Use Members\n	std::uint32_t Value;\n\n	p_uint(std::uint32_t value): Value(value) {}\n	p_uint * operator->() { return this; }\n	p_uint const * operator->() const { return this; }\n	p_uint & operator* () { return *this; }\n	p_uint const & operator* () const { return *this; }\n\n	// Hack to support conversion of int to uint for now\n	p_uint(p_int value): Value(value.Value) {}\n\n	// Adamant Members\n	p_uint(): Value(0) {}\n	void op_PlusAssign(p_uint other) { this->Value += other.Value; }\n	void op_MinusAssign(p_uint other) { this->Value -= other.Value; }\n	p_bool op_Equal(p_uint other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_uint other) const { return this->Value != other.Value; }\n	p_bool op_LessThan(p_uint other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_uint other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_uint other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_uint other) const { return this->Value >= other.Value; }\n	p_uint op_Plus(p_uint other) const { return this->Value + other.Value; }\n	p_uint op_Minus(p_uint other) const { return this->Value - other.Value; }\n};\n\ninline p_int::p_int(p_uint value)\n	: Value(value.Value)\n{\n}\n\nstruct p_code_point\n{\nprivate:\n	std::int32_t Value;\n\npublic:\n	// Runtime Use Members\n	p_code_point(): Value(0) {}\n	p_code_point(char value): Value(value) {}\n	p_code_point * operator->() { return this; }\n	p_code_point const * operator->() const { return this; }\n	p_code_point & operator* () { return *this; }\n	p_code_point const & operator* () const { return *this; }\n	char CharValue() const;\n\n	// Adamant Members\n	p_bool op_Equal(p_code_point const & other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_code_point const & other) const { return this->Value != other.Value; }\n	// TODO: Not sure code_point should support these operations\n	p_bool op_LessThan(p_code_point other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_code_point other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_code_point other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_code_point other) const { return this->Value >= other.Value; }\n\n};\n\nstruct p_string\n{\npublic:\n	// Runtime Use Members\n	char const * Buffer;\n\n	p_string();\n	p_string(char const * s);\n	p_string(int length, char const * s);\n	char const * cstr() const;\n	p_string const * operator->() const { return this; }\n	p_string const & operator* () const { return *this; }\n\n	typedef char const * const_iterator;\n	const_iterator begin() const { return &Buffer[0]; }\n	const_iterator end() const { return &Buffer[Length_.Value]; }\n\n	// Hack to support conversion of integers to strings for now\n	p_string(p_int other);\n\n	// Adamant Members\n	p_int Length_;\n\n	p_string(p_code_point c, p_int repeat);\n\n	p_string Substring_(p_int start, p_int length) const;\n	p_string Substring_(p_int start) const { return Substring_(start, Length_.Value-start.Value); }\n	p_string Replace_(p_string oldValue, p_string newValue) const;\n	p_int LastIndexOf_(p_code_point c) const;\n\n	p_code_point op_Element(p_int const index) const { return Buffer[index.Value]; }\n	p_string op_Plus(p_string const & value) const;\n	p_bool op_Equal(p_string const & other) const;\n	p_bool op_NotEqual(p_string const & other) const { return !this->op_Equal(other).Value; }\n	p_bool op_LessThan(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) < 0; }\n	p_bool op_LessThanOrEqual(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) <= 0; }\n	p_bool op_GreaterThan(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) > 0; }\n	p_bool op_GreaterThanOrEqual(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) >= 0; }\n};\n\nclass ResourceManager\n{\npublic:\n	p_string const & GetString_(p_string resourceName);\n	void AddResource(p_string name, p_string value);\n};\n\nextern ResourceManager *const resource_manager_;\n\nclass NoneType\n{\npublic:\n	template<class T>\n	operator T*() const { return static_cast<T*>(0); }\n};\nstatic const NoneType None = NoneType();\n\ntemplate<typename T>\nstruct Maybe\n{\nprivate:\n	T data;\n	bool hasValue;\n\npublic:\n	Maybe(T const & value) : data(value), hasValue(true) {}\n	Maybe(::NoneType const & none) : hasValue(false) {}\n	T& operator->() { return data; }\n	T const & operator->() const\n	{\n		if(!hasValue) throw \"Access to null Maybe value\";\n		return data;\n	}\n	T  & operator* ()\n	{\n		if(!hasValue) throw \"Access to null Maybe value\";\n		return data;\n	}\n	T const & operator* () const\n	{\n		if(!hasValue) throw \"Access to null Maybe value\";\n		return data;\n	}\n	bool operator==(T const & other) const\n	{\n		return hasValue && data == other;\n	}\n	bool operator!=(T const & other) const\n	{\n		return hasValue && data != other;\n	}\n};\n\nnamespace System_\n{\n	namespace Collections_\n	{\n		template<typename T>\n		class List_\n		{\n		private:\n			T* values;\n			int length;\n			int capacity;\n\n		public:\n			// Runtime Use Members\n			typedef T const * const_iterator;\n			const_iterator begin() const { return values; }\n			const_iterator end() const { return &values[length]; }\n\n			// Adamant Members\n			List_() : values(0), length(0), capacity(0) { }\n			void Add_(T value);\n			p_int Length_() const { return length; }\n			T const & Get_(p_int const index) const { return values[index.Value]; }\n		};\n\n		template<typename T>\n		void List_<T>::Add_(T value)\n		{\n			if(length >= capacity)\n			{\n				int newCapacity = capacity == 0 ? 16 : capacity * 2;\n				T* newValues = new T[newCapacity];\n				std::memcpy(newValues, values, length * sizeof(T));\n				values = newValues;\n				capacity = newCapacity;\n			}\n			values[length] = value;\n			length++;\n		}\n	}\n\n	namespace Console_\n	{\n		class Console_\n		{\n		public:\n			void Write_(p_string value);\n			void WriteLine_(p_string value);\n			void WriteLine_();\n		};\n\n		class Arguments_\n		{\n		private:\n			p_string* args;\n		public:\n			typedef p_string const * const_iterator;\n			const int Count_;\n\n			Arguments_(int argc, char const *const * argv);\n			const_iterator begin() const { return &args[0]; }\n			const_iterator end() const { return &args[Count_]; }\n			p_string const & Get_(int const index) const { return args[index]; }\n		};\n	}\n\n	namespace IO_\n	{\n		class File_Reader_\n		{\n		private:\n			std::FILE* file;\n\n		public:\n			File_Reader_(const p_string& fileName);\n			p_string ReadToEndSync_();\n			void Close_();\n		};\n\n		class File_Writer_\n		{\n		private:\n			std::FILE* file;\n\n		public:\n			File_Writer_(const p_string& fileName);\n			void Write_(const p_string& value);\n			void Close_();\n		};\n	}\n\n	namespace Text_\n	{\n		class String_Builder_\n		{\n		private:\n			p_string buffer;\n		public:\n			String_Builder_();\n			String_Builder_(p_string const & value);\n			void Append_(p_string const & value);\n			void Append_(String_Builder_ const * value);\n			void AppendLine_(p_string const& value);\n			void AppendLine_();\n			void Remove_(p_int start, p_int length);\n			void Remove_(p_int start);\n			p_string ToString_() const { return buffer; }\n		};\n	}\n}\n"));

	Main_(new ::System_::Console_::Console_(), new ::System_::Console_::Arguments_(argc, argv));
	return 0;
}
