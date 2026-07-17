// c:/Users/user/Documents/Programming/Contest/ProblemCreation/GenerateSamples/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../WriteInSamples/a_Body.hpp"
#include "../../../Mathematics/Utility/Random/a_Body.hpp"

void GenerateSamples( const string& directory_name )
{

  ofstream ofs_input_list;
  const string input_file_list_name = "/" + directory_name + "/サンプル入力/一覧.txt";
  cout << "LL_TYPEは" << WhatIsLL_TYPE << "として定義されています。" << endl;
  cout << "ジェネレータコードでサンプルを生成します。"  << endl;
  SEARCH_SAMPLE_LIST_DIRECTORY( ofs , ios::app , cout << "ジェネレータコードでサンプルを生成します。" << endl );
  string reply = "y";
  while( reply == "y" ){
    COUT( "サンプルの種類番号を入力してください。" );
    CIN( int , num );
    COUT( "種類番号" , num , "のサンプルを生成する回数を入力してください。" );
    CEXPR( int , bound_T , 100 );
    CIN_ASSERT( T , 0 , bound_T );
    GetRand( 0 , 1 );
  
    REPEAT( T ){

      GenerateSamples_Body( ofs_input_list , num );

    }

    COUT( "種類番号" , num , "のサンプルを" , T , "回生成しました。" );
    while( true ){
      COUT( "サンプル生成を続行しますか？[y/n]" );
      CIN( string , temp );
      if( temp == "y" || temp == "n" ){
        reply = temp;
        break;
      } else {
        COUT( "返答は[y/n]でお願いします。" );
      }
    }
  }
  
  return;
  
}
