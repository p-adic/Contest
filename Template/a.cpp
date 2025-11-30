#ifndef INCLUDE_MODE
  #define INCLUDE_MODE
  // #define REACTIVE
  // #define USE_GETLINE
  /* #define SUBMIT_ONLY */
  #define DEBUG_OUTPUT
  #define SAMPLE_CHECK dummy
#endif
#ifdef INCLUDE_MAIN

VO Solve()
{
  // 数 ../Contest/Template/Solve/Number.txt
  // 配列 ../Contest/Template/Solve/Array.txt
  // 順列 ../Contest/Template/Solve/Permutation.txt
  // 文字列 ../Contest/Template/Solve/String.txt
  // グリッド ../Contest/Template/Solve/Grid.txt
  // グラフ ../Contest/Template/Solve/Graph.txt
  // 重み付きグラフ ../Contest/Template/Solve/WeightedGraph.txt
  // 区間クエリ ../Contest/Template/Solve/IntervalQuery.txt
  // 多種クエリ ../Contest/Template/Solve/MultiTypeQuery.txt

}
REPEAT_MAIN(1);

#else /* INCLUDE_MAIN */
#ifdef INCLUDE_SUB

// /* COMPAREに使用。圧縮時は削除する。*/
// using answer_type = ll;
// answer_type Naive( int N , int M , int K , const vector<int>& A , const bool& debug_output = true )
// {
//   answer_type a{};
//   return a;
// }
// 
// answer_type Answer( int N , int M , int K , const vector<int>& A , const bool& debug_output = true )
// {
//   answer_type a{};
//   return a;
// }

/* 圧縮時は中身だけ削除する。*/
IN VO Experiment()
{
  // 1変数 ../Contest/Template/Experiment/OneVariable.txt
  // 2変数 ../Contest/Template/Experiment/TwoVariable.txt
  // 3変数 ../Contest/Template/Experiment/ThreeVariable.txt
  
}

/* 圧縮時は中身だけ削除する。*/
IN VO SmallTest()
{
  // 数 ../Contest/Template/SmallTest/Number.txt
  // 配列 ../Contest/Template/SmallTest/Array.txt
  // 順列 ../Contest/Template/SmallTest/Permutation.txt
  // 文字列 ../Contest/Template/SmallTest/String.txt
  // グリッド ../Contest/Template/SmallTest/Grid.txt
  // グラフ ../Contest/Template/SmallTest/Graph.txt
  // 重み付きグラフ ../Contest/Template/SmallTest/WeightedGraph.txt
  // 区間クエリ ../Contest/Template/SmallTest/IntervalQuery.txt

  CERR( "全てのケースを確認しました。" );
}

/* 圧縮時は中身だけ削除する。*/
IN VO RandomTest( const int& test_case_num )
{
  // 数 ../Contest/Template/RandomTest/Number.txt
  // 配列 ../Contest/Template/RandomTest/Array.txt
  // 順列 ../Contest/Template/RandomTest/Permutation.txt
  // 文字列 ../Contest/Template/RandomTest/String.txt
  // グリッド ../Contest/Template/RandomTest/Grid.txt
  // グラフ ../Contest/Template/RandomTest/Graph.txt
  // 重み付きグラフ ../Contest/Template/RandomTest/WeightedGraph.txt
  // 区間クエリ ../Contest/Template/RandomTest/IntervalQuery.txt
  // 多種クエリ ../Contest/Template/RandomTest/MultiTypeQuery.txt
  REPEAT( test_case_num ){

  }
  CERR( "全てのケースを確認しました。" );
}

#define INCLUDE_MAIN
#include __FILE__
#else /* INCLUDE_SUB */
#ifdef INCLUDE_LIBRARY

/* VVV 常設でないライブラリは以下に挿入する。*/
// AffineSpace ../Contest/Template/Library/AffineSpace.txt
// Arithmetic ../Contest/Template/Library/Arithmetic.txt
// BFS ../Contest/Template/Library/BFS.txt
// BIT ../Contest/Template/Library/BIT.txt
// CoordinateCompress ../Contest/Template/Library/CoordinateCompress.txt
// DFS ../Contest/Template/Library/DFS.txt
// DifferenceSequence ../Contest/Template/Library/DifferenceSequence.txt
// Dijkstra ../Contest/Template/Library/Dijkstra.txt
// Knapsack ../Contest/Template/Library/Knapsack.txt
// Matrix ../Contest/Template/Library/Matrix.txt
// Set ../Contest/Template/Library/Set.txt
// Polynomial ../Contest/Template/Library/Polynomial.txt
// SqrtDecomposition ../Contest/Template/Library/SqrtDecomposition.txt
// UnionFind ../Contest/Template/Library/UnionFind.txt

/* AAA 常設でないライブラリは以上に挿入する。*/

#define INCLUDE_SUB
#include __FILE__
#else /* INCLUDE_LIBRARY */
#ifdef DEBUG
  #define _GLIBCXX_DEBUG
#else
  #pragma GCC optimize ( "O3" )
  #pragma GCC optimize ( "unroll-loops" )
  #pragma GCC target ( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" )
  #define DEXPR( LL , BOUND , VALUE1 , VALUE2 ) CEXPR( LL , BOUND , VALUE1 )
  #define ASSERT( A , MIN , MAX ) AS( ( MIN ) <= A && A <= ( MAX ) )
  #define REPEAT_MAIN( BOUND ) START_MAIN; CEXPR( int , test_case_num_bound , BOUND ); int test_case_num = 1; if CE( test_case_num_bound > 1 ){ FINISH_MAIN
  #ifdef USE_GETLINE
    #define SET_SEPARATE( SEPARATOR , ... ) VariadicGetline( cin , SEPARATOR , __VA_ARGS__ )
    #define SET( ... ) SET_SEPARATE( '\n' , __VA_ARGS__ )
    #define GETLINE_SEPARATE( SEPARATOR , ... ) string __VA_ARGS__; SET_SEPARATE( SEPARATOR , __VA_ARGS__ )
    #define GETLINE( ... ) GETLINE_SEPARATE( '\n' , __VA_ARGS__ )
    #define FINISH_MAIN GETLINE( test_case_num_str ); test_case_num = stoi( test_case_num_str ); ASSERT( test_case_num , 1 , test_case_num_bound ); } REPEAT( test_case_num ){ Solve(); } }
  #else
    #define SET( ... ) VariadicCin( cin , __VA_ARGS__ )
    #define CIN( LL , ... ) LL __VA_ARGS__; SET( __VA_ARGS__ )
    #define SET_A( I , N , ... ) VariadicResize( N + I , __VA_ARGS__ ); FOR( VARIABLE_FOR_SET_A , 0 , N ){ VariadicSet( cin , VARIABLE_FOR_SET_A + I , __VA_ARGS__ ); }
    #define CIN_A( LL , I , N , ... ) VE<LL> __VA_ARGS__; SET_A( I , N , __VA_ARGS__ )
    #define CIN_AA( LL , I0 , N0 , I1 , N1 , VAR ) VE VAR( N0 + I0 , VE<LL>( N1 + I1 ) ); FOR( VARIABLE_FOR_CIN_AA , 0 , N0 ){ SET_A( I1 , N1 , VAR[VARIABLE_FOR_CIN_AA + I0] ); }
    #define FINISH_MAIN SET_ASSERT( test_case_num , 1 , test_case_num_bound ); } REPEAT( test_case_num ){ Solve(); } }
  #endif
  #define SET_ASSERT( A , MIN , MAX ) SET( A ); ASSERT( A , MIN , MAX )
  #define SOLVE_ONLY 
  #define COUT( ... ) VariadicCout( cout , __VA_ARGS__ ) << ENDL
  #define COUTNS( ... ) VariadicCoutNonSep( cout , __VA_ARGS__ )
  #define CERR( ... ) 
  #define CERRNS( ... ) 
  #define COUT_A( I , N , A ) CoutArray( cout , I , N , A ) << ENDL
  #define CERR_A( I , N , A ) 
  #define WHAT( ... ) 
  #define TLE( CONDITION ) if( !( CONDITION ) ){ ll TLE_VAR = 1; while( TLE_VAR != 0 ){ ( TLE_VAR += 2 ) %= int( 1e9 ); } cerr << TLE_VAR << endl; }
  #define MLE( CONDITION ) if( !( CONDITION ) ){ vector<vector<ll>> MLE_VAR{}; REPEAT( 1e6 ){ MLE_VAR.push_back( vector<ll>( 1e6 ) ); } cerr << MLE_VAR << endl; }
  #define OLE( CONDITION ) if( !( CONDITION ) ){ REPEAT( 1e8 ){ cerr << "OLE\n"; } }
#endif
#ifdef REACTIVE
  #ifndef DEBUG
    #define LOCAL( ... ) 
    #define RSET( A , ... ) SET( A )
  #endif
  #define RCIN( LL , A , ... ) LL A; RSET( A , __VA_ARGS__ )
  #define ENDL endl
#else
  #define ENDL "\n"
