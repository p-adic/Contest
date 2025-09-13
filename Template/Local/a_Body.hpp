// c:/Users/user/Documents/Programming/Contest/Template/Local/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Mode/a_Body.hpp"
#include "../../AutoCheck/a_Body.hpp"

#include "../../../Mathematics/Utility/Set/a_Body.hpp"
#include "../../../Mathematics/Utility/Tuple/a_Body.hpp"
#include "../../../Mathematics/Utility/Vector/a_Body.hpp"
#include "../../../Mathematics/Utility/Set/Map/a_Body.hpp"
#include "../../../Utility/StdStream/__float128/a_Body.hpp"
#include "../../../Utility/StdStream/a_Body.hpp"
#include "../../../Utility/String/a_Body.hpp"
#include "../../../Utility/String/Encode/a_Body.hpp"

#include "../../../Mathematics/Utility/BinarySearch/Debug/a_Body.hpp"
#include "../../../Mathematics/Utility/TwoPointerApproach/Debug/a_Body.hpp"
#include "../../../Mathematics/Algebra/Monoid/Group/Module/a_Body.hpp"
#include "../../../Mathematics/Geometry/Graph/Grid/a_Body.hpp"
#include "../../../Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a_Body.hpp"
#include "../../../Mathematics/Combinatorial/Loop/a_Body.hpp"
#include "../../../Mathematics/Arithmetic/Iteration/a_Body.hpp"
#include "../../../Mathematics/Arithmetic/Sqrt/a_Body.hpp"

inline void AlertAbort( int n ) { CERR( "abort関数が呼ばれました。assertマクロのメッセージが出力されていない場合はオーバーフローの有無を確認をしてください。" ); }

inline bool HasBr() { return false; }
bool HasBr( const string& s )
{

  for( auto& c : s ){

    if( c == '\n' ){

      return true;

    }

  }
  
  return false;
  
}

template <typename Arg0 , typename Arg1 , typename...Args> inline bool HasBr( const Arg0& arg0 , const Arg1& arg1 , const Args&... args ) { return HasBr( to_string( arg0 ) ) || HasBr( to_string( arg1 ) ) || HasBr( args... ); }
