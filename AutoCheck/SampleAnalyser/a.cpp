// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleAnalyser/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

extern int exec_mode;
#include "../../Template/Local/Mode/a_Body.hpp"

// デバッグモードでないと翻訳単位ごとに異なる実装をDynamicModが持ってしまうるので実行時に
// Segmentation Faultとなる。
#include "../../../Mathematics/Arithmetic/Mod/DynamicModulo/Debug/a_Body.hpp"
#include "../../../Mathematics/Arithmetic/Mod/Function/DiscreteLog/a_Body.hpp"
#include "../../../Mathematics/Combinatorial/Loop/a_Body.hpp"
#include "../../../Mathematics/LinearAlgebra/Rank/Mod/a_Body.hpp"
#include "../../../Mathematics/Polynomial/LagrangeInterpolation/a_Body.hpp"

AC( SampleAnalyser )
{
  ASK_YES_NO( "出力の法は998244353または0ですか？" );
  int P = 998244353;
  if( reply != "y" ){
    CERRNS( "出力の法: " ); cin >> P;
  }
  DynamicMod::SetModulo( P );
  int sample_repetition_num = 3;
  bool use_memorised_sample = false;
  const string sample_path = "C:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/Sample/";
  if( sample_check ){
    ASK_YES_NO( "記録済みのサンプルを登録しますか？" );
    if( reply == "y" ){
      use_memorised_sample = true;
      ifstream sample_count{ sample_path + problem_order + "/count.txt" };
      sample_count >> sample_repetition_num;
    }
  }
  if( !use_memorised_sample ){
    ASK_YES_NO( "サンプルの個数は3個ですか？" );
    if( reply != "y" ){
      CERRNS( "サンプルの個数: " ); cin >> sample_repetition_num;
      assert( sample_repetition_num > 0 );
    }
  }
  vector<vector<ll>> input( sample_repetition_num );
  vector<DynamicMod> output( sample_repetition_num );
  int var = 0;
  if( use_memorised_sample ){
    const string input_path = sample_path + problem_order + "/input/sample";
    const string output_path = sample_path + problem_order + "/output/sample";
    for( int sample_num = 1 ; sample_num <= sample_repetition_num ; sample_num++ ){
      const string sample_num_str = to_string( 100 + sample_num ).substr( 1 );
      ifstream ifs_input{ input_path + sample_num_str + ".txt" };
      ifstream ifs_output{ output_path + sample_num_str + ".txt" };
      while( !ifs_input.eof() ){
        string temp; getline( ifs_input , temp );
        if( temp == "" ){
          continue;
        }
        int l = 0 , size = temp.size();
        for( int r = 0 ; r <= size ; r++ ){
          if( r == size || temp[r] == ' ' ){
            if( l < r ){
              if( sample_num == 1 ){
                var++;
              }
              input[sample_num - 1].push_back( stoll( temp.substr( l , r - l ) ) );
            }
            l = r + 1;
          }
        }
      }
      if( sample_num == 1 ){
        CERRNS( "サンプルの個数は" , var , "個です。\n" );
        CERR( "" );
      }
      while( !ifs_output.eof() ){
        ifs_output >> output[sample_num - 1];
      }
    }
  } else {
    CERRNS( "サンプル入力中の固定長な数値の個数: " ); cin >> var;
    CERR( "" );
    bool hand = true;
    if( var == 1 ){
      ASK_NUMBER(
                 "等差数列を入力する。" ,
                 "サンプルごとに入力する。"
                 );
      hand = num == 1;
    }
    if( hand ){
      ASK_NUMBER(
                 "(入力-出力)群を入力する。" ,
                 "(入力)群と(出力)群を入力する。"
                 );
      if( num == num_temp++ ){
        FOR( sample_num , 0 , sample_repetition_num ){
          CERRNS( "サンプル" , sample_num + 1 , "入力中の固定長な数値: " );
          CIN_A( ll , 0 , var , A );
          input[sample_num] = move( A );
          CERRNS( "サンプル" , sample_num + 1 , "出力: " ); cin >> output[sample_num];
          CERR( "" );
        }
      } else {
        FOR( sample_num , 0 , sample_repetition_num ){
          CERRNS( "サンプル" , sample_num + 1 , "入力中の固定長な数値: " );
          CIN_A( ll , 0 , var , A );
          input[sample_num] = move( A );
        }
        FOR( sample_num , 0 , sample_repetition_num ){
          CERRNS( "サンプル" , sample_num + 1 , "出力: " ); cin >> output[sample_num];
          CERR( "" );
        }
      }
    } else {
      CERRNS( "初項aと公差d: " ); CIN( int , a , d );
      FOR( sample_num , 0 , sample_repetition_num ){
        input[sample_num] = { a + d * sample_num };
      }
      CERRNS( "出力列: " ); CIN_A( DynamicMod , 0 , sample_repetition_num , A );
      output = move( A );
    }
  }
  bool continuous = true;
  for( int sample_num = 1 ; sample_num < sample_repetition_num ; sample_num++ ){
    continuous &= input[sample_num][0] - input[sample_num-1][0];
  }
  if( var == 1 ){
    if( continuous ){
      CERR( "入力が連続した数値なので入力の一部をスキップした時の補間も行います。" );
    } else {
      CERR( "入力が連続した数値でないので入力の一部をスキップした時の補間は行いません。" );
    }
  }
  const string P_str = to_string( P );
  int scale = 1;
  while( true ){
    PowerAnalysis( sample_repetition_num , output , scale , P );
    if( 0 < var && var <= 4 ){
      bool prime = P == 998244353 || P == 1000000007;
      if( !prime && (
		     ( var == 1 && sample_repetition_num >= 4 ) ||
		     ( var == 2 && sample_repetition_num >= 7 ) ||
		     ( var == 3 && sample_repetition_num >= 8 )
		     )
	  ){
	ASK_YES_NO( P_str + "は素数ですか？" );
	prime = reply == "y";
      }
      CERR( "サンプル出力の法" + P_str + "における" + to_string( var ) + "変数多項式補間を試みます。" );
      if( var == 1 ){
	if( sample_repetition_num < 4 || ! prime ){
	  InputPolynomialAnalysis1_few( sample_repetition_num , input , output , scale , P , P_str );
	} else {
	  InputPolynomialAnalysis1_enough( sample_repetition_num , input , output , scale , P , P_str , continuous );
	}
      } else if( var == 2 ){
	if( sample_repetition_num < 9 || !prime ){
	  InputPolynomialAnalysis2_few( sample_repetition_num , input , output , scale , P , P_str );
	} else {
	  InputPolynomialAnalysis2_enough( sample_repetition_num , input , output , scale , P , P_str );
	}
      } else if( var == 3 ){
	if( sample_repetition_num < 8 || !prime ){
	  InputPolynomialAnalysis3_few( sample_repetition_num , input , output , scale , P , P_str );
	} else {
	  InputPolynomialAnalysis3_enough( sample_repetition_num , input , output , scale , P , P_str );
	}
      } else {
	assert( var == 4 );
	InputLinearAnalysis4( sample_repetition_num , input , output , scale , P , P_str );
      }
      if( var < 3 ){
	CERR( "サンプル出力の法" + P_str + "における指数関数の一次結合による補間を試みます。" );	
	if( var == 1 ){
	  if( sample_repetition_num < 5 || ! prime ){
	    InputExponentialAnalysis1_few( sample_repetition_num , input , output , scale , P , P_str );
	  } else {
	    InputExponentialAnalysis1_enough( sample_repetition_num , input , output , scale , P , P_str , continuous );
	  }
	} else {
	  assert( var == 2 );
	  if( sample_repetition_num < 7 || !prime ){
	    InputExponentialAnalysis2_few( sample_repetition_num , input , output , scale , P , P_str );
	  } else {
	    InputExponentialAnalysis2_enough( sample_repetition_num , input , output , scale , P , P_str );
	  }
	}
      }
    }
    ASK_YES_NO( "解析範囲を広げますか？" );
    if( reply == "y" ){
      while( true ){
	int rate = 0;
	CERR( "各係数の探索範囲の拡大倍率: " ); cin >> rate;
	if( rate <= 1 ){
	  CERR( "倍率は2以上の整数にしてください。" );
	} else {
	  scale *= rate;
	  break;
	}
      }
    } else {
      break;
    }
  }
  CERR( "サンプルの解析を終了します。");
}