#endif
#include <bits/stdc++.h>
using namespace std;
#define ATT __attribute__( ( target( "sse4.2,fma,avx2,popcnt,lzcnt,bmi2" ) ) )
#define START_MAIN int main(){ ios_base::sync_with_stdio( false ); cin.tie( nullptr )
#define START_WATCH chrono::system_clock::time_point watch = chrono::system_clock::now(); double loop_average_time = 0.0 , loop_start_time = loop_average_time , current_time = loop_start_time; int loop_count = current_time; assert( loop_count == 0 )
#define CURRENT_TIME ( current_time = static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 ) )
#define CHECK_WATCH( TL_MS ) ( CURRENT_TIME , loop_count == 0 ? loop_start_time = current_time : loop_average_time = ( current_time - loop_start_time ) / loop_count , ++loop_count , current_time < TL_MS - loop_average_time * 2 - 100.0 )
#define CEXPR( LL , BOUND , VALUE ) CE LL BOUND = VALUE
#define SET_A_ASSERT( I , N , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_A , 0 , N ){ SET_ASSERT( A[VARIABLE_FOR_SET_A + I] , MIN , MAX ); }
#define SET_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX ) FOR( VARIABLE_FOR_SET_AA0 , 0 , N0 ){ FOR( VARIABLE_FOR_SET_AA1 , 0 , N1 ){ SET_ASSERT( A[VARIABLE_FOR_SET_AA0 + I0][VARIABLE_FOR_SET_AA1 + I1] , MIN , MAX ); } }
#define CIN_ASSERT( A , MIN , MAX ) decldecay_t( MAX ) A; SET_ASSERT( A , MIN , MAX )
#define CIN_A_ASSERT( I , N , A , MIN , MAX ) vector<decldecay_t( MAX )> A( N + I ); SET_A_ASSERT( I , N , A , MIN , MAX )
#define CIN_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX ) vector A( N0 + I0 , vector<decldecay_t( MAX )>( N1 + I1 ) ); SET_AA_ASSERT( I0 , N0 , I1 , N1 , A , MIN , MAX )
#define PR1( A1 , ... ) A1
#define PR2( A1 , A2 , ... ) A2
#define PR3( A1 , A2 , A3 , ... ) A3
#define FOR_( VAR , INITIAL , FINAL , UPPER , COMP , INCR ) for( decldecay_t( UPPER ) VAR = INITIAL ; VAR COMP FINAL ; VAR INCR )
#define FOR( VAR , INITIAL , ... ) FOR_( VAR , INITIAL , PR1( __VA_ARGS__ ) , PR1( __VA_ARGS__ ) , < , PR3( __VA_ARGS__ , += PR2( __VA_ARGS__ , ? ) , ++ ) )
#define FOREQ( VAR , INITIAL , ... ) FOR_( VAR , INITIAL , PR1( __VA_ARGS__ ) , PR1( __VA_ARGS__ ) , <= , PR3( __VA_ARGS__ , += PR2( __VA_ARGS__ , ? ) , ++ ) )
#define FOREQINV( VAR , INITIAL , ... ) FOR_( VAR , INITIAL , PR1( __VA_ARGS__ ) , INITIAL , + 1 > , PR3( __VA_ARGS__ , -= PR2( __VA_ARGS__ , ? ) , -- ) )
#define ITR( ARRAY ) auto begin_ ## ARRAY = ARRAY .BE() , itr_ ## ARRAY = begin_ ## ARRAY , end_ ## ARRAY = ARRAY .EN()
#define FOR_ITR( ARRAY ) for( ITR( ARRAY ) , itr = itr_ ## ARRAY ; itr_ ## ARRAY != end_ ## ARRAY ; itr_ ## ARRAY ++ , itr++ )
#define RUN( ARRAY , ... ) for( auto&& __VA_ARGS__ : ARRAY )
#define REPEAT( HOW_MANY_TIMES ) FOR( VARIABLE_FOR_REPEAT , 0 , HOW_MANY_TIMES )
#define SET_PRECISION( DECIMAL_DIGITS ) cout << fixed << setprecision( DECIMAL_DIGITS ); cerr << fixed << setprecision( DECIMAL_DIGITS )
#define RETURN( ... ) SOLVE_ONLY; COUT( __VA_ARGS__ ); RE
#define COMPARE( ... ) auto naive = Naive( __VA_ARGS__ , false ); auto answer = Answer( __VA_ARGS__ , false ); bool match = naive == answer; CERR( "(" , #__VA_ARGS__ , ") == (" , __VA_ARGS__ , ") : Naive ==" , naive , match ? "==" : "!=" , answer , "== Answer" ); if( !match ){ CERR( "出力の不一致が検出されました。" ); RE; }
#define CHECK( ... ) auto answer = Answer( __VA_ARGS__ , false ); CERR( "(" , #__VA_ARGS__ , ") == (" , __VA_ARGS__ , ") : Answer == " , answer )

/* 圧縮用 */
#define TE template
#define TY typename
#define US using
#define ST static
#define AS assert
#define IN inline
#define CL class
#define PU public
#define OP operator
#define CE constexpr
#define CO const
#define NE noexcept
#define RE return 
#define WH while
#define VO void
#define VE vector
#define LI list
#define BE begin
#define EN end
#define SZ size
#define LE length
#define PW Power
#define MO move
#define TH this
#define CRI CO int&
#define CRUI CO uint&
#define CRL CO ll&
#define VI virtual 
#define IS basic_istream<char,Traits>
#define OS basic_ostream<char,Traits>
#define ST_AS static_assert
#define reMO_CO remove_const
#define is_COructible_v is_constructible_v
#define rBE rbegin

/* 型のエイリアス */
#define decldecay_t(VAR)decay_t<decltype(VAR)>
TE <TY F,TY...Args> US ret_t = decltype(declval<F>()(declval<Args>()...));
TE <TY T> US inner_t = TY T::type;
US uint = unsigned int;
US ll = long long;
US ull = unsigned long long;
US ld = long double;
US lld = __float128;

/* VVV 常設ライブラリは以下に挿入する。*/
#ifdef DEBUG
  #include "C:/Users/user/Documents/Programming/Contest/Template/Local/a_Body.hpp"
#else
/* BinarySearch (2KB)*/
/* EXPRESSIONがANSWERの広義単調関数の時、EXPRESSION >= CONST_TARGETの整数解を格納。*/
CE bool reactive =
#ifdef REACTIVE
true;
#else
false;
#endif
#define BS(AN,MINIMUM,MAXIMUM,EXPRESSION,DESIRED_INEQUALITY,CO_TARGET,INEQUALITY_FOR_CHECK,UPDATE_U,UPDATE_L,UPDATE_AN)ST_AS(! is_same<decldecay_t(CO_TARGET),uint>::value && ! is_same<decldecay_t(CO_TARGET),ull>::value);ll AN = MINIMUM;{ll AN ## _L = MINIMUM;ll AN ## _R = MAXIMUM;AN = UPDATE_AN;ll EXPRESSION_BS;CO ll CO_TARGET_BS =(CO_TARGET);ll DIFFERENCE_BS;WH(AN ## _L < AN ## _R){DIFFERENCE_BS =(EXPRESSION_BS =(EXPRESSION))- CO_TARGET_BS;if(DIFFERENCE_BS INEQUALITY_FOR_CHECK 0){AN ## _R = UPDATE_U;}else{AN ## _L = UPDATE_L;}AN = UPDATE_AN;}if(AN ## _L > AN ## _R || !(reative ||(EXPRESSION)DESIRED_INEQUALITY CO_TARGET_BS)){AN = MAXIMUM + 1;}}
// 単調増加の時にEXPRESSION >= CO_TARGETの最小解を格納。
#define MIN_GEQ(AN,MINIMUM,MAXIMUM,EXPRESSION,CO_TARGET)BS(AN,MINIMUM,MAXIMUM,EXPRESSION,>=,CO_TARGET,>=,AN,AN + 1,Mid(AN ## _L,AN ## _R))
// 単調増加の時にEXPRESSION <= CO_TARGETの最大解を格納。
#define MAX_LEQ(AN,MINIMUM,MAXIMUM,EXPRESSION,CO_TARGET)BS(AN,MINIMUM,MAXIMUM,EXPRESSION,<=,CO_TARGET,>,AN - 1,AN,Mid(AN ## _L + 1,AN ## _R))
// 単調減少の時にEXPRESSION >= CO_TARGETの最大解を格納。
#define MAX_GEQ(AN,MINIMUM,MAXIMUM,EXPRESSION,CO_TARGET)BS(AN,MINIMUM,MAXIMUM,EXPRESSION,>=,CO_TARGET,<,AN - 1,AN,Mid(AN ## _L + 1,AN ## _R))
// 単調減少の時にEXPRESSION <= CO_TARGETの最小解を格納。
#define MIN_LEQ(AN,MINIMUM,MAXIMUM,EXPRESSION,CO_TARGET)BS(AN,MINIMUM,MAXIMUM,EXPRESSION,<=,CO_TARGET,<=,AN,AN + 1,Mid(AN ## _L,AN ## _R))
TE <TY INT> IN CE INT Mid(CO INT& l,CO INT& r){RE l +((r - l)>> 1);}

/* TwoPoitnterApproach (2KB)*/
// VAR_TPAは尺取り法用の変数名の接頭辞で、実際の変数名ではなく、_Lと_Rと_infoがつく。
// ANSWER ## _temp = {VAR_TPA ## _L,VAR_TPA ## _R,VPA_TPA ## _info}を
// {INIT,INIT,INFO_init}で初期化する。VPA_TPA ## _infoは区間和など。
// ANSWER ## _tempがCONTINUE_CONDITIONを満たす限り、ANSWER ## _tempが
// 条件ON_CONDITIONを満たすか否かを判定し、それがtrueになるか
// VAR_TAR ## _LがVAR_TAR ## _Rに追い付くまでVAR_TPA ## _LとVPA_TPA ## _infoの
// 更新操作UPDATE_Lを繰り返し、その後VAR_TPA ## _RとVPA_TPA ## _infoの
// 更新操作UPDATE_Rを行う。（マクロとコンマの制約上、関数オブジェクトを用いる）
// ON_CONDITIONがtrueとなる極大閉区間とその時点でのinfoをANSWERに格納する。
// 例えば長さNの非負整数値配列Aで極大な正値区間とそこでの総和を取得したい場合
// auto update_L = [&]( int& i_L , auto& i_info ){ i_info -= A[i_L++]; };
// auto update_R = [&]( int& i_R , auto& i_info ){ if( ++i_R < N ){ i_info += A[i_R]; } };
// TPA( interval , i , 0 , i_R < N , update_L( i_L , i_info ) , update_R( i_R , i_info ) , A[i_L] > 0 && A[i_R] > 0 , ll( A[0] ) );
// とすればtuple<int,int,ll>値配列intervalに{左端,右端,総和}の列が格納される。
// VAR_TPA ## _infoもintervalにコピーされるので、setやvectorなどのコピーのコストが
// 大きいデータを用いてon,off判定する時はTPAより前に宣言して使う。
#define TPA(AN,VAR_TPA,INIT,CONTINUE_CONDITION,UPDATE_L,UPDATE_R,ON_CONDITION,INFO_init)VE<tuple<decldecay_t(INIT),decldecay_t(INIT),decldecay_t(INFO_init)>> AN{};{auto init_TPA = INIT;decldecay_t(AN.front())AN ## _temp ={init_TPA,init_TPA,INFO_init};auto AN ## _prev = AN ## _temp;auto& VAR_TPA ## _L = get<0>(AN ## _temp);auto& VAR_TPA ## _R = get<1>(AN ## _temp);auto& VAR_TPA ## _info = get<2>(AN ## _temp);bool on_TPA_prev = false;WH(true){bool continuing = CONTINUE_CONDITION;bool on_TPA = continuing &&(ON_CONDITION);if(on_TPA_prev && ! on_TPA){AN.push_back(AN ## _prev);}if(continuing){if(on_TPA || VAR_TPA ## _L == VAR_TPA ## _R){AN ## _prev = AN ## _temp;UPDATE_R;}else{UPDATE_L;}}else{break;}on_TPA_prev = on_TPA;}}

/* Random (1KB)*/
ll GetRand(CRL Rand_min,CRL Rand_max){AS(Rand_min <= Rand_max);ll AN = time(NULL);RE AN * rand()%(Rand_max + 1 - Rand_min)+ Rand_min;}

/* Set (2KB)*/
#define DC_OF_HASH(...)struct hash<__VA_ARGS__>{IN size_t OP()(CO __VA_ARGS__& n)CO;};
CL is_ordered{PU:is_ordered()= delete;TE <TY T> ST CE auto Check(CO T& t)-> decltype(t < t,true_type());ST CE false_type Check(...);TE <TY T> ST CE CO bool value = is_same_v< decltype(Check(declval<T>())),true_type >;};
TE <TY T>US Set = conditional_t<is_COructible_v<unordered_set<T>>,unordered_set<T>,conditional_t<is_ordered::value<T>,set<T>,VO>>;

