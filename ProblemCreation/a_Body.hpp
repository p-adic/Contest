// c:/Users/user/Documents/Programming/Contest/ProblemCreation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "ExecuteSolution/a_Body.hpp"
#include "GenerateSamples/a_Body.hpp"
#include "RearrangeSamples/a_Body.hpp"
#include "WriteInSamples/a_Body.hpp"

#include "../../Mathematics/Utility/Set/a_Body.hpp"
#include "../../Mathematics/Utility/Tuple/a_Body.hpp"
#include "../../Mathematics/Utility/Vector/a_Body.hpp"
#include "../../Mathematics/Utility/Set/Map/a_Body.hpp"
#include "../../Utility/StdStream/a_Body.hpp"
#include "../../Utility/String/a_Body.hpp"
#include "../../Utility/String/ToArray/a_Body.hpp"

#include "../../Mathematics/Utility/BinarySearch/a_Body.hpp"
#include "../../Mathematics/Utility/TwoPointerApproach/a_Body.hpp"
#include "../../Mathematics/Algebra/Monoid/Group/Module/a_Body.hpp"
#include "../../Mathematics/Geometry/Graph/Grid/a_Body.hpp"
#include "../../Mathematics/Arithmetic/Mod/ConstexprModulo/a_Body.hpp"
#include "../../Mathematics/Combinatorial/Loop/a_Body.hpp"
#include "../../Mathematics/Arithmetic/IteratedArithmetic/a_Body.hpp"
#include "../../Mathematics/Arithmetic/IteratedArithmetic/Power/a_Body.hpp"

// デバッグ用
inline void AlertAbort( int n ) { CERR( "abort関数が呼ばれました。assertマクロのメッセージが出力されていない場合はオーバーフローの有無を確認をしてください。" ); }
void AutoCheck( int& exec_mode , const bool& use_getline );
inline void Solve();
inline void Experiment();
inline void SmallTest();
inline void RandomTest();
inline void BreakPoint( const int& LINE ) {}

#ifdef USE_GETLINE
  CEXPR( bool , use_getline , true );
#else
  CEXPR( bool , use_getline , false );
#endif