void PowerAnalysis( const int& sample_repetition_num , const vector<DynamicMod>& output , const int& scale , const int& P )
{
  CEXPR( int , diff_bound , 30 );
  const int diff_max = diff_bound / sample_repetition_num * scale;
  const vector bases{2,3,5,6,7};
  int sqrtP = sqrt( P );
  RUN( bases , base ){
    CERRNS( "サンプル" );
    FOR( sample_num , 0 , sample_repetition_num ){
      CERRNS( ( sample_num == 0 ? "" : ", " ) , sample_num + 1 );
    }
    CERRNS( "の出力の法" , P , "における底" , base , "の離散対数を求めます。\n" );
    FOREQ( diff , - diff_max , diff_max ){
      CERRNS( "出力" , ( diff > 0 ? "+" : "" ) , ( diff == 0 ? "" : to_string( diff ) ) , ": " );
      bool small = true;
      FOR( sample_num , 0 , sample_repetition_num ){
	int dl = DiscreteLog( int( output[sample_num].Represent() ) + diff , base , P );
	small &= ( int( output[sample_num].Represent() ) + diff ) % P == 0 || ( 0 <= dl && dl < sqrtP );
	CERRNS( ( dl < 0 ? "NaN" : to_string( dl ) ) , ( sample_num == sample_repetition_num - 1 ? "\n" : ", " ) );
      }
      if( small ){
	CERR( "(0または離散対数が有意に小さい値です。)" );
	CERR( "" );
      }
    }
    vector exponent( sample_repetition_num , vector( sqrtP * 2 + 1 , sqrtP ) );
    DynamicMod base_mod{ base } , power = Power( base_mod , -sqrtP );
    FOREQ( d , -sqrtP , sqrtP ){
      FOR( sample_num , 0 , sample_repetition_num ){
	int temp = ( power - output[sample_num] ).Represent();
	if( temp <= sqrtP ){
	  exponent[sample_num][temp + sqrtP] = d;
	} else if( -sqrtP <= ( temp -= P ) ){
	  exponent[sample_num][temp + sqrtP] = d;
	}
      }
    }
    CERR( "" );
    bool found = false;
    FOREQ( diff , -sqrtP , sqrtP ){
      if( abs( diff ) > diff_max ){
	bool small = true;
	FOR( sample_num , 0 , sample_repetition_num ){
	  small &= exponent[sample_num][diff + sqrtP] < sqrtP;
	}
	if( small ){
	  if( !found ){
	    found = true;
	    CERRNS( "出力からのズレ" , sqrtP , "以下の範囲で他に離散対数が有意に小さい\n" );
	    CERRNS( "値を列挙します。\n" );
	  }
	  CERRNS( "出力" , ( diff > 0 ? "+" : "" ) , ( diff == 0 ? "" : to_string( diff ) ) , ": " );
	  FOR( sample_num , 0 , sample_repetition_num ){
	    CERRNS( exponent[sample_num][diff + sqrtP] , ( sample_num == sample_repetition_num - 1 ? "" : ", " ) );
	  }
	}
      }
    }
    if( !found ){
      CERRNS( "出力からのズレ" , sqrtP , "以下の範囲で他に離散対数が有意に小さい値は\n" );
      CERRNS( "見付かりませんでした。\n" );
    }
    CERR( "" );
  }
}