#define DF_OF_POP_FOR_SET(SET)TE <TY T> IN T pop_max(SET& S){AS(!S.empty());auto IT = --S.EN();T AN = *IT;S.erase(IT);RE AN;}TE <TY T> IN T pop_min(SET& S){AS(!S.empty());auto IT = S.BE();T AN = *IT;S.erase(IT);RE AN;}TE <TY T> IN SET& OP<<=(SET& S,T t){S.insert(MO(t));RE S;}TE <TY T,TY U> IN SET& OP<<=(SET& S,U&& u){S.insert(T{forward<U>(u)});RE S;}TE <TY T> IN SET& OP>>=(SET& S,CO T& t){auto IT = S.find(t);if(IT != S.EN()){S.erase(IT);}RE S;}TE <TY T,TY U> IN SET& OP>>=(SET& S,CO U& u){RE S >>= T{u};}TE <TY T> IN CO T& Get(CO SET& S,int i){auto BE = S.BE(),EN = S.EN();auto& IT = i < 0?(++i,--EN):BE;WH(i > 0 && IT != EN){--i;++IT;}WH(i < 0 && IT != BE){++i;--IT;}AS(i == 0);RE *IT;}
#define DF_OF_UNION_FOR_SET(SET)TE <TY T> IN SET& OP|=(SET& S0,SET S1){S0.merge(MO(S1));RE S0;}TE <TY T> IN SET OP|(SET S0,SET S1){RE MO(S0.SZ()< S1.SZ()?S1 |= MO(S0):S0 |= MO(S1));}
TE <TY SET,TY T> IN TY SET::const_iterator MaximumLeq(CO SET& S,CO T& t){auto IT = S.upper_bound(t);RE IT == S.BE()?S.EN():--IT;}TE <TY SET,TY T> IN TY SET::const_iterator MaximumLt(CO SET& S,CO T& t){auto IT = S.lower_bound(t);RE IT == S.BE()?S.EN():--IT;}TE <TY SET,TY T> IN TY SET::const_iterator MinimumGeq(CO SET& S,CO T& t){RE S.lower_bound(t);}TE <TY SET,TY T> IN TY SET::const_iterator MinimumGt(CO SET& S,CO T& t){RE S.upper_bound(t);}TE <TY SET,TY ITERATOR> IN VO EraseBack(SET& S,ITERATOR& IT){IT = S.erase(IT);}TE <TY SET,TY ITERATOR> IN VO EraseFront(SET& S,ITERATOR& IT){IT = S.erase(IT);IT == S.BE()?IT = S.EN():--IT;}TE <TE <TY...> TY SET,TY T,TY...Args> IN bool In(CO T& t,CO SET<T,Args...>& S){RE S.count(t)== 1;}DF_OF_POP_FOR_SET(set<T>);DF_OF_POP_FOR_SET(unordered_set<T>);DF_OF_POP_FOR_SET(multiset<T>);DF_OF_POP_FOR_SET(unordered_multiset<T>);DF_OF_UNION_FOR_SET(set<T>);DF_OF_UNION_FOR_SET(unordered_set<T>);DF_OF_UNION_FOR_SET(multiset<T>);DF_OF_UNION_FOR_SET(unordered_multiset<T>);DF_OF_UNION_FOR_SET(VE<T>);DF_OF_UNION_FOR_SET(LI<T>);

/* Tuple (6KB)*/
#define DF_OF_AR_FOR_TUPLE(OPR)TE <TY T,TY U,TE <TY...> TY PAIR> IN auto OP OPR ## =(PAIR<T,U>& t0,CO PAIR<T,U>& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);RE t0;}TE <TY T,TY U,TY V,TE <TY...> TY TUPLE> IN auto OP OPR ## =(TUPLE<T,U,V>& t0,CO TUPLE<T,U,V>& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);get<2>(t0)OPR ## = get<2>(t1);RE t0;}TE <TY T,TY U,TY V,TY W,TE <TY...> TY TUPLE> IN auto OP OPR ## =(TUPLE<T,U,V,W>& t0,CO TUPLE<T,U,V,W>& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = get<0>(t1);get<1>(t0)OPR ## = get<1>(t1);get<2>(t0)OPR ## = get<2>(t1);get<3>(t0)OPR ## = get<3>(t1);RE t0;}TE <TY ARG,TY T,TY U,TE <TY...> TY PAIR> IN auto OP OPR ## =(PAIR<T,U>& t0,CO ARG& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = t1;get<1>(t0)OPR ## = t1;RE t0;}TE <TY ARG,TY T,TY U,TY V,TE <TY...> TY TUPLE> IN auto OP OPR ## =(TUPLE<T,U,V>& t0,CO ARG& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = t1;get<1>(t0)OPR ## = t1;get<2>(t0)OPR ## = t1;RE t0;}TE <TY ARG,TY T,TY U,TY V,TY W,TE <TY...> TY TUPLE> IN auto OP OPR ## =(TUPLE<T,U,V,W>& t0,CO ARG& t1)-> decltype((get<0>(t0),t0))&{get<0>(t0)OPR ## = t1;get<1>(t0)OPR ## = t1;get<2>(t0)OPR ## = t1;get<3>(t0)OPR ## = t1;RE t0;}TE <TE <TY...> TY TUPLE,TY...ARGS,TY ARG> IN auto OP OPR(CO TUPLE<ARGS...>& t0,CO ARG& t1)-> decldecay_t((get<0>(t0),t0)){auto t = t0;RE MO(t OPR ## = t1);}
#define DF_OF_INCREMENT_FOR_TUPLE(INCR)TE <TY T,TY U,TE <TY...> TY PAIR> IN auto OP INCR(PAIR<T,U>& t)-> decltype((get<0>(t),t))&{INCR get<0>(t);INCR get<1>(t);RE t;}TE <TY T,TY U,TY V,TE <TY...> TY TUPLE> IN auto OP INCR(TUPLE<T,U,V>& t)-> decltype((get<0>(t),t))&{INCR get<0>(t);INCR get<1>(t);INCR get<2>(t);RE t;}TE <TY T,TY U,TY V,TY W,TE <TY...> TY TUPLE> IN auto OP INCR(TUPLE<T,U,V,W>& t)-> decltype((get<0>(t),t))&{INCR get<0>(t);INCR get<1>(t);INCR get<2>(t);INCR get<3>(t);RE t;}
TE <CL Traits,TY T> IN IS& OP>>(IS& is,tuple<T>& arg){RE is >> get<0>(arg);}TE <CL Traits,TY T,TY U,TE <TY...> TY V> IN auto OP>>(IS& is,V<T,U>& arg)-> decltype((get<0>(arg),is))&{RE is >> get<0>(arg)>> get<1>(arg);}TE <CL Traits,TY T,TY U,TY V> IN IS& OP>>(IS& is,tuple<T,U,V>& arg){RE is >> get<0>(arg)>> get<1>(arg)>> get<2>(arg);}TE <CL Traits,TY T,TY U,TY V,TY W> IN IS& OP>>(IS& is,tuple<T,U,V,W>& arg){RE is >> get<0>(arg)>> get<1>(arg)>> get<2>(arg)>> get<3>(arg);}TE <CL Traits,TY T> IN OS& OP<<(OS& os,CO tuple<T>& arg){RE os << get<0>(arg);}TE <CL Traits,TY T,TY U,TE <TY...> TY V> IN auto OP<<(OS& os,CO V<T,U>& arg)-> decltype((get<0>(arg),os))&{RE os << get<0>(arg)<< " " << get<1>(arg);}TE <CL Traits,TY T,TY U,TY V> IN OS& OP<<(OS& os,CO tuple<T,U,V>& arg){RE os << get<0>(arg)<< " " << get<1>(arg)<< " " << get<2>(arg);}TE <CL Traits,TY T,TY U,TY V,TY W> IN OS& OP<<(OS& os,CO tuple<T,U,V,W>& arg){RE os << get<0>(arg)<< " " << get<1>(arg)<< " " << get<2>(arg)<< " " << get<3>(arg);}DF_OF_AR_FOR_TUPLE(+);TE <TY T,TY U,TE <TY...> TY V> IN auto OP-(CO V<T,U>& t)-> decldecay_t((get<0>(t),t)){RE{-get<0>(t),-get<1>(t)};}TE <TY T,TY U,TY V> IN tuple<T,U,V> OP-(CO tuple<T,U,V>& t){RE{-get<0>(t),-get<1>(t),-get<2>(t)};}TE <TY T,TY U,TY V,TY W> IN tuple<T,U,V,W> OP-(CO tuple<T,U,V,W>& t){RE{-get<0>(t),-get<1>(t),-get<2>(t),-get<3>(t)};}DF_OF_AR_FOR_TUPLE(-);DF_OF_AR_FOR_TUPLE(*);DF_OF_AR_FOR_TUPLE(/);DF_OF_AR_FOR_TUPLE(%);DF_OF_INCREMENT_FOR_TUPLE(++);DF_OF_INCREMENT_FOR_TUPLE(--);

TE <int n>CL TupleAccessIndex{};TE <TY...Types>CL Tuple:PU tuple<Types...>{PU:IN Tuple(Types&&... args);TE <TY...Args> IN Tuple(Args&&... args);TE <int n> IN auto& OP[](CO TupleAccessIndex<n>& i)NE;TE <int n> IN CO auto& OP[](CO TupleAccessIndex<n>& i)CO NE;};TE <TY...Types>CL tuple_size<Tuple<Types...>>:PU tuple_size<tuple<Types...>>{};TE <size_t n,TY...Types>CL tuple_element<n,Tuple<Types...>>:PU tuple_element<n,tuple<Types...>>{};
TE <TY T,TY U> US Pair = Tuple<T,U>;TE <TY INT> US T2 = Pair<INT,INT>;TE <TY INT> US T3 = Tuple<INT,INT,INT>;TE <TY INT> US T4 = Tuple<INT,INT,INT,INT>;
CE TupleAccessIndex<0> O{};CE TupleAccessIndex<1> I{};CE TupleAccessIndex<2> II{};CE TupleAccessIndex<3> III{};
TE <TY...Types> IN Tuple<Types...>::Tuple(Types&&... args):tuple<Types...>(MO(args)...){}TE <TY...Types> TE <TY...Args> IN Tuple<Types...>::Tuple(Args&&... args):tuple<Types...>(forward<Args>(args)...){}TE <TY...Types> TE <int n> IN auto& Tuple<Types...>::OP[](CO TupleAccessIndex<n>& i)NE{RE get<n>(*TH);}TE <TY...Types> TE <int n> IN CO auto& Tuple<Types...>::OP[](CO TupleAccessIndex<n>& i)CO NE{RE get<n>(*TH);}TE <TY RET,TE <TY...> TY PAIR,TY INT> T2<RET> cast(CO PAIR<INT,INT>& t){RE{get<0>(t),get<1>(t)};}TE <TY RET,TY INT> T3<RET> cast(CO tuple<INT,INT,INT>& t){RE{get<0>(t),get<1>(t),get<2>(t)};}TE <TY RET,TY INT> T4<RET> cast(CO tuple<INT,INT,INT,INT>& t){RE{get<0>(t),get<1>(t),get<2>(t),get<3>(t)};}

