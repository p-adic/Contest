// c:/Users/user/Documents/Programming/Contest/ProblemCreation/a.cpp

// 作問用
#include "a_Body.hpp"
// stdstream系のライブラリのためにinclude順を後にする。
#include "../Header.hpp"

int main()
{
  const string directory_name = "問題名";
  COUT( "どれを選択しますか？" );
  COUT( "0:" , directory_name , "の想定解を実行する。" );
  COUT( "1:" , directory_name , "のサンプルを生成する。" );
  COUT( "2:" , directory_name , "のサンプルを格納するファイルを作成する。" );
  COUT( "3:" , directory_name , "のサンプルのフォーマットを変更する。" );
  COUT( "4: 終了する。" );
  CIN_ASSERT( branch , 0 , 4 );
  int branch_temp = 0;
  if( branch == branch_temp++ ){
    ExecuteSolution( directory_name );
  } else if( branch == branch_temp++ ){
    GenerateSamples( directory_name );
  } else if( branch == branch_temp++ ){
    WriteInSamples( directory_name );
  } else if( branch == branch_temp++ ){
    RearrangeSamples( directory_name );
  }
  return 0;
}

inline void Solve()
{
}
REPEAT_MAIN(1);

void GenerateSamples_Body( ofstream& ofs_input_list , const int& num )
{
}

void WriteInSamples_Body( VLArray<string>& file_prefix , VLArray<int>& file_num )
{
  // VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" };
  // VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" , "Sugoi_" };
  // VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" , "Sugoi_" , "Tester_" };
  // VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" , "Tester_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" , "Sugoi_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" , "Sugoi_" , "evil_" };
  VLArray<string> prefix{ "Sampuru_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" , "Tester_" };
  // VLArray<string> prefix{ "test" };
  VLArray<int> num{};
  file_prefix = prefix;
  file_num = num;
  return;
}

// 出力一覧ファイルがある場合、それを削除しないと正しくファイル書き込みができないことに注意。
void RearrangeSamples_Body( ifstream& ifs_input_list , ofstream& ofs_input_list )
{
  REPEAT( 20 ){
    // フォーマット変更コードをここに入れる。
    IFS( int , N );
    OFS( N + 1 );
    OFS( "" );
  }
  string check_redundant = "";
  while( ifs_input_list >> check_redundant ){
    assert( check_redundant == "" );
  }
  cout << "書き込みが完了しました。" << endl;
  return;
}