void InputPolynomialAnalysis1_few( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 4 );
  CEXPR( int , length , size ); // 4
  CEXPR( int , denom , 12 );
  CEXPR( int , numer_bound , 50 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_repetition_num * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  CERRNS( "（予想解析時間: " , time / 16000000 , "秒）\n" );
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_repetition_num ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] };
      DynamicMod temp{};
      FOR( i , 0 , size ){
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    FOR( i , 0 , size ){
      CERRNS( "(" , index[i] , "/" , denom , ") * (引数1)^" , i , ( i == size - 1 ? "\n" : " +\n" ) );
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERRNS( "解析時間: " , int( CURRENT_TIME / 1000 ) , "秒\n" );
  CERR( "" );
}

void InputPolynomialAnalysis1_enough( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str , const bool& continuous )
{
  for( int skip_span = 1 ; skip_span <= ( continuous ? ( sample_repetition_num + 2 ) / 3 : 1 ) ; skip_span++ ){
    for( int residue = 0 ; residue < skip_span ; residue++ ){
      vector<DynamicMod> input_copy{};
      vector<DynamicMod> output_copy{};
      int sample_size = 0;
      for( int sample_num = residue ; sample_num < sample_repetition_num ; sample_num += skip_span ){
        input_copy.push_back( ( input[sample_num][0] - residue ) / skip_span );
        output_copy.push_back( output[sample_num] );
        sample_size++;
      }
      if( continuous ){
        CERR( "入力を" , residue , "番目から" , skip_span , "置きに選んで多項式補間を試みます。" );
      }
      auto answer = LagrangeInterpolation( input_copy , output_copy );
      answer.RemoveRedundantZero();
      int size = answer.size();
      if( size < sample_size ){
        CERR( "補間成功（次数が小さいため信頼度は高い）:" );
      } else if( size < 5 ) {
        CERR( "補間成功（サンプルが少なすぎるため信頼度は低い）:" );
      } else {
        CERR( "補間成功（次数が高すぎるため信頼度はほとんどなし）:" );
      }
      if( skip_span == 1 ){
        FOR( i , 0 , size ){
          CERRNS( "(" , answer[i] , ") * (引数1)^" , i , ( i == size - 1 ? "\n" : " +\n" ) );
        }
      } else {
        FOR( i , 0 , size ){
          CERRNS( "(" , answer[i] , ") * floor(((引数1)" , residue == 0 ? "" : to_string( -residue ),  ")/" , skip_span , ")^" , i , ( i == size - 1 ? "\n" : " +\n" ) );
        }
      }
      CERR( "" );
    }
  }
}

void InputPolynomialAnalysis2_few( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , length , size * size ); // 9
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 3 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_repetition_num * size * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  CERRNS( "（予想解析時間: " , time / 16000000 , "秒）\n" );
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_repetition_num ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] };
      DynamicMod temp{};
      FOR( dx , 0 , size ){
	DynamicMod xy_power = x_power;
	FOR( dy , 0 , size ){
	  int i = size * dx + dy;
	  temp += DynamicMod( index[i] ) * xy_power;
	  xy_power *= y;
	}
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	int i = size * dx + dy;
	CERRNS( "(" , index[i] , "/" , 2 * index[i+size*size] - 1 , ") * (引数1)^" , dx , " (引数2)^" , dy , ( dx == size - 1 && dy == size - 1 ? "\n" : " +\n" ) );
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERRNS( "解析時間: " , int( CURRENT_TIME / 1000 ) , "秒\n" );
  CERR( "" );
}

