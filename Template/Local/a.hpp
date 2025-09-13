// c:/Users/user/Documents/Programming/Contest/Template/Local/a.hpp

#pragma once
#include "a_Macro.hpp"

inline void AlertAbort( int n );
void AutoCheck( const bool& use_getline , const bool& sample_check , const string& problem_order );
void Solve();
void SampleCheck( const string& sample_path , const string& input_path , const string& output_path , const string& problem_order , const int& test_case_num_bound , ifstream& ifs , ofstream& ofs );
inline void Experiment();
inline void SmallTest();
inline void RandomTest( const int& test_case_num );
inline void BreakPoint( const int& LINE ) {}

#ifdef USE_GETLINE
  CEXPR( bool , use_getline , true );
#else
  CEXPR( bool , use_getline , false );
#endif

#ifdef SUBMIT_ONLY
  CEXPR( bool , submit_only , true );
#else
  CEXPR( bool , submit_only , false );
#endif

ifstream ifs{};
ofstream ofs{};
const string sample_path = "C:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/Sample/";

int exec_mode;
#include "Mode/a.hpp"

#include "../../../Mathematics/Utility/Set/a.hpp"
#include "../../../Mathematics/Utility/Tuple/a.hpp"
#include "../../../Mathematics/Utility/Vector/a.hpp"
#include "../../../Mathematics/Utility/Set/Map/a.hpp"
#include "../../../Utility/StdStream/__float128/a.hpp"
#include "../../../Utility/StdStream/a.hpp"
#include "../../../Utility/String/a.hpp"
#include "../../../Utility/String/Encode/a.hpp"

#include "../../../Mathematics/Utility/BinarySearch/Debug/a.hpp"
#include "../../../Mathematics/Utility/TwoPointerApproach/Debug/a.hpp"
#include "../../../Mathematics/Algebra/Monoid/Group/Module/a.hpp"
#include "../../../Mathematics/Geometry/Graph/Grid/a.hpp"
#include "../../../Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a.hpp"
#include "../../../Mathematics/Combinatorial/Loop/a.hpp"
#include "../../../Mathematics/Arithmetic/Iteration/a.hpp"
#include "../../../Mathematics/Arithmetic/Sqrt/a.hpp"

CEXPR( uint , P , 998244353 );
using MP = Mod<P>;

#ifdef SAMPLE_CHECK
  static_assert( TO_CHAR( SAMPLE_CHECK )[0] != 'd'  );
  constexpr bool sample_check = true;
  const string problem_order = TO_STRING( SAMPLE_CHECK );
  const string input_path = sample_path + problem_order + "/input/sample";
  const string output_path = sample_path + problem_order + "/output/exec";
  ofstream ofs_err{ "C:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/cerr.txt" , ios::trunc };
#else
  constexpr bool sample_check = false;
  const string problem_order = "dummy";
  const string input_path = "dummy.txt";
  const string output_path = "dummy.txt";
#endif

inline bool HasBr();
bool HasBr( const string& s );
template <typename Arg0 , typename Arg1 , typename...Args> inline bool HasBr( const Arg0& arg0 , const Arg1& arg1 , const Args&... args );
bool searched_br = true;