#define DF_OF_HASH_FOR_TUPLE(PAIR)TE <TY T,TY U> IN size_t hash<PAIR<T,U>>::OP()(CO PAIR<T,U>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<T> h0;ST CO hash<U> h1;RE(h0(get<0>(n))* seed)^ h1(get<1>(n));}
TE <TY T> DC_OF_HASH(tuple<T>);TE <TY T,TY U> DC_OF_HASH(pair<T,U>);TE <TY T,TY U> DC_OF_HASH(tuple<T,U>);TE <TY T,TY U,TY V> DC_OF_HASH(tuple<T,U,V>);TE <TY T,TY U,TY V,TY W> DC_OF_HASH(tuple<T,U,V,W>);
TE <TY T> IN size_t hash<tuple<T>>::OP()(CO tuple<T>& n)CO{ST CO hash<T> h;RE h(get<0>(n));}DF_OF_HASH_FOR_TUPLE(pair);DF_OF_HASH_FOR_TUPLE(tuple);TE <TY T,TY U,TY V> IN size_t hash<tuple<T,U,V>>::OP()(CO tuple<T,U,V>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<pair<T,U>> h01;ST CO hash<V> h2;RE(h01({get<0>(n),get<1>(n)})* seed)^ h2(get<2>(n));}TE <TY T,TY U,TY V,TY W> IN size_t hash<tuple<T,U,V,W>>::OP()(CO tuple<T,U,V,W>& n)CO{ST CO size_t seed =(GetRand(1e3,1e8)<< 1)| 1;ST CO hash<pair<T,U>> h01;ST CO hash<pair<V,W>> h23;RE(h01({get<0>(n),get<1>(n)})* seed)^ h23({get<2>(n),get<3>(n)});}

/* Vector (3KB)*/
#define DF_OF_COUT_FOR_VE(V)TE <CL Traits,TY Arg> IN OS& OP<<(OS& os,CO V<Arg>& arg){auto BE = arg.BE(),EN = arg.EN();auto IT = BE;WH(IT != EN){(IT == BE?os:os << " ")<< *IT;IT++;}RE os;}
DF_OF_COUT_FOR_VE(VE);DF_OF_COUT_FOR_VE(LI);DF_OF_COUT_FOR_VE(set);DF_OF_COUT_FOR_VE(unordered_set);DF_OF_COUT_FOR_VE(multiset);IN VO VariadicResize(CRI SZ){}TE <TY Arg,TY... ARGS> IN VO VariadicResize(CRI SZ,Arg& arg,ARGS&... args){arg.resize(SZ);VariadicResize(SZ,args...);}

#define DF_OF_AR_FOR_VE(V,OPR)TE <TY T> IN V<T>& OP OPR ## =(V<T>& a0,CO V<T>& a1){AS(a0.SZ()<= a1.SZ());auto IT0 = a0.BE(),EN0 = a0.EN();auto IT1 = a1.BE();WH(IT0 != EN0){*(IT0++)OPR ## = *(IT1++);}RE a0;}TE <TY T> IN V<T>& OP OPR ## =(V<T>& a,CO T& t){for(auto& x:a){x OPR## = t;}RE a;}TE <TY T,TY U> IN V<T> OP OPR(V<T> a,CO U& u){RE MO(a OPR ## = u);}
#define DF_OF_INCREMENT_FOR_VE(V,INCR)TE <TY T> IN V<T>& OP INCR(V<T>& a){for(auto& i:a){INCR i;}RE a;}
#define DF_OF_SHIFT_FOR_VE(V)TE <TY T> IN V<T>& OP<<=(V<T>& a,T t){a.push_back(MO(t));RE a;}TE <TY T,TY U> IN V<T>& OP<<=(V<T>& a,U&& u){RE a <<= T{forward<U>(u)};}TE <TY T> IN T pop(V<T>& a){AS(!a.empty());T AN = MO(a.back());a.pop_back();RE AN;}
#define DF_OF_ARS_FOR_VE(V)DF_OF_AR_FOR_VE(V,+);DF_OF_AR_FOR_VE(V,-);DF_OF_AR_FOR_VE(V,*);DF_OF_AR_FOR_VE(V,/);DF_OF_AR_FOR_VE(V,%);DF_OF_INCREMENT_FOR_VE(V,++);DF_OF_INCREMENT_FOR_VE(V,--);TE <TY T> IN V<T> OP-(V<T> a){RE MO(a *= T(-1));}TE <TY T> IN V<T> OP*(CO T& t,V<T> v){RE MO(v *= t);}DF_OF_SHIFT_FOR_VE(V);
DF_OF_ARS_FOR_VE(VE);DF_OF_ARS_FOR_VE(LI);DF_OF_SHIFT_FOR_VE(basic_string);
TE <TY V> IN auto Get(V& a){RE[&](CRI i = 0)-> CO decldecay_t(a[0])&{RE a[i];};}TE <TY T> IN VE<T> id(CRI SZ){VE<T> AN(SZ);for(int i = 0;i < SZ;i++){AN[i]= i;}RE AN;}TE <TY V> IN VO Sort(V& a,CO bool& reversed = false){US T = decldecay_t(a[0]);if(reversed){ST auto comp =[](CO T& t0,CO T& t1){RE t1 < t0;};sort(a.BE(),a.EN(),comp);}else{sort(a.BE(),a.EN());}}TE <TY V0,TY V1> IN VO Sort(V0& a,V1& b,CO bool& reversed = false){CO int SZ = a.SZ();AS(SZ == int(b.SZ()));VE<pair<decldecay_t(a[0]),decldecay_t(b[0])>> v(SZ);for(int i = 0;i < SZ;i++){v[i]={MO(a[i]),MO(b[i])};}Sort(v,reversed);for(int i = 0;i < SZ;i++){a[i]= MO(v[i].first);b[i]= MO(v[i].second);}}TE <TY V> IN pair<VE<int>,VE<int>> IndexSort(CO V& a,CO bool& reversed = false){CO int SZ = a.SZ();auto index = id<int>(SZ),ord = index;sort(index.BE(),index.EN(),[&](CRI i,CRI j){CO pair ti{a[i],i},tj{a[j],j};RE reversed?tj < ti:ti < tj;});for(int i = 0;i < SZ;i++){ord[index[i]]= i;}RE{MO(index),MO(ord)};}TE <TY V> IN int len(CO V& a){RE a.SZ();}TE <TY V> IN VO Reverse(V& a){CO int SZ = len(a),half = SZ / 2;for(int i = 0;i < half;i++){swap(a[i],a[SZ-1-i]);}};TE <TY V> IN V Reversed(V a){Reverse(a);RE MO(a);}TE <TY RET,TE <TY...> TY V,TY T> IN V<RET> cast(CO V<T>& a){V<RET> AN{};for(auto& x:a){AN <<= a;}}

/* Map (1KB)*/
#define DF_OF_AR_FOR_MAP(MAP,OPR)TE <TY T,TY U> IN MAP<T,U>& OP OPR ## =(MAP<T,U>& a,CO pair<T,U>& v){a[v.first]OPR ## = v.second;RE a;}TE <TY T,TY U> IN MAP<T,U>& OP OPR ## =(MAP<T,U>& a0,CO MAP<T,U>& a1){for(auto&[t,u]:a1){a0[t]OPR ## = u;}RE a0;}TE <TY T,TY U,TY ARG> IN MAP<T,U> OP OPR(MAP<T,U> a,CO ARG& arg){RE MO(a OPR ## = arg);}
#define DF_OF_ARS_FOR_MAP(MAP)DF_OF_AR_FOR_MAP(MAP,+);DF_OF_AR_FOR_MAP(MAP,-);DF_OF_AR_FOR_MAP(MAP,*);DF_OF_AR_FOR_MAP(MAP,/);DF_OF_AR_FOR_MAP(MAP,%);
TE <TY T,TY U>US Map = conditional_t<is_COructible_v<unordered_map<T,int>>,unordered_map<T,U>,conditional_t<is_ordered::value<T>,map<T,U>,VO>>;
DF_OF_ARS_FOR_MAP(map);DF_OF_ARS_FOR_MAP(unordered_map);