void InputPolynomialAnalysis2_enough( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , length , size * size ); // 9
  vector M( sample_repetition_num , vector<DynamicMod>( length + 1 ) );
  FOR( sample_num , 0 , sample_repetition_num ){  
    DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] };
    FOR( dx , 0 , size ){
      DynamicMod xy_power = x_power;
      FOR( dy , 0 , size ){
	int i = size * dx + dy;
	M[sample_num][i] = xy_power;
	xy_power *= y;
      }
      x_power *= x;
    }
    M[sample_num][length-1] = output[sample_num];
  }
  auto [rank,index] = ExtendedReducedRowEchelonForm( M );
  if( rank == length ){
    CERR( "補間成功:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	int i = size * dx + dy;
	CERRNS( "(" , index[i] , ") * (引数1)^" , dx , " (引数2)^" , dy , ( i == length - 1 ? "}\n" : "} +\n" ) );
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERR( "" );
}

void InputPolynomialAnalysis3_few( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 2 );
  CEXPR( int , length , size * size * size ); // 8
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 4 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_repetition_num * size * size * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  CERRNS( "（予想解析時間: " , time / 16000000 , "秒）\n" );
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_repetition_num ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] } , z{ input[sample_num][2] };
      DynamicMod temp{};
      FOR( dx , 0 , size ){
	DynamicMod xy_power = x_power;
	FOR( dy , 0 , size ){
	  DynamicMod xyz_power = xy_power;
	  FOR( dz , 0 , size ){
	    int i = size * size * dx + size * dy + dz;
	    temp += DynamicMod( index[i] ) * xyz_power;
	    xyz_power *= z;
	  }
	  xy_power *= y;
	}
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	FOR( dz , 0 , size ){
	  int i = size * size * dx + size * dy + dz;
	  CERRNS( "(" , index[i] , "/" , denom , ") * (引数1)^" , dx , " (引数2)^" , dy , " (引数3)^" , dz , ( dx == size - 1 && dy == size - 1 && dz == size - 1 ? "\n" : " +\n" ) );
	}
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERRNS( "解析時間: " , int( CURRENT_TIME / 1000 ) , "秒\n" );
  CERR( "" );
}

