#include <micropython-wrap/functionwrapper.h>

//function we want to call from within a MicroPython script
std::vector< std::string > SomeFunction2( std::vector< std::string > vec )
{
  for( auto& v : vec )
    v += "TRANSFORM5"; 
  return vec;
}

//function names are declared in structs
struct FunctionNames
{
  func_name_def( TransformList3 )
};

extern "C"
{
  void RegisterMyModule(void)
  {
    //register a module named 'foo'
    auto mod = upywrap::CreateModule( "foo" );

    //register our function with the name 'TransformList'
    //conversion of a MicroPython list of strings is done automatically
    upywrap::FunctionWrapper wrapfunc( mod );
    wrapfunc.Def< FunctionNames::TransformList3 >( SomeFunction2 );
  }
}

//now call RegisterMyModule() in MicroPython's main() for example