/* StdStream (2KB)*/
TE <CL Traits> IN IS& VariadicCin(IS& is){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicCin(IS& is,Arg& arg,ARGS&... args){RE VariadicCin(is >> arg,args...);}TE <CL Traits> IN IS& VariadicSet(IS& is,CRI i){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicSet(IS& is,CRI i,Arg& arg,ARGS&... args){RE VariadicSet(is >> arg[i],i,args...);}TE <CL Traits> IN IS& VariadicGetline(IS& is,CO char& separator){RE is;}TE <CL Traits,TY Arg,TY... ARGS> IN IS& VariadicGetline(IS& is,CO char& separator,Arg& arg,ARGS&... args){RE VariadicGetline(getline(is,arg,separator),separator,args...);}TE <CL Traits,TY Arg> IN OS& VariadicCout(OS& os,Arg&& arg){RE os << forward<Arg>(arg);}TE <CL Traits,TY Arg1,TY Arg2,TY... ARGS> IN OS& VariadicCout(OS& os,Arg1&& arg1,Arg2&& arg2,ARGS&&... args){RE VariadicCout(os << forward<Arg1>(arg1)<< " ",forward<Arg2>(arg2),forward<ARGS>(args)...);}TE <CL Traits,TY Arg> IN OS& VariadicCoutNonSep(OS& os,Arg&& arg){RE os << forward<Arg>(arg);}TE <CL Traits,TY Arg1,TY Arg2,TY... ARGS> IN OS& VariadicCoutNonSep(OS& os,Arg1&& arg1,Arg2&& arg2,ARGS&&... args){RE VariadicCoutNonSep(os << forward<Arg1>(arg1),forward<Arg2>(arg2),forward<ARGS>(args)...);}TE <CL Traits,TY ARRAY> IN OS& CoutArray(OS& os,CRI i_start,CRI i_ulim,ARRAY&& a){for(int i = i_start;i < i_ulim;i++){(i == i_start?os:(os << " "))<< a[i];}RE os;}

/* Module (6KB)*/
#define DC_OF_CPOINT(POINT)IN CO U& POINT()CO NE
#define DC_OF_POINT(POINT)IN U& POINT()NE
#define DF_OF_CPOINT(POINT)TE <TY U> IN CO U& VirtualPointedSet<U>::POINT()CO NE{RE Point();}
#define DF_OF_POINT(POINT)TE <TY U> IN U& VirtualPointedSet<U>::POINT()NE{RE Point();}
TE <TY U>CL UnderlyingSet{PU:US type = U;};TE <TY U>CL VirtualPointedSet:VI PU UnderlyingSet<U>{PU:VI CO U& Point()CO NE = 0;VI U& Point()NE = 0;DC_OF_CPOINT(Unit);DC_OF_CPOINT(Zero);DC_OF_CPOINT(One);DC_OF_CPOINT(Infty);DC_OF_POINT(init);DC_OF_POINT(root);};TE <TY U>CL PointedSet:VI PU VirtualPointedSet<U>{PU:U m_b_U;IN PointedSet(U b_u = U());IN CO U& Point()CO NE;IN U& Point()NE;};TE <TY U>CL VirtualNSet:VI PU UnderlyingSet<U>{PU:VI U Transfer(CO U& u)= 0;IN U Inverse(CO U& u);};TE <TY U,TY F_U>CL AbstractNSet:VI PU VirtualNSet<U>{PU:F_U m_f_U;IN AbstractNSet(F_U f_U);IN AbstractNSet<U,F_U>& OP=(CO AbstractNSet&)NE;IN U Transfer(CO U& u);};TE <TY U>CL VirtualMagma:VI PU UnderlyingSet<U>{PU:VI U Product(U u0,CO U& u1)= 0;IN U Sum(U u0,CO U& u1);};TE <TY U = ll>CL AdditiveMagma:VI PU VirtualMagma<U>{PU:IN U Product(U u0,CO U& u1);};TE <TY U = ll>CL MultiplicativeMagma:VI PU VirtualMagma<U>{PU:IN U Product(U u0,CO U& u1);};TE <TY U,TY M_U>CL AbstractMagma:VI PU VirtualMagma<U>{PU:M_U m_m_U;IN AbstractMagma(M_U m_U);IN AbstractMagma<U,M_U>& OP=(CO AbstractMagma<U,M_U>&)NE;IN U Product(U u0,CO U& u1);};
TE <TY U> IN PointedSet<U>::PointedSet(U b_U):m_b_U(MO(b_U)){}TE <TY U> IN CO U& PointedSet<U>::Point()CO NE{RE m_b_U;}TE <TY U> IN U& PointedSet<U>::Point()NE{RE m_b_U;}DF_OF_CPOINT(Unit);DF_OF_CPOINT(Zero);DF_OF_CPOINT(One);DF_OF_CPOINT(Infty);DF_OF_POINT(init);DF_OF_POINT(root);TE <TY U,TY F_U> IN AbstractNSet<U,F_U>::AbstractNSet(F_U f_U):m_f_U(MO(f_U)){ST_AS(is_invocable_r_v<U,F_U,U>);}TE <TY U,TY F_U> IN AbstractNSet<U,F_U>& AbstractNSet<U,F_U>::operator=(CO AbstractNSet<U,F_U>&)NE{RE *TH;}TE <TY U,TY F_U> IN U AbstractNSet<U,F_U>::Transfer(CO U& u){RE m_f_U(u);}TE <TY U> IN U VirtualNSet<U>::Inverse(CO U& u){RE Transfer(u);}TE <TY U,TY M_U> IN AbstractMagma<U,M_U>::AbstractMagma(M_U m_U):m_m_U(MO(m_U)){ST_AS(is_invocable_r_v<U,M_U,U,U>);}TE <TY U,TY M_U> IN AbstractMagma<U,M_U>& AbstractMagma<U,M_U>::OP=(CO AbstractMagma<U,M_U>&)NE{RE *TH;}TE <TY U> IN U AdditiveMagma<U>::Product(U u0,CO U& u1){RE MO(u0 += u1);}TE <TY U> IN U MultiplicativeMagma<U>::Product(U u0,CO U& u1){RE MO(u0 *= u1);}TE <TY U,TY M_U> IN U AbstractMagma<U,M_U>::Product(U u0,CO U& u1){RE m_m_U(MO(u0),u1);}TE <TY U> IN U VirtualMagma<U>::Sum(U u0,CO U& u1){RE Product(MO(u0),u1);}

TE <TY U>CL VirtualMonoid:VI PU VirtualMagma<U>,VI PU VirtualPointedSet<U>{};TE <TY U = ll>CL AdditiveMonoid:VI PU VirtualMonoid<U>,PU AdditiveMagma<U>,PU PointedSet<U>{};TE <TY U = ll>CL MultiplicativeMonoid:VI PU VirtualMonoid<U>,PU MultiplicativeMagma<U>,PU PointedSet<U>{PU:IN MultiplicativeMonoid(U e_U);};TE <TY U,TY M_U>CL AbstractMonoid:VI PU VirtualMonoid<U>,PU AbstractMagma<U,M_U>,PU PointedSet<U>{PU:IN AbstractMonoid(M_U m_U,U e_U);};
TE <TY U> IN MultiplicativeMonoid<U>::MultiplicativeMonoid(U e_U):PointedSet<U>(MO(e_U)){}TE <TY U,TY M_U> IN AbstractMonoid<U,M_U>::AbstractMonoid(M_U m_U,U e_U):AbstractMagma<U,M_U>(MO(m_U)),PointedSet<U>(MO(e_U)){}

TE <TY U>CL VirtualGroup:VI PU VirtualMonoid<U>,VI PU VirtualPointedSet<U>,VI PU VirtualNSet<U>{};TE <TY U = ll>CL AdditiveGroup:VI PU VirtualGroup<U>,PU AdditiveMonoid<U>{PU:IN U Transfer(CO U& u);};TE <TY U,TY M_U,TY I_U>CL AbstractGroup:VI PU VirtualGroup<U>,PU AbstractMonoid<U,M_U>,PU AbstractNSet<U,I_U>{PU:IN AbstractGroup(M_U m_U,U e_U,I_U i_U);};
TE <TY U,TY M_U,TY I_U> IN AbstractGroup<U,M_U,I_U>::AbstractGroup(M_U m_U,U e_U,I_U i_U):AbstractMonoid<U,M_U>(MO(m_U),MO(e_U)),AbstractNSet<U,I_U>(MO(i_U)){}TE <TY U> IN U AdditiveGroup<U>::Transfer(CO U& u){RE -u;}

TE <TY R,TY U>CL VirtualRSet:VI PU UnderlyingSet<U>{PU:VI U Action(CO R& r,U u)= 0;IN U PW(U u,CO R& r);IN U ScalarProduct(CO R& r,U u);};TE <TY U,TY MAGMA>CL RegularRSet:VI PU VirtualRSet<U,U>,PU MAGMA{PU:IN RegularRSet(MAGMA magma);IN U Action(CO U& r,U u);};TE <TY MAGMA> RegularRSet(MAGMA magma)-> RegularRSet<inner_t<MAGMA>,MAGMA>;TE <TY R,TY U,TY O_U>CL AbstractRSet:VI PU VirtualRSet<R,U>{PU:O_U m_o_U;IN AbstractRSet(CO R& dummy0,CO U& dummy1,O_U o_U);IN AbstractRSet<R,U,O_U>& OP=(CO AbstractRSet<R,U,O_U>&)NE;IN U Action(CO R& r,U u);};TE <TY R,TY U,TY O_U,TY GROUP>CL AbstractModule:PU AbstractRSet<R,U,O_U>,PU GROUP{PU:IN AbstractModule(CO R& dummy,O_U o_U,GROUP M);};TE <TY R,TY O_U,TY GROUP> AbstractModule(CO R& dummy,O_U o_U,GROUP M)-> AbstractModule<R,inner_t<GROUP>,O_U,GROUP>;TE <TY R,TY U>CL Module:VI PU VirtualRSet<R,U>,PU AdditiveGroup<U>{PU:IN U Action(CO R& r,U u);};
TE <TY R,TY MAGMA> IN RegularRSet<R,MAGMA>::RegularRSet(MAGMA magma):MAGMA(MO(magma)){}TE <TY R,TY U,TY O_U> IN AbstractRSet<R,U,O_U>::AbstractRSet(CO R& dummy0,CO U& dummy1,O_U o_U):m_o_U(MO(o_U)){ST_AS(is_invocable_r_v<U,O_U,R,U>);}TE <TY R,TY U,TY O_U,TY GROUP> IN AbstractModule<R,U,O_U,GROUP>::AbstractModule(CO R& dummy,O_U o_U,GROUP M):AbstractRSet<R,U,O_U>(dummy,M.One(),MO(o_U)),GROUP(MO(M)){ST_AS(is_same_v<U,inner_t<GROUP>>);}TE <TY R,TY U,TY O_U> IN AbstractRSet<R,U,O_U>& AbstractRSet<R,U,O_U>::OP=(CO AbstractRSet<R,U,O_U>&)NE{RE *TH;}TE <TY U,TY MAGMA> IN U RegularRSet<U,MAGMA>::Action(CO U& r,U u){RE TH->Product(r,MO(u));}TE <TY R,TY U,TY O_U> IN U AbstractRSet<R,U,O_U>::Action(CO R& r,U u){RE m_o_U(r,MO(u));}TE <TY R,TY U> IN U Module<R,U>::Action(CO R& r,U u){RE MO(u *= r);}TE <TY R,TY U> IN U VirtualRSet<R,U>::PW(U u,CO R& r){RE Action(r,MO(u));}TE <TY R,TY U> IN U VirtualRSet<R,U>::ScalarProduct(CO R& r,U u){RE Action(r,MO(u));}

/* Graph (5KB)*/
TE <TY T,TY R1,TY R2,TY E>CL VirtualGraph:VI PU UnderlyingSet<T>{PU:VI R1 Enumeration(CRI i)= 0;IN R2 Enumeration_inv(CO T& t);TE <TY PATH> IN R2 Enumeration_inv(CO PATH& p);IN VO Reset();VI CRI SZ()CO NE = 0;VI E& edge()NE = 0;VI ret_t<E,T> Edge(CO T& t)= 0;TE <TY PATH> IN ret_t<E,T> Edge(CO PATH& p);ST IN CO T& Vertex(CO T& t)NE;TE <TY PATH> ST IN CO T& Vertex(CO PATH& e)NE;VI R2 Enumeration_inv_Body(CO T& t)= 0;};TE <TY T,TY R1,TY R2,TY E>CL EdgeImplimentation:VI PU VirtualGraph<T,R1,R2,E>{PU:int m_SZ;E m_edge;IN EdgeImplimentation(CRI SZ,E edge);IN CRI SZ()CO NE;IN E& edge()NE;IN ret_t<E,T> Edge(CO T& t);};TE <TY E>CL Graph:PU EdgeImplimentation<int,CRI,CRI,E>{PU:IN Graph(CRI SZ,E edge);IN CRI Enumeration(CRI i);TE <TY F> IN Graph<F> GetGraph(F edge)CO;IN CRI Enumeration_inv_Body(CRI t);};TE <TY T,TY Enum_T,TY Enum_T_inv,TY E>CL EnumerationGraph:PU EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>{PU:Enum_T m_enum_T;Enum_T_inv m_enum_T_inv;IN EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge);IN ret_t<Enum_T,int> Enumeration(CRI i);TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> GetGraph(F edge)CO;IN ret_t<Enum_T_inv,T> Enumeration_inv_Body(CO T& t);};TE <TY Enum_T,TY Enum_T_inv,TY E> EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge)-> EnumerationGraph<decldecay_t(declval<Enum_T>()(0)),Enum_T,Enum_T_inv,E>;TE <TY T,TY E>CL MemorisationGraph:PU EdgeImplimentation<T,T,CRI,E>{PU:int m_LE;VE<T> m_memory;Map<T,int> m_memory_inv;IN MemorisationGraph(CRI SZ,CO T& dummy,E edge);IN T Enumeration(CRI i);IN VO Reset();TE <TY F> IN MemorisationGraph<T,F> GetGraph(F edge)CO;IN CRI Enumeration_inv_Body(CO T& t);};
TE <TY T,TY R1,TY R2,TY E> IN EdgeImplimentation<T,R1,R2,E>::EdgeImplimentation(CRI SZ,E edge):m_SZ(SZ),m_edge(MO(edge)){ST_AS(is_COructible_v<T,R1> && is_COructible_v<int,R2> && is_invocable_v<E,T>);}TE <TY E> IN Graph<E>::Graph(CRI SZ,E edge):EdgeImplimentation<int,CRI,CRI,E>(SZ,MO(edge)){}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN EnumerationGraph<T,Enum_T,Enum_T_inv,E>::EnumerationGraph(CRI SZ,Enum_T enum_T,Enum_T_inv enum_T_inv,E edge):EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>(SZ,MO(edge)),m_enum_T(MO(enum_T)),m_enum_T_inv(MO(enum_T_inv)){}TE <TY T,TY E> IN MemorisationGraph<T,E>::MemorisationGraph(CRI SZ,CO T& dummy,E edge):EdgeImplimentation<T,T,CRI,E>(SZ,MO(edge)),m_LE(),m_memory(),m_memory_inv(){ST_AS(is_invocable_v<E,T>);}TE <TY E> IN CRI Graph<E>::Enumeration(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T,int> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration(CRI i){RE m_enum_T(i);}TE <TY T,TY E> IN T MemorisationGraph<T,E>::Enumeration(CRI i){AS(0 <= i && i < m_LE);RE m_memory[i];}TE <TY T,TY R1,TY R2,TY E> IN R2 VirtualGraph<T,R1,R2,E>::Enumeration_inv(CO T& t){RE Enumeration_inv_Body(t);}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN R2 VirtualGraph<T,R1,R2,E>::Enumeration_inv(CO PATH& p){RE Enumeration_inv_Body(get<0>(p));}TE <TY E> IN CRI Graph<E>::Enumeration_inv_Body(CRI i){RE i;}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> IN ret_t<Enum_T_inv,T> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration_inv_Body(CO T& t){RE m_enum_T_inv(t);}TE <TY T,TY E> IN CRI MemorisationGraph<T,E>::Enumeration_inv_Body(CO T& t){if(m_memory_inv.count(t)== 0){AS(m_LE < TH->SZ());m_memory.push_back(t);RE m_memory_inv[t]= m_LE++;}RE m_memory_inv[t];}TE <TY T,TY R1,TY R2,TY E> VO VirtualGraph<T,R1,R2,E>::Reset(){}TE <TY T,TY E> IN VO MemorisationGraph<T,E>::Reset(){m_LE = 0;m_memory.clear();m_memory_inv.clear();}TE <TY T,TY R1,TY R2,TY E> IN CRI EdgeImplimentation<T,R1,R2,E>::SZ()CO NE{RE m_SZ;}TE <TY T,TY R1,TY R2,TY E> IN E& EdgeImplimentation<T,R1,R2,E>::edge()NE{RE m_edge;}TE <TY T,TY R1,TY R2,TY E> IN ret_t<E,T> EdgeImplimentation<T,R1,R2,E>::Edge(CO T& t){RE m_edge(t);}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN ret_t<E,T> VirtualGraph<T,R1,R2,E>::Edge(CO PATH& p){RE Edge(get<0>(p));}TE <TY E> TE <TY F> IN Graph<F> Graph<E>::GetGraph(F edge)CO{RE Graph<F>(TH->SZ(),MO(edge));}TE <TY T,TY Enum_T,TY Enum_T_inv,TY E> TE <TY F> IN EnumerationGraph<T,Enum_T,Enum_T_inv,F> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::GetGraph(F edge)CO{RE EnumerationGraph<T,Enum_T,Enum_T_inv,F>(TH->SZ(),m_enum_T,m_enum_T_inv,MO(edge));}TE <TY T,TY E> TE <TY F> IN MemorisationGraph<T,F> MemorisationGraph<T,E>::GetGraph(F edge)CO{RE MemorisationGraph<T,F>(TH->SZ(),MO(edge));}TE <TY T,TY R1,TY R2,TY E> IN CO T& VirtualGraph<T,R1,R2,E>::Vertex(CO T& t)NE{RE t;}TE <TY T,TY R1,TY R2,TY E> TE <TY PATH> IN CO T& VirtualGraph<T,R1,R2,E>::Vertex(CO PATH& e)NE{RE Vertex(get<0>(e));}

/* Grid (3KB)*/
#define SET_GRID H_minus = H - 1;W_minus = W - 1;HW = ll(H)* W
#define SET_HW(h,w)H = h;W = w;SET_GRID
#define CIN_HW SET(H,W);SET_GRID
TE <TY E>CL GridGraph:PU EnumerationGraph<T2<int>,T2<int>(&)(CRI),int(&)(CO T2<int>&),E>{PU:IN GridGraph(E e);};int H,W,H_minus,W_minus;ll HW;VE<string> grid;char walkable = '.';CO string direction="URDL";bool grid_edge_i_plus = true;bool grid_edge_j_plus = true;bool grid_edge_i_minus = true;bool grid_edge_j_minus = true;
IN T2<int> EnumHW(CRI v){RE{v / W,v % W};}IN int EnumHW_inv(CO T2<int>& ij){auto&[i,j]= ij;RE i * W + j;}TE <TY E> IN GridGraph<E>::GridGraph(E e):EnumerationGraph<T2<int>,T2<int>(&)(CRI),int(&)(CO T2<int>&),E>(HW,EnumHW,EnumHW_inv,MO(e)){AS(HW >> 31 == 0 && H * W == HW);}VE<T2<int>> EdgeOnGrid(CO T2<int>& v){VE<T2<int>> AN{};auto&[i,j]= v;if(grid[i][j]== walkable){if(grid_edge_i_minus && i > 0 && grid[i-1][j]== walkable){AN.push_back({i-1,j});}if(grid_edge_i_plus && i+1 < H && grid[i+1][j]== walkable){AN.push_back({i+1,j});}if(grid_edge_j_minus && j > 0 && grid[i][j-1]== walkable){AN.push_back({i,j-1});}if(grid_edge_j_plus && j+1 < W && grid[i][j+1]== walkable){AN.push_back({i,j+1});}}RE AN;}VE<Pair<T2<int>,ll>> WEdgeOnGrid(CO T2<int>& v){VE<Pair<T2<int>,ll>> AN{};auto&[i,j]= v;if(grid[i][j]== walkable){if(grid_edge_i_minus && i>0 && grid[i-1][j]== walkable){AN.push_back({{i-1,j},1});}if(grid_edge_i_plus && i+1 < H && grid[i+1][j]== walkable){AN.push_back({{i+1,j},1});}if(grid_edge_j_minus && j>0 && grid[i][j-1]== walkable){AN.push_back({{i,j-1},1});}if(grid_edge_i_plus && j+1 < W && grid[i][j+1]== walkable){AN.push_back({{i,j+1},1});}}RE AN;}IN VO SetWallStringOnGrid(){grid.resize(H);for(int i = 0;i < H;i++){SET(grid[i]);AS(int(grid[i].SZ())== W);}}IN int DirectionNumberOnGrid(CRI i,CRI j,CRI k,CRI h,CO bool& xy_axis = false){RE xy_axis?i < k?1:i > k?3:j < h?0:j > h?2:-1:i < k?2:i > k?0:j < h?1:j > h?3:-1;}IN int DirectionNumberOnGrid(CO T2<int>& v,CO T2<int>& w,CO bool& xy_axis = false){auto&[i,j]= v;auto&[k,h]= w;RE DirectionNumberOnGrid(i,j,k,h);}IN int DirectionNumberOnGrid(CRI v,CRI w,CO bool& xy_axis = false){RE DirectionNumberOnGrid(EnumHW(v),EnumHW(w));}IN int DirectionNumberOnGrid(CO char& c){RE c == 'U'?0:c == 'R'?1:c == 'D'?2:c == 'L'?3:-1;}IN int ReverseDirectionNumberOnGrid(CRI n){AS(0 <= n && n < 4);RE n ^ 2;}IN T2<int> DirectionVEOnGrid(CO char& c,CO bool& xy_axis = false){CO int n = DirectionNumberOnGrid(c);AS(n != -1);RE T2<int>{xy_axis?n == 1?1:n == 3?-1:0:n == 0?-1:n == 2?1:0,xy_axis?n == 0?1:n == 2?-1:0:n == 1?1:n == 3?-1:0};}

/* DynamicModulo (9KB)*/
CEXPR(uint,P,998244353);
// SetModulo( M , M_is_prime = false );
// M_is_primeがtrueの時はinverseの計算がメモ化再帰される。
#define RP Represent
#define DeRP Derepresent

TE <TY INT1,TY INT2> CE INT1 Residue(INT1 n,CO INT2& M)NE{RE MO(n < 0?((((++n)*= -1)%= M)*= -1)+= M - 1:n < M?n:n %= M);}
TE <TY INT> IN INT ModularInverse(CO INT& base,ll c){AS(base > 0);ll a[2]={0,1 % base};INT b[2]={base,INT((c %= base)< 0?c += base:c)};WH(b[1]!= 0){CO INT q = b[0]/ b[1];(a[0]-= q * a[1]% base)< 0?a[0]+= base:a[0];b[0]-= q * b[1];swap(a[0],a[1]);swap(b[0],b[1]);}AS(b[0]== 1 &&(a[0]* c - 1)% base == 0);RE a[0];}

TE <int NUM> CL DMods;TE <int NUM>CL COantsForDMods{PU:COantsForDMods()= delete;ST uint g_M;ST CE CO uint g_memory_bound = 2e6;ST uint g_memory_le;ST uint g_M_minus;ST bool g_M_is_prime;};
TE <int NUM> uint COantsForDMods<NUM>::g_M = P;TE <int NUM> uint COantsForDMods<NUM>::g_memory_le = g_memory_bound;TE <int NUM> uint COantsForDMods<NUM>::g_M_minus = P-1;TE <int NUM> bool COantsForDMods<NUM>::g_M_is_prime = true;

#define SFINAE_FOR_DMOD enable_if_t<is_COructible_v<uint,decay_t<T>>>*
#define DC_OF_CM_FOR_DMOD(OPR)IN bool OP OPR(CO DMods<NUM>& n)CO NE
#define DC_OF_AR_FOR_DMOD(OPR,EX)IN DMods<NUM> OP OPR(DMods<NUM> n)CO EX;
#define DF_OF_CM_FOR_DMOD(OPR)TE <int NUM> IN bool DMods<NUM>::OP OPR(CO DMods<NUM>& n)CO NE{RE m_n OPR n.m_n;}
#define DF_OF_AR_FOR_DMOD(OPR,EX,LEFT,OPR2)TE <int NUM> IN DMods<NUM> DMods<NUM>::OP OPR(DMods<NUM> n)CO EX{RE MO(LEFT OPR2 ## = *TH);}TE <int NUM,TY T,SFINAE_FOR_DMOD = nullptr> IN DMods<NUM> OP OPR(T n0,CO DMods<NUM>& n1)EX{RE MO(DMods<NUM>(MO(n0))OPR ## = n1);}
TE <int NUM>CL DMods{PU:uint m_n;IN DMods()NE;IN DMods(CO DMods<NUM>& n)NE;IN DMods(DMods<NUM>&& n)NE;TE <TY T,SFINAE_FOR_DMOD = nullptr> IN DMods(T n)NE;IN DMods<NUM>& OP=(DMods<NUM> n)NE;IN DMods<NUM>& OP+=(CO DMods<NUM>& n)NE;IN DMods<NUM>& OP-=(CO DMods<NUM>& n)NE;IN DMods<NUM>& OP*=(CO DMods<NUM>& n)NE;IN DMods<NUM>& OP/=(DMods<NUM> n);IN DMods<NUM>& OP^=(ll EX);IN DMods<NUM>& OP<<=(ll n);IN DMods<NUM>& OP>>=(ll n);IN DMods<NUM>& OP++()NE;IN DMods<NUM> OP++(int)NE;IN DMods<NUM>& OP--()NE;IN DMods<NUM> OP--(int)NE;DC_OF_CM_FOR_DMOD(==);DC_OF_CM_FOR_DMOD(!=);DC_OF_CM_FOR_DMOD(<);DC_OF_CM_FOR_DMOD(<=);DC_OF_CM_FOR_DMOD(>);DC_OF_CM_FOR_DMOD(>=);DC_OF_AR_FOR_DMOD(+,NE);DC_OF_AR_FOR_DMOD(-,NE);DC_OF_AR_FOR_DMOD(*,NE);DC_OF_AR_FOR_DMOD(/,);IN DMods<NUM> OP^(ll EX)CO;IN DMods<NUM> OP<<(ll n)CO;IN DMods<NUM> OP>>(ll n)CO;IN DMods<NUM> OP-()CO NE;IN VO swap(DMods<NUM>& n)NE;IN CRUI RP()CO NE;ST IN DMods<NUM> DeRP(uint n)NE;ST IN CO DMods<NUM>& Factorial(CRL n);ST IN CO DMods<NUM>& FactorialInverse(CRL n);ST IN DMods<NUM> Combination(CRL n,CRL i);ST IN CO DMods<NUM>& zero()NE;ST IN CO DMods<NUM>& one()NE;ST IN CRUI GetModulo()NE;ST IN VO SetModulo(CRUI M,CO bool& M_is_prime = false)NE;IN DMods<NUM>& SignInvert()NE;IN DMods<NUM>& Invert();IN DMods<NUM>& PPW(ll EX)NE;IN DMods<NUM>& NNPW(ll EX)NE;ST IN CO DMods<NUM>& Inverse(CRI n);ST IN CO DMods<NUM>& TwoPower(CRI n);ST IN CO DMods<NUM>& TwoPowerInverse(CRI n);US COants = COantsForDMods<NUM>;};
US DMod = DMods<0>;
TE <int NUM> IN DMods<NUM>::DMods()NE:m_n(){}TE <int NUM> IN DMods<NUM>::DMods(CO DMods<NUM>& n)NE:m_n(n.m_n){}TE <int NUM> IN DMods<NUM>::DMods(DMods<NUM>&& n)NE:m_n(MO(n.m_n)){}TE <int NUM> TE <TY T,SFINAE_FOR_DMOD> IN DMods<NUM>::DMods(T n)NE:m_n(Residue(MO(n),COants::g_M)){}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP=(DMods<NUM> n)NE{m_n = MO(n.m_n);RE *TH;}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP+=(CO DMods<NUM>& n)NE{(m_n += n.m_n)< COants::g_M?m_n:m_n -= COants::g_M;RE *TH;}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP-=(CO DMods<NUM>& n)NE{m_n < n.m_n?(m_n += COants::g_M)-= n.m_n:m_n -= n.m_n;RE *TH;}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP*=(CO DMods<NUM>& n)NE{m_n = Residue(MO(ull(m_n)* n.m_n),COants::g_M);RE *TH;}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP/=(DMods<NUM> n){RE OP*=(n.Invert());}TE <int NUM> IN DMods<NUM>& DMods<NUM>::PPW(ll EX)NE{DMods<NUM> pw{*TH};EX--;WH(EX != 0){(EX & 1)== 1?*TH *= pw:*TH;EX >>= 1;pw *= pw;}RE *TH;}TE <int NUM> IN DMods<NUM>& DMods<NUM>::NNPW(ll EX)NE{RE EX == 0?(m_n = 1,*TH):PPW(MO(EX));}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP^=(ll EX){if(EX < 0){m_n = ModularInverse(COants::g_M,MO(m_n));EX *= -1;}RE NNPW(MO(EX));}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP<<=(ll n){RE *TH *=(n < 0 && -n < int(COants::g_memory_le))?TwoPowerInverse(- int(n)):(n >= 0 && n < int(COants::g_memory_le))?TwoPower(int(n)):DMods<NUM>(2)^= MO(n);}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP>>=(ll n){RE *TH <<= MO(n *= -1);}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP++()NE{m_n < COants::g_M_minus?++m_n:m_n = 0;RE *TH;}TE <int NUM> IN DMods<NUM> DMods<NUM>::OP++(int)NE{DMods<NUM> n{*TH};OP++();RE n;}TE <int NUM> IN DMods<NUM>& DMods<NUM>::OP--()NE{m_n == 0?m_n = COants::g_M_minus:--m_n;RE *TH;}TE <int NUM> IN DMods<NUM> DMods<NUM>::OP--(int)NE{DMods<NUM> n{*TH};OP--();RE n;}DF_OF_CM_FOR_DMOD(==);DF_OF_CM_FOR_DMOD(!=);DF_OF_CM_FOR_DMOD(>);DF_OF_CM_FOR_DMOD(>=);DF_OF_CM_FOR_DMOD(<);DF_OF_CM_FOR_DMOD(<=);DF_OF_AR_FOR_DMOD(+,NE,n,+);DF_OF_AR_FOR_DMOD(-,NE,n.SignInvert(),+);DF_OF_AR_FOR_DMOD(*,NE,n,*);DF_OF_AR_FOR_DMOD(/,,n.Invert(),*);TE <int NUM> IN DMods<NUM> DMods<NUM>::OP^(ll EX)CO{RE MO(DMods<NUM>(*TH)^= MO(EX));}TE <int NUM> IN DMods<NUM> DMods<NUM>::OP<<(ll n)CO{RE MO(DMods<NUM>(*TH)<<= MO(n));}TE <int NUM> IN DMods<NUM> DMods<NUM>::OP>>(ll n)CO{RE MO(DMods<NUM>(*TH)>>= MO(n));}TE <int NUM> IN DMods<NUM> DMods<NUM>::OP-()CO NE{RE MO(DMods<NUM>(*TH).SignInvert());}TE <int NUM> IN DMods<NUM>& DMods<NUM>::SignInvert()NE{m_n > 0?m_n = COants::g_M - m_n:m_n;RE *TH;}TE <int NUM> IN DMods<NUM>& DMods<NUM>::Invert(){m_n = COants::g_M_is_prime && m_n < COants::g_memory_le?Inverse(int(m_n)).m_n:ModularInverse(COants::g_M,MO(m_n));RE *TH;}TE <int NUM> IN VO DMods<NUM>::swap(DMods<NUM>& n)NE{std::swap(m_n,n.m_n);}TE <int NUM> IN CO DMods<NUM>& DMods<NUM>::Inverse(CRI n){if(COants::g_M == 1){RE zero();}AS(COants::g_M_is_prime && 0 < n && n < int(COants::g_memory_le));ST VE<DMods<NUM>> memory ={zero(),one()};ST int le_curr = 2;WH(le_curr <= n){memory.push_back(DeRP(COants::g_M - memory[COants::g_M % le_curr].m_n * ull(COants::g_M / le_curr)% COants::g_M));le_curr++;}RE memory[n];}TE <int NUM> IN CO DMods<NUM>& DMods<NUM>::TwoPower(CRI n){if(COants::g_M == 1){RE zero();}AS(0 <= n && n < int(COants::g_memory_le));ST VE<DMods<NUM>> memory ={one()};ST int le_curr = 1;WH(le_curr <= n){memory.push_back(memory.back()+ memory.back());le_curr++;}RE memory[n];}TE <int NUM> IN CO DMods<NUM>& DMods<NUM>::TwoPowerInverse(CRI n){if(COants::g_M == 1){RE zero();}AS(0 <= n && n < int(COants::g_memory_le));ST VE<DMods<NUM>> memory ={one()};ST int le_curr = 1;WH(le_curr <= n){auto& m = memory.back().m_n;memory.push_back(DeRP(((m & 1)== 0?m:m + COants::g_M)>> 1));le_curr++;}RE memory[n];}TE <int NUM> IN CO DMods<NUM>& DMods<NUM>::Factorial(CRL n){AS(0 <= n);if(ll(COants::g_M)<= n){RE zero();}ST VE<DMods<NUM>> memory ={one(),one()};ST int le_curr = 2;WH(le_curr <= n && memory.back().m_n != 0){memory.push_back(memory.back()* DeRP(le_curr));le_curr++;}RE le_curr <= n?memory.back():memory[n];}TE <int NUM> IN CO DMods<NUM>& DMods<NUM>::FactorialInverse(CRL n){AS(0 <= n && n < COants::g_M);ST VE<DMods<NUM>> memory ={one(),one()};ST int le_curr = 2;WH(le_curr <= n){memory.push_back(memory[le_curr - 1]* Inverse(le_curr));le_curr++;}RE memory[n];}TE <int NUM> IN DMods<NUM> DMods<NUM>::Combination(CRL n,CRL i){RE 0 <= i && i <= n?Factorial(n)* FactorialInverse(i)* FactorialInverse(n - i):zero();}TE <int NUM> IN CRUI DMods<NUM>::RP()CO NE{RE m_n;}TE <int NUM> IN DMods<NUM> DMods<NUM>::DeRP(uint n)NE{DMods<NUM> n_copy{};n_copy.m_n = MO(n);RE n_copy;}TE <int NUM> IN CO DMods<NUM>& DMods<NUM>::zero()NE{ST CO DMods<NUM> z{};RE z;}TE <int NUM> IN CO DMods<NUM>& DMods<NUM>::one()NE{ST CO DMods<NUM> o{1};RE o;}TE <int NUM> IN CRUI DMods<NUM>::GetModulo()NE{RE COants::g_M;}TE <int NUM> IN VO DMods<NUM>::SetModulo(CRUI M,CO bool& M_is_prime)NE{COants::g_M = M;COants::g_memory_le = M < COants::g_memory_bound?M:COants::g_memory_bound;COants::g_M_minus = M - 1;COants::g_M_is_prime = M_is_prime;}TE <int NUM> IN DMods<NUM> Inverse(CO DMods<NUM>& n){RE MO(DMods<NUM>(n).Invert());}TE <int NUM> IN DMods<NUM> Power(DMods<NUM> n,ll EX){RE MO(n ^= MO(EX));}TE <int NUM> IN VO swap(DMods<NUM>& n0,DMods<NUM>& n1)NE{n0.swap(n1);}TE <int NUM,CL Traits> IN IS& OP>>(IS& is,DMods<NUM>& n){ll m;is >> m;n = m;RE is;}TE <int NUM,CL Traits> IN OS& OP<<(OS& os,CO DMods<NUM>& n){RE os << n.RP();}

IN int GCD(){RE 0;}TE <TY INT1,TY...INT2>INT1 GCD(INT1 b_0,INT2... args){b_0 < 0?b_0 = -b_0:b_0;INT1 b_1 = GCD(MO(args)...);WH(b_1 != 0){swap(b_0 %= b_1,b_1);}RE MO(b_0);}TE <TY INT,TE <TY...> TY V>INT GCD(V<INT> a){INT AN = 0;for(auto& b:a){AN = GCD(MO(AN),MO(b));}RE AN;}

#define DF_OF_HASH_FOR_MOD(MOD)IN size_t hash<MOD>::OP()(CO MOD& n)CO{ST CO hash<decldecay_t(n.RP())> h;RE h(n.RP());}
TE <int NUM> DC_OF_HASH(DMods<NUM>);TE <int NUM> DF_OF_HASH_FOR_MOD( DMods<NUM> );
US MP = DMod;

/* Iteration (3KB) */
#define SPECIALSATION_OF_AR_PROGRESSION_SUM(TYPE)TE <> IN TYPE ArithmeticProgressionSum(CO TYPE& l,CO TYPE& r,CO TYPE& d){RE SpecialisedArithmeticProgressionSum(l,r,d);}
 TE <TY T,TY U,TE <TY...> TY V,TY OPR> T LeftConnectiveProd(T t,CO V<U>& f,OPR opr){for(auto& u:f){t = opr(MO(t),u);}RE MO(t);}TE <TY T,TY U,TE <TY...> TY V> IN T Sum(CO V<U>& f){RE LeftConnectiveProd(T{0},f,[](T t0,CO U& u1){RE MO(t0 += u1);});}TE <TY T,TY U,TE <TY...> TY V> IN T Prod(CO V<U>& f){RE LeftConnectiveProd(T{1},f,[](T t0,CO U& u1){RE MO(t0 *= u1);});}TE <TY T> IN T& SetMax(T& t){RE t;}TE <TY T,TY U,TY... Args> IN T& SetMax(T& t0,CO U& u1,CO Args&... args){RE SetMax(t0 < u1?t0 = u1:t0,args...);}TE <TY T> IN T& SetMin(T& t){RE t;}TE <TY T,TY U,TY... Args> IN T& SetMin(T& t0,CO U& u1,CO Args&... args){RE SetMin(u1 < t0?t0 = u1:t0,args...);}TE <TY T> IN CO T& Max(CO VE<T>& f){RE *max_element(f.BE(),f.EN());}TE <TY T,TE <TY...> TY SET> IN CO T& Max(CO SET<T>& f){RE *--f.EN();}TE <TY T,TY U,TY...Args> IN T Max(T t0,CO U& t1,CO Args&... args){RE MO(SetMax(t0,t1,args...));}TE <TY T> IN CO T& Min(CO VE<T>& f){RE *min_element(f.BE(),f.EN());}TE <TY T,TE <TY...> TY SET> IN CO T& Min(CO SET<T>& f){RE *f.BE();}TE <TY T,TY U,TY...Args> IN T Min(T t0,CO U& t1,CO Args&... args){RE MO(SetMin(t0,t1,args...));}TE <TY T,TY UINT>T Power(CO T& t,CO UINT& EX,T init = 1){RE EX > 1?Power(t * t,EX >> 1,MO(EX & 1?init *= t:init)):MO(EX > 0?init *= t:(AS(EX == 0),init));}TE <TY T> IN T PowerMemorisation(CO T& t,CRI EX){AS(EX >= 0);ST Map<T,VE<T>> memory{};auto& AN = memory[t];if(AN.empty()){AN.push_back(1);}WH(int(AN.SZ())<= EX){AN.push_back(AN.back()* t);}RE AN[EX];}TE <TY INT> IN INT ArithmeticProgressionSum(CO INT& l,CO INT& r,CO INT& d = 1){RE(l + r)*(r - l + 1)/ 2;}TE <TY INT> IN INT SpecialisedArithmeticProgressionSum(CO INT& l,CO INT& r,CO INT& d){AS(l - 1 <= r);CO INT c =(r - l)/ d;RE l - 1 == r?0:(c & 1)== 0?(c + 1)*(l + d *(c >> 1)):((c + 1)>> 1)*((l << 1)+ d * c);}
SPECIALSATION_OF_AR_PROGRESSION_SUM(int);
SPECIALSATION_OF_AR_PROGRESSION_SUM(uint);
SPECIALSATION_OF_AR_PROGRESSION_SUM(ll);
SPECIALSATION_OF_AR_PROGRESSION_SUM(ull);
TE <TY INT> IN INT ArithmeticProgressionSum(CO INT& r){RE ArithmeticProgressionSum(INT{},r);}TE <TY T,TY UINT> IN T GeometricProgressionSum(T rate,UINT EX_max,CO T& init = 1){T rate_minus = rate - 1;RE rate_minus == 0?init * ++EX_max:(Power(MO(rate),MO(++EX_max))- 1)/ MO(rate_minus)* init;}TE <TY T,TY UINT>T GeometricProgressionLinearCombinationSum(VE<T> rate,VE<UINT> EX_max,CO VE<T>& init){CO int SZ = init.SZ();AS(int(rate.SZ())== SZ && int(EX_max.SZ())== SZ);T AN{};for(int i = 0;i < SZ;i++){AN += GeometricProgressionSum(MO(rate[i]),MO(EX_max[i]),init[i]);}RE AN;}

/* Sqrt (1KB) */
TE <TY INT>INT RoundDownSqrt(CO INT& n){ST_AS(is_same_v<INT,int> || is_same_v<INT,uint> || is_same_v<INT,ll> || is_same_v<INT,ull>);AS(n >= 0);if(n <= 1){RE n;}CE INT r_max = is_same_v<INT,int>?46341:is_same_v<INT,uint>?65536:is_same_v<INT,ll>?3037000500:4294967296;INT l = 1,r = min(r_max,n);WH(l < r - 1){CO INT m =(l + r)>> 1;(m <= n / m?l:r)= m;}RE l;}TE <TY INT>INT RoundUpSqrt(CO INT& n){ST_AS(is_same_v<INT,int> || is_same_v<INT,uint> || is_same_v<INT,ll> || is_same_v<INT,ull>);AS(n >= 0);if(n <= 2){RE n;}CE INT r_max = is_same_v<INT,int>?46341:is_same_v<INT,uint>?65536:is_same_v<INT,ll>?3037000500:4294967296;CO INT n_minus = n - 1;INT l = 1,r = min(r_max,n);WH(l + 1 < r){CO INT m =(l + r)>> 1;(m <= n_minus / m?l:r)= m;}RE r;}TE <TY INT> bool IsSquare(CO INT& n){CO INT r = RoundDownSqrt(n);RE n == r * r;}

/* Loop (1KB)*/
TE <TY INT> bool NextLoop(CRI SZ,CO VE<INT>& lower_bound,CO VE<INT>& upper_limit,VE<INT>& index){int depth = 0;WH(depth < SZ){if(++index[depth]< upper_limit[depth]){break;}index[depth]= lower_bound[depth];depth++;}RE depth < SZ;}TE <TY INT> bool NextLoop(CO VE<INT>& lower_bound,CO VE<INT>& upper_limit,VE<INT>& index){RE NextLoop(index.SZ(),lower_bound,upper_limit,index);}TE <TY INT> bool NextLoopEq(CRI SZ,CO VE<INT>& lower_bound,CO VE<INT>& upper_bound,VE<INT>& index){int depth = 0;WH(depth < SZ){if(++index[depth]<= upper_bound[depth]){break;}index[depth]= lower_bound[depth];depth++;}RE depth < SZ;}TE <TY INT> bool NextLoopEq(CO VE<INT>& lower_bound,CO VE<INT>& upper_bound,VE<INT>& index){RE NextLoopEq(index.SZ(),lower_bound,upper_bound,index);}

/* string (1KB)*/
TE <TY INT> IN char IntToChar(CO INT& i,CO char& c = 'a'){RE c + i;}TE <TY INT = int> IN INT CharToInt(CO char& i){RE i -(i < 'a'?'A':'a');}TE <TY INT>string ArrayToString(CO VE<INT>& A,CO char& c = 'a'){CO int N = A.SZ();string S(N,c);for(int i = 0;i < N;i++){S[i]= IntToChar<INT>(A[i],c);}RE S;}TE <TY INT = int>VE<INT> StringToArray(CO string& S){CO int N = S.SZ();VE<int> A(N);for(int i = 0;i < N;i++){A[i]= CharToInt<INT>(S[i]);}RE A;}TE <TY INT>string ArrayToParenthesisString(CO VE<INT>& A){CO int N = A.SZ();string S(N,'(');for(int i = 0;i < N;i++){AS(0 <= A[i]&& A[i]<= 1);S[i]= "()"[A[i]];}RE S;}TE <TY INT = int>VE<INT> ParenthesisStringToArray(CO string& S){CO int N = S.SZ();VE<int> A(N);for(int i = 0;i < N;i++){A[i]= S[i]- '(';}RE A;}
#endif
/* AAA 常設ライブラリは以上に挿入する。*/

#define INCLUDE_LIBRARY
#include __FILE__
#endif /* INCLUDE_LIBRARY */
#endif /* INCLUDE_SUB */
#endif /* INCLUDE_MAIN */