void InputPolynomialAnalysis3_enough( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 2 );
  CEXPR( int , length , size * size * size ); // 8
  vector M( sample_repetition_num , vector<DynamicMod>( length + 1 ) );
  FOR( sample_num , 0 , sample_repetition_num ){  
    DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] } , z{ input[sample_num][1] };
    FOR( dx , 0 , size ){
      DynamicMod xy_power = x_power;
      FOR( dy , 0 , size ){
	DynamicMod xyz_power = xy_power;
	FOR( dz , 0 , size ){
	  int i = size * size * dx + size * dy + dz;
	  M[sample_num][i] = xyz_power;
	  xyz_power *= z;
	}
	xy_power *= y;
      }
      x_power *= x;
    }
    M[sample_num][length-1] = output[sample_num];
  }
  auto [rank,index] = ExtendedReducedRowEchelonForm( M );
  if( rank == length ){
    CERR( "補間成功:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	FOR( dz , 0 , size ){
	  int i = size * size * dx + size * dy + dz;
	  CERRNS( "(" , index[i] , ") * (引数1)^" , dx , " (引数2)^" , dy , " (引数3)^" , dz , ( i == length - 1 ? "}\n" : "} +\n" ) );
	}
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERR( "" );
}

void InputLinearAnalysis4( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , var , 4 );
  CEXPR( int , length , var + 1 ); // 5
  CEXPR( int , denom , 12 );
  CEXPR( int , numer_bound , 24 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound{ length , numer_max };
  vector<int> index = lower_bound;
  ll time = sample_repetition_num * var;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  CERRNS( "（予想解析時間: " , time / 16000000 , "秒）\n" );
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_repetition_num ){
      DynamicMod temp = index[var];
      FOR( i , 0 , var ){
	temp += DynamicMod( index[i] ) * input[sample_num][i];
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    CERRNS( "(" , index[var] , "/" , denom , ") +\n" );
    FOR( i , 0 , var ){
      CERRNS( "(" , index[i] , "/" , denom , ") * (引数" , i , ")" , ( i == var - 1 ? "\n" : " +\n" ) );
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERRNS( "解析時間: " , int( CURRENT_TIME / 1000 ) , "秒\n" );
  CERR( "" );
}

void InputExponentialAnalysis1_few( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , length , size + 2 ); // 5
  CEXPR( int , denom , 6 );
  CEXPR( int , numer_bound , 18 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_repetition_num * ( size + 2 );
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  CERRNS( "（予想解析時間: " , time / 16000000 , "秒）\n" );
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_repetition_num ){
      DynamicMod x{ input[sample_num][0] } , x_power = Power( x , input[sample_num][0] - 1 );
      DynamicMod temp = DynamicMod( index[length-1] ) + DynamicMod( index[length-2] ) * x;
      FOR( d , 0 , size ){
	int i = d;
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    CERRNS( "(" , index[length-1] , "/" , denom , ") + " , "(" , index[length-2] , "/" , denom , ") (引数1) + " );
    FOR( d , 0 , size ){
      int i = d , dx = d - 1;
      CERRNS( "(" , index[i] , "/" , denom , ") * (引数1)^{(引数1)" , ( dx > 0 ? "+" : "" ) , ( dx == 0 ? "" : to_string( dx ) ) , ( d == size - 1 ? "}\n" : "} +\n" ) );
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERRNS( "解析時間: " , int( CURRENT_TIME / 1000 ) , "秒\n" );
  CERR( "" );
}

void InputExponentialAnalysis1_enough( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str , const bool& continuous )
{
  CEXPR( int , size , 3 );
  CEXPR( int , length , size + 2 );
  for( int skip_span = 1 ; skip_span <= ( continuous ? ( sample_repetition_num + length - 1 ) / length : 1 ) ; skip_span++ ){
    for( int residue = 0 ; residue < skip_span ; residue++ ){
      int sample_size = 0;
      for( int sample_num = residue ; sample_num < sample_repetition_num ; sample_num += skip_span ){
        sample_size++;
      }
      CERR( "入力を" , residue , "番目から" , skip_span , "置きに選んで指数関数の一次結合による補間を試みます。" );
      FOREQ( dx1 , -1 , 1 ){
        vector M( sample_size , vector<DynamicMod>( length + 1 ) );
        for( int sample_num = residue ; sample_num < sample_repetition_num ; sample_num += skip_span ){
          DynamicMod x{ ( input[sample_num][0] + skip_span - 1 ) / skip_span + dx1 };
          DynamicMod x_power = Power( x , ( input[sample_num][0] + skip_span - 1 ) / skip_span - 1 );
          FOR( d , 0 , size ){
            M[sample_num / skip_span][d] = x_power;
            x_power *= x;
          }
          M[sample_num / skip_span][size] = x;
          M[sample_num / skip_span][size+1] = 1;
          M[sample_num / skip_span][length] = output[sample_num];
        }
        auto [rank,index] = ExtendedReducedRowEchelonForm( M );
        if( rank == length ){
          CERR( "補間成功:" );
          if( skip_span == 1 ){
            string base = "(引数1)";
            if( dx1 != 0 ){
              base = "(" + base + ( dx1 > 0 ? "+" : "" ) + to_string( dx1 ) + ")";
            }
            CERRNS( "(" , index[length-1] , ") +\n" );
            CERRNS( "(" , index[length-2] , ") * " , base , " +\n" );
            FOR( d , 0 , size ){
              int i = d , dx2 = d - 1;
              CERRNS( "(" , index[i] , ") * " , base , "^{(引数1)" , ( dx2 > 0 ? "+" : "" ) , ( dx2 == 0 ? "" : to_string( dx2 ) ) , ( d == size - 1 ? ")}\n" : ")} +\n" ) );
            }
          } else {
            string base = "ceil((引数1)/" + to_string( skip_span ) + ")";
            if( dx1 != 0 ){
              base = "(" + base + ( dx1 > 0 ? "+" : "" ) + to_string( dx1 ) + ")";
            }
            CERRNS( "(" , index[length-1] , ") +\n" );
            CERRNS( "(" , index[length-2] , ") * " , base , " +\n" );
            FOR( d , 0 , size ){
              int i = d , dx2 = d - 1;
              CERRNS( "(" , index[i] , ") * " , base , "^{ceil((引数1)/" , skip_span , ( dx2 > 0 ? "+" : "" ) , ( dx2 == 0 ? "" : to_string( dx2 ) ) , ( d == size - 1 ? ")}\n" : ")} +\n" ) );
            }
          }
        } else {
          CERR( "補間失敗。" );
        }
        CERR( "" );
      }
    }
  }
}

void InputExponentialAnalysis2_few( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , var , 2 );
  CEXPR( int , length , var * ( var - 1 ) * size + 1 ); // 7
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 5 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_repetition_num * size * 2;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  CERRNS( "（予想解析時間: " , time / 16000000 , "秒）\n" );
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_repetition_num ){
      DynamicMod x{ input[sample_num][0] } , y{ input[sample_num][1] } , x_power = Power( x , input[sample_num][1] - 1 ) , y_power = Power( y , input[sample_num][0] - 1 );
      DynamicMod temp = DynamicMod( index[length-1] );
      FOR( d , 0 , size ){
	int i = d;
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      FOR( d , 0 , size ){
	int i = size + d;
	temp += DynamicMod( index[i] ) * y_power;
	y_power *= y;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    CERRNS( "(" , index[length-1] , "/" , denom , ") +\n" );
    FOR( d , 0 , size ){
      int i = d , dy = d - 1;
      CERRNS( "(" , index[i] , "/" , denom , ") * (引数1)^{(引数2)" , ( dy > 0 ? "+" : "" ) , ( dy == 0 ? "" : to_string( dy ) ) , "} +\n" );
    }
    FOR( d , 0 , size ){
      int i = size + d , dx = d - 1;
      CERRNS( "(" , index[i] , "/" , denom , ") * (引数2)^{(引数1)" , ( dx > 0 ? "+" : "" ) , ( dx == 0 ? "" : to_string( dx ) ) , ( d == size - 1 ? "}\n" : "} +\n" ) );
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERRNS( "解析時間: " , int( CURRENT_TIME / 1000 ) , "秒\n" );
  CERR( "" );
}

void InputExponentialAnalysis2_enough( const int& sample_repetition_num , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , var , 2 );
  CEXPR( int , length , var * ( var - 1 ) * size + 1 ); // 7
  vector M( sample_repetition_num , vector<DynamicMod>( length + 1 ) );
  FOR( sample_num , 0 , sample_repetition_num ){  
    DynamicMod x{ input[sample_num][0] } , y{ input[sample_num][1] } , x_power = Power( x , input[sample_num][1] - 1 ) , y_power = Power( y , input[sample_num][0] - 1 );
    FOR( d , 0 , size ){
      int i = d;
      M[sample_num][i] = x_power;
      x_power *= x;
    }
    FOR( d , 0 , size ){
      int i = size + d;
      M[sample_num][i] = y_power;
      y_power *= y;
    }
    M[sample_num][var * ( var - 1 ) * size] = 1;
    M[sample_num][length] = output[sample_num];
  }
  auto [rank,index] = ExtendedReducedRowEchelonForm( M );
  if( rank == length ){
    CERR( "補間成功:" );
    CERRNS( "(" , index[length-1] , ") +\n" );
    FOR( d , 0 , size ){
      int i = d , dy = d - 1;
      CERRNS( "(" , index[i] , ") * (引数1)^{(引数2)" , ( dy > 0 ? "+" : "" ) , ( dy == 0 ? "" : to_string( dy ) ) , "} +\n" );
    }
    FOR( d , 0 , size ){
      int i = size + d , dx = d - 1;
      CERRNS( "(" , index[i] , ") * (引数2)^{(引数1)" , ( dx > 0 ? "+" : "" ) , ( dx == 0 ? "" : to_string( dx ) ) , ( d == size - 1 ? "}\n" : "} +\n" ) );
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERR( "" );
}
